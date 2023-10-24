---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# Linux

**值得一提**，我们可以通过 `build-essential` 包来安装 GCC 等一系列编译工具。

## GNU

GNU（GNU's Not Unix）是一个自由软件运动的项目，提供了许多重要的系统工具和应用程序：

* GNU 编译器套件（GCC）
* GNU Bash shell
* GNU Core Utilities（基本的命令行工具：ls、cp、mv、rm等）
...

这些工具的自由软件许可证（通常是GNU通用公共许可证，GPL）确保了用户对这些软件的自由使用权。

当人们谈论“Linux操作系统”时，通常指的是一个由Linux内核和GNU项目提供的工具和应用程序组成的系统

<br>

---

## GCC

GCC（GNU Compiler Collection）：GNU编译器集合是GNU项目的核心部分，支持多种编程语言的编译：

* **C：** GCC为C而生。
* **C++：** 尽管GCC可以编译C++程序，但它不会自动链接C++标准库。可能需要手动添加 `-lstdc++` 标志来链接C++标准库。

* **Objective-C & Objective-C++：** 这两种语言是用于苹果（如iOS和macOS）的主要编程语言。
* **Go（通过GCCGO）：** GCC的一个变体，称为GCCGO，支持Go语言的编译。

* **Rust（通过Rust-GCC插件）：** 在Rust编程语言的生态系统中，也有Rust-GCC插件，使得可以使用GCC来编译Rust程序。

`gcc` 命令，是GCC的默认命令，它可以编译C、C++、Objective-C、Objective-C++程序。

<br>

---

## G++

`g++` 命令，是GCC中的C++编译器命令，专门用于编译C++程序。

1. **编译C++程序：**
    ```sh
    g++ ac.cpp -o ac
    ```
    * `ac.cpp` 是需要编译的C++源文件。
    * `-o` 选项指定了输出文件的名称，这里是 `ac`。

2. **指定C++标准：**
    ```sh
    g++ -std=c++11 ac.cpp -o ac
    ```
    * `-std=c++23` 选项指定了C++标准，这里是C++23标准。

3. **指定编译器优化级别：**
    ```sh
    g++ -O2 ac.cpp -o ac
    ```
    
    * `-O0`（无优化）：
        * 效果： 不进行任何优化。生成的代码与源代码结构一致，方便调试。
        * 适用： 开发和调试阶段，用于方便调试和查找问题。

    * `-O1`（基本优化）（缺省）：

        * 效果： 应用基本的优化策略，如内联函数、去除未使用的变量等。
        * 适用： 提供一些优化，但不会显著增加编译时间，适用于大多数情况。
    
    * `-O2`（标准优化）：
        * 效果： 包括更多的内联、循环展开、消除不必要的指令等优化策略。
        * 适用： 提供更多的性能优化，适用于发布版本，编译时间可能会增加。
    
    *  `-O3`（更高级的优化）：
        * 效果： 包括更多复杂的优化，如矢量化、函数调用优化等。
        * 适用： 对性能要求非常高的应用，但可能增加编译时间，不建议用于所有应用。
        
    * `-Ofast`（最高级的优化）： 
        * 效果： 启用所有可能的优化，包括不遵循标准的优化，例如非标准数学优化和禁用安全性检查。
        * 适用： 对极致性能要求的应用，但可能引入精度损失和不可预料的行为。

4. **生成调试信息：**
    ```sh
    g++ -g ac.cpp -o ac
    ```
    * `-g` 选项指定生成调试信息，这样可以使用调试器调试程序。

<br>

---

## GDB

GDB（GNU Debugger）：GNU调试器是一个功能强大的调试器，可以用于调试C、C++、Objective-C、Fortran、Java、Go等程序。

在上面生成调试信息中，我们生成了一个可调试的程序，现在我们可以使用GDB调试这个程序。

1. **启动GDB：**
    ```sh
    gdb ac
    ```
    * `ac` 是需要调试的程序。

2. **设置断点：**
    ```sh
    break ac.cpp:main
    break ac.cpp:10
    ```
    * `break` 命令用于设置断点，可以简写为 `b`。
    * `ac.cpp:main` 是断点的位置，这里是 `ac.cpp` 文件的 `main` 函数。
    * `ac.cpp:10` 是断点的位置，这里是 `ac.cpp` 文件的第 `10` 行。
    * 如果不指定文件名，那么默认是当前文件。

3. **运行程序：**
    ```sh
    run
    ```
    * `run` 命令用于运行程序，可以简写为 `r`。

4. **单步执行：**
    ```sh
    step
    ```
    * `step` 命令用于单步执行程序，可以简写为 `s`。

5. **继续执行：**
    ```sh
    continue
    ```
    * `continue` 命令用于继续执行程序，直到遇到下一个断点，可以简写为 `c`。

6. **查看变量：**
    ```sh
    print a
    ```
    * `print` 命令用于查看变量，可以简写为 `p`。

7. **查看堆栈：**
    ```sh
    backtrace
    ```
    * `backtrace` 命令用于查看堆栈，可以简写为 `bt`。

5. **退出GDB：**
    ```sh
    quit
    ```
    * `quit` 命令用于退出GDB，可以简写为 `q`。

<br>

---

## Make & Makefile

Make 是一个构建工具，依赖 Makefile 文件来描述构建规则，然后通过 make 命令来执行构建。

我们考虑一下这样一个场景：
* `ac` 程序依赖 `ac.cpp` 文件。
* `bc` 程序依赖 `bc.cpp` 文件和 `ac` 程序。

