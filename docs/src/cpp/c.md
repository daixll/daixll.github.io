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
| `void *` | 8 | `%p` |

</center>

和其他数据类型一样

* `int` 存储数字

* `char` 存储字符

* `double` 存储浮点数

* **`void *` 存储内存地址**


> **那为何有 `char *`、`int *`、`double *` 等类型呢？**
**指明指针指向的数据类型：**

1. 指针的算术操作

    不同类型的指针运算时，步长不同

    * `char` 占用 1 字节， `char *` 步长为 1。
        ```cpp
        char c = '6';   // c 的地址为 0xa
        char *p = c;    // p 的 值 为 0xa
        p = p + 1;      // p 的 值 为 0xb
        ```

    * `int` 占用 4 字节， `int *` 步长为 4
        ```cpp
        int i = 6;      // i 的地址为 0x1
        int *p = i;     // p 的 值 为 0x1
        p = p + 1;      // p 的 值 为 0x5
        ```

2. 类型安全

    编译器会在编译时检查指针的类型，从而避免不同类型的指针直接赋值或比较，确保了在程序中正确使用指针

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


<br>

---

## 异常处理