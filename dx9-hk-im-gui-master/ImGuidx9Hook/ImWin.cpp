#include "pch.h"
#include "ImWin.h"


bool mainBeginSate = TRUE;
bool tab_bar_flags = TRUE;
bool checkBoxFalgs_1 = FALSE;

void loadTab1()
{
    IM_TAB�ӹ�����_��ʼ(u8"�ɵ��ջ�")

        IM_���_����
        IM_��ǩ(u8"������ս")

        IM_���_��ʼ(6, "table1")

        IM_��ǩ(u8"���") IM_���_����
        IM_��ǩ(u8"����") IM_���_����
        IM_��ǩ(u8"�Ա�") IM_���_����
        IM_��ǩ(u8"����") IM_���_����
        IM_��ǩ(u8"�༶") IM_���_����
        IM_��ǩ(u8"����") IM_���_����
        IM_���_����
        const char* names[3] = { u8"����", u8"����", u8"����" };
        const char* aYear[3] = { "19", "20", "45" };
        const char* aClass[3] = { u8"1��", u8"2��", u8"3��" };
        const char* Nums[3] = { u8"ȡ��1", u8"ȡ��2", u8"ȡ��3" };
        for (int i = 0; i < 3; i++)
        {
            ImGui::Text("%02d", i); IM_���_����
            IM_��ǩ(names[i]) IM_���_����
            IM_��ǩ(u8"��") IM_���_����
            IM_��ǩ(aYear[i]) IM_���_����
            IM_��ǩ(aClass[i]) IM_���_����
            if (IM_��ť(Nums[i]))  
                MessageBoxA(0, (LPCSTR)(aYear[i]), 0,  0);

        IM_���_����
            //IM_��ǩ(Nums[i]) IM_���_���� 

    }
    IM_���_����
    IM_TAB�ӹ�����_����
}

void loadTab2()
{
    if (ImGui::BeginTabItem(u8"SCR-����"))
    {


        if (ImGui::Button(u8"��Ϸ��ʼ��2"))
        {
            checkBoxFalgs_1 = !checkBoxFalgs_1;
        }

        if (ImGui::Checkbox(u8"��������", &checkBoxFalgs_1))
        {
            //  ����¼�ִ��
        }

        if (checkBoxFalgs_1)
        {
            ImGui::Text(u8"��ӭʹ��IMGUI ����3");
            ImGui::SameLine();
            ImGui::Text(u8"��ӭʹ��IMGUI ����4");
        }
        ImGui::EndTabItem();
    }

}
void loadTab3()
{
    if (ImGui::BeginTabItem(u8"SCR-����"))
    {
        if (ImGui::Button(u8"��Ϸ��ʼ��3"))
        {
            checkBoxFalgs_1 = !checkBoxFalgs_1;
        }

        if (ImGui::Checkbox(u8"��������", &checkBoxFalgs_1))
        {

        }
        ImGui::Columns(1);
        ImGui::Separator();

        ImGui::Text(u8"��Χ�����Ķ�������������:");

        ImGui::Columns(4, "mycolumns"); // 4-ways, with border
        ImGui::Separator();
        ImGui::Text("ID"); ImGui::NextColumn();//����
        ImGui::Text("Name"); ImGui::NextColumn();
        ImGui::Text("Path"); ImGui::NextColumn();
        ImGui::Text("Hovered"); ImGui::NextColumn();
        // ����
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
    if (ImGui::BeginTabItem(u8"SCR-˵��"))
    {

        if (ImGui::Button(u8"��Ϸ��ʼ��4"))
        {
            checkBoxFalgs_1 = !checkBoxFalgs_1;
        }

        if (ImGui::Checkbox(u8"��������", &checkBoxFalgs_1))
        {
            //  ����¼�ִ��
        }

        if (checkBoxFalgs_1)
        {
            ImGui::Text(u8"��ӭʹ��IMGUI ����3");
            ImGui::SameLine();
            ImGui::Text(u8"��ӭʹ��IMGUI ����4");
        }
        ImGui::EndTabItem();
    }

}


void LoadMyWin()
{
    // ���濪ʼ����
    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();

    ImGui::NewFrame();

    // ���ڴ�С
    ImGui::SetNextWindowPos(ImVec2(50, 50), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(350, 450), ImGuiCond_FirstUseEver);

    ImGui::Begin(u8"��Ϸ��������", &mainBeginSate);

    ImGui::Checkbox(u8"������-Ӱ����Ϸ����     ", &checkBoxFalgs_1); ImGui::SameLine();
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