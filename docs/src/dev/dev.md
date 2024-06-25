# develop

## windows develop

* [NV 驱动](https://www.nvidia.com/en-us/software/nvidia-app/) / [INTEL 驱动](https://www.intel.com/content/www/us/en/support/detect.html)

* [MS 激活](https://github.com/massgravel/Microsoft-Activation-Scripts) `irm https://get.activated.win | iex`

* [clash-verge](https://github.com/clash-verge-rev/clash-verge-rev/releases) / [Bandizip](https://www.bandisoft.com/bandizip/)

* [状态栏状态显示](https://github.com/zhongyang219/TrafficMonitor)


* [Office](https://otp.landian.vip/zh-cn/download.html) / [WPS](https://www.wps.cn/)

* [todesk](https://dl.todesk.com/windows/ToDesk_Lite.exe)

<br>

* [VS Code](https://code.visualstudio.com/insiders/) 登陆 `github` 账号，等待配置同步

* [VS 2022](https://visualstudio.microsoft.com/zh-hans/vs/preview/) 登陆 `github` 账号，等待配置同步

* [JetBrains Toolbox](https://www.jetbrains.com/toolbox-app/) 登陆 `JB` 账号，等待配置同步


<br>

### WSL2

**安装**

* 自动安装：[官方文档](https://learnmicrosoft.com/zh-cn/windows/wsl/install)
    ```sh
    wsl --update                    # powershell
    wsl --install -d Ubuntu-22.04   # 下载安装 Ubuntu 22.04
    ```

* 手动安装：[ms/WSL](https://github.commicrosoft/WSL)

<br>

**镜像网络** [官方文档](https://learn.microsoft.com/zh-cn/windows/wsl/networking#mirrored-mode-networking)

1. 创建 `C:\Users\<UserName>\.wslconfig` 文件
    ```sh
    [wsl2]
    networkingMode=mirrored
    dnsTunneling=true
    autoProxy=true
    ```

<br>

**启动脚本**

1. win + r 输入  `shell:startup`
2. 新建 `wsl.vbs` 文件
    ```sh
    Set ws = WScript.CreateObject("WScript.Shell")        
    ws.run "wsl -d Ubuntu-22.04 -u user /home/user/startupsh"
    ```

<br>

**挂载 Windows 网络磁盘** [非官文档](https://www.public-health.uiowa.edu/it/support/kb48568/)

1. 下载软件 `sudo apt install cifs-utils`
2. 在 `/mnt` 中创建挂载目录 `mkdir /mnt/z`
3. 挂载 `mount -t drvfs Z: /mnt/z`
4. 持久化 `vim /etc/fstab`
    ```sh
    Z: /mnt/z drvfs defaults 0 0
    ```

<br>

### ACM

1. vscode 下载拓展 `WSL`

2. vscode 连接到 WSL，下载拓展 `C++`
    * 我们仅需 `C++` 的代码提示（IntelliSense）功能
    * 如果你不需要代码提示也可以不下

3. 进入 WSL 环境，下载 `g++` `gdb`

4. 在项目目录下创建运行任务 `.vscode/tasks.json`
    ```json
    {
        "version": "2.0.0",
        "tasks": [
            {
                "label": "AC",
                "type": "shell",
                "command": "./ac.sh",
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

6. 在项目目录下创建运行脚本 `ac.sh`

    ```shell
    cppVersion="c++17"
    runTime="3s"
    keepLine="30000"

    echo -n '⏳' > 'exes/out' && \
    g++ -g -std="$cppVersion" ac.cpp -o exes/ac && \
    cat 'exes/in' | \
    timeout "$runTime" sh -c "'exes/ac' > 'exes/out.raw'"

    if [ $? -ne 0 ]; then
        echo -e "\033[0;31m TLE "$runTime" \033[0m"
    fi  # 检查 timeout 命令的退出状态

    head -n "$keepLine" 'exes/out.raw' > 'exes/out'
    ```



7. 所有文件结构如此：
    ```
    ├── .vscode/
    |   ├── launch.json
    |   ├── tasks.json
    |
    ├── exes/
    |   ├── ac
    |   ├── in
    |   ├── out
    |   ├── out.raw
    |
    ├── ac.cpp
    ├── ac.sh
    ```

8. 配置快捷方式，f5一键执行命令

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

9. 打断点 -> `运行` -> `启动调试`
    * 需要先 `f5` 一次，再 `启动调试`

<br>

---

## macos develop



<br>

---

## windows server

用于文件存储

<br>

---

## linux server

用于服务驱动