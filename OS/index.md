---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

全文分为三个部分：

1. Linux 常用操作
2. 黑书的实验题
3. 操作系统的笔记 / 王道习题

书籍参考：

* 《操作系统概念/原书第10版》机械工业出版社
* 《操作系统 王道2025》

编程环境：

* `Ubuntu 22.04 LTS`
* `gcc 11.4.0`

源码参考：

* [osc10e](https://github.com/greggagne/osc10e)
* [此文源码]

---

[Linux 命令大全](https://www.linuxcool.com/)

# Linux-Ubuntu

## 基础命令

### 软件安装

* 更新软件源、软件、系统更新（非升级）
    `sudo apt update && sudo apt upgrade && sudo apt dist-upgrade && sudo apt autoremove`

* 查看已安装的软件
    `sudo apt list --installed | grep 软件名`

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

    > `chmod u+x`，给 **所属人** 添加执行权限
    > `chmod g+r`，给 **所属组** 添加读权限
    > `chmod o+w`，给 **其他人** 添加写权限

    > `chmod 777`，给 **所有人** 添加所有权限
    > `chmod 755`，给 **所属人** 添加所有权限，给 **所属组** 和 **其他人** 添加读和执行权限

    > `chmod -R`，递归修改

<br>


### 磁盘管理

**`mount` 磁盘挂载**



**`umount` 磁盘卸载**

<br>

---

## 常用命令



### 守护进程

### 计划作业

`crontab`

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

### build-essential

GNU编辑器合辑


### ssh

### ufw

1. 启动防火墙 `ufw enable`
2. 关闭防火墙 `ufw disenable`
3. 打开端口 `ufw allow 22`
4. 关闭端口 `ufw delete allow 22`
5. 防火墙状态 `ufw status`

### vim

1. 编辑文件 `vim a.txt`
2. 默认进入文件的 normal 模式
    * `i` 进入 编辑 模式  
    * `esc` 切换回 normal 模式
3. 大部分操作需要在 normal 模式下进行
    * 退出 `q`，强制退出 `q!`
    * 保存 `wq`，强制保存 `wq!`
    * 选择
        * 全选
        * 部分选择
    * 复制
    * 粘贴
    * 查找
    * 替换

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
* 压缩文件
    `tar -zcvf *.tar.gz *` 
    * `-c` 打包（tar）


### mount

* 挂载
    `mount -t ntfs /dev/sda1 /mnt`
    * `-t` 指定文件系统类型
    * /dev/sda1 磁盘分区
    * /mnt 挂载点



### rsync


### nc

网络工具

<br>

---


# 编程题

## 2.24

```cpp
// FileCopy.cpp
#include <fcntl.h>  // open
#include <unistd.h> // read write
#include <string.h> // memset
#include <iostream> // std::cerr

int main(int argc, char *argv[]) {
    if(argc != 3){
        std::cerr << "请输入源文件和目标文件的名称" << std::endl;
        return 1;
    }

    // 以只读的方式打开
    int fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1){
        std::cerr << "打开源文件失败" << std::endl;
        return 1;
    }

    // 以只写的方式打开，如果不存在则创建，如果存在则清空，权限为 666
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fd2 == -1){
        std::cerr << "打开目标文件失败" << std::endl;
        return 1;
    }

    char buffer[64];
    while(true){
        memset(buffer, '\0', sizeof buffer);
        int len = read(fd1, buffer, sizeof buffer);
        
        if(len == -1){
            std::cerr << "读取文件失败" << std::endl;
            return 1;
        }

        if(len == 0) break;

        if(write(fd2, buffer, len) == -1){
            std::cerr << "写入文件失败" << std::endl;
            return 1;
        }
    };
    
    return 0;
}
```

* 可以通过 `man open`，`man read` 等命令查看函数的使用方法

**运行**：

1. 编译源文件 `g++ FileCopy.cpp -o FileCopy`
2. 运行 `./FileCopy FileCopy.cpp FileCopy.cpp.bak`
3. 查看文件 `cat FileCopy.cpp.bak`
    * 与 `FileCopy.cpp` 一致
4. 使用系统调用跟踪工具 `strace ./FileCopy FileCopy.cpp FileCopy.cpp.bak`
    * 可以看到系统调用的详细信息

<br>

---

# 编程项目

## 2.17

**加载与卸载内核模块**

进入 `ch2` 目录

> 我将 `simple.c` 中的 `printk` 的输出分别改为 `内核加载`，`内核卸载`，以便区分

1. 编译 `make`
    * 生成 `simple.ko` 内核模块

2. 加载内核模块 `sudo insmod simple.ko`
    * 查看内核模块 `lsmod`
    * 可以看到 `simple` 模块

3. 查看内核日志缓冲区 `sudo dmesg`
    * 可以看到 `内核加载`
    * 删除内核日志缓冲区 `sudo dmesg -c`

4. 卸载内核模块 `sudo rmmod simple`
    * 查看内核模块 `lsmod`
    * 无 `simple` 模块

5. 查看内核日志缓冲区 `dmesg`
    * 可以看到 `内核卸载`

<br>

**输出内核模块从加载到卸载的时间**

```cpp
// simple.c
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/jiffies.h>
unsigned long cnt=0;

/* This function is called when the module is loaded. */
static int simple_init(void)
{
       cnt = jiffies;
       printk(KERN_INFO "加载内核:%lu %d\n", cnt, HZ);
       return 0;
}

/* This function is called when the module is removed. */
static void simple_exit(void) {
        cnt = (jiffies-cnt)/HZ;
        printk(KERN_INFO "卸载内核:%lu\n", cnt);
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
```

<br>

## 2.17 - 1




<br>

## 2.17 - 2