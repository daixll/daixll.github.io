---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 参考

**书籍：** [阿里云盘](https://www.aliyundrive.com/s/N3uJKMZFdzF)

**视频：**

* 123

**网站：**

* 123

<br>

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
                    "stopAtEntry": true,
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
    例如：`C:\Qt\6.5.3\msvc2019_64\bin\qmake.exe`

3. 创建项目：文件 -> 新建 -> 项目 -> Qt Widgets Application
    F5 一键运行，弹出窗口即成功



<br>

---

当涉及到Qt框架中常用的一些类时，下面是一个简单的结构图：

```
QObject
  └── QWidget
      ├── QMainWindow
      ├── QLabel
      ├── QPushButton
      ├── QLineEdit
      ├── QComboBox
      ├── QCheckBox
      ├── QRadioButton
      ├── QSlider
      ├── QProgressBar
      └── ...

QLayout
  ├── QHBoxLayout
  └── QVBoxLayout

QEvent
  ├── QMouseEvent
  ├── QKeyEvent
  ├── QResizeEvent
  ├── QCloseEvent
  └── ...
  
QPainter
QPixmap
QImage
QPen
QBrush
QColor
...
```



# 信号与槽

简单理解，当你在页面点击一个按钮，这个点击就是 **信号**，而后端的处理函数就是 **槽**。
同理，当你在页面输入一个字符，这个输入就是 **信号**，而后端的处理函数就是 **槽**。

QT 官方对信号与槽的描述如下：
>Qt 的核心思想是信号与槽机制。信号与槽是一种机制，用于在对象间进行通信。信号在特定事件发生时被发射，槽是在信号被发射时被调用的函数。Qt 中，任何 Qt 对象都能发送信号和处理信号。信号与槽是一种非常灵活和松耦合的通信机制，它允许对象间的通信完全独立于彼此的实现。

**值得一提** 的是，信号与槽的连接是 **动态** 的，也就是说，你可以在程序运行的过程中，动态的连接信号与槽，也可以动态的断开信号与槽的连接。

**信号与槽的新语法** 

* 之前 信号与槽连接的方式：

    ```cpp
    connect(sender, SIGNAL(valueChanged(QString, QString)),
            receiver, SLOT(updateValue(QString)));

    // 具体的
    connect(button, SIGNAL(clicked()), this, SLOT(showMessage()));
    ```

    官网对这种方式的弊端进行了详细的说明：[Qt 5中信号和槽的新语法](https://www.qt.io/zh-cn/blog/2012/08/07/new-signals-slots-syntax-in-qt5)

    <br>

* 目前 信号与槽连接的方式：

    ```cpp
    connect(sender, &Sender::valueChanged, receiver, &Receiver::updateValue);

    // 具体的
    connect(button, &QPushButton::clicked, this, &MyWidget::showMessage);

    // 使用 lambda 表达式
    connect(button, &QPushButton::clicked, [=](){ 
        QMessageBox::information(nullptr, "消息", "按钮被点击了！"); 
        });
    ```

<br>

---

# 简单窗口和基本控件

## Hello Qt

Qt 创建一个窗口非常简单，只需要创建一个 `QWidget` 对象，然后调用 `QWidget` 的 `show()` 方法即可。

不过在这之前，我们先了解一下 `QApplication` 类，它是 Qt 程序的入口，也是 Qt 程序的核心对象，每个 Qt 程序都必须 **有且仅有一个** `QApplication` 对象。

1. 应用程序的初始化。
    * 命令行参数的解析。
    * 资源文件的加载：例如应用图标，各种按钮的图片等。
    * 初始化第三方库和服务：例如数据库服务。

2. 事件循环。
    * 通过调用 `exec()` 方法进入事件循环。

3. 处理系统事件。
    * 确保事件（鼠标点击、键盘输入）被传递给适当的窗口部件进行处理。

4. 退出应用程序。
    * 用户关闭主窗口，它负责安全地关闭所有窗口并释放所有资源。
    * 或调用 `quit()` 方法安全地退出事件循环。

5. 跟踪应用程序的状态。
    * 例如，`QApplication` 类提供了 `applicationStateChanged()` 信号，当应用程序的状态发生变化时，就会发射这个信号。

因此，我们的程序应该是这样的：

```cpp
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);   // 创建一个应用程序对象
    return app.exec();              // 进入事件循环
}
```

程序有了，但是没有窗口，我们需要创建一个窗口，然后显示出来，
很有必要，创建一个主窗口类：

```cpp
// MainWindow.h
#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow   // 创建一个主窗口类
{                                       // 继承自QMainWindow
    Q_OBJECT                            // 使用Qt的信号与槽机制需要这个宏

public:
    MainWindow(QWidget *parent = nullptr); 
    ~MainWindow();

private:
    // 在这里声明私有成员变量和私有方法
};
```

`Q_OBJECT` 宏是使用 Qt 的信号与槽机制必须的，它会在编译阶段自动将 `moc` 文件（元对象编译器）插入到源文件中，这个文件中包含了信号与槽的实现。

```cpp
// MainWindow.cpp
#include "include/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) // 这里的parent是可选的
    : QMainWindow(parent)               // 构造函数的初始化列表
{
    // 在这里进行主窗口的初始化操作
    this -> setWindowTitle("Hello Qt!");// 设置窗口标题
}

MainWindow::~MainWindow()
{
    // 在这里进行资源的清理工作（如果需要）
}
```

在 `main.cpp` 中，我们需要创建一个 `MainWindow` 对象，然后显示出来：

```cpp
MainWindow *w = new MainWindow();   // 创建一个主窗口对象
w->show();                          // 显示主窗口
```

源代码及 `.pro` 参见：[Leg1](https://github.com/daixll/A_Tour_of_Qt/tree/main/Leg1)


## 按钮和标签

## 文本输入和显示

## 布局管理器

## 🧮 计算器

## 菜单和工具栏

# 列表和组合控件

## 选择和显示日期/时间

## ⛺ 图片显示


## 🎨 画图


## 进度条和滑块

## 表格和滚动区域

## 多媒体




# 布局管理器



# 文件和图像操作