## nginx的使用

* 安装nginx
```sh
apt install nginx
```

* nginx配置反向代理
  修改 `/etc/nginx/nginx.conf`
```
http {
  server {
    listen 本地端口;
    server_name 监听ip;
    
    location / {
      proxy_pass 目标ip:端口;
    }
  }
}
```

* 验证是否正确

```sh
nginx -t
```

* 重启并加载新的配置文件
```sh
nginx -s reload
```