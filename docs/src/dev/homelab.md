# 个人工作站的最佳实践

---

## 配置

<center>

| 设备 | 配置 | OS | IP | 网口 | 硬盘 | 备注 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| routing | - | TP-Link | 10.0.0.1 | 2.5G |  | |
| gateway | 2c2g | OpenWrt |10.0.0.2 | 2.5G（独占） | 30G | Hyper-V |
| idc | 8c8g | WinServer 2022 | 10.0.0.3 | 10G（独占） | 500G + 1T + 8T | Hyper-V |
| down | 4c8g | Win10 LTSC | 10.0.0.4 | 1G | 100G | Hyper-V | 
| web | 2c2g | ubuntu 22.04 | 10.0.0.5 | 1G | 60G | Hyper-V |
| rog | 24c64g | Win11 Pro for Workstations | 10.0.0.6 | 10G | 2T | |


</center>

<br>

---

## UPS

### 断电延迟关机

### 来电自动开机

<br>

---

## routing

### WAN：拨号

1. 光猫改桥接，默认模式拨号

* `IPv6` 不使用代理
    1. 复用 `IPv4` 拨号链路，地址获取协议为 `SLAAC`，开启前缀授权，`MTU: 1432`

* `IPv6` 下启用代理（还未验证）
    1. 复用 `IPv4` 拨号链路，地址获取协议为 `DHCPv6`，开启前缀授权，`MTU: 1432`
    2. 设置 `DHCPv6` 网关

<br>

### LAN：DHCPv4与静态IP

1. 地址 `10.0.0.100 - 10.0.0.254`
2. 网关地址 `10.0.0.2`
3. `DNS` 地址 `10.0.0.2`

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

`OpenVPN` 失效时的冗余方案，平时关闭

