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

* 联网 [下载](https://archive.org/download/clash_for_windows_pkg)
    `Clash for Windows`

* 激活 [下载](https://github.com/massgravel/Microsoft-Activation-Scripts/releases)
    `Microsoft-Activation-Scripts` `irm https://massgrave.dev/get | iex`

* Office [下载](https://otp.landian.vip/zh-cn/download.html) | [文档](https://www.coolhub.top/archives/11)
    `Office Tool Plus`

* Adobe [下载](https://creativecloud.adobe.com/apps/download/creative-cloud) | [激活](https://github.com/cw2k/Adobe-GenP)
    `Adobe`

* 解压缩 [下载](https://www.bandisoft.com/bandizip/)
    `Bandizip`

<br>


## WSL2 安装

[官方文档](https://learn.microsoft.com/zh-cn/windows/wsl/install)

* 在 `powershell` 中执行
    ```sh
    wsl --update
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

<br>

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

## BIOS

1. `AC power loss` 来电自启
2. `RTC` 定时启动

<br>


## 上网

### 访问到自己

##### 公网 IPv4

> 一般而言，运营商都不会给固定的公网IP

1. 光猫设置为桥接模式
2. 路由器设置为拨号上网
3. 路由器上有两种方法，可以在使你访问到内网设备
    1. DMZ（将内网某一个设备的IP映射到外网，方便从外网访问到该设备）
    2. 端口转发（通过 **外网IP+端口** 访问 **内网IP+端口**）
    
    *推荐使用端口转发的方式*

> 如果路由器上有 DDNS 功能，可以直接使用路由器的 DDNS 功能。

**更个性化** 买个自己喜欢的域名 [阿里]

1. ggg
2. ggg 

<br>

##### 公网 IPv6 + DDNS

> DDNS 用于动态更新域名解析，使域名指向动态公网IP，这里以 **noip** 为例
> 一般而言，每台设备都有 公网IPv6，所以直接在设备上配置 DDNS 即可 
> 在 Linux 上运行 DDNS 客户端，使域名指向该设备的公网IPv6：

[NO-IP 管理面板](https://my.noip.com/dynamic-dns) / [官方文档](https://www.noip.com/support/knowledgebase/install-linux-3-x-dynamic-update-client-duc/) / [Linux IPv6 使用方法](https://www.noip.com/support/knowledgebase/automatic-ipv6-updates-linux-duc/)

1. 下载 [地址](https://my.noip.com/dynamic-dns/duc)
2. 解压 `tar -zxvf noip*.tar.gz`
3. 安装 `cd binaries && apt install ./noip-duc_3.0.0-beta.5_amd64.deb`
4. `noip-duc --username 账号 --password 密码 -g 域名 --ip-method http://ip1.dynupdate6.no-ip.com/`


<br>

##### 内网 IPv4 + frp

> 一般，内网穿透 和 内网IPv4 一起使用 

**小鸡穿透** [管理面板](https://console.chickfrp.com/#/penManage/tunnel) [官方文档](http://help.chickfrp.com/#/%E5%BF%AB%E9%80%9F%E5%85%A5%E9%97%A8) 固定ip，高带宽（1.25MB/s），高流量（5GB）

1. 下载 `wget https://chickfrp.com/download/frp045/linux/frp_0.45.0_linux_amd64.tar.gz` 
2. 解压 `tar -zxvf frp*.tar.gz`
3. 复制 管理面板中的配置文件代码
4. 替换 `frpc.ini` 文件
5. 穿透 `./frpc`

**cpolar** [管理面板](https://dashboard.cpolar.com/status) [官方文档](https://www.cpolar.com/docs) 无固定ip，低带宽（128K/s），流量无限
1. 安装 `curl -sL https://git.io/cpolar | sudo bash`
2. 查看 `token` 在管理面板
3. 认证 `cpolar authtoken 你的token`
4. 穿透 `cpolar http 端口`

**花生壳** [管理面板](https://console.hsk.oray.com/forward) [官方文档](https://service.oray.com/question/11630.html) 两个固定ip
1. 安装 `dpkg -i phddns-5.0.0-amd64.deb`
2. 运行 `phddns start`
3. 查看 `phddns status`
4. 登录 `sn码` + `admin` 登录管理面板  
5. 穿透 管理面板添加映射  

<br>

### 访问到外面

##### Clash

> **[R.I.P.](https://github.com/Fndroid)** `2023-11-2` `Clash for Windows` 已删库。

1. 在 [archive.org](https://archive.org/download/clash_for_windows_pkg) 中下载



<br>



## code-server

1. 下载 [地址](https://github.com/coder/code-server/releases)
2. 安装 `apt install ./code-server*.deb`
3. 启动 `export PASSWORD="密码" && ./code-server* --host 0.0.0.0 --port 端口 &`

> * 此方法非常不安全，建议使用 `docker` 部署
> * `--host` 后面的 IP地址，只有是 `0.0.0.0` 时，外网才可访问到。

<br>



## gitlab


## 远程桌面

> 直接使用微软的远程桌面协议（RDP）

1. 下载 `apt install xrdp`
2. 打开端口 `ufw allow 3389`

<br>


## 文件

### 本地

> 使用 `samba` 服务

1. 下载 `apt install samba`
2. 配置分享文件夹 `chmod 777 /home/user/Public/ -R`
3. 添加samba用户 `smbpasswd -a 用户名`
4. 提示输入密码 x2
5. 配置samba `vim /etc/samba/smb.conf`
    ```sh
    [share name]            # 共享名
        path = /home/user/Public/# 共享路径
        writable = yes      # 可写
    ```
6. 重启samba `samba restart`
    * 可能还需要重启一下电脑
7. 开启端口 `ufw allow 445`

### 远程

> 使用 `docker` + `nginx` 搭建文件服务器

见 [网站](#网站)


<br>


## 网站

> 使用 `docker` + `nginx` 搭建静态网站服务

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
    }

    error_page  404               /404.html;
    error_page   500 502 503 504  /50x.html; # 错误页面
    location = /50x.html {
        root   /usr/share/nginx/html;
    }
}
```

写一个启动脚本 `NginxRun.sh`

```sh
docker run \
-p 2023:80 \
--name nginx \
-v /home/jiao/Public/daixll.github.io:/usr/share/nginx/html \
-v /home/jiao/Public/doc:/usr/share/nginx/doc \
-v /home/jiao/Documents/NGINX/:/etc/nginx/conf.d \
--restart unless-stopped \
-d nginx:latest
```

<br>



## 影音

> 使用 `docker` + `emby` 搭建影音服务

写一个启动脚本 `EmbyRun.sh`

```sh
docker run \
-p 8096:8096 \
--name emby \
-v /home/jiao/Videos:/mnt/share1 \
--restart unless-stopped \
-d emby/embyserver:latest
```
