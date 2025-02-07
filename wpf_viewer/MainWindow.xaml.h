#pragma once

#include "stdafx.h"
#include "MainWindow.g.h"

namespace WpfFileViewer
{
    /// <summary>
    /// MainWindow 的交互逻辑
    /// </summary>
    public ref class MainWindow : public System::Windows::Window
    {
    public:
        MainWindow();
    protected:
        void OpenFileButton_Click(System::Object^ sender, System::Windows::RoutedEventArgs^ e);
    };
}
