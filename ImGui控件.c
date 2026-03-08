// by.逸晨
// ImGui 1.92.7 WIP 所有控件

1. 文本显示类控件

ImGui::Text("普通文本")

作用：在界面上显示一段普通文本，不支持格式化（若需格式化可使用 TextF 系列）
参数：字符串内容
返回值：无
示例：ImGui::Text("普通文本");

ImGui::TextColored(ImVec4(1,0,0,1), "红色文本")

作用：显示指定颜色的文本
参数：ImVec4 颜色（RGBA），后跟文本内容
示例：红色文本

ImGui::TextDisabled("灰色文本")

作用：显示灰色（禁用样式）的文本，常用于不可交互的提示
示例：ImGui::TextDisabled("灰色文本");

ImGui::BulletText("带项目符号的文本")

作用：显示带有圆点项目符号的文本，常用于列表项
示例：ImGui::BulletText("带项目符号的文本");

ImGui::LabelText("##label", "标签", "值")

作用：显示一个“标签-值”对，标签左对齐，值右对齐，常用于展示只读数据
参数：第一个是唯一ID（可用 ## 隐藏显示），第二个是标签文本，第三个是值文本
示例：ImGui::LabelText("##label", "标签", "值");

ImGui::Separator()

作用：绘制一条水平分隔线，用于视觉分组
示例：ImGui::Separator();


2. 按钮类控件

ImGui::Button("普通按钮")

作用：创建一个标准按钮，可响应点击
参数：按钮标签
返回值：bool——当按钮被点击时返回 true，通常包裹在 if 中执行操作
示例：if (ImGui::Button("普通按钮")) { /* 点击动作 */ }

ImGui::SameLine()

作用：将下一个控件放在同一行，而不是另起一行
示例：ImGui::SameLine();

ImGui::SmallButton("小按钮")

作用：创建一个紧凑型小按钮，高度略小于标准按钮
返回值：同 Button
示例：if (ImGui::SmallButton("小按钮")) { ... }

ImGui::ArrowButton("##arrow", ImGuiDir_Right)

作用：创建一个只显示箭头的按钮，方向由第二个参数指定（左、右、上、下）
参数：第一个是ID，第二个是方向枚举
返回值：点击返回 true
示例：if (ImGui::ArrowButton("##arrow", ImGuiDir_Right)) { ... }


3. 复选框

ImGui::Checkbox("复选框", &boolValue)

作用：显示一个复选框，与一个 bool 变量绑定，点击时自动切换变量值
参数：标签文本，指向 bool 变量的指针
返回值：bool——当值被修改时返回 true（通常用于触发响应）
示例：ImGui::Checkbox("复选框", &boolValue);


4. 单选框

ImGui::RadioButton("选项 A", &radioChoice, 0)

作用：显示单选框，多个单选框通过同一个 int 变量和不同的 v_button 值组成一组
参数：标签文本，指向 int 变量的指针，该选项对应的值
返回值：bool——当被选中且值发生变化时返回 true
示例：

完整代码:
ImGui::RadioButton("选项 A", &radioChoice, 0);
ImGui::SameLine();
ImGui::RadioButton("选项 B", &radioChoice, 1);



5. 滑动条

ImGui::SliderInt("整数滑块", &intValue, 0, 100)

作用：整数滑动条，通过拖动滑块调节整数值
参数：标签，变量指针，最小值，最大值
返回值：bool——值变化时返回 true

ImGui::SliderFloat("浮点滑块", &floatValue, 0.0f, 1.0f)

作用：浮点数滑动条，用法同上

ImGui::SliderFloat3("三维滑块", floatArray, -1.0f, 1.0f)

作用：同时控制三个浮点数的滑动条组，适合调节三维向量
参数：数组指针，最小/最大值

ImGui::SliderAngle("角度滑块", &floatValue)

作用：角度滑动条，值以弧度存储，但显示为角度（默认范围 -360° 到 360°）
参数：变量指针，可额外指定范围、格式等


6. 拖拽控件

ImGui::DragInt("拖拽整数", &intValue, 1.0f, 0, 100)

作用：通过鼠标拖拽调节整数值，适合连续调节
参数：标签，变量指针，拖拽速度（每像素变化量），最小值，最大值
返回值：值变化时返回 true

