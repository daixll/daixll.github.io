[Linux 命令大全](https://www.linuxcool.com/)

## 基础命令

修改时间

`cp /usr/share/zoneinfo/Asia/Shanghai  /etc/localtime`

修改网络

`vim /etc/netplan/00-in`


### 软件安装

* 更新软件源、软件、系统更新（非升级）
    `sudo apt update && sudo apt upgrade && sudo apt dist-upgrade && sudo apt autoremove`

* 使用代理
    `sudo apt -o Acquire::http::proxy="http://127.0.0.1:7897/" update`

* 查看已安装的软件
    `sudo apt list --installed | grep 软件名`

* 删除软件
    `sudo apt purge 软件名`

* 查找软件
    `sudo apt-cache search 软件名`


### 文件管理

* **`ls` 查看** 

    * `ls -a`
        列出全部文件（含隐藏）

    * `ls -l`
        ```shell
        文件类型[所属人权限][所属组权限][其他人权限] 硬连接数量 所属人 所属组 文件大小 修改 日期和时间 文件名
        ```
        文件类型：
        * `-` 普通文件
        * `d` 目录
        * `l` 软链接
        * `b` 块设备
        * `c` 字符设备
        * `s` 套接字
        * `p` 管道

* **`cd` 切换目录**

* **`mkdir` 创建文件夹**
    * `mkdir -m 711 dir`
        创建文件夹，权限为 711
    * `mkdir -p dir/dir/dir`
        创建多层文件夹

* **`cp` 复制文件**
    * `cp -p file file.bak`
        同时复制文件属性
    * `cp -r dir/ dir.bak/`
        递归复制

* **`mv` 移动文件**

* **`rm` 删除文件**
    * `rm -r dir/`
        递归删除
    * `rm -f dir/`
        忽略不存在的文件


<br>

### 权限管理

每个文件有三种粒度：

* 所属人 `u`
* 所属组 `g`
* 其他人 `o`

各自有三种权限：

* 读 `r` `4`
* 写 `w` `2`
* 行 `x` `1`


修改：

* 修改所有者 `chown`
* 修改用户组 `chgrp`
* 修改权限 `chmod`

    > `chmod +x`，给 **所有人** 添加执行权限，等价于 `chmod a+x`

    > `chmod +r`，给 **所有人** 添加读权限，等价于 `chmod a+r`

    > `chmod +w`，给 **所属人** 添加写权限，若想给所有人，`chmod a+w`

    <br>

    > `chmod u+x`，给 **所属人** 添加执行权限

    > `chmod g+r`，给 **所属组** 添加读权限

    > `chmod o+w`，给 **其他人** 添加写权限

    <br>

    > `chmod 777`，给 **所有人** 添加所有权限

    > `chmod 755`，给 **所属人** 添加所有权限，给 **所属组** 和 **其他人** 添加读和执行权限

    > `chmod -R`，递归修改

<br>


### 磁盘管理

**`mount` 磁盘挂载**

* 挂载
    `mount -t ntfs /dev/sda1 /mnt`
    * `-t` 指定文件系统类型
    * `/dev/sda1` 磁盘分区
    * `/mnt` 挂载点

**`umount` 磁盘卸载**


### 守护进程

[Systemd](https://www.ruanyifeng.com/blog/2016/03/systemd-tutorial-part-two.html)

### 计划作业

`crontab`

* 查看计划作业 `crontab -l`
* 编辑计划作业 `crontab -e`
* 删除计划作业 `crontab -r`

### 脚本编写

### 文件传输

`scp` `rsync` `rz` `sz`

### 文件定位

`find` `whereis`

### 软链接

`ln`

### `lsof`

### 跟踪系统调用

* **`strace`** 
    `strace ./a.out`
    > 显示程序执行过程的系统调用



<br>

---

## 状态查询

### 基本信息

* **screenfetch**
    `sudo apt install screenfetch`

* **btop**
    `sudo apt install btop`

* **top**

### 进程

* **`ps -ef`**
    > 显示所有用户的所有进程

* **`pstree`**
    > 显示进程树

* **`pgrep 进程名`**
    > 通过进程名查找 pid

* **`kill PID`**
    > 结束进程，`kill -9 PID` 强制结束

### 内存状态

`memstat` `free`

### IO状态

`iostat` `df` `du`



## 常用软件

### ufw

1. 启动防火墙 `ufw enable`
2. 关闭防火墙 `ufw disenable`
3. 打开端口 `ufw allow 22`
4. 关闭端口 `ufw delete allow 22`
5. 防火墙状态 `ufw status`


### curl

* get 请求
    `curl https://www.bing.com` 
* get 请求，返回 http 标头
    `curl -i https://www.bing.com`

### wget


### tar
* 解压文件
    `tar -zxvf *.tar.gz`
    * `-z` 解压缩（gz）（有时可以省略）
    * `-x` 解包（tar）
    * `-v` 显示详细的解压过程信息
    * `-f` 指定名称
    * `-C` 指定路径

* 压缩文件
    `tar -zcvf *.tar.gz *` 
    * `-c` 打包（tar）






### rsync


### nc

网络工具
