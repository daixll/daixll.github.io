[Docker 入门教程 - 阮一峰](https://www.ruanyifeng.com/blog/2018/02/docker-tutorial.html)


**Virtual Machines** 

* **更强的隔离性**：在硬件层面上实现虚拟化
* **文件特性**：硬盘文件、快照都是文件，可以持久化

**Docker**

* **轻量化**：在操作系统层面上实现虚拟化
* **分布式**：可以在同一台机器上运行多个容器，每个容器之间相互隔离
* **无状态**：容器每次创建都是全新的，容器内的进程也是全新的，容器内的内容不可持久化

**Kubernetes**

* 容器编排平台

<br>

---

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
sudo docker pull IMAGE_NAME[:TAG]
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

### 查看镜像

```sh
sudo docker images
```

* `REPOSITORY` 镜像名称
* `TAG` 镜像版本或标签
* `IMAGE ID` 镜像 ID：**唯一标识**
* `CREATED` 创建时间
* `SIZE` 镜像大小

### 删除镜像

```sh
sudo docker rmi IMAGE_NAME[:TAG]
```

<br>

---

## 容器 CONTAINER

### 查看容器

```sh
sudo docker ps [-a]
```

### 创建 / 删除容器

**删除容器**

* 删除容器前需要先停止容器

```sh
sudo docker rm [CONTAINER_ID]
```

* 删除所有已停止容器

```sh
sudo docker container prune
```

**创建容器**

```sh
docker run [OPTIONS] IMAGE [COMMAND] [ARG...]
```

```sh
docker run \
    --name [c_name] \           # 容器名
    -it \                       # 台前运行，容器在没有指定长时间运行的进程时会立即退出
    --detach \                  # 后台运行
    --restart unless-stopped \  # 非手动停止自动重启
    -p 10086:80 \               # 容器内 80 -> 主机 10086
    -P \                        # 容器公开的所有端口随机映射到主机的可用端口
    -v /host/path:/c/path \     # 映射目录
    -v /host/file:/c/file:ro \  # 映射文件 [:ro] 只读
[image_name]                    # 镜像名
```


### 进入 / 退出容器

**进入容器**

```sh
sudo docker exec -it [CONTAINER_ID] /bin/bash
```

**退出容器**

```sh
exit
```

### 启动 / 停止容器

**重启容器**

```sh
sudo docker restart [CONTAINER_ID]
```

**启动容器**

```sh
sudo docker start [CONTAINER_ID]
```

**停止容器**

```sh
sudo docker stop [CONTAINER_ID]
```

<br>

---

## Dockerfile


### Dockerfile 构建镜像

```sh
sudo docker build -t IMAGE_NAME[:TAG] PATH_TO_DOCKERFILE
```

* `IMAGE_NAME` 镜像名称
* `TAG` 可选，镜像版本或标签
* `PATH_TO_DOCKERFILE` Dockerfile 所在路径

<br>

---

## 安装 K8s

[文档](https://kubernetes.io/docs/tasks/tools/install-kubectl-linux/)

```sh
curl -LO "https://dl.k8s.io/release/$(curl -L -s https://dl.k8s.io/release/stable.txt)/bin/linux/amd64/kubectl"
sudo install -o root -g root -m 0755 kubectl /usr/local/bin/kubectl
kubectl version --client --output=yaml
```
