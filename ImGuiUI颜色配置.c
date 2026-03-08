//by.逸晨
//ImGui 1.92.7 WIP 所有控件RGBA颜色

作用描述 Dark 主题默认颜色 (RGBA)
ImGuiCol_Text 普通文本颜色 1.00, 1.00, 1.00, 1.00
ImGuiCol_TextDisabled 禁用文本颜色 0.50, 0.50, 0.50, 1.00
ImGuiCol_WindowBg 窗口背景色 0.06, 0.06, 0.06, 0.94
ImGuiCol_ChildBg 子窗口背景色 0.00, 0.00, 0.00, 0.00
ImGuiCol_PopupBg 弹出窗口背景色 0.08, 0.08, 0.08, 0.94
ImGuiCol_Border 边框颜色 0.50, 0.50, 0.50, 0.50
ImGuiCol_FrameBg 框架背景（输入框、滑动条等） 0.20, 0.21, 0.21, 0.54
ImGuiCol_FrameBgHovered 框架悬停背景 0.26, 0.59, 0.98, 0.40
ImGuiCol_FrameBgActive 框架激活背景 0.26, 0.59, 0.98, 0.67
ImGuiCol_TitleBg 非活动窗口标题栏 0.04, 0.04, 0.04, 1.00
ImGuiCol_TitleBgActive 活动窗口标题栏 0.16, 0.16, 0.16, 1.00
ImGuiCol_TitleBgCollapsed 折叠窗口标题栏 0.16, 0.16, 0.16, 0.20
ImGuiCol_MenuBarBg 菜单栏背景 0.14, 0.14, 0.14, 1.00
ImGuiCol_ScrollbarBg 滚动条背景 0.02, 0.02, 0.02, 0.53
ImGuiCol_ScrollbarGrab 滚动条滑块 0.31, 0.31, 0.31, 1.00
ImGuiCol_ScrollbarGrabHovered 滑块悬停 0.41, 0.41, 0.41, 1.00
ImGuiCol_ScrollbarGrabActive 滑块激活 0.51, 0.51, 0.51, 1.00
ImGuiCol_SliderGrab 滑块手柄 0.24, 0.52, 0.88, 1.00
ImGuiCol_SliderGrabActive 滑块手柄激活 0.26, 0.59, 0.98, 1.00
ImGuiCol_Button 按钮背景 0.26, 0.59, 0.98, 0.40
ImGuiCol_ButtonHovered 按钮悬停 0.26, 0.59, 0.98, 1.00
ImGuiCol_ButtonActive 按钮按下 0.06, 0.53, 0.98, 1.00
ImGuiCol_Header 树节点/表头背景 0.26, 0.59, 0.98, 0.31
ImGuiCol_HeaderHovered 树节点/表头悬停 0.26, 0.59, 0.98, 0.80
ImGuiCol_HeaderActive 树节点/表头激活 0.26, 0.59, 0.98, 1.00
ImGuiCol_Tab 选项卡背景 0.18, 0.18, 0.18, 0.86
ImGuiCol_TabHovered 选项卡悬停 0.26, 0.59, 0.98, 0.80
ImGuiCol_TabActive 活动选项卡 0.20, 0.41, 0.68, 1.00
ImGuiCol_TabUnfocused 非活动窗口的选项卡 0.07, 0.07, 0.07, 0.97
ImGuiCol_TabUnfocusedActive 非活动窗口的活动选项卡 0.14, 0.26, 0.42, 1.00
ImGuiCol_Separator 分隔线 0.50, 0.50, 0.50, 0.50
ImGuiCol_SeparatorHovered 分隔线悬停 0.26, 0.59, 0.98, 0.60
ImGuiCol_SeparatorActive 分隔线拖动 0.26, 0.59, 0.98, 1.00
ImGuiCol_ResizeGrip 调整大小手柄 0.26, 0.59, 0.98, 0.20
ImGuiCol_ResizeGripHovered 手柄悬停 0.26, 0.59, 0.98, 0.67
ImGuiCol_ResizeGripActive 手柄拖动 0.26, 0.59, 0.98, 0.95
ImGuiCol_PlotLines 折线图线条 0.61, 0.61, 0.61, 1.00
ImGuiCol_PlotLinesHovered 折线图悬停点 1.00, 0.43, 0.35, 1.00
ImGuiCol_PlotHistogram 直方图柱状 0.73, 0.60, 0.15, 1.00
ImGuiCol_PlotHistogramHovered 直方图悬停柱 1.00, 0.60, 0.00, 1.00
ImGuiCol_TextSelectedBg 文本选中背景 0.26, 0.59, 0.98, 0.35
ImGuiCol_DragDropTarget 拖拽目标高亮 1.00, 1.00, 0.00, 0.90
ImGuiCol_NavHighlight 键盘导航高亮轮廓 0.26, 0.59, 0.98, 1.00
ImGuiCol_NavWindowingHighlight 窗口切换高亮 1.00, 1.00, 1.00, 0.70
ImGuiCol_NavWindowingDimBg 窗口切换背景变暗层 0.80, 0.80, 0.80, 0.35
ImGuiCol_ModalWindowDimBg 模态窗口遮罩 0.04, 0.04, 0.04, 0.73

//使用方法:
void UI颜色() {
    ImGuiStyle& style = ImGui::GetStyle();

    // 文本与基础框架
    style.Colors[ImGuiCol_Text]                 = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_TextDisabled]         = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    style.Colors[ImGuiCol_WindowBg]             = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
    style.Colors[ImGuiCol_ChildBg]              = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_PopupBg]              = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    style.Colors[ImGuiCol_Border]                = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);
    style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.20f, 0.21f, 0.21f, 0.54f);
    style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
    style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);

    // 标题栏与菜单
    style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
    style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.16f, 0.16f, 0.16f, 0.20f);
    style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);

    // 滚动条
    style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);

    // 滑块与下拉手柄
    style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
    style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);

    // 按钮
    style.Colors[ImGuiCol_Button]                = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
    style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);

    // 表头、树节点与选项卡
    style.Colors[ImGuiCol_Header]                = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
    style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    style.Colors[ImGuiCol_Tab]                    = ImVec4(0.18f, 0.18f, 0.18f, 0.86f);
    style.Colors[ImGuiCol_TabHovered]             = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    style.Colors[ImGuiCol_TabActive]              = ImVec4(0.20f, 0.41f, 0.68f, 1.00f);
    style.Colors[ImGuiCol_TabUnfocused]           = ImVec4(0.07f, 0.07f, 0.07f, 0.97f);
    style.Colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);

    // 分隔线与其他
    style.Colors[ImGuiCol_Separator]              = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);
    style.Colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.26f, 0.59f, 0.98f, 0.60f);
    style.Colors[ImGuiCol_SeparatorActive]        = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    style.Colors[ImGuiCol_ResizeGrip]             = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
    style.Colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    style.Colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    style.Colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram]          = ImVec4(0.73f, 0.60f, 0.15f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    style.Colors[ImGuiCol_DragDropTarget]         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    style.Colors[ImGuiCol_NavHighlight]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    style.Colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    style.Colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
    style.Colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.04f, 0.04f, 0.04f, 0.73f);
}