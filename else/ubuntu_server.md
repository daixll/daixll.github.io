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

## 操作系统

### 启动盘
* u盘
  * [ubuntu server](https://cn.ubuntu.com/download/server/step1) iso镜像下载
  * [rufus](https://rufus.ie/zh/)   制作启动u盘

<img src="https://git.acwing.com/jiao/p/-/raw/main/set/ubuntu1.jpg" height="400"> 

### 定时重启


---

## 软件


### 基础软件

* ssh
    > ssh安装
    1. 更新 `apt update && apt upgrade`
    2. 下载 `apt install openssh-server`
    
* ufw    
    > 防火墙
    1. 启用防火墙 `ufw enable`
    2. 打开端口 `ufw allow 22`
    3. 关闭端口 `ufw delete allow 22`
    4. 查看端口 `ufw status` 

* build-essential
    > GNU编辑器合辑
    1. 安装 `apt install build-essential` 

### DDNS

* NO-IP [管理面板](https://my.noip.com/dynamic-dns) [官方文档](https://www.noip.com/support/knowledgebase/installing-the-linux-dynamic-update-client-on-ubuntu/) [Linux ipv6](https://www.noip.com/support/knowledgebase/automatic-ipv6-updates-linux-duc/)
  > 只能搞一个域名
    1. 下载 [下载地址](https://my.noip.com/dynamic-dns/duc)
    2. 解压 `tar -xzf noip*.tar.gz`
    3. 安装 `make install`
    4. 配置 `xxxxxxxx`
    5. 此时需要输入账户密码
    6. 运行 `xxxxxxx`
    7. ipv6 `noip --username 用户名 --password 密码 -g 域名 --ip-method http://ip1.dynupdate6.no-ip.com/`


### 内网穿透

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

### 服务
* code-server
    > vscode 服务器版
    1. 下载 [下载地址](https://github.com/coder/code-server/releases)
    2. 解压 `tar -zxvf code-server*.tar.gz`  
    3. 带参启动 `export PASSWORD="hh" && ./code-server --host 127.0.0.1 --port 8080`

* samba 
    > 文件分享


### 开机自启
