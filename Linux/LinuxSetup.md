---
html:
    toc: true    # 打开侧边目录
---

## 制作启动盘

1. [ubuntu iso](https://cn.ubuntu.com/download/server/step1) 镜像下载
2. [rufus](https://rufus.ie/zh/) 制作启动盘


## 定时启动
> bios 电源管理
  1. AC power loss 来电自启
  2. RTC 定时启动

## 开机默认进入命令行 / 图形界面

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

## 开机运行  
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

## 基础软件

* 更新软件源、软件、系统更新（非升级）
    `apt update && apt upgrade && apt dist-upgrade`

### build-essential
GNU编辑器合辑

`apt install build-essential` 

### ssh
`apt install ssh`

### ufw
`apt install ufw`

1. 启动防火墙 `ufw enable`
2. 关闭防火墙 `ufw disenable`
3. 打开端口 `ufw allow 22`
4. 关闭端口 `ufw delete allow 22`
5. 防火墙状态 `ufw status`

### vim
`apt install vim`

1. 编辑文件 `vim a.txt`
2. 默认进入文件的 normal 模式
    * `i` 进入 编辑 模式  
    * `esc` 切换回 normal 模式
3. 大部分操作需要在 normal 模式下进行
    * 退出 `q`，强制退出 `q!`
    * 保存 `wq`，强制保存 `wq!`
    * 选择
        * 全选
        * 部分选择
    * 复制
    * 粘贴
    * 查找
    * 替换

### curl
`apt install curl`
* get 请求
    `curl https://www.baidu.com` 
* get 请求，返回 http 标头
    `curl -i https://www.baidu.com`

### tar
`apt install tar`
* 解压文件
    `tar -zxvf *.tar.gz`
    * -z 解压缩（gz）
    * -x 解包（tar）
    * -v 显示详细的解压过程信息
    * -f 指定名称
* 压缩文件
    `tar -zcvf *.tar.gz *` 


### 远程桌面

1. 下载微软的远程桌面协议（RDP）
    `apt install xrdp`

### samba

> 文件分享
1. 下载 `apt install samba`
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



