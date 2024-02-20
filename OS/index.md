---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

全文分为两个部分：

1. 黑书的实验题
2. 操作系统的笔记 / 王道习题

书籍参考：

* 《操作系统概念/原书第10版》机械工业出版社
* 《操作系统 王道2025》

编程环境：

* `Ubuntu 22.04 LTS` [下载](https://ubuntu.com/download/desktop)
* `gcc 11.4.0`

源码参考：

* [osc10e](https://github.com/greggagne/osc10e)
* [此文源码]()

**注意!**

* 除非你知道你在做什么，否则不要在生产环境中使用这些 **代码** / **命令**
    强烈建议新开一个 [虚拟机](https://www.vmware.com/products/workstation-pro/workstation-pro-evaluation.html) 进行实验


---

# 编程题

## 2.24

```cpp
// FileCopy.cpp
#include <fcntl.h>  // open
#include <unistd.h> // read write
#include <string.h> // memset
#include <iostream> // std::cerr

int main(int argc, char *argv[]) {
    if(argc != 3){
        std::cerr << "请输入源文件和目标文件的名称" << std::endl;
        return 1;
    }

    // 以只读的方式打开
    int fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1){
        std::cerr << "打开源文件失败" << std::endl;
        return 1;
    }

    // 以只写的方式打开，如果不存在则创建，如果存在则清空，权限为 666
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fd2 == -1){
        std::cerr << "打开目标文件失败" << std::endl;
        return 1;
    }

    char buffer[64];
    while(true){
        memset(buffer, '\0', sizeof buffer);
        int len = read(fd1, buffer, sizeof buffer);
        
        if(len == -1){
            std::cerr << "读取文件失败" << std::endl;
            return 1;
        }

        if(len == 0) break;

        if(write(fd2, buffer, len) == -1){
            std::cerr << "写入文件失败" << std::endl;
            return 1;
        }
    };
    
    return 0;
}
```

* 可以通过 `man open`，`man read` 等命令查看函数的使用方法

**运行**：

1. 编译源文件 `g++ FileCopy.cpp -o FileCopy`
2. 运行 `./FileCopy FileCopy.cpp FileCopy.cpp.bak`
3. 查看文件 `cat FileCopy.cpp.bak`
    * 与 `FileCopy.cpp` 一致
4. 使用系统调用跟踪工具 `strace ./FileCopy FileCopy.cpp FileCopy.cpp.bak`
    * 可以看到系统调用的详细信息

<br>

---

# 编程项目

## 2.17

**加载与卸载内核模块**

进入 `ch2` 目录

> 我将 `simple.c` 中的 `printk` 的输出分别改为 `内核加载`，`内核卸载`，以便区分

1. 编译 `make`
    * 生成 `simple.ko` 内核模块

2. 加载内核模块 `sudo insmod simple.ko`
    * 查看内核模块 `lsmod`
    * 可以看到 `simple` 模块

3. 查看内核日志缓冲区 `sudo dmesg`
    * 可以看到 `内核加载`
    * 删除内核日志缓冲区 `sudo dmesg -c`

4. 卸载内核模块 `sudo rmmod simple`
    * 查看内核模块 `lsmod`
    * 无 `simple` 模块

5. 查看内核日志缓冲区 `dmesg`
    * 可以看到 `内核卸载`

<br>

**输出内核模块从加载到卸载的时间**

```cpp
// simple.c
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/jiffies.h>
unsigned long cnt=0;

/* This function is called when the module is loaded. */
static int simple_init(void)
{
       cnt = jiffies;
       printk(KERN_INFO "加载内核:%lu %d\n", cnt, HZ);
       return 0;
}

/* This function is called when the module is removed. */
static void simple_exit(void) {
        cnt = (jiffies-cnt)/HZ;
        printk(KERN_INFO "卸载内核:%lu\n", cnt);
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
```

<br>

## 2.17 - 1




<br>

## 2.17 - 2