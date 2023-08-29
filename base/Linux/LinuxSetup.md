---
html:
    toc: true    # 打开侧边目录
---

## 制作启动盘

1. [ubuntu iso](https://cn.ubuntu.com/download/server/step1) 镜像下载
2. [rufus](https://rufus.ie/zh/) 制作启动盘

## 基础软件

* 更新软件源、软件、系统更新（非升级）
    `apt update && apt upgrade && apt dist-upgrade`

### ssh
`apt install ssh`

### ufw
`apt install ufw`

1. 启动防火墙 `ufw enable`
2. 关闭防火墙 `ufw disenable`
3. 打开端口 `ufw allow 22`
4. 关闭端口 `ufw delete allow 22`
5. 防火墙状态 `ufw status`

### vim
`apt install vim`

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
`apt install curl`
* get 请求
    `curl https://www.baidu.com` 
* get 请求，返回 http 标头
    `curl -i https://www.baidu.com`

### tar
`apt install tar`
* 解压文件
    `tar -zxvf *.tar.gz`
    * -z 解压缩（gz）
    * -x 解包（tar）
    * -v 显示详细的解压过程信息
    * -f 指定名称
* 压缩文件
    `tar -zcvf *.tar.gz *` 


### 远程桌面

1. 下载微软的远程桌面协议（RDP）
    `apt install xrdp`

### samba

1. 



