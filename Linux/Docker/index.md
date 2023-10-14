---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 安装docker


使用官方安装脚本
```sh
 curl -fsSL https://test.docker.com -o test-docker.sh
 sudo sh test-docker.sh
```

# 镜像

下载镜像
```sh
docker pull nginx
```

查看镜像
```sh
docker images
```

# 容器

运行容器

```sh
docker run --name nginx_proxy  
```