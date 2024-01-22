---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

* 为了更快的搭建完所需环境
* 为了能够实现 `存算分离` 和 `多端同步备份`

故而记录下来，以备后用

**注意**：

**只负责起飞，不负责降落，但会标明官方文档链接**

**希望读者在执行每一条命令之前，都知道自己在干什么**

<br>


---

# Windows `Windows 11 Pro`

## 装机必备

* 联网
    `Clash for Windows`

* 激活 [下载](https://github.com/massgravel/Microsoft-Activation-Scripts/releases)
    `Microsoft-Activation-Scripts`

* Office [下载](https://otp.landian.vip/zh-cn/download.html) | [文档](https://www.coolhub.top/archives/11)
    `Office Tool Plus`

* 解压缩 [下载](https://www.bandisoft.com/bandizip/)
    `Bandizip`

<br>


## WSL2 安装

[官方文档](https://learn.microsoft.com/zh-cn/windows/wsl/install)

* 在 `powershell` 中执行
    ```sh
    wsl --install -d Ubuntu-22.04   # 下载并安装 Ubuntu 22.04
    ```

<br>

## WSL2 镜像网络

[官方文档](https://learn.microsoft.com/zh-cn/windows/wsl/networking#mirrored-mode-networking)

* 创建 `C:\Users\<UserName>\.wslconfig` 文件
    ```sh
    [wsl2]
    networkingMode=mirrored
    dnsTunneling=true
    autoProxy=true
    ```

## WSL2 启动脚本

1. win + r 输入  `shell:startup`
2. 新建 `*.vbs` 文件
    ```sh
    Set ws = WScript.CreateObject("WScript.Shell")        
    ws.run "wsl -d Ubuntu-22.04 -u user /home/user/startup.sh"
    ```

<br>

## WSL2 挂载 Windows 磁盘

1. 在 `/mnt` 中创建挂载目录
    * `mkdir /mnt/z`
2. 挂载
    * `mount -t drvfs Z: /mnt/z`
3. 持久化
    * `vim /etc/fstab`
        ```
        Z: /mnt/z drvfs defaults 0 0
        ```


<br>

## IDE and more

[VS Code](https://code.visualstudio.com/insiders/) 登陆 `github` 账号，等待配置同步

[VS 2022](https://visualstudio.microsoft.com/zh-hans/downloads/) 登陆 `MS` 及 `github` 账号，等待配置同步

[JetBrains Toolbox](https://www.jetbrains.com/toolbox-app/) 登陆 `JB` 账号，等待配置同步


<br>

## vs for Algorithm

1. vscode 下载拓展 `WSL`

2. vscode 连接到 WSL，下载拓展 `C++`
    * 我们仅需 `C++` 的代码提示（IntelliSense）功能
    * 如果你不需要代码提示也可以不下

3. 进入 ubuntu 环境，下载 `gcc` `gdb`
    * `sudo apt install gcc`
    * `sudo apt install gdb`

4. 在项目目录下创建运行任务 `.vscode/tasks.json`
    ```json
    {
        "version": "2.0.0",
        "tasks": [
            {
                "label": "AC",
                "type": "shell",
                "command": "echo -n '⏳' > '${fileDirname}/exes/out'  && g++ -g -std=c++23 '${file}' -o '${fileDirname}/exes/${fileBasenameNoExtension}' && cat '${fileDirname}/exes/in' | '${fileDirname}/exes/${fileBasenameNoExtension}' > '${fileDirname}/exes/out' && sync",
                "problemMatcher": [
                    "$gcc"
                ]
            }
        ]
    }
    ```

5. 在项目目录下创建调试任务 `.vscode/launch.json`
    ```json
    {
        "version": "0.2.0",
        "configurations": [
            {
                // 配置的名称，可以自定义
                "name": "Debug",
                // 配置类型为cppdbg，表示C++调试
                "type": "cppdbg",
                // 请求类型为launch，表示启动调试
                "request": "launch",
                // 可执行文件路径为当前打开文件的路径和文件名（不带扩展名）
                "program": "${fileDirname}/exes/${fileBasenameNoExtension}",
                // 是否在程序入口处停止
                "stopAtEntry": true,
                // 当前工作目录为VS Code的工作区目录
                "cwd": "${workspaceFolder}",
                // 调试器类型为gdb
                "MIMode": "gdb",
                // 指定gdb的可执行文件路径
                "miDebuggerPath": "gdb",
            }
        ]
    }
    ```


* 文件结构如此：**[已整理](AC.zip)**
    ```
    ├── .vscode/
    |   ├── launch.json
    |   ├── tasks.json
    |
    ├── exes/
    |   ├── ac
    |   ├── in
    |   ├── out
    |
    ├── ac.cpp
    ```

    * 使用 `g++` 编译源文件 `ac.cpp`，生成可执行文件 `ac`，将 `in` 的数据输入到 `ac`，`ac` 再输出到 `out`

5. 配置快捷方式，f5一键执行命令

    修改 `C:\Users\USERNAME\AppData\Roaming\Code\User\keybindings.json` 文件

    ```json
    // 将键绑定放在此文件中以覆盖默认值auto[]
    [
        {
            "key": "f5",
            "command": "workbench.action.tasks.runTask",
            "args": "AC"
        }
    ]
    ```

    在 `ac.cpp` 文件中，即可 `f5` 一键执行。

6. 打断点 -> `运行` -> `启动调试`
    * 需要先 `f5` 一次，再 `启动调试`



<br>

---


# Ubuntu `Ubuntu 22.04 LTS`


<br>

---