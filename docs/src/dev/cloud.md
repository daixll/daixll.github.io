# 个人工作站的最佳实践

---

## 配置

<center>

| 设备 | 配置 | OS | IP | 网口 | 硬盘 |
|:-:|:-:|:-:|:-:|:-:|:-:|
| routing | - | TP-Link | 10.0.0.1 | 2.5G |  |
| gateway | 2c2g | OpenWrt（V） |10.0.0.2 | 2.5G（独占） | |
| idc | 4c8g | WinServer 2022（V） | 10.0.0.3 | 10G（独占） | 500G + 1T + 8T |
| down | 4c8g | Win10 LTSC（V） | 10.0.0.4 | 1G | 100G |
| run | 4c8g | ubuntu 22.04（V） | 10.0.0.5 | 1G | 60G |
| rog | 24c64g | Win11 Pro for Workstations | 10.0.0.6 | 10G + WiFi | 2T |


</center>

<br>

---

## UPS

### 断电延迟关机

### 来电自动开机

<br>

---

## routing

### WAN

* `PPPoE`

    1. 光猫改桥接，默认模式拨号

    2. 关闭 `IPv6`

<br>

### LAN

* `DHCPv4` 

    1. `DNS` 与网关 `10.0.0.2`

    2. 地址范围
        
        * 保留 `.2 - .100`
        
        * 临时 `.101 - .200` `DHCP`

        * 隔离 `.201 - .254`

* `static IP`

    * 长期 `.1 - .20`

    * 短期 `.21 - .100`

<br>

### 定时重启

* 每天 `2:00`，重新上电 POE

* 每天 `2:20`，设备重启

* 每天 `2:40`，本机清理

* 每天 `3:00`，射频调优

<br>

### 安全管理

* `ARP` 防护

* 攻击防护

<br>

### VPN-PPTP

* `OpenVPN` 失效时的冗余方案，平时关闭

