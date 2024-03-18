// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
//#include "ImWin.h"

typedef HRESULT(WINAPI* Reset_t)(LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*); // 16
typedef long(__stdcall* EndScene_t)(LPDIRECT3DDEVICE9);                      // 42
typedef LRESULT(__stdcall* WndProc_t)(const HWND, UINT, WPARAM, LPARAM);


#ifdef _WIN64
#define SELF_PTR LONG_PTR
#define WNDPROC_INDEX GWLP_WNDPROC
#else
#define SELF_PTR DWORD
#define WNDPROC_INDEX GWL_WNDPROC
#endif



D3DPRESENT_PARAMETERS   g_present;
IDirect3D9*             g_Direct3D9 = NULL;
IDirect3DDevice9*       g_pd3dDevice = NULL;

HWND g_hWnd = NULL;

Reset_t     oReset;
EndScene_t  oEndScene;
WndProc_t   oWndProc;

SELF_PTR* dDeviceVT = NULL;
//(EndScene)(THIS) PURE;
// 窗口消息处理，获取窗口操作消息转嫁给IMGUI
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT __stdcall hkWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam)) return true;
    switch (msg){
    case WM_LBUTTONDOWN: case WM_LBUTTONDBLCLK:    case WM_RBUTTONDOWN: case WM_RBUTTONDBLCLK:
    case WM_MBUTTONDOWN: case WM_MBUTTONDBLCLK:    case WM_XBUTTONDOWN: case WM_XBUTTONDBLCLK:
    if (checkBoxFalgs_1) return true;
    }


    return CallWindowProc(oWndProc, hWnd, msg, wParam, lParam);
}


HRESULT __stdcall hkReset(IDirect3DDevice9* pd3dDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{    
    Helpers::UnHookFunction((PVOID*)(&oReset), hkReset);
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT tmpReset = pd3dDevice->Reset(pPresentationParameters);
    ImGui_ImplDX9_CreateDeviceObjects();
    Helpers::HookFunction((PVOID*)(&oReset), hkReset);
    return tmpReset;
}


void MineImGuiInit(IDirect3DDevice9* pd3dDevice)
{
    // 检查IMGUI 版本
    IMGUI_CHECKVERSION();

    // 创建IMGUI上下文
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    // 关闭imgui  配置文件的显示
    io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
    io.WantSaveIniSettings = false;
    io.IniFilename = NULL;

    //ImGuiStyle& style = ImGui::GetStyle();
    //ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();
    //ImGui::StyleColorsLight();
    LoadMyStype();

    //SetLayeredWindowAttributes();
    // 设置字体---为了显示中文
    ImFontConfig f_cfg;
    f_cfg.FontDataOwnedByAtlas = false;
    const ImFont* font = io.Fonts->AddFontFromMemoryTTF((void*)baidu_font_data, baidu_font_size, 17.0f, &f_cfg, io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
    
    ImGui_ImplWin32_Init(g_hWnd);
    ImGui_ImplDX9_Init(pd3dDevice);

}

HRESULT __stdcall hkEndScene(IDirect3DDevice9* pd3dDevice)
{
    Helpers::UnHookFunction((PVOID*)(&oEndScene), hkEndScene);

    // IMGUI初始化
    static bool firstCall = TRUE;
    if (firstCall)
    {
        firstCall = !firstCall;
        MineImGuiInit(pd3dDevice);
        oWndProc = (WNDPROC)SetWindowLongPtr(g_hWnd, WNDPROC_INDEX, (LONG_PTR)hkWndProc);
    }

    LoadMyWin();
    HRESULT result = pd3dDevice->EndScene();
    Helpers::HookFunction((PVOID*)(&oEndScene), hkEndScene);
    return result;
}

void InitD3d()
{
    //AllocConsole();    
    //freopen("CON", "w", stdout);
    //SetConsoleTitleA("调试窗口");

    // 获取目标游戏窗口句柄
    g_hWnd = FindWindowA("Direct3DWindowClass",NULL);

    // 创建D39设备对象
    g_Direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);

    // 初始化参数结构体
    memset(&g_present, 0, sizeof(g_present));
    g_present.Windowed = TRUE;
    g_present.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_present.BackBufferFormat = D3DFMT_UNKNOWN;
    g_present.EnableAutoDepthStencil = TRUE;
    g_present.AutoDepthStencilFormat = D3DFMT_D16;

    // 创建d3d9设备标识
    HRESULT result = g_Direct3D9->CreateDevice(
        D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, 
        g_hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &g_present,&g_pd3dDevice
    );

    // 开始hook对应的D3D9函数
    dDeviceVT   = (SELF_PTR*)*(SELF_PTR*)g_pd3dDevice;
    oReset      = (Reset_t)dDeviceVT[16];
    oEndScene   = (EndScene_t)dDeviceVT[42];

    Helpers::HookFunction((PVOID*)(&oReset), hkReset);
    Helpers::HookFunction((PVOID*)(&oEndScene), hkEndScene);
    
    //g_pd3dDevice->Release();
    g_Direct3D9->Release();
    
}

void unLoad()
{
    Helpers::UnHookFunction((PVOID*)(&oReset), hkReset);
    Helpers::UnHookFunction((PVOID*)(&oEndScene), hkEndScene);    
    //g_pd3dDevice->Release();
    g_Direct3D9->Release();
}
BOOL APIENTRY DllMain( HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        DisableThreadLibraryCalls(hModule);
        ::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)InitD3d, NULL, NULL, NULL);
        break;
    }
    case DLL_THREAD_ATTACH:break;
    case DLL_THREAD_DETACH:break;
    case DLL_PROCESS_DETACH: 
    {
        unLoad();
        break;
    }
    }
    return TRUE;
}

