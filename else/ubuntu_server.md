---
html:
    toc: true           # 打开侧边目录
    toc_depth: 6        # 打开的目录层级
    toc_float: true     # 侧边悬停
    collapsed: true     # 只显示高级别标题(2)
    smooth_scroll: true # 页面滚动,标题变化
    number_sections: false  # 显示标题编号
    theme: united
--- 

## WSL自启动

1. win + r 输入  `shell:startup`
2. 新建 `.bat` 文件
    ```
    wsl noip-duc --username 邮箱 --password 密码 -g 域名 --ip-method http://ip1.dynupdate6.no-ip.com/ &
    ```

## 操作系统

### 启动盘
* u盘
  * [ubuntu server](https://cn.ubuntu.com/download/server/step1) iso镜像下载
  * [rufus](https://rufus.ie/zh/)   制作启动u盘

### 定时启动
> bios 电源管理
  1. AC power loss 来电自启
  2. RTC 定时启动

### 定时关机
> 直接在开机启动脚本设置

### 开机默认进入命令行 / 图形界面

> 默认命令行
```sh
systemctl set-default multi-user.target
```
> 命令行进入图形
```sh
startx
```
> 默认图形
```sh
systemctl set-default graphical.target
```

---

## 软件


### 基础软件

* 更新
    1. 更新 `apt update && apt upgrade`
    2. 安装升级管理核心 `apt install update-manager-core` 
    3. 检查更新 `do-release-upgrade -d`

* ssh
    > ssh安装
    1. 安装 `apt install openssh-server`
    
* ufw    
    > 防火墙
    1. 启用防火墙 `ufw enable`
    2. 打开端口 `ufw allow 22`
    3. 关闭端口 `ufw delete allow 22`
    4. 查看端口 `ufw status` 

* build-essential
    > GNU编辑器合辑
    1. 安装 `apt install build-essential` 

### DDNS 及 内网穿透

* NO-IP [管理面板](https://my.noip.com/dynamic-dns) [官方文档](https://www.noip.com/support/knowledgebase/install-linux-3-x-dynamic-update-client-duc/) [Linux ipv6](https://www.noip.com/support/knowledgebase/automatic-ipv6-updates-linux-duc/)
  > 只能搞一个域名
    1. 下载 [下载地址](https://my.noip.com/dynamic-dns/duc)
    2. 解压 `tar -xf noip*.tar.gz`
    3. 安装 `cd binaries && apt install ./noip-duc_3.0.0-beta.5_amd64.deb`
    4. `noip-duc --username 账号 --password 密码 -g 域名 --ip-method http://ip1.dynupdate6.no-ip.com/`


<details><summary>内网穿透(有备无患, 无奈之举)</summary>

* 小鸡穿透 [管理面板](https://console.chickfrp.com/#/penManage/tunnel) [官方文档](http://help.chickfrp.com/#/%E5%BF%AB%E9%80%9F%E5%85%A5%E9%97%A8)
    > 固定ip, 高带宽(1.25MB/s), 高流量(5GB)
    1. 下载 `wget https://chickfrp.com/download/frp045/linux/frp_0.45.0_linux_amd64.tar.gz` 
    2. 解压 `tar -zxvf frp*.tar.gz`
    3. 复制管理面板中的配置文件代码
    4. 替换 frpc.ini
    5. 穿透 `./frpc`

* cpolar [管理面板](https://dashboard.cpolar.com/status) [官方文档](https://www.cpolar.com/docs)
    > cpolar不能固定ip, 但流量无限
    1. 安装 `curl -sL https://git.io/cpolar | sudo bash`
    2. 查看 `token`在管理面板
    3. 认证 `cpolar authtoken 你的token`
    4. 穿透 `cpolar http 9070`

* 花生壳 [管理面板](https://console.hsk.oray.com/forward) [官方文档](https://service.oray.com/question/11630.html)
    > 花生壳可以配置两个固定ip
    1. 安装 `dpkg -i phddns-5.0.0-amd64.deb`
    2. 运行 `phddns start`
    3. 查看 `phddns status`
    4. 登录 `sn码` + `admin` 登录管理面板  
    5. 穿透 管理面板添加映射  


</details>

### 服务
* code-server
    > vscode 服务器版
    1. 下载 [下载地址](https://github.com/coder/code-server/releases)
    2. 安装 `apt install ./code-server*.deb`  
    3. 带参启动 `export PASSWORD="hh" && ./code-server --host 127.0.0.1 --port 8080`

* samba 
    > 文件分享
    1. 下载 `apt install samba samba-common`
    2. 配置分享文件夹 `chmod 777 /home/share/ -R`
    3. 添加samba用户 `smbpasswd -a 用户名`
    4. 提示输入密码 x2
    5. 配置samba `vim /etc/samba/smb.conf`
    ```sh
    [share]                 # 共享名
        comment = share     # 共享备注
        path = /home/share/ # 共享路径
        browseable = yes    # 所有人可见
        public = no         # 不允许匿名访问
        writable = yes      # 可写
        valid users = 用户名 # 设置访问用户
    ``` 
    6. 重启samba `samba restart`
    7. 开启端口 `ufw allow 445`

### 开机运行  
  1. 创建 `rc-local.service` 文件
```sh
cp /lib/systemd/system/rc-local.service /etc/systemd/system
```
  2. 修改 `/etc/systemd/system/rc-local.service` 文件, 添加如下内容
```sh
[Install]   
WantedBy=multi-user.target   
Alias=rc-local.service
```
  3. 创建 `/etc/rc.local` 文件, 输入执行的脚本
```sh
#!/bin/sh
noip-duc --username xx --password xx -g xx --ip-method http://ip1.dynupdate6.no-ip.com/ &
export PASSWORD="xx" && code-server --host [::] --port 9070 &
shutdown -h 23:55
```
  4. 给文件 `/etc/rc.local` 可执行权限
```sh
chmod +x /etc/rc.local
```
