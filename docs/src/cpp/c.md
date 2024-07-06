## 异常处理

```c
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// 定义宏 ERRIF，自动计算可变参数的数量
#define ERRIF(flg, ...) do { \
    if (flg == 1){ \
        fprintf(stderr, __VA_ARGS__); \
        fprintf(stderr, "\nerrno[%d]: %s\n", errno, strerror(errno)); \
        exit(1); \
    } \
} while (0)

int main(){
    FILE* file = fopen("test.txt", "r");
    ERRIF(file == NULL, "%s 打开错误", "test.txt"); // 使用示例
    return 0;
}
```

| errno | errno | strerror                                 | note                          |
|-------|-------|------------------------------------------|-------------------------------|
| 1     | EPERM | Operation not permitted                  | 无权操作                      |
| 2     | ENOENT| No such file or directory                | 无此文件或目录                |
| 3     | ESRCH | No such process                          | 无此进程                      |
| 4     | EINTR | Interrupted system call                  | 系统调用中断 <br> `ctrl+c`            |
| 5     | EIO   | I/O error                                | 输入/输出错误                 |
| 6     | ENXIO | No such device or address                | 无此设备或地址                |
| 7     | E2BIG | Argument list too long                   | 参数列表过长                  |
| 8     | ENOEXEC| Exec format error                       | 执行格式错误                  |
| 9     | EBADF | Bad file number                          | 错误文件描述符                 |
| 10    | ECHILD| No child processes                       | 无子进程                      |
| 11    | EAGAIN| Try again                                | 再试 <br> 在 `socket` 中，非阻塞下无数据可读 |
| 12    | ENOMEM| Out of memory                            | 内存不足                      |
| 13    | EACCES| Permission denied                        | 权限被拒绝                    |
| 14    | EFAULT| Bad address                              | 坏地址                        |
| 15    | ENOTBLK| Block device required                   | 需要块设备                    |
| 16    | EBUSY | Device or resource busy                  | 设备或资源忙                  |
| 17    | EEXIST| File exists                              | 文件存在                      |
| 18    | EXDEV | Cross-device link                        | 跨设备链接                    |
| 19    | ENODEV| No such device                           | 无此设备                      |
| 20    | ENOTDIR| Not a directory                         | 非目录                        |
| 21    | EISDIR| Is a directory                           | 是目录                        |
| 22    | EINVAL| Invalid argument                         | 无效参数                      |
| 23    | ENFILE| File table overflow                      | 文件表溢出                    |
| 24    | EMFILE| Too many open files                      | 打开的文件过多                |
| 25    | ENOTTY| Not a typewriter                         | 不是打字机                    |
| 26    | ETXTBSY| Text file busy                          | 文本文件忙                    |
| 27    | EFBIG | File too large                           | 文件太大                      |
| 28    | ENOSPC| No space left on device                  | 设备上无空间                  |
| 29    | ESPIPE| Illegal seek                             | 非法寻道                      |
| 30    | EROFS | Read-only file system                    | 只读文件系统                  |
| 31    | EMLINK| Too many links                           | 链接数过多                    |
| 32    | EPIPE | Broken pipe                              | 管道破裂                      |
| 33    | EDOM  | Math argument out of domain of func      | 数学参数超出函数域            |
| 34    | ERANGE| Math result not representable            | 数学结果不可表示              |
| 35    | EDEADLK| Resource deadlock would occur           | 资源死锁会发生                |
| 36    | ENAMETOOLONG| File name too long                 | 文件名过长                    |
| 37    | ENOLCK| No record locks available                | 无记录锁可用                  |
| 38    | ENOSYS| Invalid system call number               | 无效的系统调用号              |
| 39    | ENOTEMPTY| Directory not empty                   | 目录不空                      |
| 40    | ELOOP | Too many symbolic links encountered      | 符号链接过多                  |
| 42    | ENOMSG| No message of desired type               | 无所需类型的消息              |
| 43    | EIDRM | Identifier removed                       | 标识符已移除                  |
| 44    | ECHRNG| Channel number out of range              | 通道号超出范围                |
| 45    | EL2NSYNC| Level 2 not synchronized               | 2级不同步                     |
| 46    | EL3HLT| Level 3 halted                           | 3级停止                       |
| 47    | EL3RST| Level 3 reset                            | 3级重置                       |
| 48    | ELNRNG| Link number out of range                 | 链接号超出范围                |
| 49    | EUNATCH| Protocol driver not attached            | 协议驱动程序未连接            |
| 50    | ENOCSI| No CSI structure available               | 无CSI结构可用                 |
| 51    | EL2HLT| Level 2 halted                           | 2级停止                       |
| 52    | EBADE | Invalid exchange                         | 无效交换                      |
| 53    | EBADR | Invalid request descriptor               | 无效请求描述符                |
| 54    | EXFULL| Exchange full                            | 交换满                        |
| 55    | ENOANO| No anode                                 | 无阳极                        |
| 56    | EBADRQC| Invalid request code                    | 无效请求代码                  |
| 57    | EBADSLT| Invalid slot                            | 无效插槽                      |
| 59    | EBFONT| Bad font file format                     | 坏字体文件格式                |
| 60    | ENOSTR| Device not a stream                      | 设备不是流                    |
| 61    | ENODATA| No data available                       | 无数据可用                    |
| 62    | ETIME | Timer expired                            | 计时器已到期                  |
| 63    | ENOSR | Out of streams resources                 | 流资源耗尽                    |
| 64    | ENONET| Machine is not on the network            | 机器不在网络上                |
| 65    | ENOPKG| Package not installed                    | 未安装软件包                  |
| 66    | EREMOTE| Object is remote                        | 对象是远程的                  |
| 67    | ENOLINK| Link has been severed                   | 链接已断开                    |
| 68    | EADV  | Advertise error                          | 广告错误                      |
| 69    | ESRMNT| Srmount error                            | Srmount错误                   |
| 70    | ECOMM | Communication error on send              | 发送时通信错误                |
| 71    | EPROTO| Protocol error                           | 协议错误                      |
| 72    | EMULTIHOP| Multihop attempted                    | 尝试多跳                      |
| 73    | EDOTDOT| RFS specific error                      | RFS特定错误                   |
| 74    | EBADMSG| Not a data message                      | 不是数据消息                  |
| 75    | EOVERFLOW| Value too large for defined data type | 值对于定义的数据类型太大      |
| 76    | ENOTUNIQ| Name not unique on network             | 网络上名称不唯一              |
| 77    | EBADFD| File descriptor in bad state             | 文件描述符状态错误            |
| 78    | EREMCHG| Remote address changed                  | 远程地址已更改                |
| 79    | ELIBACC| Can not access a needed shared library  | 无法访问所需的共享库          |
| 80    | ELIBBAD| Accessing a corrupted shared library    | 访问损坏的共享库              |
| 81    | ELIBSCN| .lib section in a.out corrupted         | .lib段在a.out中损坏           |
| 82    | ELIBMAX| Attempting to link in too many shared libraries | 尝试链接太多共享库    |
| 83    | ELIBEXEC| Cannot exec a shared library directly  | 无法直接执行共享库            |
| 84    | EILSEQ| Illegal byte sequence                    | 非法字节序列                  |
| 85    | ERESTART| Interrupted system call should be restarted | 中断的系统调用应重新启动 |
| 86    | ESTRPIPE| Streams pipe error                     | 流管错误                      |
| 87    | EUSERS| Too many users                           | 用户过多                      |
| 88    | ENOTSOCK| Socket operation on non-socket         | 非套接字上的套接字操作        |
| 89    | EDESTADDRREQ| Destination address required       | 需要目的地址                  |
| 90    | EMSGSIZE| Message too long                       | 消息过长                      |
| 91    | EPROTOTYPE| Protocol wrong type for socket       | 协议套接字类型错误            |
| 92    | ENOPROTOOPT| Protocol not available              | 协议不可用                    |
| 93    | EPROTONOSUPPORT| Protocol not supported          | 不支持协议                    |
| 94    | ESOCKTNOSUPPORT| Socket type not supported       | 不支持的套接字类型            |
| 95    | EOPNOTSUPP| Operation not supported on transport endpoint | 传输终点不支持的操作 |
| 96    | EPFNOSUPPORT| Protocol family not supported      | 不支持的协议族                |
| 97    | EAFNOSUPPORT| Address family not supported by protocol | 协议不支持的地址族    |
| 98    | EADDRINUSE| Address already in use               | 地址已在使用                  |
| 99    | EADDRNOTAVAIL| Cannot assign requested address   | 无法分配请求的地址            |
| 100   | ENETDOWN| Network is down                        | 网络不可用                    |
| 101   | ENETUNREACH| Network is unreachable              | 网络无法访问                  |
| 102   | ENETRESET| Network dropped connection because of reset | 网络因重置而断开连接    |
| 103   | ECONNABORTED| Software caused connection abort   | 软件导致的连接中止            |
| 104   | ECONNRESET| Connection reset by peer             | 对等方重置连接                |
| 105   | ENOBUFS| No buffer space available               | 无可用缓冲区                  |
| 106   | EISCONN| Transport endpoint is already connected | 传输终点已连接                |
| 107   | ENOTCONN| Transport endpoint is not connected    | 传输终点未连接                |
| 108   | ESHUTDOWN| Cannot send after transport endpoint shutdown | 终点关闭后无法发送    |
| 109   | ETOOMANYREFS| Too many references: cannot splice | 引用过多：无法拼接            |
| 110   | ETIMEDOUT| Connection timed out                  | 连接超时                      |
| 111   | ECONNREFUSED| Connection refused                 | 连接被拒绝                    |
| 112   | EHOSTDOWN| Host is down                          | 主机不可用                    |
| 113   | EHOSTUNREACH| No route to host                   | 无路由到主机                  |
| 114   | EALREADY| Operation already in progress          | 操作已在进行中                |
| 115   | EINPROGRESS| Operation now in progress           | 操作正在进行中                |
| 116   | ESTALE| Stale file handle                        | 陈旧的文件句柄                |
| 117   | EUCLEAN| Structure needs cleaning                | 结构需要清理                  |
| 118   | ENOTNAM| Not a XENIX named type file             | 不是XENIX命名类型文件         |
| 119   | ENAVAIL| No XENIX semaphores available           | 无XENIX信号量可用             |
| 120   | EISNAM| Is a named type file                     | 是命名类型文件                |
| 121   | EREMOTEIO| Remote I/O error                      | 远程I/O错误                   |
| 122   | EDQUOT| Quota exceeded                           | 超出配额                      |
| 123   | ENOMEDIUM  | No medium found                      | 未找到介质                 |
| 124   | EMEDIUMTYPE| Wrong medium type                    | 错误的介质类型             |
| 125   | ECANCELED  | Operation Canceled                   | 操作被取消                 |
| 126   | ENOKEY     | Required key not available           | 所需密钥不可用             |
| 127   | EKEYEXPIRED| Key has expired                      | 密钥已过期                 |
| 128   | EKEYREVOKED| Key has been revoked                 | 密钥已被撤销               |
| 129   | EKEYREJECTED| Key was rejected by service         | 密钥被服务拒绝             |
| 130   | EOWNERDEAD | Owner died                           | 拥有者已死亡               |
| 131   | ENOTRECOVERABLE| State not recoverable           | 状态不可恢复               |
| 132   | ERFKILL    | Operation not possible due to RF-kill| 由于RF-kill不可能进行操作  |
| 133   | EHWPOISON  | Memory page has hardware error       | 内存页面存在硬件错误       |

