#include "stdafx.h"
#include "MainWindow.xaml.h"
#include <System/IO/File.h>
#include <System/Windows/Forms/OpenFileDialog.h>

using namespace WpfFileViewer;
using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

MainWindow::MainWindow()
{
    InitializeComponent();
}

void MainWindow::OpenFileButton_Click(System::Object^ sender, System::Windows::RoutedEventArgs^ e)
{
    // 创建文件打开对话框实例
    OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
    // 设置文件筛选器，支持多种常见文本文件类型
    openFileDialog->Filter = "文本文件 (*.txt;*.csv;*.log)|*.txt;*.csv;*.log|所有文件 (*.*)|*.*";
    openFileDialog->Title = "选择要查看的文件";

    // 显示文件打开对话框并检查用户是否点击了“确定”
    if (openFileDialog->ShowDialog() == DialogResult::OK)
    {
        String^ filePath = openFileDialog->FileName;
        try
        {
            // 读取文件的全部文本内容
            String^ fileContent = File::ReadAllText(filePath);
            // 将文件内容显示在预览文本框中
            PreviewTextBox->Text = fileContent;
        }
        catch (Exception^ ex)
        {
            // 若读取文件出错，显示错误消息框
            System::Windows::MessageBox::Show("读取文件时出错: " + ex->Message, "错误", System::Windows::MessageBoxButton::OK, System::Windows::MessageBoxImage::Error);
        }
    }
}