我们需要确保在构建 `bc` 程序之前，`ac` 程序已经构建完成。


```cpp
// ac.cpp
#include <fstream>

int main(){
    std::ofstream("ac.txt") << "Hello_World!";
    return 0;
}
```

```cpp
// bc.cpp
#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::string s;
    std::ifstream("ac.txt") >> s;
    std::cout << "This is from AC: " << s;
    return 0;
}
```

编写 Makefile 文件：

```makefile
# Makefile
CC = g++                # 指定编译器
CFLAGS = -g -std=c++23  # 指定编译选项

all: ac bc

ac: ac.cpp
	$(CC) $(CFLAGS) -o ac ac.cpp
	./ac

bc: bc.cpp 
	$(CC) $(CFLAGS) -o bc bc.cpp

clean:
	rm -f ac bc ac.txt
```

* `CC` 变量指定了编译器，这里是 `g++`。
* `CFLAGS` 变量指定了编译选项，这里是 `-g -std=c++23`。
* `all` 是一个伪目标，一个约定俗成，通过 `make all` 命令，依次构建 `all` 所依赖的目标。
* `ac` 是一个目标，依赖 `ac.cpp` 文件，通过 `make ac` 命令，依次构建 `ac` 所依赖的目标。
* `bc` 是一个目标，依赖 `bc.cpp` 文件，通过 `make bc` 命令，依次构建 `bc` 所依赖的目标。
* `clean` 是一个目标，通过 `make clean` 命令，清理构建过程中产生的文件。

在此目录下，我们可以使用以下几种命令：
* `make`：构建 `all` 目标。
* `make all`：构建 `all` 目标。
* `make ac`：构建 `ac` 目标。
* `make bc`：构建 `bc` 目标。
* `make clean`：清理构建过程中产生的文件。

综上，其实可以发现，Makefile 文件就是一系列的目标和依赖关系，通过 `make` 命令来执行构建，
其本身并不具备编译的能力，而是通过调用编译器来实现编译。

<br>

---

## Cmake & CmakeLists.txt

Cmake 是一个跨平台的构建工具，依赖 CmakeLists.txt 文件来描述构建规则，可以自动生成各种操作系统和开发环境下的构建脚本，然后通过 cmake 命令来执行构建。

1. **一个基础的CmakeLists.txt：**
    ```cmake
    # 指定CMake的最低版本要求
    cmake_minimum_required(VERSION 3.0)

    # 设置项目的版本号
    set(PROJECT_VERSION_MAJOR 1)
    set(PROJECT_VERSION_MINOR 0)
    set(PROJECT_VERSION_PATCH 0)

    # 指定项目名称和支持的编程语言
    project(JiaoProject VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH} LANGUAGES CXX)

    # 添加可执行文件
    add_executable(JiaoProject main.cpp help.cpp)
    ```
    * `cmake_minimum_required` 指定了Cmake的最低版本。
    * `project` 指定了项目名称和版本，这里是 `JiaoProject` 项目，版本号是 `1.0.0`，支持的语言是 C++。
        * `PROJECT_VERSION_MAJOR` 是主版本号。
        * `PROJECT_VERSION_MINOR` 是次版本号。
        * `PROJECT_VERSION_PATCH` 是修订号。
        * `LANGUAGES` 指定了支持的编程语言。
    * `add_executable` 指定了可执行文件的名称和源文件：将 `main.cpp` 和 `help.cpp` 编译并链接到 `JiaoProject` 可执行文件中。


<br>

---

# Windows

## mingw-w64

[下载地址](https://github.com/niXman/mingw-builds-binaries/releases)

mingw-w64 是一个跨平台的编译器，可以在 Windows 上编译出 Linux 下可执行文件。

| 系统架构 | 位数 |
|:-:|:-:
| **i686** | 32位 |
| **x86-64**| 64位 | 

| 接口标准 | 跨平台性 | 主要特点 |
|:-------:|:-------:|:-------:|
| **POSIX**  | 跨UNIX和类UNIX系统   | 标准化的UNIX系统API，跨平台 |
| **MCF**    | 仅限于Windows平台    | Windows API集成，提供高级功能 |
| **Win32**  | 仅限于Windows平台    | 提供Windows操作系统的各种功能 |

| 异常处理与调试 | 用途 | 应用范围 | 使用场景 | 
|:-:|:-:|:-:|:-:|
| **SEH** | 仅限于Windows平台，处理Windows特定的异常 | 处理程序运行时的异常，提供结构化的异常处理           | 应用程序中处理可能出现的异常情况，如文件读取失败或内存访问错误    |
| **DWARF** | 用于多种操作系统，包括Linux、Unix、macOS等             | 提供编译后程序的调试信息给调试器                  | 由编译器生成，提供源代码级别的调试信息给开发者，用于程序调试和分析    |

| 运行时库   | 版本兼容性和兼容性 | 提供的函数和特性 |
|:-:|:-:|:-:|
| **ucrt**   | 较新的Windows版本 | 标准C库函数，包括C11和POSIX标准的扩展函数 |
| **msvcrt** | 早期和某些Windows版本 | 早期的C库函数和一些扩展函数         |

值得一提，虽然 POSIX 接口标准是跨平台的，但是 Windows 并不支持 POSIX 标准，如果使用 POSIX 标准，那么程序会

<br>

---

## MSVC

MSVC（Microsoft Visual C++）是微软的 C++ 编译器，通常与 Visual Studio 集成使用。