[官网](https://ffmpeg.org/) | [下载](https://ffmpeg.org/download.html) | [文档](https://ffmpeg.org/documentation.html)

## setup

### linux

1. 下载 `wget` / 解压 `tar -xvf` / 提权 `chmod +x`

2. 下载编译工具 `sudo apt install nasm pkg-config`

3. 配置安装选项 `./configure --prefix=/.../FFmpeg-x.y.z`

4. 编译安装 `make && make install`

5. 编写测试代码
    ```cpp
    #define __STDC_CONSTANT_MACROS

    extern "C" {
    #include <libavutil/avutil.h>
    }
    #include <iostream>

    int main(){
        std::cout << av_version_info() << std::endl;
        return 0;
    }
    ```

6. 编译
    ```bash
    g++ -std=c++20 -O2 -g a.cpp -I/.../FFmpeg-7.0.1/include -L/.../FFmpeg-7.0.1/lib -o a -lavutil
    ```

### windows

<br>

---

## use



<br>

---

## dev

