---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# SETUP

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