* 参考：[[R系列企业VPN路由器] PPTP PC到站点VPN配置指南](https://smb.tp-link.com.cn/service/detail_article_3829.html)

* 连接手机热点时，客户端 `MTU` 设置为 `1400`

<br>

### 端口映射

非必要不做端口映射，尽量使用 `VPN`

<center>

| 设备 | IP | 外部端口 | 内部端口 |
|:-:|:-:|:-:|:-:|
| 站点 | 10.0.0.5 | 1314 | 1314 |

</center>

<br>

### DDNS

* TP-Link（更新很快，但解析效果不行）

* 科迈（解析效果很好，但是更新很慢）

<br>

### 网络唤醒

<center>

| 设备 | IP | 备注 |
|:-:|:-:|:-:|
| rog | 10.0.0.3 | ups 保护 |

</center>

<br>

### 云管理-TP商云

* 当 `VPN` 失效时的唯一管理手段

<br>

---

## rog

### 驱动和软件

* [NV 驱动](https://www.nvidia.com/en-us/software/nvidia-app/) / [INTEL 驱动](https://www.intel.com/content/www/us/en/support/detect.html)

* [MS 激活](https://github.com/massgravel/Microsoft-Activation-Scripts) `irm https://get.activated.win | iex`

* [微软商店免费下载](https://store.rg-adguard.net/)

* [状态监控](https://github.com/zhongyang219/TrafficMonitor) / [Bandizip](https://www.bandisoft.com/bandizip/) / [Office](https://otp.landian.vip/zh-cn/download.html) / [WPS](https://www.wps.cn/) / [todesk](https://dl.todesk.com/windows/ToDesk_Lite.exe)

* [VM-win-linux](https://support.broadcom.com/group/ecx/productdownloads?subfamily=VMware%20Workstation%20Pro) / [VM-mac](https://support.broadcom.com/group/ecx/productdownloads?subfamily=VMware%20Fusion)

* [VS Code](https://code.visualstudio.com/insiders/) / [VS 2022](https://visualstudio.microsoft.com/zh-hans/vs/preview/) 登陆 `github` 账号，等待配置同步

* [JetBrains Toolbox](https://www.jetbrains.com/toolbox-app/) 登陆 `JB` 账号，等待配置同步

<br>

### Hyper-V

<br>

### WSL2

**安装**

* 自动安装 [官方文档](https://learnmicrosoft.com/zh-cn/windows/wsl/install)
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

**挂载网络磁盘** [非官文档](https://www.public-health.uiowa.edu/it/support/kb48568/)

1. 下载软件 `sudo apt install cifs-utils`

2. 创建挂载目录 `sudo mkdir /mnt/z`

3. 挂载 `sudo mount -t drvfs Z: /mnt/z`

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
    cat 'qwq/in' │ \
    timeout "$runTime" sh -c "'qwq/ac' > 'qwq/out.raw'"

    if [ $? -ne 0 ]; then
        echo -e "\033[0;31m TLE [ac1] "$runTime" \033[0m"
    fi  # 检查 timeout 命令的退出状态

    head -n "$keepLine" 'qwq/out.raw' > 'qwq/out'

    # 第二个程序

    echo -n '⏳' > 'qwq/out2' && \
    g++ -g -std="$cppVersion" ac2.cpp -o qwq/ac2 && \
    cat 'qwq/in' │ \
    timeout "$runTime" sh -c "'qwq/ac2' > 'qwq/out2.raw'"

    if [ $? -ne 0 ]; then
        echo -e "\033[0;31m TLE [ac2] "$runTime" \033[0m"
    fi  # 检查 timeout 命令的退出状态

    head -n "$keepLine" 'qwq/out2.raw' > 'qwq/out2'
    ```



6. 所有文件结构如此：
    ```
    ├── .vscode/
    │   ├── tasks.json
    │
    ├── qwq/
    │   ├── ac.sh
    │   ├── in
    │   ├── ac
    │   ├── out
    │   ├── out.raw
    │   ├── ac2
    │   ├── out2
    │   ├── out2.raw
    │
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

## gateway

### ImmortalWrt

`vim /etc/config/network`

<br>

### HomeProxy


<br>

### OpenVPN

[openvpn 网络速率优化](http://www.xixicool.com/870.html)

<br>

---

## idc

```
├── C:/
│   
├── D:/
│   │
│   ├── daixll.github.io/
│   ├── AC/
│   ├── STL/
│   ├── ...
│   │
│   ├── work/
│   └── t/
│
└── E:/
    ├── AV/
    ├── ☁️ WQF/
    │
    └── ☁️ DATA/
        ├── conf
        ├── down        
        ├── 2024
        ├── 辉煌迎来虚伪的看客，黄昏见证真正的信徒
        ├── 纸上得来终得浅，绝知此事要躬行
        ├── 认清生活真相之后依然热爱生活 
        │   ├── 公司 A
        │   └── ...
        │
        └── 往事堪堪亦澜澜，前路漫漫亦灿灿
            ├── 2023
            ├── 2022
            └── ...
```


* `C / SSD / 1T`

    * 800G 做缓存

* `D / SSD / 512G`

    * 全盘共享, 只放项目，同步 github / gitee

    * `D:/work` 工作上的项目

* `E / HDD / 8T`

    * 全盘共享，只放文件，静态依赖，配置文件信息等

    * `E:/AV` 娱乐

    * `E:/WQF` wxqq 文件，手动备份

    * `E:/DATA` 多云盘介入，自动同步备份

### SSD Cache

PrimoCache

### SAMBA

<br>

---


## run

### 挂载磁盘

[挂载 SMB](../cs/os/quick_linux.md)

[安装 docker](./docker.md)

<br>

### 网页服务

[nginx for docker](./nginx.md#for-docker)

<br>

### 云盘


<br>

### 影音

`docker` + `emby` 搭建影音服务，启动脚本 `EmbyRun.sh`

```sh
docker run \
-p 8096:8096 \
--name emby \
-v /home/jiao/Videos:/mnt/share1 \
--restart unless-stopped \
-d emby/embyserver:latest
```

<br>

### code-server

1. 下载 [地址](https://github.com/coder/code-server/releases)

2. 安装 `sudo apt install ./code-server*.deb`

3. 启动 `export PASSWORD="密码" && ./code-server* --host 0.0.0.0 --port 端口 &`

    * IP 地址，只有是 `0.0.0.0` 时，对外才可访问

<br>

---



## Ubuntu 22.04

* [Linux WeChat](https://blog.csdn.net/Jason_Yansir/article/details/138117714)

### SMB 对外共享

1. 下载 `sudo apt install samba`

2. 配置分享文件夹 `chmod 777 /home/user/Public/ -R`

3. 添加samba用户 `sudo smbpasswd -a 用户名`

4. 提示输入密码 x2

5. 配置samba `sudo vim /etc/samba/smb.conf`
    
    ```sh
    [share name]            # 共享名
        path = /home/user/Public/# 共享路径
        writable = yes      # 可写
    ```

6. 重启samba `sudo samba restart`
    
    * 可能还需要重启一下电脑

7. 开启端口 `sudo ufw allow 445`


<br>

### 远程控制本机

直接使用微软的远程桌面协议（RDP）

1. 下载 `sudo apt install xrdp`

2. 打开端口 `sudo ufw allow 3389`