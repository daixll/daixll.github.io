**Docker**

* **轻量化**：在操作系统层面上实现虚拟化
* **分布式**：可以在同一台机器上运行多个容器，每个容器之间相互隔离
* **无状态**：容器每次创建都是全新的，容器内的进程也是全新的，容器内的内容不可持久化

**Virtual Machines** 

* **更强的隔离性**：在硬件层面上实现虚拟化
* **文件特性**：硬盘文件、快照都是文件，可以持久化

## 安装 Docker

使用官方安装脚本（[参考文档](https://docs.docker.com/engine/install/ubuntu/#install-using-the-convenience-script)）：

```sh
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh
```

## 镜像 IMAGE

是一个只读模板，用来创建容器，类似于：

* 面向对象中的类，容器是对象
* 虚拟机中的 `.iso`，容器是虚拟机

### Docker Hub 下载镜像

[Docker Hub](https://hub.docker.com/search?q=)

```sh
docker pull IMAGE_NAME[:TAG]
```

* `IMAGE_NAME` 镜像名称
* `TAG` 可选，镜像版本或标签，默认为 `latest`

代理加速（[参考文档](https://www.lfhacks.com/tech/pull-docker-images-behind-proxy/#practice)）:

* `sudo mkdir -p /etc/systemd/system/docker.service.d`

* `sudo vim /etc/systemd/system/docker.service.d/http-proxy.conf`

    ```bash
    [Service]
    Environment="HTTP_PROXY=http://127.0.0.1:7897"
    Environment="HTTPS_PROXY=http://127.0.0.1:7897"
    ```

* `sudo systemctl daemon-reload && sudo systemctl restart docker`

* `sudo systemctl show --property=Environment docker`

### Dockerfile 构建镜像

```sh
docker build -t IMAGE_NAME[:TAG] PATH_TO_DOCKERFILE
```

* `IMAGE_NAME` 镜像名称
* `TAG` 可选，镜像版本或标签
* `PATH_TO_DOCKERFILE` Dockerfile 所在路径

### 查看镜像

```sh
docker images
```

* `REPOSITORY` 镜像名称
* `TAG` 镜像版本或标签
* `IMAGE ID` 镜像 ID：**唯一标识**
* `CREATED` 创建时间
* `SIZE` 镜像大小

### 删除镜像

```sh
docker rmi IMAGE_NAME[:TAG]
```



## 容器 CONTAINER

### 查看容器

```sh
docker ps [-a]
```

### 创建 / 删除容器

**删除容器**

> 删除容器前需要先停止容器

```sh
docker rm CONTAINER_ID
```

**创建容器**

```sh
docker run \
    [OPTIONS] \
    IMAGE_NAME[:TAG] \
    [COMMAND] \
    [ARG...]
```

1. **OPTIONS** 命令选项
    * `-it` 进入容器终端，通常与 `/bin/bash` 一起使用
    * `-d` 后台运行容器，通常与 `sleep infinity` 一起使用
    * `--name` 容器名称
    * `--restart` 容器停止后自动重启
        * `no`（默认），不重启
        * `on-failure`，非 0 退出时重启
        * `always`，总是重启
    * `--net` 网络模式
        * `bridge`（默认），需要端口映射
        * `host`，直接使用宿主机端口
        * `none`，无网络
    * `--rm` 容器停止后自动删除
    * `-p` 端口映射，`HOST_PORT:CONTAINER_PORT`，`外:内`
    * `-v` 挂载目录，`HOST_DIR:CONTAINER_DIR`，`外:内`
    * `-e` 环境变量，`KEY=VALUE`
    * `-w` 工作目录，`WORK_DIR`，指定容器内的工作目录


### 进入 / 退出容器

**进入容器**

```sh
docker exec -it CONTAINER_ID /bin/bash
```

**退出容器**

```sh
exit
```

### 启动 / 停止容器

**启动容器**

```sh
docker start CONTAINER_ID
```

**停止容器**

```sh
docker stop CONTAINER_ID
```

## Dockerfile
