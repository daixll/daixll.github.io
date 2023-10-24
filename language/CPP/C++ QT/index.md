---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# SETUP

首先注册一个 QT 账号：[官网](https://www.qt.io/zh-cn/)

## LINUX

[visual studio code](https://visualstudio.microsoft.com/zh-hans/downloads/) + [QT](https://mirrors.tuna.tsinghua.edu.cn/help/qt/)

* 安装 QT 的过程 **可能** 出现依赖缺失问题：~~*不知道装什么，那就全装*~~
    ```bash
    sudo apt install libxcb*
    sudo apt install libgl1-mesa-dev
    ```

<br>

1. **检测是否安装成功，添加用户级环境变量**

    * 检测
    ```bash
    /QT/6.5.3/gcc_64/bin/qmake -v
    ```

    * 添加用户级环境变量 `~/.bashrc`
    
    ```bash
    export PATH=$PATH:/QT/6.5.3/gcc_64/bin
    ```

    将其添加到文件末尾，保存后执行 `source ~/.bashrc` 使其生效


<br>

2. **配置 VSCode**

    * 安装插件 `C/C++`
    * 在项目文件夹中，创建 `.vscode/c_cpp_properties.json` 文件：

        > Q：为什么是在项目文件夹中创建？
        > A：这个配置文件仅仅针对本项目，所以放在项目文件夹中，不同的项目应该是不同的配置文件。

    ```json
    {
        "configurations": [
            {
                "name": "Simple C++ QT Configuration",
                "includePath": [
                    "${workspaceFolder}/**",
                    "/QT/**"
                ],
                "compilerPath": "/usr/bin/gcc"
            }
        ],
        "version": 4
    }
    ```
    `name`：配置名称，这里是 Simple C++ QT Configuration
    `includePath`：头文件路径，这里是项目文件夹和 QT 安装路径
    `compilerPath`：编译器路径，这里是 GCC 的路径

<br>

3. **Hello QT!**

    <br>

    **QT 的构建过程**：`*.cpp` -> `*.pro` -> `Makefile` -> `*`

    <br>

    1. 源文件：`main.cpp`

        ```cpp
        #include <QApplication>
        #include <QPushButton>
        #include <QMessageBox>

        int main(int argc, char *argv[]) {
            QApplication app(argc, argv);

            // 创建一个按钮
            QPushButton button("点击我！", nullptr);

            // 当按钮被点击时，连接到应用程序的quit()槽函数
            QObject::connect(&button, &QPushButton::clicked, [&]() {
                // 显示一个消息框
                QMessageBox::information(nullptr, "消息", "按钮被点击了！");
            });

            // 显示窗口
            button.show();

            // 运行应用程序的事件循环
            return app.exec();
        }
        ```

    <br>

    2. 工程管理文件：`main.pro` 

        ```sh
        # 指定项目的配置信息
        QT += widgets

        # 开启调试信息
        CONFIG += debug

        # 指定源文件
        SOURCES += main.cpp
        ```

    <br>

    3. 生成 `Makefile`

        ```sh
        qmake hello.pro
        ```

    <br>

    4. 生成 `main`

        ```sh
        make
        ```

<br>

4. **调试**

    1. 在项目文件夹中，创建 `.vscode/launch.json` 文件： 

        ```json
        {
            "version": "0.2.0",
            "configurations": [
                {
                    // 配置的名称，可以自定义
                    "name": "Debug",
                    // 配置类型为cppdbg，表示C++调试
                    "type": "cppdbg",
                    // 请求类型为launch，表示启动调试
                    "request": "launch",
                    // 可执行文件路径为当前打开文件的路径和文件名（不带扩展名）
                    "program": "${fileDirname}/${fileBasenameNoExtension}",
                    // 是否在程序入口处停止
                    "stopAtEntry": false,
                    // 当前工作目录为VS Code的工作区目录
                    "cwd": "${workspaceFolder}",
                    // 调试器类型为gdb
                    "MIMode": "gdb",
                    // 指定gdb的可执行文件路径
                    "miDebuggerPath": "gdb",
                }
            ]
        }
        ```
    
    2. 依次点击：`运行` -> `启动调试`，即可开始调试
        
        1. 继续：运行到下一个断点
        2. 逐过程：逐行执行，遇到函数则跳过函数的内部执行
        3. 单步调试：单步执行，如果遇到函数则进入函数内部执行
        4. 单步跳出：执行到当前函数的最后一行，然后跳出函数


## WINDOWS

[visual studio](https://visualstudio.microsoft.com/zh-hans/downloads/) + [QT](https://mirrors.tuna.tsinghua.edu.cn/help/qt/)

1. visual studio 安装 Qt Visual Studio Tools插件

2. 拓展 -> Qt VS Tools -> Qt Versions -> Add -> 选择 QT 安装路径
    例如：`C:\Qt\6.x.x\msvc2019_64\bin\qmake.exe`

3. 创建项目：文件 -> 新建 -> 项目 -> Qt Widgets Application
    F5 一键运行，弹出窗口即成功



<br>

---

# QT设计师

## Buttons

### Push Button

**按钮**

按下按钮时，会发出 `pressed()` 信号。
释放按钮时，会发出 `released()` 信号。

```cpp
// 槽函数
void QT2::press() { // 按下事件的槽函数
	qDebug() << "press";
}

void QT2::release() { // 松开事件的槽函数
	qDebug() << "release";
}

// 连接信号和槽
// 将 QPushButton 的 pressed() 信号连接到 QT2 的 press() 槽
QObject::connect(ui.pushButton, &QPushButton::pressed, this, &QT2::press);
// 将 QPushButton 的 released() 信号连接到 QT2 的 release() 槽
QObject::connect(ui.pushButton, &QPushButton::released, this, &QT2::release);
```


单击（按下+释放）按钮时，会发出 `clicked()` 信号。
可以使用 Lambda 表达式来连接信号和槽。

```cpp
// 信号与槽的连接
QObject::connect(ui.pushButton, &QPushButton::clicked, [&]() {
    qDebug() << "click";
    });
```

<br>

### Tool Button

**工具按钮**

单击（按下+释放）工具按钮时，会发出 `clicked()` 信号。

```cpp
QObject::connect(ui.toolButton, &QToolButton::clicked, [&]() {
	qDebug() << "toolButton click";
	});
```

<br>

### Check Box

**复选框**

单击（按下+释放）复选框时，会发出 `clicked()` 信号。

```cpp
QObject::connect(ui.checkBox, &QCheckBox::clicked, [&]() {
    qDebug() << "checkBox click";
    });
```

