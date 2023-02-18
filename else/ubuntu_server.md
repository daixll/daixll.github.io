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


### 来电自启


---

## 软件

### 内网穿透
* 花生壳 [管理面板](https://console.hsk.oray.com/forward)
    > 花生壳可以配置两个固定ip, 一条跑ssh, 一条跑code-server
    1. 安装 `dpkg -i phddns_3.0_x86_64.deb`
    2. 运行 `phddns start`
    3. 查看 `phddns status`
    4. 登录 `sn码` + `admin` 登录管理面板  
    5. 穿透 管理面板添加映射  
    > ssh安装
    1. 更新 `apt update`
    2. 下载 `apt install openssh-server`
    3. 启用防火墙 `ufw enable`
    4. 打开端口 `allow 22`
    5. 查看端口 `ufw status` 

* cpolar [管理面板](https://dashboard.cpolar.com/status)
    > cpolar不能固定ip, 但流量无限
    1. 安装 `curl -L https://www.cpolar.com/static/downloads/install-release-cpolar.sh | sudo bash`
    2. 查看 `token`在管理面板
    3. 认证 `cpolar authtoken 你的token`
    4. 穿透 `cpolar http 9070`



### 编程环境
* code-server   
    > vscode 服务器版
    1. 安装 `curl -fsSL https://code-server.dev/install.sh | sh`
    2. 运行 `./code-server`

* build-essential
    > GNU编辑器合辑
    1. 安装 `apt install build-essential`    

### 开机自启


