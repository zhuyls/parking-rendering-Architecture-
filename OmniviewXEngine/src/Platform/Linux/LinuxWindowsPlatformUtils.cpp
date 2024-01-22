#include "Omniviewpch.h"
#include "OmniviewXEngine/Utils/PlatformUtils.h"
#include "OmniviewXEngine/Core/Application.h"

#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_LINUX
#include <GLFW/glfw3native.h>

#include <string>
#include <optional>
#include <unistd.h> // 用于获取当前工作目录
#include <sys/types.h>
#include <dirent.h> // 用于文件对话框

namespace OmniviewXEngine
{
    float Time::GetTime()
    {
        return glfwGetTime();
    }

    std::optional<std::string> FileDialogs::OpenFile(const std::string& filter)
    {
        char currentDir[256];
        if (getcwd(currentDir, sizeof(currentDir)) == nullptr)
        {
            // 处理获取当前目录失败的情况
            return std::nullopt;
        }

        // 创建文件对话框
        std::string cmd = "zenity --file-selection --file-filter=\"" + filter + "\"";
        FILE* pipe = popen(cmd.c_str(), "r");
        if (pipe == nullptr)
        {
            // 处理打开文件对话框失败的情况
            return std::nullopt;
        }

        char buffer[128];
        std::string selectedFile;

        // 读取选定的文件路径
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
        {
            selectedFile += buffer;
        }

        int status = pclose(pipe);
        if (status == -1 || !WIFEXITED(status) || WEXITSTATUS(status) != 0)
        {
            // 处理关闭文件对话框失败的情况
            return std::nullopt;
        }

        // 移除末尾的换行符
        selectedFile.erase(selectedFile.find_last_not_of("\n") + 1);

        return selectedFile;
    }   


   std::optional<std::string> FileDialogs::SaveFile(const std::string& filter)
   {
        char currentDir[256];
        if (getcwd(currentDir, sizeof(currentDir)) == nullptr)
        {
            // 处理获取当前目录失败的情况
            return std::nullopt;
        }

        // 创建文件对话框
        std::string cmd = "zenity --file-selection --save --confirm-overwrite --file-filter=\"" + filter + "\"";
        FILE* pipe = popen(cmd.c_str(), "r");
        if (pipe == nullptr)
        {
            // 处理打开文件对话框失败的情况
            return std::nullopt;
        }

        char buffer[128];
        std::string selectedFile;

        // 读取选定的文件路径
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
        {
            selectedFile += buffer;
        }

        int status = pclose(pipe);
        if (status == -1 || !WIFEXITED(status) || WEXITSTATUS(status) != 0)
        {
            // 处理关闭文件对话框失败的情况
            return std::nullopt;
        }

        // 移除末尾的换行符
        selectedFile.erase(selectedFile.find_last_not_of("\n") + 1);

        return selectedFile;
    }

}