#pragma once

extern bool checkBoxFalgs_1;


// ����1����ʾ����<���ͣ��ַ���>   
// ����2��ѡ�еı�ʶ<���ͣ�bool> 
#define IM_ѡ���(��ʾ����,ѡ�б�ʶ) ImGui::Checkbox(��ʾ����,ѡ�б�ʶ)

#define IM_������ ImGui::SameLine();

#define IM_������EX(������߿�ʼ���,��ǰ���������) ImGui::SameLine(������߿�ʼ���,��ǰ���������);

#define IM_��ǩ(��������) ImGui::Text(��������);

#define IM_��ť(��������) ImGui::Button(��������)

#define IM_��ɫ��ť(��������,��ɫ,�Ƿ�ɱ༭) ImGui::ColorButton(��������,��ɫ,�Ƿ�ɱ༭)

// ����1������<���ͣ��ַ���>
// ����2��ѡ�б��<���ͣ�int>
// ����3����Ŀ�б�<���ͣ��ַ���>
#define IM_��Ͽ�(����,ѡ�б��ָ��,��Ŀ�б�) ImGui::Combo(����,ѡ�б��ָ��,��Ŀ�б�)

#define IM_������_FLOAT(����,����FLOATָ��,��Сֵ,���ֵ,�����ַ���,��־) ImGui::SliderFloat(����,����FLOATָ��,��Сֵ,���ֵ,�����ַ���,��־);
#define IM_������_INT(����,����INTָ��,��Сֵ,���ֵ,�����ַ���,��־) ImGui::SliderInt(����,����INTָ��,��Сֵ,���ֵ,�����ַ���,��־);

#define IM_���ο�ʼ(����) if(ImGui::TreeNode(����)){
#define IM_���ν��� ImGui::TreePop();}

#define IM_TAB��������_��ʼ(����,�򿪱�ʶ) if(ImGui::BeginTabBar(����, �򿪱�ʶ)){
#define IM_TAB��������_���� }ImGui::EndTabBar();

#define IM_TAB�ӹ�����_��ʼ(����) if(ImGui::BeginTabItem(����)){
#define IM_TAB�ӹ�����_���� ImGui::EndTabItem();}



//ImGui::InputText("Completion", buf1, 64, ImGuiInputTextFlags_CallbackCompletion, Funcs::MyCallback);
//ImGui::InputText("password (clear)", password, IM_ARRAYSIZE(password));
//ImGui::InputTextWithHint("password (w/ hint)", "<password>", password, IM_ARRAYSIZE(password), ImGuiInputTextFlags_Password);

#define IM_�༭��(����,����ָ��,�ڴ�ռ�ô�С) ImGui::InputText(����, ����ָ��, �ڴ�ռ�ô�С)
#define IM_�༭��_INT(����,��ʾ����,����ָ��,�ڴ�ռ�ô�С) ImGui::InputTextWithHint(����,��ʾ����, ����ָ��, �ڴ�ռ�ô�С)

#define IM_���_���� ImGui::Separator();
#define IM_���_���� ImGui::NextColumn();

#define IM_���_��ʼ(����,����ʶ) ImGui::Columns(����, ����ʶ);ImGui::Separator();
#define IM_���_���� ImGui::Columns(1);ImGui::Separator();

void LoadMyWin();



