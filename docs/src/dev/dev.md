# develop

## 桌面平台

*windows 11 pro*

* [NV 驱动](https://www.nvidia.com/en-us/software/nvidia-app/) / [INTEL 驱动](https://www.intel.com/content/www/us/en/support/detect.html)

* [MS 激活](https://github.com/massgravel/Microsoft-Activation-Scripts) `irm https://get.activated.win | iex`

* [clash-verge](https://github.com/clash-verge-rev/clash-verge-rev/releases) / [Bandizip](https://www.bandisoft.com/bandizip/)

* [状态栏状态显示](https://github.com/zhongyang219/TrafficMonitor)


* [Office](https://otp.landian.vip/zh-cn/download.html) / [WPS](https://www.wps.cn/)

* [todesk](https://dl.todesk.com/windows/ToDesk_Lite.exe)

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

* 手动安装：[ms/WSL](https://github.com/microsoft/WSL/releases)

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
                "command": "./qwq/ac.sh",
                "problemMatcher": [
                    "$gcc"
                ]
            }
        ]
    }
    ```

5. 在项目目录下创建运行脚本 `qwq/ac.sh`

    ```shell
    # 以下配置不会对代码造成任何影响
    cppVersion="c++17"  # 指定 C++ 版本
    runTime="3s"        # 限定程序运行时间
    keepLine="100"      # 保留输出数据长度

    echo -n '⏳' > 'qwq/out' && \
    g++ -g -std="$cppVersion" ac.cpp -o qwq/ac && \
    cat 'qwq/in' | \
    timeout "$runTime" sh -c "'qwq/ac' > 'qwq/out.raw'"

    if [ $? -ne 0 ]; then
        echo -e "\033[0;31m TLE [ac1] "$runTime" \033[0m"
    fi  # 检查 timeout 命令的退出状态

    head -n "$keepLine" 'qwq/out.raw' > 'qwq/out'

    # 第二个程序

    echo -n '⏳' > 'qwq/out2' && \
    g++ -g -std="$cppVersion" ac2.cpp -o qwq/ac2 && \
    cat 'qwq/in' | \
    timeout "$runTime" sh -c "'qwq/ac2' > 'qwq/out2.raw'"

    if [ $? -ne 0 ]; then
        echo -e "\033[0;31m TLE [ac2] "$runTime" \033[0m"
    fi  # 检查 timeout 命令的退出状态

    head -n "$keepLine" 'qwq/out2.raw' > 'qwq/out2'
    ```



6. 所有文件结构如此：
    ```
    ├── .vscode/
    |   ├── tasks.json
    |
    ├── qwq/
    |   ├── ac.sh
    |   ├── in
    |   ├── ac
    |   ├── out
    |   ├── out.raw
    |   ├── ac2
    |   ├── out2
    |   ├── out2.raw
    |
    ├── ac.cpp
    ├── ac2.cpp
    ```

7. 配置快捷方式，f5一键执行命令

    `ctrl + k` + `ctrl + s` 打开键盘快捷方式，右上角选择 `json`，填入
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

    在 `ac.cpp` 文件中，即可 `f5` 一键执行

8. 打断点 -> `运行` -> `启动调试`
    `f11` 单步运行，如果单步进入库函数，可以通过 `shift + f11` 跳出，相当于 `finsh` 命令

<br>

---

## 移动平台

*macos*


<br>

---

## 文件服务

*windows server 2022*

<br>

---

## 应用服务

*ubuntu server 22.04*

<br>

### network

**DDNS + 公网 IPv4**

路由器上配置即可，最好的方式


**DDNS + 公网 IPv6**

DDNS 用于动态更新域名解析，使域名指向动态公网 IP

一般而言，每台设备都有公网 IPv6，所以直接在设备上配置 DDNS 即可

在设备上运行 DDNS 客户端，使域名指向该设备的公网IPv6

<details><summary>noip</summary>

<a href="https://my.noip.com/dynamic-dns">管理面板</a> |
<a href="https://www.noip.com/support/knowledgebase/install-linux-3-x-dynamic-update-client-duc/">官方文档</a> | 
<a href="https://www.noip.com/support/knowledgebase/automatic-ipv6-updates-linux-duc/">Linux IPv6 使用方法</a>

<ol>

<li> <a href="https://my.noip.com/dynamic-dns/duc">下载</a> </li>
<li> 解压 <code>tar -zxvf noip*.tar.gz</code> </li>
<li> 安装 <code>cd binaries && apt install ./noip-duc_3.0.0-beta.5_amd64.deb</code> </li>
<li> 运行 noip-duc --username 账号 --password 密码 -g 域名 --ip-method http://ip1.dynupdate6.no-ip.com/<code></code> </li>

</ol>

</details>

<br>

**frp + 内网 IPv4**

<details><summary>小鸡穿透</summary>

<a href="https://console.chickfrp.com/#/penManage/tunnel">管理面板</a> |
<a href="http://help.chickfrp.com/#/%E5%BF%AB%E9%80%9F%E5%85%A5%E9%97%A8">官方文档</a> |
固定ip，高带宽（1.25MB/s），高流量（5GB）

<ol>
<li> 下载 <code>wget https://chickfrp.com/download/frp045/linux/frp_0.45.0_linux_amd64.tar.gz</code> </li>
<li> 解压 <code>tar -zxvf frp*.tar.gz</code> </li>
<li> 复制 管理面板中的配置文件代码 </li>
<li> 替换 <code>frpc.ini</code> 文件 </li>
<li> 穿透 <code>./frpc</code> </li>
</ol>

</details>

<details><summary>cpolar</summary>

<a href="https://dashboard.cpolar.com/status">管理面板</a> |
<a href="https://www.cpolar.com/docs">官方文档</a> |
无固定ip，低带宽（128K/s），流量无限

<ol>
<li> 安装 <code>curl -sL https://git.io/cpolar | sudo bash</code> </li>
<li> 查看 <code>token</code> 在管理面板</li>
<li> 认证 <code>cpolar authtoken 你的token</code> </li>
<li> 穿透 <code>cpolar http 端口</code> </li>
</ol>

</details>

<details><summary>花生壳</summary>

<a href="https://console.hsk.oray.com/forward">管理面板</a> |
<a href="https://service.oray.com/question/11630.html">官方文档</a> |
两个固定ip

<ol>
<li> 安装 <code>dpkg -i phddns-5.0.0-amd64.deb</code> </li>
<li> 运行 <code>phddns start</code> </li>
<li> 查看 <code>phddns status</code> </li>
<li> 登录 <code>sn码</code> + <code>admin</code> 登录管理面板</li>
<li> 穿透 管理面板添加映射 </li>
</ol>

</details>


### storage

**挂载 Windows 网络磁盘**

1. 下载软件 `sudo apt install cifs-utils`
2. 在 `/mnt` 中创建挂载目录 `mkdir /mnt/z`
3. 挂载


### web


### av