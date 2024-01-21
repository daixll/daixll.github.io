---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 参考

关于 C/C++ 的学习参考：

1. 学习 **基本语法**：最快速的上手方式是国内自学网站 [菜鸟教程](https://www.runoob.com/cplusplus/cpp-tutorial.html) 等 + [洛谷OJ](https://www.luogu.com.cn/training/list) 等，再看看视频等。
    * 视频推荐：[【Youtube】 The Cherno](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb) / [【bilibili】 The Cherno(搬运)](https://www.bilibili.com/video/BV1oD4y1h7S3)
    * 洛谷OJ 只需要完成入门系列的题目即可，但如果你未来想要更好的从事开发相关的工作，建议开始 **系统地** 学习数据结构与算法，同时，对网络、OS、数据库等方面也要有一定的了解。
    * 学有余力，可以看看《C++ Primer》 、《C 和指针》等书籍。

<br>

2. 学习 **C++ STL**：如果你有数据结构和算法的基础，其实也就不必再学习 C++ STL 了，因为 C++ STL 本质上就是数据结构和算法的实现。
    * [C语言中文网：C++ STL快速入门](https://c.biancheng.net/stl/)
    * 书籍：侯捷 - 《STL源码剖析》

<br>

3. 学习 **现代C++** C++ 11/14/17/20：这是一个非常庞大的话题，涉及了很多方面，最高效的方式是看书。
    * 优先学习新特性，或者说，优先学习新特性的使用方法，而不是去了解新特性的实现原理。
    * **网络编程** 和 **并发编程** 部分，建议单独学习。
    * 推荐阅读：[现代 C++ 教程](https://changkun.de/modern-cpp/)、《C++ XX高级编程》、《现代C++ 白皮书》（课外阅读）。
    * 近期出版的《C++ 之旅（第三版）》、《C++ Core Guildelines解析》也是非常不错的书籍。

<br>

4. 学习 **面向对象**：用C++之父 本贾尼 的话说，C++是支持面向对象，而不是，C++是面向对象的语言。*“面向对象不是 C++ 的所有，而仅仅是其支持的多种编程范式（面向过程、面向对象、泛型编程、函数式编程）中的一种”*。
    * 面向对象编程：封装、继承、多态。
    * 既然面向对象是一种思想，我们应该跳脱出语言的限制，去思考如何设计一个面向对象的系统。
    * [书籍参考]()：《设计模式的艺术——软件开发人员内功修炼之道》、《head first设计模式》。
    * 架构为道、设计为术。设计模式是确定架构下的最佳实践。



<br>

---

# C是如何工作的

对于这个问题，
* 通俗的，计算机是如何看懂我给它下达的指令。
* 具体的，如何把 `.c` （文本文件） -> `.exe` （可执行文件） 

**源文件 -> 预处理 -> 编译 -> 汇编 -> 链接 -> 可执行文件**

<br>

## 预处理

* 一个文本替换工具罢了，它会根据源文件中的预处理指令，修改源文件。
* 预处理指令以 `#` 开头，如 `#include`、`#define` 等。
    * `#include` 会把指定的文件内容插入到当前文件中。
    * `#define` （宏定义）会把指定的内容替换到当前文件中。
        ```cpp
        #define MAX 100

        int a[MAX];             // int a[100]; 定义一个大小为 100 的数组
        printf("%d", MAX*MAX);  // printf("%d", 100*100); 输出 10000
        ```
        **值得注意的是，宏定义只是简单的文本替换**
        
        C语言自带一些宏定义：`__TIME__`，`__FILE__` 等等
        ```cpp
        printf("%s", __TIME__);    // 输出当前（预处理器替换时候的）时间
        printf("%s", __FILE__);    // 输出当前文件名
        ```

    更多内容可以参考：[C语言预处理器](https://www.runoob.com/cprogramming/c-preprocessors.html)

    <br>

* 预处理后的文件，以 `.i` 为后缀名，如 `main.i`。

    1. 源文件 `main.c`
        ```cpp
        #include <stdio.h>
        #define MAX 100

        int main(){
            int a[MAX];
            printf("%d", MAX*MAX);
        }
        ```

    2. 使用 gcc 生成预处理后的文件 `main.i`
        ```bash
        gcc -E main.c -o main.i
        ```


<br>

## 编译

* 编译器会把预处理后的文件，翻译成汇编语言。
    * 一种低级语言，它使用助记符（mnemonic）代替二进制指令。
    * 汇编语言是与硬件相关的，不同的硬件有不同的汇编语言。
* 汇编语言以 `.s` 为后缀名，如 `main.s`。
    1. 使用 gcc 生成汇编文件 `main.s`
        ```bash
        gcc -S main.i -o main.s
        ```


<br>

## 汇编

* 汇编器会把汇编语言翻译成机器语言。
    * 机器语言，使用二进制指令。

* 机器语言以 `.o` 为后缀名，如 `main.o`。
    1. 使用 gcc 生成目标文件 `main.o`
        ```bash
        gcc -c main.s -o main.o
        ```


<br>

## 链接

* 链接器将多个汇编文件链接成一个可执行文件。

* 在 linux 中，可执行文件以 `.out` 为后缀名，如 `main.out`。
    1. 使用 gcc 生成可执行文件 `main.out`
        ```bash
        gcc main.o -o main.out
        ```

* 现在有 `a.c` 文件和 `b.c` 文件
    * `a.c`
        ```c
        #include <stdio.h>

        int main(){
            printf("%d", ADD(2, 3));
            return 0;
        }
        ```
    * `b.c`
        ```c
        #include <stdio.h>

        int ADD(int a, int b){
            return a + b;
        }
        ```

    1. 使用 gcc 生成 `.o` 文件
        ```bash
        gcc -c a.c -o a.o
        ```
        此时，`a.o` 中的 `main` 函数调用了 `ADD` 函数，但是 `ADD` 函数的定义并没有找到。弹出了一个警告。
        **注意，`gcc` 只检查语法，不检查函数的定义。**
        **注意，`g++` 会检查函数的定义，它会在这里弹出错误。**
    
        ```bash
        gcc -c b.c -o b.o
        ```



    2. 使用 gcc 生成可执行文件
        ```bash
        gcc a.o b.o -o main.out
        ```
        **注意，链接器会检查函数的定义，如果找不到定义，就会报错。**


<br>

至此，我们不仅知道 C 工作的原理，还在一定程度上了解 `.h`，`.c` 文件的关系
    

<br>

---

# 编译器是如何工作的

## todo 

<br>

---

# 链接器是如何工作的

## todo

<br>

---

# 基本数据类型

> **预习**：
[C 数据类型](https://www.runoob.com/cprogramming/c-data-types.html)
[C 变量](https://www.runoob.com/cprogramming/c-variables.html)
[C 常量](https://www.runoob.com/cprogramming/c-constants.html)
**练习**：
[NOI 1.1 编程基础之输入输出](http://noi.openjudge.cn/ch0101/)
[NOI 1.2 编程基础之变量定义、赋值及转换](http://noi.openjudge.cn/ch0102/)



在 C 中，有以下几种基本数据类型：

## 整型

| 类型 | 字节数 | signed | unsigned |
|:-:|:-:|:-:|:-:|
| `short`    | 2      | \(-2^{15}\) 到 \(2^{15} - 1\) `%hd`  | 0 到 \(2^{16} - 1\) `%hu` |
| `int`      | 4      | \(-2^{31}\) 到 \(2^{31} - 1\) `%d`  | 0 到 \(2^{32} - 1\) `%u` |
| `long long`| 8      | \(-2^{63}\) 到 \(2^{63} - 1\) `%lld`  | 0 到 \(2^{64} - 1\) `%llu`|

特别的，为了兼容性，有了精确宽度整数类型（exact-width integers types）的定义。

`#include <stdint.h>`

| 类型 | 字节数 | signed | unsigned |
|:-:|:-:|:-:|:-:|
|`int8_t`|1| \(-2^{7}\) 到 \(2^{7} - 1\) | 0 到 \(2^{8} - 1\) |
|`int16_t`|2| \(-2^{15}\) 到 \(2^{15} - 1\) | 0 到 \(2^{16} - 1\) |
|`int32_t`|4| \(-2^{31}\) 到 \(2^{31} - 1\) | 0 到 \(2^{32} - 1\) |
|`int64_t`|8| \(-2^{63}\) 到 \(2^{63} - 1\) | 0 到 \(2^{64} - 1\) |

特别的，GCC编译器还支持 `__int128_t` 类型，即128位整型。

遗憾的，因为是编译器扩展，所以不是标准的C语言，无法直接 printf。

## 浮点型

| 类型 | 字节数 | 精度 | 格式化 |
|:-:|:-:|:-:|:-:|
| `float`    | 4      | $10^{-7}$ | `%f` |
| `double`   | 8      | $10^{-15}$ | `%lf` |

## 字符型

| 类型 | 字节数 | 格式化 |
|:-:|:-:|:-:|
| `char` | 1 | `%c` |

常用的 ASCII 码表：

| 字符 | ASCII 码 |
|:-:|:-:|
| `\0`| 0 |
| `0` | 48 |
| `A` | 65 |
| `a` | 97 |

## 指针

指针也是一种数据类型，它用于存储内存地址。

| 类型 | 字节数 | 格式化 |
|:-:|:-:|:-:|
| `void *` | 8 | `%p` |

和其他数据类型一样
* `int` 存储数字
* `char` 存储字符
* `double` 存储浮点数
* **`void *` 存储内存地址**

**那为何有 `char *`、`int *`、`double *` 等类型呢？**
**指明指针指向的数据类型：**
1. 指针的算术操作
    不同类型的指针运算时，步长不同。
    * `char` 占用 1 字节， `char *` 步长为 1。
        ```cpp
        char c = '6';   // c 的地址为 0xa
        char *p = c;    // p 的 值 为 0xa
        p = p + 1;      // p 的 值 为 0xb
        ```

    * `int` 占用 4 字节， `int *` 步长为 4。
        ```cpp
        int i = 6;      // i 的地址为 0x1
        int *p = i;     // p 的 值 为 0x1
        p = p + 1;      // p 的 值 为 0x5
        ```

2. 类型安全
    编译器会在编译时检查指针的类型，
    从而避免不同类型的指针直接赋值或比较，
    确保了在程序中正确使用指针。

```c
#include <stdio.h>

int main(){
    char c = '6';
    char t = '?';
    char *p = &c;

    // 变量 c 的值
    // 变量 c 的地址
    // 指针 p 的值
    // 指针 p 的地址
    // 通过指针 p 访问变量 c 的值
	puts("c的地址 和 p的值，都是一样的 | *p 就是 c的值");
    printf("\nc                &c               p                &p               *p\n");
    printf("%-16c %-16p %-16p %-16p %-16c\n\n", c, &c, p, &p, *p);

	puts("c+1的地址 和 p+1的值，都是一样的 | *p+1 就是 t的值");

    printf("\nc                &c+1             p+1              &p+1             *(p+1)\n");
    printf("%-16c %-16p %-16p %-16p %-16c\n\n", c, &c+1, p+1, &p+1, *(p+1));

	puts("输入一个数，到 p+1 的值里面去：");
    scanf("%c", p+1);
	puts("c+1的地址 和 p+1的值，都是一样的 | *p+1 就是 t的值");

    printf("\nc                &c+1             p+1              &p+1             *(p+1)\n");
    printf("%-16c %-16p %-16p %-16p %-16c\n\n", c, &c+1, p+1, &p+1, *(p+1));

	puts("输出t的值：");

    printf("%c", t);
}
```

## 聚合类型

聚合类型是由多个基本类型组成的数据类型。

**数组**

数组的本质是一段连续的内存空间，数组名是数组首元素的地址。

```c
int a[100];         // 定义一个大小为 100 的数组
int b[] = {1,2,3,4};// 定义一个大小为 4 的数组，元素为 1,2,3,4
int c[100] = {1};   // 定义一个大小为 100 的数组，第一个元素为 1，其他元素为 0
```

**结构体**

* 数组：多个 **相同** 元素的集合
* 结构体：多个 **不同** 的元素的集合

```c
struct PII{
	int fst;
	int sed;
};

PII a;              // 定义一个结构体变量
PII b[10];          // 定义一个结构体数组      
```

```c
a.fst = 1;          // 访问结构体变量的成员
scanf("%d", &a.fst);// 输入结构体变量的成员
```

**联合体**

联合体是一种特殊的结构体，它的所有成员共用一段内存空间。
内存空间的大小为最大成员的大小。

```c
union UIC{
    int x;
    char y;
};

UIC a;               // 定义一个联合体变量
UIC b[10];           // 定义一个联合体数组
```

在 `UIC` 中，`x` 和 `y` 共用一段内存空间，它们的地址是一样的。
内存空间的大小为 `sizeof(int)`

```c
a.x = 1;             // 访问联合体变量的成员
scanf("%d", &a.x);   // 输入联合体变量的成员
```

C，就是一个玩地址的语言。

```c
#include <stdio.h>

union UIC {
	int x;
	char y;
};

int main() {
	UIC a;              // 定义一个联合体变量，开辟 4 个字节的内存空间
	char* p = &(a.y);   // 指针 p 指向联合体变量的第一个字节

	p[0] = 'A';	// 0100 0001
	p[1] = 'A';
	p[2] = 'A';
	p[3] = 'A';

	printf("%d", a.x);  // 1094795585
	return 0;
}
```

<br>

---

# 基本数据运算

> **预习**：
[C 运算符](https://www.runoob.com/cprogramming/c-operators.html)
**练习**：
[NOI 1.3 编程基础之算术表达式与顺序执行](http://noi.openjudge.cn/ch0103/)


> 选择最合适的数据类型参与运算

**注意！**

* 小数在参与运算时，会存在 **浮点误差**，导致结果不准确。
    例如，`1.0` 被保存为 `1.0000000000000002`。
    在 `float` 类型中，尤为明显。追求精确的计算，尽量使用 `double` 类型。

## 算术运算

**`+`** **`-`** **`*`** **`/`** **`%`**

* 注意操作数的数据范围，防止溢出。
* 注意除数为 0 的情况。
* 注意字符型和整型的转换。

**`++`** 

* `a++` / `a--`，先使用 `a` 的值，再对 `a` 进行自增/自减。
* `++a` / `--a`，先对 `a` 进行自增/自减，再使用 `a` 的值。

## 关系运算

**`>`** **`<`** **`>=`** **`<=`** **`==`** **`!=`**

* 小数在进行比较时，需要限定精度进行比较
* 字符型和整型的比较，会先将字符型转换为整型，再进行比较。

## 逻辑运算

**`&&`** **`||`** **`!`**

* 逻辑运算的结果是 `0` 或 `1`，可以和整型进行运算。
* 逻辑运算的短路特性。

## 位运算

* 位运算的操作数必须是整型。

**`<<`**

* `a << b`，将 `a` 的二进制表示左移 `b` 位，右边空出的位用 `0` 填充。
* `a << b`，相当于 `a * 2^b`。

**`>>`**
* **值得注意！**
    `-5 >> 1` 的结果是 `-3`，而不是 `-2`。
    因为 `-5` 的二进制表示为 `1111 1111 1111 1111 1111 1111 1111 1011`
    右移一位后，变成了 `1111 1111 1111 1111 1111 1111 1111 1101`，即 `-3`。
    因此，并不是简单的除以 `2`。


## 赋值运算

**`+=`** **`-=`** **`*=`** **`/=`** **`%=`** **`<<=`** **`>>=`**

简单写法罢了。

<br>

---


# 分支结构

> **预习**：
[C 判断](https://www.runoob.com/cprogramming/c-decision.html)
**练习**：
[luogu 分支结构](https://www.luogu.com.cn/training/101#problems)
[NOI 1.4 编程基础之逻辑表达式与条件分支](http://noi.openjudge.cn/ch0104/)

# 循环结构

> **预习**：
[C 循环](https://www.runoob.com/cprogramming/c-loops.html)
**练习**：
[luogu 循环结构](https://www.luogu.com.cn/training/102#problems)
[NOI 1.5 编程基础之循环结构](http://noi.openjudge.cn/ch0105/)





# Memory Areas

C 在程序执行时，将内存大致分为 **代码区**，**全局区**，**栈区**，**堆区** 四个区域。
不同的区域存储不同的数据，赋予不同的 **生命周期**，能够更灵活地进行编程。

## Code Segment

代码区，简单来说，就是存放 **执行指令** 的地方。
代码区是只读的，不允许修改。
当一个 `.c` 文件，开始运行时，从 `ROM` 加载到 `RAM`，成为代码区。

## Data Segment

数据区（常量区），用来存储 **静态变量**、**全局变量**、**静态数据**。
在这个区域中，数据的大小和结构在程序编译时就已经确定。

1. **全局变量：** 如果你在程序中定义了一个全局变量，它会被存储在数据段中。例如：
   
   ```c
   int globalVar = 10;
   ```
   
   在这个例子中，`globalVar`是一个全局变量，它的初始值为10，会被存储在数据段中。

2. **静态变量：** 静态变量（包括静态全局变量和静态局部变量）也会被存储在数据段中。例如：

   ```c
   void function() {
       static int staticVar = 5;
   }
   ```
   
   在这个例子中，`staticVar`是一个静态局部变量，它的值在函数调用之间保持不变，存储在数据段中。

3. **常量：** 字符串常量和其他常量数据也被存储在数据段中。例如：

   ```c
   const char hello[] = "Hello, World!";
   ```

   在这个例子中，字符串常量"Hello, World!"会被存储在数据段中，而`hello`数组则会在栈或堆上分配内存，存储在数据段中的地址。

## Stack


```c
#include <stdio.h>

int *p;

void a(){
    int x = 666;

    p = &x;

    printf("a函数 y:\n%d %p\n", x, &x);
}

void b(){
    int y = 888; 
    printf("b函数 y:\n%d %p\n", y, &y);
}

int main(){
    a();

    printf("主函数 p:\n%d %p\n", *p, p);
    
    b();
    printf("主函数 p:\n%d %p\n", *p, p);
    
    return 0;
}
```


## Heap


```cpp
#include <stdio.h>

int *p;

void a(){
    int* x = new int(666);

    p = x;

    printf("a函数 y:\n%d %p\n", *x, x);

    // 手动释放内存
    // delete x;
}

void b(){
    int* y = new int(888); 
    printf("b函数 y:\n%d %p\n", *y, y);
}

int main(){
    a();

    printf("主函数 p:\n%d %p\n", *p, p);
    
    b();
    printf("主函数 p:\n%d %p\n", *p, p);
    
    return 0;
}
```

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
    g++ -std=c++23 ac.cpp -o ac
    ```
    * `-std=c++23` 选项指定了 C++ 标准，这里是 C++23 标准。

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

    # 指定项目名称
    project(JiaoProject)

    # 添加可执行文件
    add_executable(JiaoProject main.cpp)
    ```

2. **编译：**
    ```sh
    cmake --build build
    ```
    * `--build` 选项指定构建目标，这里是 `build` 目录。

<br>

---


## Boost

Boost 是一个跨平台的C++库，提供了许多重要的系统工具和应用程序。

1. 下载 [Boost](https://www.boost.org/users/download/)

2. 解压到 `~/Desktop/boost_*`

3. 进入解压后的目录，执行 `./bootstrap.sh`
    * 编译前的配置工作

4. 执行 `sudo ./b2 install`
    * 编译安装

5. 测试
    ```cpp
    #include <boost/version.hpp>//包含 Boost 头文件
    #include <boost/config.hpp> //包含 Boost 头文件
    #include <iostream>

    using namespace std;
    int main(){
        cout << BOOST_VERSION << endl;      // Boost 版本号
        cout << BOOST_LIB_VERSION << endl;  // Boost 版本号
        cout << BOOST_PLATFORM << endl;     // 操作系统
        cout << BOOST_COMPILER << endl;     // 编译器
        cout << BOOST_STDLIB << endl;       // 标准库
        return 0;
    }
    ```

<br>

---

## Perf

Perf 是一个性能分析工具，可以用于分析程序的性能瓶颈。

1. **安装 perf**
    ```sh
    sudo apt install linux-tools-common linux-tools-generic linux-tools-`uname -r`
    ```
    * `linux-tools-common`：Linux 性能分析工具的公共文件。
    * `linux-tools-generic`：Linux 性能分析工具的通用文件。
    * `linux-tools-<version>`：Linux 性能分析工具的内核版本文件。
        * `uname -r` 命令用于查看内核版本。

    ```sh
    perf -v # 验证是否安装成功
    ```

2. **下载 FlameGraph**
    

    FlameGraph 是一个生成火焰图的工具。

    ```sh
    git clone https://github.com/brendangregg/FlameGraph.git
    ```

3. **使用** 

    ```sh
    sudo perf record -g ./a.out sleep 10
    ```

    * `perf record` 命令用于记录性能数据。
    * `-g` 选项用于记录调用图。
    * `./a.out` 需要记录性能的程序。
    * `sleep 10` 程序运行 10 秒。

    ```sh
    sudo perf script -i perf.data &> perf.unfold 
    ```

    * `perf script` 命令用于将性能数据转换为可读的格式。
    * `-i` 选项用于指定输入文件。
    * `perf.data` 是性能数据文件。
    * `&> perf.unfold` 用于将输出重定向到 `perf.unfold` 文件。

    ```sh
    sudo FlameGraph/stackcollapse-perf.pl perf.unfold &> perf.folded
    ```

    * `stackcollapse-perf.pl` 命令用于将性能数据转换为火焰图的输入格式。
    * `perf.unfold` 是性能数据文件。
    * `&> perf.folded` 用于将输出重定向到 `perf.folded` 文件。

    ```sh
    sudo FlameGraph/flamegraph.pl perf.folded > perf.svg
    ```

    * `flamegraph.pl` 命令用于生成火焰图。
    * `perf.folded` 是火焰图需要的性能数据文件。
    * `> perf.svg` 用于将输出重定向到 `perf.svg` 文件。


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