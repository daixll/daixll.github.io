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


# 安装docker


使用官方安装脚本
```sh
 curl -fsSL https://test.docker.com -o test-docker.sh
 sudo sh test-docker.sh
```


haha


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