**perror**

使用 `perror` 输出错误信息到 `stderr`

```c
perror("Error opening file");
// Error opening file: No such file or directory
```

**stderr**

使用 `fprintf` 和 `strerror` 结合输出到 `stderr`

```c
fprintf(stderr, "Error opening file: %s\n", strerror(errno));
// Error opening file: No such file or directory
```

**errno**

一个全局变量，在程序运行过程中会被标准库函数设置为不同的值，以表示不同类型的错误

<br>

---




## 基本数据类型

**整型**

<center>

| type | byte | signed | unsigned |
|:-:|:-:|:-:|:-:|
| `short int`| 2      | \(-2^{15}\) ~ \(2^{15} - 1\) `%hd`  | 0 ~ \(2^{16} - 1\) `%hu` |
| `int`      | 4      | \(-2^{31}\) ~ \(2^{31} - 1\) `%d`  | 0 ~ \(2^{32} - 1\) `%u` |
| `long int` | 8      | \(-2^{63}\) ~ \(2^{63} - 1\) `%ld`  | 0 ~ \(2^{64} - 1\) `%lu`|
| `long long int` | 8      | \(-2^{63}\) ~ \(2^{63} - 1\) `%lld`  | 0 ~ \(2^{64} - 1\) `%llu`|

</center>

