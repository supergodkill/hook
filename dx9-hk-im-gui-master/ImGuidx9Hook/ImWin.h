#pragma once

extern bool checkBoxFalgs_1;


// 参数1：显示标题<类型：字符串>   
// 参数2：选中的标识<类型：bool> 
#define IM_选择框(显示标题,选中标识) ImGui::Checkbox(显示标题,选中标识)

#define IM_不换行 ImGui::SameLine();

#define IM_不换行EX(与最左边开始宽度,与前面的组件间隔) ImGui::SameLine(与最左边开始宽度,与前面的组件间隔);

#define IM_标签(标题内容) ImGui::Text(标题内容);

#define IM_按钮(标题内容) ImGui::Button(标题内容)

#define IM_颜色按钮(标题内容,颜色,是否可编辑) ImGui::ColorButton(标题内容,颜色,是否可编辑)

// 参数1：标题<类型：字符串>
// 参数2：选中编号<类型：int>
// 参数3：项目列表<类型：字符串>
#define IM_组合框(标题,选中编号指针,项目列表) ImGui::Combo(标题,选中编号指针,项目列表)

#define IM_进度条_FLOAT(标题,返回FLOAT指针,最小值,最大值,序列字符串,标志) ImGui::SliderFloat(标题,返回FLOAT指针,最小值,最大值,序列字符串,标志);
#define IM_进度条_INT(标题,返回INT指针,最小值,最大值,序列字符串,标志) ImGui::SliderInt(标题,返回INT指针,最小值,最大值,序列字符串,标志);

#define IM_树形开始(标题) if(ImGui::TreeNode(标题)){
#define IM_树形结束 ImGui::TreePop();}

#define IM_TAB父工具栏_开始(标题,打开标识) if(ImGui::BeginTabBar(标题, 打开标识)){
#define IM_TAB父工具栏_结束 }ImGui::EndTabBar();

#define IM_TAB子工具栏_开始(标题) if(ImGui::BeginTabItem(标题)){
#define IM_TAB子工具栏_结束 ImGui::EndTabItem();}



//ImGui::InputText("Completion", buf1, 64, ImGuiInputTextFlags_CallbackCompletion, Funcs::MyCallback);
//ImGui::InputText("password (clear)", password, IM_ARRAYSIZE(password));
//ImGui::InputTextWithHint("password (w/ hint)", "<password>", password, IM_ARRAYSIZE(password), ImGuiInputTextFlags_Password);

#define IM_编辑框(标题,内容指针,内存占用大小) ImGui::InputText(标题, 内容指针, 内存占用大小)
#define IM_编辑框_INT(标题,显示内容,内容指针,内存占用大小) ImGui::InputTextWithHint(标题,显示内容, 内容指针, 内存占用大小)

#define IM_表格_横线 ImGui::Separator();
#define IM_表格_竖线 ImGui::NextColumn();

#define IM_表格_开始(列数,表格标识) ImGui::Columns(列数, 表格标识);ImGui::Separator();
#define IM_表格_结束 ImGui::Columns(1);ImGui::Separator();

void LoadMyWin();



