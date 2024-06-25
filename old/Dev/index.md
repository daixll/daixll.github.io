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





<br>

## IDE and more




<br>

## vsc for Algorithm





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
