---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

---
html:
  toc: true   # 打开侧边目录
export_on_save:
  html: true  # 自动保存
---

## WSL2自启动

1. win + r 输入  `shell:startup`
2. 新建 `.` 文件



# C++ for Algorithm

> win10 22H2 使用 wsl 下的 gcc 编译器，配置竞赛友好的环境

1. 微软商店下载 `ubuntu`，vscode 下载拓展 `WSL`

2. `控制面板\程序\启用或关闭 Windows 功能`：
    * `虚拟机平台`
    * `适用于 Linux 的 Windows 子系统`

3. vscode 连接到 WSL，下载拓展 `C++`
    * 我们仅需 `C++` 的代码提示（IntelliSense）功能
    * 如果你不需要代码提示也可以不下

4. 进入 ubuntu 环境，下载 `gcc`
    * `sudo apt install gcc`

5. 创建配置文件 `.vscode/tasks.json`
```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "AC",    // 任务名
      "type": "shell",  // 此任务在 shell 下执行；（command）执行命令
      "command": "g++ -std=c++17 '${file}' -o '${fileDirname}/exes/${fileBasenameNoExtension}' && cat '${fileDirname}/exes/in' | '${fileDirname}/exes/${fileBasenameNoExtension}' > '${fileDirname}/exes/out' && sync",
      "problemMatcher": [   // 捕捉错误
        "$gcc"
      ]
    }
  ]
}
```

文件结构如此：
```
├── .vscode/
|   ├── tasks.json   
|
└── exes/
|   ├── ac
|   ├── in
|   ├── out
|
├── ac.cpp
```

使用 `g++` 编译源文件 `ac.cpp`，生成可执行文件 `ac`，
将 `in` 的数据输入到 `ac`，`ac` 再输出到 `out`。

6. 配置快捷方式，f5一键执行命令

修改 `C:\Users\用户名\AppData\Roaming\Code\User\keybindings.json` 文件。
```json
// 将键绑定放在此文件中以覆盖默认值auto[]
[
{
  "key": "f5",
  "command": "workbench.action.tasks.runTask",
  "args": "AC"
  }
]
```


在 `ac.cpp` 文件中，即可 `f5` 一键执行。

---

# GO

> win10 22H2 在 Goland 中依赖 wsl 开发 GO

1. [官网](https://golang.google.cn/dl/)康康最新版本，下载
    * `wget https://golang.google.cn/dl/go1.21.0.linux-amd64.tar.gz`

2. 解压缩至 `/usr/local/`
    * `tar -zxvf go1.21.0.linux-amd64.tar.gz -C /usr/local/`

3. 配置环境变量 （WSL下的建议方案）
    * `vim ~/.bashrc`
      ```sh
      export GOROOT=/usr/local/go
      export PATH=$PATH:$GOROOT/bin
      ```

    * 刷新
      `source ~/.bashrc`

4. 测试 `go version`

5. GoLand 新建项目
    * Location：`\\ubuntu\home\工作目录`
    * GOROOT：`\usr\local\go`




* ssh / ufw / vim /
    curl / wget / tar /
    rsync / mount / samba / 
    远程桌面（xrdp）

## 制作启动盘

1. [ubuntu iso](https://cn.ubuntu.com/download/server/step1) 镜像下载
2. [rufus](https://rufus.ie/zh/) 制作启动盘


## 定时启动
> bios 电源管理
  1. AC power loss 来电自启
  2. RTC 定时启动

## 开机默认进入命令行 / 图形界面

> 默认命令行
```sh
systemctl set-default multi-user.target
```
> 命令行进入图形
```sh
startx
```
> 默认图形
```sh
systemctl set-default graphical.target
```

## 开机运行  
  1. 创建 `rc-local.service` 文件
```sh
cp /lib/systemd/system/rc-local.service /etc/systemd/system
```
  2. 修改 `/etc/systemd/system/rc-local.service` 文件, 添加如下内容
```sh
[Install]   
WantedBy=multi-user.target   
Alias=rc-local.service
```
  3. 创建 `/etc/rc.local` 文件, 输入执行的脚本
```sh
#!/bin/sh
noip-duc --username xx --password xx -g xx --ip-method http://ip1.dynupdate6.no-ip.com/ &
export PASSWORD="xx" && code-server --host [::] --port 9070 &
shutdown -h 23:55
```
  4. 给文件 `/etc/rc.local` 可执行权限
```sh
chmod +x /etc/rc.local
```

## 基础软件

* 更新软件源、软件、系统更新（非升级）
    `apt update && apt upgrade && apt dist-upgrade`

### build-essential
GNU编辑器合辑

`apt install build-essential` 

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
    `tar -cvf *.tar.gz *` 


### 远程桌面

1. 下载微软的远程桌面协议（RDP）
    `apt install xrdp`

### samba

> 文件分享
1. 下载 `apt install samba`
2. 配置分享文件夹 `chmod 777 /home/share/ -R`
3. 添加samba用户 `smbpasswd -a 用户名`
4. 提示输入密码 x2
5. 配置samba `vim /etc/samba/smb.conf`
```sh
[share]                 # 共享名
    comment = share     # 共享备注
    path = /home/share/ # 共享路径
    browseable = yes    # 所有人可见
    public = no         # 不允许匿名访问
    writable = yes      # 可写
    valid users = 用户名 # 设置访问用户
``` 
6. 重启samba `samba restart`
7. 开启端口 `ufw allow 445`



