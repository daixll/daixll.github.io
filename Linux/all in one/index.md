---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

一台 **all in one** 的 [Ubuntu](https://cn.ubuntu.com/download/desktop) 小服务器

# BIOS

1. `AC power loss` 来电自启
2. `RTC` 定时启动

<br>

---

# 上网

## 访问到自己

#### 公网 IPv4

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

#### 公网 IPv6 + DDNS

> DDNS 用于动态更新域名解析，使域名指向动态公网IP，这里以 **noip** 为例
> 一般而言，每台设备都有 公网IPv6，所以直接在设备上配置 DDNS 即可 
> 在 Linux 上运行 DDNS 客户端，使域名指向该设备的公网IPv6：

[NO-IP 管理面板](https://my.noip.com/dynamic-dns) / [官方文档](https://www.noip.com/support/knowledgebase/install-linux-3-x-dynamic-update-client-duc/) / [Linux IPv6 使用方法](https://www.noip.com/support/knowledgebase/automatic-ipv6-updates-linux-duc/)

1. 下载 [地址](https://my.noip.com/dynamic-dns/duc)
2. 解压 `tar -zxvf noip*.tar.gz`
3. 安装 `cd binaries && apt install ./noip-duc_3.0.0-beta.5_amd64.deb`
4. `noip-duc --username 账号 --password 密码 -g 域名 --ip-method http://ip1.dynupdate6.no-ip.com/`


<br>

#### 内网 IPv4 + frp

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

## 访问到外面

#### Clash

> **[R.I.P.](https://github.com/Fndroid)** `2023-11-2` `Clash for Windows` 已删库。

1. 在 [archive.org](https://archive.org/download/clash_for_windows_pkg) 中下载



<br>

---

# code-server

1. 下载 [地址](https://github.com/coder/code-server/releases)
2. 安装 `apt install ./code-server*.deb`
3. 启动 `export PASSWORD="密码" && ./code-server* --host 0.0.0.0 --port 端口 &`

> * 此方法非常不安全，建议使用 `docker` 部署
> * `--host` 后面的 IP地址，只有是 `0.0.0.0` 时，外网才可访问到。

<br>

---

# gitlab


# 远程桌面

> 直接使用微软的远程桌面协议（RDP）

1. 下载 `apt install xrdp`
2. 打开端口 `ufw allow 3389`

<br>

---

# 文件

## 本地

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

## 远程

> 使用 `docker` + `nginx` 搭建文件服务器



<br>

---

# 网站

> 使用 `docker` + `nginx` 搭建静态网站服务



<br>

---


# 影音

> 使用 `docker` + `emby` 搭建影音服务