历史遗留问题，在不同的平台上，以上类型的长度无法统一

<br>

**精确宽度整数类型**（exact-width integers types）

`#include <stdint.h>`

<center>

| type | byte | signed | unsigned |
|:-:|:-:|:-:|:-:|
|`int8_t` |1| \(-2^{7}\) ~ \(2^{7} - 1\)         | 0 ~ \(2^{8} - 1\) |
|`int16_t`|2| \(-2^{15}\) ~ \(2^{15} - 1\) `%hd` | 0 ~ \(2^{16} - 1\) `%hu`|
|`int32_t`|4| \(-2^{31}\) ~ \(2^{31} - 1\) `%d`  | 0 ~ \(2^{32} - 1\) `%u`|
|`int64_t`|8| \(-2^{63}\) ~ \(2^{63} - 1\) `%ld` | 0 ~ \(2^{64} - 1\) `%lu`|

</center>

值得一提，`int8_t` 是一个 `char` 类型，使用 `cout` 输出需要处理一下

<br>

**最大对象的字节数** `size_t`

`#include <stddef.h>`

<center>

| 平台 | byte | 本质 | range |
|:-:|:-:|:-:|:-:|
| 32 | 4 | `uint32_t size_t` | 0 ~ \(2^{32} - 1\) `%u`|
| 64 | 8 | `uint64_t size_t` | 0 ~ \(2^{64} - 1\) `%lu`|

