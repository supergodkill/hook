#include "pch.h"
#include "ImWin.h"


bool mainBeginSate = TRUE;
bool tab_bar_flags = TRUE;
bool checkBoxFalgs_1 = FALSE;

void loadTab1()
{
    IM_TAB子工具栏_开始(u8"郎的诱惑")

        IM_表格_横线
        IM_标签(u8"表格大作战")

        IM_表格_开始(6, "table1")

        IM_标签(u8"序号") IM_表格_竖线
        IM_标签(u8"姓名") IM_表格_竖线
        IM_标签(u8"性别") IM_表格_竖线
        IM_标签(u8"年龄") IM_表格_竖线
        IM_标签(u8"班级") IM_表格_竖线
        IM_标签(u8"操作") IM_表格_竖线
        IM_表格_横线
        const char* names[3] = { u8"张三", u8"李四", u8"老吴" };
        const char* aYear[3] = { "19", "20", "45" };
        const char* aClass[3] = { u8"1班", u8"2班", u8"3班" };
        const char* Nums[3] = { u8"取岁1", u8"取岁2", u8"取岁3" };
        for (int i = 0; i < 3; i++)
        {
            ImGui::Text("%02d", i); IM_表格_竖线
            IM_标签(names[i]) IM_表格_竖线
            IM_标签(u8"男") IM_表格_竖线
            IM_标签(aYear[i]) IM_表格_竖线
            IM_标签(aClass[i]) IM_表格_竖线
            if (IM_按钮(Nums[i]))  
                MessageBoxA(0, (LPCSTR)(aYear[i]), 0,  0);

        IM_表格_竖线
            //IM_标签(Nums[i]) IM_表格_竖线 

    }
    IM_表格_结束
    IM_TAB子工具栏_结束
}

void loadTab2()
{
    if (ImGui::BeginTabItem(u8"SCR-特殊"))
    {


        if (ImGui::Button(u8"游戏初始化2"))
        {
            checkBoxFalgs_1 = !checkBoxFalgs_1;
        }

        if (ImGui::Checkbox(u8"开启飞天", &checkBoxFalgs_1))
        {
            //  点击事件执行
        }

        if (checkBoxFalgs_1)
        {
            ImGui::Text(u8"欢迎使用IMGUI 窗口3");
            ImGui::SameLine();
            ImGui::Text(u8"欢迎使用IMGUI 窗口4");
        }
        ImGui::EndTabItem();
    }

}
void loadTab3()
{
    if (ImGui::BeginTabItem(u8"SCR-其他"))
    {
        if (ImGui::Button(u8"游戏初始化3"))
        {
            checkBoxFalgs_1 = !checkBoxFalgs_1;
        }

        if (ImGui::Checkbox(u8"开启飞天", &checkBoxFalgs_1))
        {

        }
        ImGui::Columns(1);
        ImGui::Separator();

        ImGui::Text(u8"周围遍历的东西都在下面表格:");

        ImGui::Columns(4, "mycolumns"); // 4-ways, with border
        ImGui::Separator();
        ImGui::Text("ID"); ImGui::NextColumn();//竖线
        ImGui::Text("Name"); ImGui::NextColumn();
        ImGui::Text("Path"); ImGui::NextColumn();
        ImGui::Text("Hovered"); ImGui::NextColumn();
        // 横线
        ImGui::Separator();

        const char* names[3] = { "One", "Two", "Three" };
        const char* paths[3] = { "/path/one", "/path/two", "/path/three" };
        static int selected = -1;
        for (int i = 0; i < 3; i++)
        {
            char label[32];
            sprintf(label, "%04d", i);
            if (ImGui::Selectable(label, selected == i, ImGuiSelectableFlags_SpanAllColumns))
                selected = i;
            bool hovered = ImGui::IsItemHovered();
            ImGui::NextColumn();
            ImGui::Text(names[i]); ImGui::NextColumn();
            ImGui::Text(paths[i]); ImGui::NextColumn();
            ImGui::Text("%d", hovered); ImGui::NextColumn();
        }
        ImGui::Columns(1);
        ImGui::Separator();



        ImGui::EndTabItem();
    }

}
void loadTab4()
{
    if (ImGui::BeginTabItem(u8"SCR-说明"))
    {

        if (ImGui::Button(u8"游戏初始化4"))
        {
            checkBoxFalgs_1 = !checkBoxFalgs_1;
        }

        if (ImGui::Checkbox(u8"开启飞天", &checkBoxFalgs_1))
        {
            //  点击事件执行
        }

        if (checkBoxFalgs_1)
        {
            ImGui::Text(u8"欢迎使用IMGUI 窗口3");
            ImGui::SameLine();
            ImGui::Text(u8"欢迎使用IMGUI 窗口4");
        }
        ImGui::EndTabItem();
    }

}


void LoadMyWin()
{
    // 界面开始绘制
    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();

    ImGui::NewFrame();

    // 窗口大小
    ImGui::SetNextWindowPos(ImVec2(50, 50), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(350, 450), ImGuiCond_FirstUseEver);

    ImGui::Begin(u8"游戏辅助窗口", &mainBeginSate);

    ImGui::Checkbox(u8"鼠标操作-影响游戏界面     ", &checkBoxFalgs_1); ImGui::SameLine();
    CString tmpste = (checkBoxFalgs_1) ? "ON" : "OFF";
    ImGui::Text(u8"[ %S ]", tmpste); 

    if (ImGui::BeginTabBar("tab1", tab_bar_flags))
    {
        loadTab1();
        loadTab2();
        loadTab3();
        loadTab4();
    }
    ImGui::EndTabBar();
    ImGui::End();
    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

}