ImGui::DragFloat("拖拽浮点", &floatValue, 0.01f, 0.0f, 1.0f, "%.2f")

作用：浮点数拖拽，可指定显示格式


7. 文本输入

ImGui::InputText("单行输入", textBuffer, IM_ARRAYSIZE(textBuffer))

作用：单行文本输入框，需要提供字符缓冲区
参数：标签，缓冲区指针，缓冲区大小
返回值：当文本被修改且失去焦点或按下回车时返回 true

ImGui::InputTextMultiline("多行输入", textBuffer, IM_ARRAYSIZE(textBuffer), ImVec2(0, 80))

作用：多行文本输入框，可指定大小（宽度=0 表示自动撑满，高度=80 像素）
示例：ImVec2(0, 80) 表示宽度自适应，高度80像素


8. 数值输入

ImGui::InputInt("输入整数", &intValue)

作用：整数数值输入框，带加减按钮，也可手动键入
参数：标签，变量指针
返回值：值变化时返回 true

ImGui::InputFloat("输入浮点", &floatValue, 0.1f, 1.0f, "%.3f")

作用：浮点数输入框，可指定步长、快进步长和显示格式
参数：步长（点击按钮的增量），快进步长（Shift+点击），格式字符串


9. 组合框（下拉列表）

ImGui::BeginCombo("组合框", comboItems[comboIndex])

作用：开始一个可自定义的下拉组合框需要配合 Selectable 填充选项，最后 EndCombo()
参数：预览值显示当前选中项
返回值：bool——如果组合框打开则返回 true，内部绘制选项
示例：

完整代码:
if (ImGui::BeginCombo("组合框", comboItems[comboIndex])) {
    for (...) {
        if (ImGui::Selectable(items[n], isSelected)) {
            comboIndex = n;
        }
    }
    ImGui::EndCombo();
}


ImGui::Selectable("选项", isSelected)

作用：一个可选择的行，常用于组合框、列表等
参数：文本，选中状态
返回值：点击时返回 true

ImGui::SetItemDefaultFocus()

作用：设置当前项为默认焦点（当弹出打开时自动高亮该项）


10. 列表框

ImGui::ListBox("列表框", &listboxIndex, comboItems, IM_ARRAYSIZE(comboItems), 4)

作用：显示一个可滚动的列表，支持单选
参数：标签，当前选中索引指针，选项数组，选项数量，显示行数
返回值：当选中项变化时返回 true


11. 树节点与折叠标题

ImGui::TreeNode("树节点（可折叠）")

作用：创建一个可折叠的树节点，内部内容需在 if 块中，并以 TreePop() 结束
返回值：bool——节点展开时返回 true，则绘制内部内容
示例：

完整代码:
if (ImGui::TreeNode("节点")) {
    // 内容
    ImGui::TreePop();
}


ImGui::CollapsingHeader("可折叠标题")

作用：一个可折叠的标题，没有树节点符号，但点击标题可展开/折叠
返回值：bool——当前展开时返回 true，可绘制内部内容
示例：

完整代码:
if (ImGui::CollapsingHeader("标题")) {
    // 展开时的内容
}



12. 分组布局

ImGui::BeginGroup() / ImGui::EndGroup()

作用：将多个控件组合成一个逻辑组，便于整体布局（如整体居中、整体移动等）
示例：

完整代码:
ImGui::BeginGroup();
ImGui::Text("组内文本");
ImGui::Button("组内按钮");
ImGui::EndGroup();



13. 进度条

ImGui::ProgressBar(progress, ImVec2(0,0), "进度条显示文本")

作用：显示一个进度条
参数：进度值（0.0~1.0），尺寸（(0,0) 表示自动宽度），叠加显示的文本（可为空）
示例：ImGui::ProgressBar(progress, ImVec2(0,0), "进度条显示文本");


14. 图像（注释部分）

ImGui::Image(textureID, ImVec2(100,100))

作用：显示一张图片，需要提供纹理 ID（与图形API相关）
参数：纹理ID，图像尺寸
说明：需要提前将纹理绑定到 ImGui 的 ImTextureID 类型


15. 弹出窗口与上下文菜单

ImGui::OpenPopup("my_popup")

作用：打开一个指定名称的弹出窗口
示例：if (ImGui::Button("打开弹出菜单")) ImGui::OpenPopup("my_popup");