</center>

<br>

**指针**

指针也是一种数据类型，它用于存储内存地址

<center>

| type | byte | format |
|:-:|:-:|:-:|
| `void*` | 8 | `%p` |

</center>

和其他数据类型一样

* `int` 存储数字

* `char` 存储字符

* `double` 存储浮点数

* **`void*` 存储内存地址**


> **那为何有 `char*`、`int*`、`double*` 等类型呢？**
**指明指针指向的数据类型：**

1. 指针的算术操作

    不同类型的指针运算时，步长不同

    * `char` 占用 1 字节， `char*` 步长为 1。
        ```cpp
        char c = '6';
        char *p = &c;               // p   == 0x0
        printf("%p\n%p", p, p+1);   // p+1 == 0x1
        ```

    * `int32_t` 占用 4 字节， `int32_t*` 步长为 4
        ```cpp
        int32_t i = 6;
        int32_t *p = &i;            // p   == 0x0
        printf("%p\n%p", p, p+1);   // p+1 == 0x4
        ```

2. 类型安全

    编译器会在编译时检查指针的类型，从而避免不同类型的指针直接赋值或比较，确保了在程序中正确使用指针

    ```c
    todo
    ```

<br>

---

## 内存管理

`#include <stdlib.h>`

**申请内存**

`void* malloc(size_t size)`

* 申请 `size` 字节的空间，返回指向这片空间的指针

* 申请失败返回 `NULL`

<br>

**释放内存**

`void free(void *ptr)`

* 释放 `ptr` 指向的内存空间

<br>

---

## 文件操作

此处只整理二进制的方法

**打开文件**

`FILE* fopen(const char* filename, const char* mode)`

* 失败返回 `NULL`

<center>

| type | read | write | add | create | clean | note |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| `rb`  | 🟢 |    |    |
| `wb`  |    | 🟢 |    | 🟢 | 🟢 | 覆盖写入 |
| `ab`  |    |    | 🟢 | 🟢 |    |
| `rb+` | 🟢 | 🟢 |    |    |     | 文首插入 |
| `wb+` | 🟢 | 🟢 |    | 🟢 | 🟢 | 覆盖写入 |
| `ab+` | 🟢 |    | 🟢 | 🟢 |    | 文末追加 |

</center>

**关闭文件**

`int fclose(FILE *fp)`

* 成功返回 `0`

**文件定位**

`int fseek(FILE* fptr, long int offset, int whence)`

* `whence`：偏移起始位

    * `SEEK_SET`：文件开头

    * `SEEK_CUR`：当前位置

    * `SEEK_END`：文件末尾

* `offset`：偏移量

* 成功返回 `0`

**偏移量读取**

`long int ftell(FILE* fptr);`

* 失败返回 `-1`

**读取文件**

`size_t fread(void* ptr, size_t size_of_elements, size_t number_of_elements, FILE* fptr)`

* `ptr`：保存内存位置

* `size_of_elements`：每个元素的大小

* `number_of_elements`：元素的数量

* `fptr`：文件指针

* 成功返回 `number_of_elements`

**写入文件**

``size_t fwrite(void* ptr, size_t size_of_elements, size_t number_of_elements, FILE* fptr)``

* 成功返回 `number_of_elements`


<br>

**分段读取**

```cpp
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MBLOCK 1024 // 1kb

int8_t ERRIF(int8_t flg, const char* msg){
    if(flg == 1){
        perror(msg);
        exit(1);
    }
    return 1;
}

int main(char arg, char* argc[]){
    FILE* fptr_in = fopen(argc[1], "rb");
    ERRIF(fptr_in == NULL, "打开输入文件错误");
    
    FILE* fptr_out = fopen(argc[2], "wb"); 
    ERRIF(fptr_out == NULL, "打开输出文件错误");

    char* ptr = malloc(MBLOCK);
    ERRIF(ptr == NULL, "内存申请失败");

    fseek(fptr_in, 0, SEEK_END);
    size_t flen = ftell(fptr_in);   // 文件大小

    for(size_t i=0; i<flen; i+=MBLOCK){
        fseek(fptr_in, i, SEEK_SET);
        size_t len = i+MBLOCK > flen ? flen-i : MBLOCK;
        printf("%lu\n", len);

        size_t read_len = fread(ptr, 1, len, fptr_in);
        ERRIF(read_len != len, "写入内存错误");
        // deal();

        size_t write_len = fwrite(ptr, 1, len, fptr_out);
        ERRIF(write_len != len, "写入文件错误");
    }

    free(ptr);
    fclose(fptr_out);
    fclose(fptr_in);
    return 0;
}
```

