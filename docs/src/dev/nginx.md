## 编译安装

1. 下载依赖

    ```sh
    sudo apt update
    sudo apt install build-essential libpcre3 libpcre3-dev libssl-dev zlib1g zlib1g-dev
    ```

2. 下载源码
    ```sh
    wget https://nginx.org/download/nginx-1.*.tar.gz
    tar -zxvf nginx*
    cd nginx*
    ```

3. 下载 `rtmp` 模块（可选）
    ```sh
    git clone https://github.com/arut/nginx-rtmp-module.git
    ```

4. 编译安装
    ```sh
    ./configure --add-module=./nginx-rtmp-module
    make
    sudo make install
    ```

5. 验证
    ```sh
    sudo /usr/local/nginx/sbin/nginx -V
    ```

## /etc/nginx/nginx.conf

* 主配置文件：用于定义全局配置和基本设置
* 包含指令：包含服务器级别的设置、全局变量、工作进程数、日志文件位置、用户权限、加载模块等
* 包含其他文件：通常会使用include指令将其他配置文件包含进来，如/etc/nginx/conf.d/*.conf，从而组织和管理配置文件

## /etc/nginx/conf.d/*.conf

* 虚拟主机配置文件：用于定义具体的虚拟主机（服务器）配置的文件，通常用于设置特定域名的服务器块
* 作用范围：这个文件主要包含HTTP服务器块（server block），定义了具体的域名、监听端口、根目录、日志路径、反向代理设置等
* 从属关系：这个文件通常被主配置文件 nginx.conf 通过 include 指令包含进来，使得Nginx能够加载这些虚拟主机配置

```
server {
    listen       80;            # IPv4 监听端口
    listen  [::]:80;            # IPv6 监听端口
    server_name  localhost;     # 域名

    # 网页服务
    location / {                # 网站根目录
        root   /usr/share/nginx/html;
        index  index.html index.htm;
    }

    # 下载服务
    location /doc {                 # 文档根目录
        charset utf-8;              # 文档编码
        alias   /usr/share/nginx/doc;
        autoindex on;               # 自动索引
        autoindex_exact_size off;   # 关闭计算文件确切大小（单位bytes），只显示大概大小（单位kb、mb、gb）
        autoindex_localtime on;     # 显示本机时间而非 GMT 时间

    }

    error_page   500 502 503 504  /50x.html;
    location = /50x.html {
        root   /usr/share/nginx/html;
    }
}
```

## Nginx_Docker

`docker pull nginx`

启动脚本：`runNginx.conf`

```
docker run \
-p 2024:80 \
--name nginx \
-v /.../web:/usr/share/nginx/html \
-v /.../doc:/usr/share/nginx/doc \
-v /.../NGINX/:/etc/nginx/conf.d \
--restart unless-stopped \
-d nginx
```

## RTMP_Docker

`docker pull tiangolo/nginx-rtmp`

