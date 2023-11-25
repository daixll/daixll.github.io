---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 参考

**书籍：**

* asd

**网站：**

* [Qt 快速入门系列教程](http://shouce.jb51.net/qt-beginning/)

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

# 一次编写，到处编译

一般而言，一个Qt项目有如下文件：
* `main.pro`：工程管理文件
* `main.cpp`：源文件

将其 **完整复制** 到其他平台，然后 **重新编译** 即可运行。

## LINUX

```shell
qmake main.pro  # 生成 Makefile
make            # 编译
./main          # 运行
```

## WINDOWS

打开终端 `Qt 6.x.x (MinGW)`，到项目目录，执行：

```shell
qmake main.pro  # 生成 Makefile
mingw32-make    # 编译
debug\main.exe  # 运行
```

<br>

---

# 打包！分享给 👧


## LINUX



## WINDOWS

1. 将你的 `main.exe` 文件单独复制到一个干净的文件夹中；
2. 打开终端 `Qt 6.x.x (MinGW)`，到新建的文件夹，执行：
    ```shell
    windeployqt main.exe
    ```
    * 它会自动分析你的应用程序，找出它所依赖的Qt模块和其他依赖项，并将这些文件复制到应用程序的目录中。
    * 此时，软件已经可以在其他（同一平台）电脑上运行了。
    * 为了更好的用户体验，我们可以将其打包成一个绿色版的软件，👧 可以点击 `main.exe` 直接运行！
3. 下载安装 [Enigma Virtual Box](https://www.enigmaprotector.com/cn/downloads.html)；
4. 使用 Enigma Virtual Box 将 `main.exe` 打包：
    1. 在 `Enter input File Name:` 中打开 `main.exe`，会自动填写 `output`；
    2. 点击 `Add` -> `Add Folder Recursive`，选择 `main.exe` 所在的文件夹，默认就好；
    3. 点击 `Files Options`，勾选 `Files Virtualization` 和 `Compress Files`；
    4. 点击 `Process`，等待打包完成；

<br>

---



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

```
QObject                 # 所有类的基类，提供了对象的基本功能（属性、信号与槽...）
  └── QWidget           # 所有窗口部件的基类，提供了窗口部件的基本功能（尺寸、位置、标题...）
      ├── QMainWindow   # 主窗口类，提供了主窗口的基本功能（菜单栏、工具栏、状态栏...）
      ├── QLabel        # 标签类，用于显示文本或图像
      ├── QPushButton   # 按钮类，用于响应用户的点击
      ├── QLineEdit     # 单行文本输入框类，用于接收用户的输入
      ├── QComboBox     # 下拉列表类，用于从列表中选择一个选项
      ├── QCheckBox     # 复选框类，用于从多个选项中选择一个或多个
      ├── QRadioButton  # 单选按钮类，用于从多个选项中选择一个
      ├── QSlider       # 滑块类，用于从一个范围中选择一个值
      ├── QProgressBar  # 进度条类，用于显示任务的进度
      └── ...

QLayout             # 所有布局管理器的基类，提供了布局管理器的基本功能
  ├── QHBoxLayout   # 水平布局
  ├── QVBoxLayout   # 垂直布局
  ├── QGridLayout   # 网格布局
  └── ...

QEvent              # 所有事件的基类，提供了事件的基本功能
  ├── QMouseEvent   # 鼠标事件
  ├── QKeyEvent     # 键盘事件
  ├── QResizeEvent  # 窗口大小改变事件
  ├── QCloseEvent   # 窗口关闭事件
  └── ...
  
QPainter    # 绘图设备，用于绘制各种图形
QPixmap     # 图片设备，用于显示图片
QImage      # 图片设备，用于显示图片
QPen        # 画笔，用于绘制各种图形的轮廓
QBrush      # 画刷，用于绘制各种图形的背景
QColor      # 颜色，用于设置画笔和画刷的颜色
...
```

## Leg 1 Hello Qt

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

窗口中的内容是空的，我们可以尝试在窗口中显示一些文字：

```cpp
// MainWindow.h
#include <QLabel>   // 包含标签类的头文件
// ...
private:
    QLabel *_label; // 声明一个标签
// ...
```
    
```cpp
// MainWindow.cpp
this -> _label = new QLabel(this);  // 为其分配内存
this -> _label -> setText("Hello Qt!!!");   // 设置标签文本
```

<br>

源代码及参见：[Leg1](https://github.com/daixll/A_Tour_of_Qt/tree/main/Leg1)

---

## Leg 2 布局管理器

为了能够控制标签的位置，我们需要使用布局管理器，布局管理器是 Qt 提供的一种自动布局机制，它能够根据窗口的大小自动调整窗口部件的位置和大小。

Qt 常见的三种布局管理器：
* 水平布局：`QHBoxLayout`
* 垂直布局：`QVBoxLayout`
* 网格布局：`QGridLayout`

我们这里使用垂直布局：

```cpp
// MainWindow.h
#pragma once

#include <QMainWindow>
#include <QLayout>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget     *_centralWidget;// 声明一个中央部件
    QVBoxLayout *_layout;       // 声明一个垂直布局管理器
    QLabel      *_labeltext;    // 声明一个文本标签
    QLabel      *_labelimg;     // 声明一个图片标签
};
```

布局管理器通常需要附着在一个特定的窗口部件上，这个窗口部件被称为中央部件（central widget）。

通过调用 `setCentralWidget(centralWidget)`，将整个布局应用到主窗口。

> Q：为什么要使用中央部件？而不是直接将布局应用到主窗口？
> 
> * 当你将布局管理器设置为主窗口时，它会直接影响主窗口的整体布局，包括菜单栏、工具栏等。而将布局管理器设置为中央部件的布局管理器，只会影响中央部件内部的子部件，不会影响其他部分的布局，这样更加灵活。
> * 主窗口是一个顶级窗口，可以包含多个子部件，而中央部件是主窗口的一个特殊子部件，它会自动占据主窗口的中央区域。

```cpp
// MainWindow.cpp
#include "include/MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Leg 2 布局管理器");

    _centralWidget  = new QWidget();
    _layout         = new QVBoxLayout();
    _labeltext      = new QLabel();
    _labelimg       = new QLabel();

    setCentralWidget(_centralWidget);     // 设置中央部件
    _centralWidget -> setLayout(_layout); // 设置中央部件的布局管理器
    _layout -> addWidget(_labeltext);   // 将文本标签添加到布局管理器
    _layout -> addWidget(_labelimg);    // 将图片标签添加到布局管理器

    // 设置标签的内容
    _labeltext -> setText("Leg 2 布局管理器");         // 设置文本标签
    _labelimg  -> setPixmap(QPixmap("img/cqvie.jpg"));// 设置图片标签
    // 设置标签的对齐方式为居中
    _labeltext -> setAlignment(Qt::AlignCenter);
    _labelimg  -> setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete _labelimg;
    delete _labeltext;
    delete _layout;
    delete _centralWidget;
}
```


显然，只有这几种布局是不够的，但如果布局可以嵌套，那么就可以实现更加复杂的布局。

我们尝试在现在的基础上，在上层添加一个网格布局：

```cpp
// MainWindow.h
// ...
private:
    QVBoxLayout *_vLayout;      // 声明一个垂直布局管理器
    QGridLayout *_gLayout;      // 声明一个网格布局管理器
    QLabel      _labeltext_1,   // 创建 6 个文本标签  
                _labeltext_2,
                _labeltext_3,
                _labeltext_4,
                _labeltext_5,
                _labeltext_6;
```



```cpp
// MainWindow.cpp
_vLayout        = new QVBoxLayout();
_gLayout        = new QGridLayout();
_labelimg       = new QLabel();

setCentralWidget(_centralWidget);       // 设置中央部件
_centralWidget -> setLayout(_vLayout);  // 设置中央部件的布局管理器

_vLayout -> addLayout(_gLayout);        // 将网格布局管理器添加到垂直布局管理器
_vLayout -> addWidget(_labelimg);       // 将图片标签添加到垂直布局管理器

// 将 6 个文本标签添加到网格布局管理器，并且设置内容
_gLayout -> addWidget(&_labeltext_1, 0, 0);
_gLayout -> addWidget(&_labeltext_2, 0, 1);
_gLayout -> addWidget(&_labeltext_3, 0, 2);
_gLayout -> addWidget(&_labeltext_4, 1, 0);
_gLayout -> addWidget(&_labeltext_5, 1, 1);
_gLayout -> addWidget(&_labeltext_6, 1, 2);
_labeltext_1.setText("C"); _labeltext_1.setAlignment(Qt::AlignCenter);
_labeltext_2.setText("Q"); _labeltext_2.setAlignment(Qt::AlignCenter);
_labeltext_3.setText("V"); _labeltext_3.setAlignment(Qt::AlignCenter);
_labeltext_4.setText("I"); _labeltext_4.setAlignment(Qt::AlignCenter);
_labeltext_5.setText("E"); _labeltext_5.setAlignment(Qt::AlignCenter);
_labeltext_6.setText("!"); _labeltext_6.setAlignment(Qt::AlignCenter);

// 设置图片标签，并且设置为居中
_labelimg  -> setPixmap(QPixmap("img/cqvie.jpg"));
_labelimg  -> setAlignment(Qt::AlignCenter);
```

<br>

源代码及参见：[Leg2](https://github.com/daixll/A_Tour_of_Qt/tree/main/Leg2)

---

## Leg 3 按钮与文本输入框

现在的窗口，都只是单一的显示内容，没有任何交互，我们可以添加一些按钮，来实现一些交互。

> 输入一串小写字母，点击按钮，将其转换为大写字母。

* **左边**：文本输入框，用于输入小写字母；
* **中间**：按钮，用于转换；
* **右边**：文本显示框，用于显示大写字母。

> * 单行文本输入框：`QLineEdit` 
> * 多行文本输入框：`QTextEdit`

我们在这里使用水平布局，单行文本输入框。

```cpp
// MainWindow.h
#pragma once

#include <QMainWindow>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT                  

public:
    MainWindow(QWidget *parent = nullptr); 
    ~MainWindow();

private:
    QWidget     _centralWidget;
    QHBoxLayout _hLayout;       // 水平布局
    QLineEdit   _input, _output;// 文本框
    QPushButton _button;        // 按钮

    void _onButtonClicked();    // 按钮点击的槽函数
};
```

1. 首先将界面写出来；
2. 点击按钮时：
    1. 获取输入文本框的内容；
    2. 检测输入是否合法；
        * 不合法则弹出警告框；
    3. 将输入转换为大写；
    4. 将转换后的内容设置到输出文本框中。

```cpp
#include "include/MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Leg 3 按钮与文本框");
    
    setCentralWidget(&_centralWidget);  // 设置中心窗口
    _centralWidget.setLayout(&_hLayout);// 设置中心窗口的布局

    _hLayout.addWidget(&_input);    // 将文本框添加到布局中
    _hLayout.addWidget(&_button);   // 将按钮添加到布局中
    _hLayout.addWidget(&_output);   // 将文本框添加到布局中

    _button.setText("转换");        // 设置按钮的文本
    _output.setReadOnly(true);      // 设置输出文本框为只读

    // 连接按钮的点击信号与槽函数
    connect(&_button, &QPushButton::clicked, this, &MainWindow::_onButtonClicked);
}

void MainWindow::_onButtonClicked(){
    QString input = _input.text();  // 获取输入文本框的内容
    if (input.isEmpty()){           // 检测输入是否为空
        QMessageBox::warning(this, "警告", "输入不能为空");
        return;                     // 如果为空，弹出警告框
    }

    for (auto &c : input){          // 检测输入是否是小写字母
        if (c < 'a' || c > 'z'){    // 如果不是小写字母，弹出警告框
            QMessageBox::warning(this, "警告", "输入必须是小写字母");
            return;
        }
    }

    QString output = input.toUpper();   // 将输入转换为大写
    _output.setText(output);            // 将转换后的内容设置到输出文本框中
}

MainWindow::~MainWindow(){}
```

<br>

源代码及参见：[Leg3](https://github.com/daixll/A_Tour_of_Qt/tree/main/Leg3)

---


## Mission 1 计算器 🧮

设计一个简单的计算器，要求：

1. 输入框：用于输入数字和运算符；
2. 输出框：用于显示结果；
3. 操作符：`+`、`-`、`*`、`/`；
4. 数字：`0`、`1`、`2`、`3`、`4`、`5`、`6`、`7`、`8`、`9`；
5. 删除：`D`；
6. 清空：`C`。

<br>

源代码及参见：[Mission1](https://github.com/daixll/A_Tour_of_Qt/tree/main/Mission1)

> 此代码仅供参考，为使得代码更加简洁：
> 1. 没有进行错误处理。
> 2. 不支持高精度。
> 3. 不支持小数。 
> ...

同学们可以自行对 `calc.h` 进行修改，使得其支持更多的运算符和更高的精度。

<br>

---


# 待整理



## 菜单和工具栏

# 列表和组合控件

## 选择和显示日期/时间

## ⛺ 图片显示


## 🎨 画图


## 进度条和滑块

## 表格和滚动区域

## 多媒体

# 文件和图像操作


# raylib

raylib 是一个简单易用的游戏开发库，它提供了一系列的函数，用于处理窗口、图像、音频、输入、模型等。

## 安装

```sh
sudo apt install libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev
```

## 测试代码

```cpp
#include "raylib.h"


## 编译

```sh
gcc main.c -o main -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

## 运行

```sh
./main
```