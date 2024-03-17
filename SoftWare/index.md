---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

常用开发工具的 **安装** 及 **简单使用**

<br>

---

# **gcc**

## Linux

安装多个版本且可以随意切换

1. 下载
    ```shell
    sudo apt install gcc-12 g++-12
    sudo apt install gcc-11 g++-11
    ```
2. 设置优先级
    ```shell
    sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 120 --slave /usr/bin/g++ g++ /usr/bin/g++-12
    sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 110 --slave /usr/bin/g++ g++ /usr/bin/g++-11
    ```
    * 此时，`gcc-12` 优先级更高
3. 切换版本
    ```shell
    sudo update-alternatives --config gcc
    ```


## Windows

修改环境变量来切换版本

1. 下载
    [mingw-w64](https://github.com/niXman/mingw-builds-binaries/releases) `x86_64` `posix` `seh` `ucrt`

2. 解压

3. 添加环境变量
    * `C:\GCC\12\mingw-w64\bin`


## 简单使用


<br>

---

# **make**

## Linux

```shell
sudo apt install make   # 安装 make
make -v                 # 验证 make 安装成功
```

## Windows

1. 下载
    [make](https://gnuwin32.sourceforge.net/downlinks/make.php)

2. 安装
3. 添加环境变量
    * `C:\Program Files (x86)\GnuWin32\bin`

## 简单使用

<br>

---



# **OpenSSL**

## Linux





<br>

---

# **git**

[廖雪峰的git教程](https://www.liaoxuefeng.com/wiki/896043488029600)

## Linux
```shell
sudo apt install git # 安装 git
git --version        # 验证 git 安装成功
```

## Windows

[git 官网](https://git-scm.com/downloads)

<br>

---

## 首次使用

### 初始化仓库

在需要管理的目录（工作区）下，执行以下命令：

```shell
git init
```

> 将目标目录初始化成 git 可以管理的仓库，会生成一个 `.git` 目录
> 同时，会创建一个 `master` 分支

### 设置名字和邮箱

此操作的目的，是为了追踪每次操作，究竟是谁做的，我们一般将其存储在 `config` 中，也就是配置文件

配置文件有三个级别，权重从高到底：

1. 仓库 `local`，此配置文件只对 **当前仓库** 有效
2. 全局 `global`，此配置文件对 **当前用户** 有效
3. 系统 `system`，此配置文件对 **全局** 有效

**Windows**：

1. `local`： `.git/config`
2. `global`：`C:\Users\username\.gitconfig`
3. `system`：`C:\Program Files\Git\etc\gitconfig`


**Linux**：
1. `local`：`.git/config` 
2. `global`：`~/.gitconfig`
3. `system`：`/etc/gitconfig`

> 设置名字和邮箱；后续修改也直接使用此命令
```shell
git config --级别 user.name "名字"
git config --级别 user.email "邮箱"
```

### 将目标文件移动到暂存区

> 追踪目标文件

```shell
git add 目标文件
```

### 将暂存区提交到本地仓库

> 目标文件提交到本地仓库的当前分支
```shell
git commit -m "提交说明"
```

### 将本地仓库推送到远程仓库

将本地仓库推送到远程仓库，需要使用 `SSH key` 进行身份验证
私钥存储在本地，公钥存储在远程仓库
当你推送的时候，远程仓库会验证你的身份，如果验证通过，就可以推送

1. 生成 `SSH key`

    **Windows**：

    ```shell
    ssh-keygen -t rsa -C "email"
    ```

    > `-t rsa`：指定加密算法为 RSA
    > `-C "email"`：指定注释，一般填邮箱

    **Linux**：

    ```shell
    ssh-keygen -t rsa -C "email"
    ```

2. 将公钥添加到远程仓库（[github](https://github.com/) or [gitee](https://gitee.com/)）
    **Windows**：`C:\Users\username\.ssh\id_rsa.pub`
    **Linux**：`~/.ssh/id_rsa.pub`

    > 登录远程仓库，`setting` -> `SSH keys` -> `New SSH key`
    > `title`：填写公钥的名字
    > `key`：填写公钥的内容

3. 在远程仓库中新建仓库
    > 名称和本地仓库可以不一样，但建议一致
    > 开源和私有暂且不论，但建议开源
    > 复制仓库地址，使用 `ssh`

4. 添加远程仓库
    ```shell
    git remote add origin 远程仓库地址
    ```

    > `origin` 是远程仓库的别名，可以自定义

5. 推送到远程仓库
    ```shell
    git push origin master
    ```

> 注意，以上操作只是将本地仓库推送到远程仓库，但是远程仓库并不会自动创建分支

### 将远程仓库拉取到本地仓库

1. `git fetch origin`
    * 拉取远程仓库的所有分支到本地仓库，但是不会自动合并

    * `git merge origin/master`
        * 将远程仓库的 `master` 合并到本地仓库的当前分支

2. `git pull origin`
    * 拉取远程仓库的所有分支到本地仓库，并自动合并

3. `git clone 远程仓库地址`
    * 在本地创建一个远程仓库的克隆（副本）

<br>

---

## 查看状态


### 查看仓库的状态
```shell
git status
```
> 1. 显示位于哪个 **分支**
> 2. 显示 **暂存区** 的信息
> 3. 显示 **未跟踪** 的文件

### 查看仓库设置
```shell
git config --级别 -l
```
> `--级别` 可以省略，会显示最终三个配置文件计算后的配置信息

### 查看所有分支
```shell
git branch
```
> `*` 表示当前分支

### 查看远程仓库
```shell
git remote -v
```
> 查看远程仓库的详细信息

### 查看提交历史
```shell
git log
```
> 显示从最近到最远的提交日志
> 简化输出：`git log --pretty=oneline`

### 查看命令历史
```shell
git reflog
```
> 显示从最近到最远的命令日志
> 可以看到每一次命令的 `commit id`


<br>

---

## 撤销操作

### 从暂存区移除文件

```shell
git reset 目标文件
```

这个命令本质上是

```shell
git reset --mixed commit_id
```

> 从暂存区移除文件，但是不会删除文件
> `commit_id` 可以省略，默认是 `HEAD`
> 意思是将暂存区的文件恢复到 `commit_id` 的状态


### 撤销本次提交

1. 保留工作区的修改
    ```shell
    git reset --soft HEAD^
    ```
    > 撤销本次提交，但是保留工作区的修改
    > `HEAD^` 表示上一次提交，`HEAD^^` 表示上上次提交，以此类推

1. 删除工作区的修改
    ```shell
    git reset --hard HEAD^
    ```
    > 撤销本次提交，同时删除工作区的修改

### 删除远程仓库地址

```shell
git remote rm origin
```

> 删除远程仓库的别名为 `origin` 的仓库（地址）
> 仅仅是删除了别名，远程仓库并没有被删除


<br> 

---

## 国区操作

### 代理

**设置代理**

```shell
git config --global http.proxy http://127.0.0.1:7890
git config --global https.proxy https://127.0.0.1:7890
```

**取消代理**

```shell
git config --global --unset http.proxy
git config --global --unset https.proxy
```



### 同时推送到多个远程仓库

1. 再添加一个需要推送的远程仓库
    ```shell
    git remote set-url --add origin 远程仓库地址
    ```

2. 推送到远程仓库
    ```shell
    git push origin
    ```

> 注意，此方案只适用于多个远程仓库的代码完全一致的情况
> 因为我们只是给 `origin` 添加了多个 `URL`
> 虽然效果上看起来是推送到了多个仓库，但是实际上只是推送到了一个仓库


# **docker**

**Docker**

* **轻量化**：在操作系统层面上实现虚拟化
* **分布式**：可以在同一台机器上运行多个容器，每个容器之间相互隔离
* **无状态**：容器每次创建都是全新的，容器内的进程也是全新的，容器内的内容不可持久化

**Virtual Machines** 

* **更强的隔离性**：在硬件层面上实现虚拟化
* **文件特性**：硬盘文件、快照都是文件，可以持久化

## 安装 Docker

使用官方安装脚本（[参考文档](https://docs.docker.com/engine/install/ubuntu/)）：

```sh
 curl -fsSL https://test.docker.com -o test-docker.sh
 sudo sh test-docker.sh
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

<br>

---

# **nginx**

## nginx的使用

* 安装nginx
```sh
apt install nginx
```

* nginx配置反向代理
  修改 `/etc/nginx/nginx.conf`

```sh
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

<br>

---

# **nmap**

[官方中文文档](https://nmap.org/man/zh/index.html)

`nmap [ <扫描类型> ...] [ <选项> ] { <扫描目标说明> }`

## nmap 端口状态

### open（开放的）

应用程序正在监听端口，或者响应一个请求来自已连接的客户端。接收TCP连接或者UDP报文。

### closed（关闭的）

没有应用程序监听端口。但是此端口可以被探测到，因为没有应用程序监听，所以会返回一个 RST 包或者 ICMP 端口不可达消息。

### filtered（屏蔽的）

防火墙或者 ACL 屏蔽了端口，所以无法确定端口是否开放。目标端口可能有以下几种情况：
* 未响应，屏蔽器丢弃了探测包，此举会让 nmap 误认为探测包丢失，导致扫描时间变长。
* 丢弃了探测包，但是返回了 ICMP 错误消息。

### unfiltered（未屏蔽的）

防火墙或者 ACL 没有屏蔽端口，但是 nmap 无法确定端口开放或者关闭。用其它类型的扫描，如窗口扫描，SYN 扫描，或者 FIN 扫描可以帮助确定端口是否开放。

### open|filtered（开放或者屏蔽的）

开放的端口不响应探测包，屏蔽的端口也不响应探测包。所以无法确定端口是否开放。

### closed|filtered（关闭或者屏蔽的）

只可能出现在 IPID Idle 扫描中，因为此扫描类型需要发送两个探测包，如果两个探测包都没有响应，那么就无法确定端口是否开放。

---

## nmap 扫描技术


### 1 默认扫描

`nmap dxll.love`

默认扫描是 nmap 的最基本的扫描方式，它会扫描 1000 个最常用的端口，扫描方式是 SYN 扫描。

```sh
nmap -T0 dxll.love
nmap -T1 dxll.love
nmap -T2 dxll.love
nmap -T3 dxll.love
nmap -T4 dxll.love
nmap -T5 dxll.love
```

`-T0` 是最慢的扫描方式，`-T5` 是最快的扫描方式，`-T3` 是默认的扫描方式，`-T4` 是常用的扫描方式。

`nmap -6 dxll.love`

开启 IPv6 扫描。

`nmap -v dxll.love`

开启详细模式，显示扫描过程。

`nmap -A dxll.love`

全面扫描，包括 1-10000 端口扫描，服务版本探测，操作系统探测，脚本扫描等。

### 2 扫描多个 IP

```sh
nmap spacex.com dxll.love   # 扫描多个域名
nmap 192.168.31.100,101,102 # 扫描同一网段的多个 IP，可以用逗号分隔
nmap 192.168.31.*           # 扫描同一网段的多个 IP，可以用通配符
nmap 192.168.31.1/24        # 扫描同一网段的多个 IP，可以用 CIDR 表示法
```

### 3 扫描指定端口

```sh
nmap -p 80 dxll.love        # 扫描单个端口
nmap -p 80,443 dxll.love    # 扫描多个端口
nmap -p 1-100 dxll.love     # 扫描端口范围
nmap -p-                    # 扫描所有端口 等价于 nmap -p 1-65535
```

### 4 TCP扫描

#### TCP SYN 扫描

`nmap -sS dxll.love`

此方式不完成 TCP 三次握手，而是发送一个 SYN 包，如果目标端口开放，那么会返回一个 SYN/ACK 包，如果端口关闭，那么会返回一个 RST 包。

#### TCP Connect 扫描

`nmap -sT dxll.love`

此方式完成 TCP 三次握手，如果目标端口开放，那么会返回一个 SYN/ACK 包，如果端口关闭，那么会返回一个 RST 包。
目标主机可能会记录下连接，所以此方式不太隐蔽。

#### TCP 隐秘扫描

如果收到 RST 响应，则端口关闭，否则判定端口开放或被屏蔽。

`nmap -sN dxll.love`

不设置任何标志位。

`nmap -sF dxll.love`

只设置TCP FIN标志位。

`nmap -sX dxll.love`

flags的FIN、URG、PUSH都为1的包。

#### TCP ping 扫描

`nmap -sP dxll.love`

通过发送ICMP Echo请求（也称为Ping请求）到目标主机，命令将检测主机是否响应了请求并返回IP地址。如果主机响应，则表示主机是在线的。在这个扫描中，Nmap只检查是否有响应，而不扫描主机的任何端口。

### 5 UDP 扫描

`namp -sU dxll.love`

UDP 扫描需要发送 UDP 包，如果目标端口开放，那么会返回一个 ICMP 端口不可达消息，如果端口关闭，那么会返回一个 ICMP 端口不可达消息或者没有响应。


### 6 路由跟踪

`nmap --traceroute dxll.love`

查出从本地计算机到目标之间所经过的网络节点，并可以看到通过各个节点的时间。

### 7 操作系统探测

`nmap -O dxll.love`

nmap 会发送一系列的 TCP 和 UDP 包，然后分析返回的包，从而判断目标主机的操作系统。