[[R系列企业VPN路由器] PPTP PC到站点VPN配置指南](https://smb.tp-link.com.cn/service/detail_article_3829.html)

* 连接手机热点时，客户端 `MTU` 设置为 `1400`

<br>

### 虚拟服务器（端口映射）

非必要不做端口映射

| 设备 | IP | 外部端口 | 内部端口 |
|:-:|:-:|:-:|:-:|
| 站点 | 10.0.0.5 | 1314 | 1314 |

<br>

### DDNS

* TP-Link（更新很快，但解析效果不行）

* 科迈（解析效果很好，但是更新很慢）

<br>

### 网络唤醒

| 设备 | IP | 备注 |
|:-:|:-:|:-:|
| tp | 10.0.0.1| ups 保护 |
| rog | 10.0.0.3 | ups 保护 |

<br>

### 云管理-TP商云

当 `VPN` 失效时的唯一管理手段

<br>

---

## rog


```
├── C:/                     SSD / 2T
│   
├── D:/                     SSD / 512G
│   ├── daixll.github.io/   网站
│   ├── ☁️ project/          自己的项目（github 同步）
│   │     ├── AC/
│   │     └── STL/
│   ├── ☁️ work/             工作的项目（可能需要私有云备）
│   └── tmp/
│
├── E:/                     SSD / 512G
└── E:/                     HDD / 8T
    ├── AV/                 音视频
    ├── ☁️ DATA/             个人资料（云备份）
    │     └── run/          包括运行依赖，例如私钥备份，各配置文件
    ├── ☁️ WQF/              微信QQ（手动备份）
    ├── download/           下载站 / 资源站
    └── tmp/
```

### SSD Cache

PrimoCache

### SAMBA

### Hyper-V

### WSL2 安装

### WSL2 网络

### WSL2 挂载



<br>

---

## gateway

### ImmortalWrt

`vim /etc/config/network`

<br>

### OpenClash




<br>

### OpenVPN


<br>

---


## web

### 挂载磁盘

[挂载 SMB](../cs/os/quick_linux.md#_6)

### 启动服务

[安装 docker]()

[nginx for docker]()

<br>

---





## ---



## *Windows 11 Pro*

* [NV 驱动](https://www.nvidia.com/en-us/software/nvidia-app/) / [INTEL 驱动](https://www.intel.com/content/www/us/en/support/detect.html)

* [MS 激活](https://github.com/massgravel/Microsoft-Activation-Scripts) `irm https://get.activated.win │ iex`

* [clash-verge](https://github.com/clash-verge-rev/clash-verge-rev/releases) / [Bandizip](https://www.bandisoft.com/bandizip/)

* [状态栏状态显示](https://github.com/zhongyang219/TrafficMonitor)


* [Office](https://otp.landian.vip/zh-cn/download.html) / [WPS](https://www.wps.cn/)

* [todesk](https://dl.todesk.com/windows/ToDesk_Lite.exe)

* [VM-win-linux](https://support.broadcom.com/group/ecx/productdownloads?subfamily=VMware%20Workstation%20Pro) / [VM-mac](https://support.broadcom.com/group/ecx/productdownloads?subfamily=VMware%20Fusion)

* [VS Code](https://code.visualstudio.com/insiders/) / [VS 2022](https://visualstudio.microsoft.com/zh-hans/vs/preview/) 登陆 `github` 账号，等待配置同步

* [JetBrains Toolbox](https://www.jetbrains.com/toolbox-app/) 登陆 `JB` 账号，等待配置同步

* [Linux WeChat](https://blog.csdn.net/Jason_Yansir/article/details/138117714)

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

## *Ubuntu Desktop 22.04.4 LTS*

* 


<br>

---

## *Windows Server 2022*

<br>

---

## *Ubuntu Server 22.04.4 LTS*

<br>

### network

**DDNS + 公网 IPv4**

路由器上配置即可，最好的方式


**DDNS + 公网 IPv6**

DDNS 用于动态更新域名解析，使域名指向动态公网 IP

一般而言，每台设备都有公网 IPv6，所以直接在设备上配置 DDNS 即可

在设备上运行 DDNS 客户端，使域名指向该设备的公网IPv6

<details><summary>noip</summary>

<a href="https://my.noip.com/dynamic-dns">管理面板</a> │
<a href="https://www.noip.com/support/knowledgebase/install-linux-3-x-dynamic-update-client-duc/">官方文档</a> │ 
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

<a href="https://console.chickfrp.com/#/penManage/tunnel">管理面板</a> │
<a href="http://help.chickfrp.com/#/%E5%BF%AB%E9%80%9F%E5%85%A5%E9%97%A8">官方文档</a> │
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

<a href="https://dashboard.cpolar.com/status">管理面板</a> │
<a href="https://www.cpolar.com/docs">官方文档</a> │
无固定ip，低带宽（128K/s），流量无限

<ol>
<li> 安装 <code>curl -L https://www.cpolar.com/static/downloads/install-release-cpolar.sh │ sudo bash</code> </li>
<li> 查看 <code>token</code> 在管理面板</li>
<li> 脚本 <code>vim /home/jiao/.cpolar/cpolar.yml</code> </li>

    ```yaml
    authtoken: xxxxxxxxxxxxxxxx
    tunnels:
        a:         
            addr: 80        
            proto: http     
        b:             
            addr: 3001
            proto: http
    ```

<li> 穿透 <code>sudo cpolar start-all -config /home/jiao/.cpolar/cpolar.yml</code> </li>
</ol>

</details>

<details><summary>花生壳</summary>

<a href="https://console.hsk.oray.com/forward">管理面板</a> │
<a href="https://service.oray.com/question/11630.html">官方文档</a> │
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

**SAMBA**

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

### web

`docker` + `nginx` 搭建静态网站服务

配置修改并不多，只需要修改一下 `default.conf` 文件即可

```conf
server {
    listen       80;            # IPv4 监听端口
    listen  [::]:80;            # IPv6 监听端口
    server_name  localhost;     # 域名

    location / {                # 网站根目录
        root   /usr/share/nginx/html;
        index  index.html index.htm;
    }

    location /doc {             # 文档根目录
        charset utf-8;          # 文档编码
        alias   /usr/share/nginx/doc;
        autoindex on;           # 自动索引
        autoindex_localtime on;
        autoindex_exact_size off;
    }
}
```

写一个启动脚本 `NginxRun.sh`

```sh
docker run \
-p 2023:80 \
--name nginx \
-v /usr/share/zoneinfo/Asia/Shanghai:/etc/localtime \
-v /home/jiao/Public/daixll.github.io:/usr/share/nginx/html \
-v /home/jiao/Public/doc:/usr/share/nginx/doc \
-v /home/jiao/Documents/NGINX/:/etc/nginx/conf.d \
--restart unless-stopped \
-d nginx:latest
```


### av

`docker` + `emby` 搭建影音服务

写一个启动脚本 `EmbyRun.sh`

```sh
docker run \
-p 8096:8096 \
--name emby \
-v /home/jiao/Videos:/mnt/share1 \
--restart unless-stopped \
-d emby/embyserver:latest
```

### remoteDesktop

直接使用微软的远程桌面协议（RDP）

1. 下载 `sudo apt install xrdp`
2. 打开端口 `sudo ufw allow 3389`


### code-server

1. 下载 [地址](https://github.com/coder/code-server/releases)
2. 安装 `sudo apt install ./code-server*.deb`
3. 启动 `export PASSWORD="密码" && ./code-server* --host 0.0.0.0 --port 端口 &`

> * 此方法非常不安全，建议使用 `docker` 部署
> * `--host` 后面的 IP地址，只有是 `0.0.0.0` 时，外网才可访问到。