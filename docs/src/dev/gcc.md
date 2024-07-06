
* **安装**

    1. 下载 [mingw-w64](https://github.com/niXman/mingw-builds-binaries/releases) `x86_64` `posix` `seh` `ucrt`

    2. 解压

    3. 添加至环境变量 `GCC\XY\mingw-w64\bin`


    


* **编译安装指定版本**

    1. [下载（日本镜像站）](https://ftp.tsukuba.wide.ad.jp/software/gcc/releases/)

    2. 解压缩
        ```sh
        tar -zxvf *.tar.gz
        cd gcc*
        ```

    2. 安装依赖
        ```sh
        sudo apt install libgmp-dev libmpfr-dev libmpc-dev
        ```

    3. 配置编译选项
        ```sh
        ./configure \
            --enable-languages=c,c++ \
            --prefix='/usr/local/gcc-x.y.z' \
            --disable-multilib
        ```
    
    4. 编译
        ```sh
        make -j$(nproc)
        ```
    
    5. 安装
        ```sh
        sudo make install
        ```

    6. 添加动态连接
        ```
        export LD_LIBRARY_PATH=/usr/local/gcc-x.y.z/lib64:$LD_LIBRARY_PATH
        ```

<br>

* **多个版本切换**

    1. 设置候选项
        ```shell
        sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 110
        sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 110
        sudo update-alternatives --install /usr/bin/gcc gcc /usr/local/gcc-14.1.0/bin/gcc 140
        sudo update-alternatives --install /usr/bin/g++ g++ /usr/local/gcc-14.1.0/bin/g++ 140
        ```
    
    2. 切换版本
        ```shell
        sudo update-alternatives --config gcc
        ```

    3. 删除多余候选项
        ```shell
        sudo update-alternatives --remove gcc /usr/local/gcc-14.1.0/bin/gcc
        sudo update-alternatives --remove g++ /usr/local/gcc-14.1.0/bin/g++
        ```

## Linux-use

* 指定输出文件名字
    ```shell
    g++ main.cpp -o main
    ```
* 指定 `c++` 标准
    ```shell
    g++ main.cpp -std=c++26
    ```
* 指定编译器优化
    
    ```shell
    g++ main.cpp -O2
    ```
    
    * `-O0` 无优化
        * 效果：不进行任何优化，生成的代码与源代码结构一致，方便试
        * 适用：开发和调试阶段，用于方便调试和查找问题
    * `-O1` 基本优化（缺省）
        * 效果：应用基本的优化策略，如内联函数、去除未使用的变量等
        * 适用：提供一些优化，但不会显著增加编译时间，适用于大多情况
    * `-O2` 标准优化
        * 效果：包括更多的内联、循环展开、消除不必要的指令等优化略
        * 适用：提供更多的性能优化，适用于发布版本，编译时间可能增加
    *  `-O3` 更高级的优化
        * 效果：包括更多复杂的优化，如矢量化、函数调用优化等
        * 适用：对性能要求非常高的应用，但可能增加编译时间，不建用于所有应用
    * `-Ofast` 最高级的优化
        * 效果：启用所有可能的优化，包括不遵循标准的优化，例如非准数学优化和禁用安全性检查
        * 适用：对极致性能要求的应用，但可能引入精度损失和不可预的行为

* 输出文件带调试信息
    ```shell
    g++ main.cpp -g
    ```

* 生成动态库
    ```shell
    g++ -shared -fPIC -o libutil.so util.cpp
    ```

* 连接动态库
    ```shell
    g++ main.cpp -lssl
    ```
    * `-lssl` 是 `OpenSSL` 的 `SSL` 库
    ```shell
    g++ main.cpp -I/usr/local/openssl-x.y.z/include -L/usr/local/openssl-x.y.z/lib -lssl
    ```
    * 在手动连接动态库时，通常还需要指定头文件搜索位置