ImGui::BeginPopup("my_popup") / EndPopup()

作用：定义弹出窗口的内容只有通过 OpenPopup 激活后才会显示
示例：

完整代码:
if (ImGui::BeginPopup("my_popup")) {
    ImGui::Text("内容");
    if (ImGui::Button("关闭")) ImGui::CloseCurrentPopup();
    ImGui::EndPopup();
}


ImGui::BeginPopupContextItem("item_context_menu")

作用：为上一个控件创建右键上下文菜单当在控件区域右键点击时自动弹出
示例：

完整代码:
if (ImGui::BeginPopupContextItem("item_context_menu")) {
    ImGui::MenuItem("菜单项1");
    ImGui::EndPopup();
}


ImGui::MenuItem("菜单项", "快捷键")

作用：菜单项，常用于菜单栏或上下文菜单，可带快捷键文本
返回值：bool——点击时返回 true
示例：ImGui::MenuItem("新建", "Ctrl+N");


16. 菜单栏

ImGui::BeginMenuBar() / EndMenuBar()

作用：开始一个菜单栏（必须放在窗口内），通常配合 BeginMenu 使用
示例：

完整代码:
if (ImGui::BeginMenuBar()) {
    if (ImGui::BeginMenu("文件")) {
        ImGui::MenuItem("退出");
        ImGui::EndMenu();
    }
    ImGui::EndMenuBar();
}


ImGui::BeginMenu("文件") / EndMenu()

作用：创建一个下拉菜单，内部放置 MenuItem
返回值：bool——菜单展开时返回 true，内部可绘制菜单项


17. 标签页

ImGui::BeginTabBar("MyTabBar") / EndTabBar()

作用：开始一个标签页容器
示例：

完整代码:
if (ImGui::BeginTabBar("MyTabBar")) {
    if (ImGui::BeginTabItem("标签页1")) {
        ImGui::Text("内容1");
        ImGui::EndTabItem();
    }
    // 更多标签页
    ImGui::EndTabBar();
}


ImGui::BeginTabItem("标签页1") / EndTabItem()

作用：创建一个标签页，内部包裹该页的内容
返回值：bool——如果该标签页当前可见（被选中）则返回 true，则绘制内部内容


18. 表格

ImGui::BeginTable("MyTable", 3, ImGuiTableFlags_Borders) / EndTable()

作用：开始一个表格，指定列数和标志（如边框）
示例：

完整代码:
if (ImGui::BeginTable("MyTable", 3, ImGuiTableFlags_Borders)) {
    ImGui::TableNextRow();
    ImGui::TableSetColumnIndex(0); ImGui::Text("行1列1");
    // ...
    ImGui::EndTable();
}


ImGui::TableNextRow()

作用：开始新的一行

ImGui::TableSetColumnIndex(0)

作用：设置当前单元格所在的列索引（从0开始），之后绘制的控件将放入该单元格


19. 子窗口

ImGui::BeginChild("ScrollingRegion", ImVec2(200,100), true) / EndChild()

作用：创建一个可独立滚动的子窗口区域
参数：名称，尺寸，是否显示边框
示例：

完整代码:
ImGui::BeginChild("ScrollingRegion", ImVec2(200,100), true);
for (int i = 0; i < 20; i++) ImGui::Text("行 %d", i);
ImGui::EndChild();



20. 禁用组

ImGui::BeginDisabled(!boolValue) / EndDisabled()

作用：禁用/启用区域内所有控件的交互
参数：bool——true 表示禁用，false 表示启用
示例：

完整代码:
ImGui::BeginDisabled(!boolValue);  // 当 boolValue 为 false 时，内部控件禁用
ImGui::Button("被禁用的按钮");
ImGui::EndDisabled();



21. 交互状态查询

ImGui::IsItemHovered()

作用：查询上一个控件是否正在被鼠标悬停
返回值：bool
示例：

完整代码:
if (ImGui::Button("悬停测试")) { }
if (ImGui::IsItemHovered())
    ImGui::SetTooltip("鼠标悬停在此按钮上");


ImGui::SetTooltip("提示内容")

作用：设置工具提示（Tooltip），当鼠标悬停在某个控件上时显示
示例：ImGui::SetTooltip("鼠标悬停在此按钮上");