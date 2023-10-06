---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# QT SETUP

## LINUX

[visual studio code](https://visualstudio.microsoft.com/zh-hans/downloads/) + [QT](https://mirrors.tuna.tsinghua.edu.cn/help/qt/)

1. 安装QT如果出现依赖问题：不知道装什么，那就全装
    ```bash
    sudo apt install libxcb*
    ```

2. 选择安装路径，检测是否安装成功
    ```bash
    /QT/6.x.x/gcc_64/bin/qmake -v
    ```

3. 创建项目

    <details><summary>hello.h</summary>

    ```cpp

    ```
    </details>

    <details><summary>hello.cpp</summary>

    ```cpp

    ```
    </details>

    <details><summary>main.cpp</summary>

    ```cpp

    ```
    </details>

    编写工程管理文件：`*.pro` 

    <details><summary>hello.cpp</summary>

    ```cpp

    ```
    </details>

    通过`.pro`文件生成`Makefile`文件，再通过`Makefile`文件生成可执行文件

    ```bash
    /QT/6.x.x/gcc_64/bin/qmake hello.pro -o Makefile && make && ./hello
    ```

4. 又是依赖问题：
    ```bash
    sudo apt install libgl1-mesa-dev
    ```

## WINDOWS

[visual studio](https://visualstudio.microsoft.com/zh-hans/downloads/) + [QT](https://mirrors.tuna.tsinghua.edu.cn/help/qt/)

1. visual studio 安装 Qt Visual Studio Tools插件

2. 拓展 -> Qt VS Tools -> Qt Versions -> Add -> 选择 QT 安装路径
    例如：`C:\Qt\6.x.x\msvc2019_64\bin\qmake.exe`

3. 创建项目：文件 -> 新建 -> 项目 -> Qt Widgets Application
    F5 一键运行，弹出窗口即成功