[官网](https://www.qt.io/zh-cn/) 注册账号

## Linux-setup

* 简单安装

    1. 下载 [在线安装器](https://mirrors.tuna.tsinghua.edu.cn/qt/official_releases/online_installers/)
    2. 使用镜像启动
        ```shell
        sudo ./qt*
        ```
        * 启动过程 **可能** 出现依赖缺失问题：~~*不知道装什么，那就全装*~~
            ```bash
            sudo apt install libxcb*
            sudo apt install libgl1-mesa-dev
            ```
        * 只需要 `Desktop`
    3. 检测是否安装成功
        ```shell
        /opt/Qt/x.y.z/gcc_64/bin/qmake -v
        ```

    4. 添加用户级环境变量 `~/.bashrc`
        ```bash
        export PATH=$PATH:/opt/Qt/x.y.z/gcc_64/bin
        ```
        > 可能会出现 `qmake: could not exec '/usr/lib/x86_64-linux-gnu/qt4/bin/qmake': No such file or directory` 的错误，这是因为系统中存在多个版本的 QT，解决方法是：`sudo apt remove qt4-qmake`。

        > 另外一方案是，修改 `/usr/lib/x86_64-linux-gnu/qt-default/qtchooser/default.conf` 文件，将 `qt4` 的路径修改为 `/opt/Qt/x.y.z/gcc_64/bin`。