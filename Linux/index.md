---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

[Linux 命令大全](https://www.linuxcool.com/)

* 更新软件源、软件、系统更新（非升级）
    `apt update && apt upgrade && apt dist-upgrade`


## 权限管理

每个文件有三种身份：

* 所有者 `u`
* 用户组 `g`
* 其他人 `o`

各自有三种权限：

* 读 `r` `4`
* 写 `w` `2`
* 行 `x` `1`

修改：

* 修改所有者 `chown`
* 修改用户组 `chgrp`
* 修改权限 `chmod`

## 文件管理

## 磁盘管理

## 守护进程

## 计划作业

`crontab`

## 进程线程

`top` `strace` `pstack`

## 内存状态

`memstat` `free`

## IO状态

`iostat` `df` `du`

## 文件传输

`scp` `rsync` `rz` `sz`

## 文件定位

`find` `whereis`

## 软链接

`ln`

## `lsof`




## build-essential

GNU编辑器合辑


## ssh

## ufw

1. 启动防火墙 `ufw enable`
2. 关闭防火墙 `ufw disenable`
3. 打开端口 `ufw allow 22`
4. 关闭端口 `ufw delete allow 22`
5. 防火墙状态 `ufw status`

## vim

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

## curl

* get 请求
    `curl https://www.bing.com` 
* get 请求，返回 http 标头
    `curl -i https://www.bing.com`

## wget


## tar
* 解压文件
    `tar -zxvf *.tar.gz`
    * `-z` 解压缩（gz）
    * `-x` 解包（tar）
    * `-v` 显示详细的解压过程信息
    * `-f` 指定名称
* 压缩文件
    `tar -zcvf *.tar.gz *` 
    * `-c` 打包（tar）


## mount

* 挂载
    `mount -t ntfs /dev/sda1 /mnt`
    * `-t` 指定文件系统类型
    * /dev/sda1 磁盘分区
    * /mnt 挂载点



## rsync


## nc

网络工具

