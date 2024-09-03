参考：[Linux 命令大全](https://www.linuxcool.com/)

## 软件

### apt

参考：[apt 终极指南](https://itsfoss.com/apt-command-guide/)

* 更新软件源、软件，自动删除无关依赖

```bash
sudo apt update && sudo apt full-upgrade && sudo apt autoremove
```

* 使用代理

```bash
-o Acquire::http::proxy="http://127.0.0.1:7897/"
```

* 删除软件

```bash
sudo apt purge 软件名
```

* 查找软件

```bash
sudo apt-cache search 软件名
```

* 查看已安装的软件

```bash
sudo apt list --installed | grep 软件名
```

* 添加软件源


* 查看软件源


* 删除软件源

<br>

### snap

一托

<br>

---


## 文件

### 文件查找

find，grep


<br>

### 文件管理

* **`ls` 查看**

    * `ls -a` 列出全部文件（含隐藏）

    * `ls -l`
        `文件类型[所属人权限][所属组权限][其他人权限] 硬连接数量 所属人 所属组 文件大小 修改 日期和时间 文件名`
        文件类型：
        * `-` 普通文件
        * `d` 目录
        * `l` 软链接
        * `b` 块设备
        * `c` 字符设备
        * `s` 套接字
        * `p` 管道

* **`cd` 切换目录**

* **`pwd` 输出当前目录**

* **`mkdir ` 创建目录**
    * `mkdir -m 711 dir` 创建目录，权限为 `711`
    * `mkdir -p dir/dir/dir` 创建多层目录

* **`cp` 复制文件**
    * `cp -r dir/ dir.bak/` 递归复制
    * `cp -p file file.bak` 同时复制文件属性

* **`mv` 移动文件**
    * 如果移动目录，建议使用 `cp`，确认后再删除
    * `mv dirOld/ dirNew/`，从旧的目录移动到新的目录

* **`rm `删除文件**
    * `rm -r dir/` 递归删除
    * `rm -f dir/` 忽略不存在的文件


<br>

### 文件权限

每个文件有三种粒度

| 所属人 | 所属组 | 其他人 |
|:-:|:-:|:-:|
| `u` | `g` | `o` |

各自有三种权限

| 读 | 写 | 行 |
|:-:|:-:|:-:|
| `r` `4` | `w` `2` | `x` `1` |

修改

* **`chown` 修改所属人 `u`** 
* **`chgrp` 修改所属组 `g`**
* **`chmod` 修改权限**

    * `chmod +x`，给 **全部人 `a`** 添加执行权限，等价于 `chmod a+x`

    * `chmod +r`，给 **全部人 `a`** 添加读权限，等价于 `chmod a+r`

    * `chmod +w`，给 **所属人 `u`** 添加写权限，若想给全部人，`chmod a+w`

    <br>

    * `chmod u+x`，给 **所属人** 添加执行权限

    * `chmod g+r`，给 **所属组** 添加读权限

    * `chmod o+w`，给 **其他人** 添加写权限

    <br>

    * `chmod 777`，给 **全部人** 添加全部权限

    * `chmod 755`，给 **所属人** 添加全部权限，给 **所属组** 和 **其他人** 添加读和执行权限

    * `chmod -R`，递归修改


<br>

### 文件解压缩

tar，zip

* **`tar -zxvf *.tar.gz`**
    * `-z` 解压缩（gz）（有时可以省略）
    * `-x` 解包（tar）
    * `-v` 显示详细的解压过程信息
    * `-f` 指定名称
    * `-C` 指定路径

* **`tar -zcvf *.tar.gz *`**
    * `-c` 打包（tar）

<br>

### 文件备份

dump，rsync

<br>

---

## 磁盘

### 磁盘管理


<br>

### 挂载网络磁盘

参考：[系统启动时自动挂载 SMB 共享](https://docs.redhat.com/zh_hans/documentation/red_hat_enterprise_linux/8/html/managing_file_systems/proc_mounting-an-smb-share-automatically-when-the-system-boots_assembly_mounting-an-smb-share-on-red-hat-enterprise-linux)


1. 下载工具 `sudo apt install cifs-utils`

2. 添加共享条目 `sudo vim /etc/fstab`

    ```conf
    //10.0.0.2/administrator /mnt/idc cifs credentials=/root/smb.cred 0 0
    ```

    * `//idc/administrator` 网络路径
    * `/mnt/idc` 本地挂载路径
    * `credentials=/root/smb.cred` 指定了一个包含登录凭据（用户名和密码）的文件
    * `0 0` 不要进行 dump 备份，启动时不需要检查

3. 创建登陆凭据 `sudo vim /root/smb.cred`

    ```cred
    username=admin
    password=admin
    ```

4. 修改凭据权限

    ```bash
    chmod 600 /root/smb.cred
    ```

5. 重启验证

<br>

### 挂载普通磁盘

**`mount` 磁盘挂载**

* 挂载
    `mount -t ntfs /dev/sda1 /mnt`
    * `-t` 指定文件系统类型
    * `/dev/sda1` 磁盘分区
    * `/mnt` 挂载点

**`umount` 磁盘卸载**


<br>

---

## 系统

* **`btop`** 状态
* **`screenfetch`** 配置

### Process



<br>

### MEM



<br>

### IO



<br>

### 其他

* 查看时间 `date`，修改时区

```bash
sudo cp /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
```

<br>

---

## 网络

### net

```bash
sudo vi /etc/netplan/00-installer-config.yaml
```

* 静态 IP

```yaml
network:
  ethernets:
      eth0:
        dhcp4: false
        addresses:
          - 10.0.0.2/24
        routes:
          - to: default
            via: 10.0.0.1
        nameservers:
          addresses: [10.0.0.1,8.8.8.8]
  version: 2
```


<br>

### ssh


<br>

### scp


<br>

### ping


<br>

### wget


<br>

### curl


<br>

### nmap



<br>


### telnet


<br>

### iperf3


<br>

---

## 守护进程

[Systemd](https://www.ruanyifeng.com/blog/2016/03/systemd-tutorial-part-two.html)



<br>

---

## 计划作业

`crontab`

* 查看计划作业 `crontab -l`
* 编辑计划作业 `crontab -e`
* 删除计划作业 `crontab -r`

<br>

---

## UFW

* **`ufw enable`** 启动防火墙 
* **`ufw disenable`**  关闭防火墙 
* **`ufw allow 22`** 打开端口
* **`ufw delete allow 22`** 关闭端口
* **`ufw status`** 防火墙状态