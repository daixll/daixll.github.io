---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

常用开发软件/包的 **安装** 及 **简单使用**

`Linux` 以 `Ubuntu 22.04` 为例
`Win` 以 `Windows 11 pro` 为例

```
├── 软件名/
    ├── Linux-setup
    ├── Linux-use
    ├── Linux-dev-setup
    ├── Linux-dev-use
    ├── Win-setup
    ├── Win-use
    ├── Win-dev-setup
    ├── Win-dev-use
```

<br>

---

# **gcc**

## Linux-setup

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




## Win-setup

* **安装**

    1. 下载 [mingw-w64](https://github.com/niXman/mingw-builds-binaries/releases) `x86_64` `posix` `seh` `ucrt`

    2. 解压

    3. 添加至环境变量 `GCC\XY\mingw-w64\bin`


<br>

---

# **Make**

> `make` 并不编译文件，`make` 只用于申明编译规则

## Linux-setup

* **安装**
    ```shell
    sudo apt install make   # 安装 make
    make -v                 # 验证 make 安装成功
    ```

## Linux-use

* 当前目录下存在 `Makefile` 文件
    ```
    project/
    ├── main.cpp
    └── Makefile
    ```

    ```shell
    make # 直接 make 即可
    ```

* `Makefile` 最简示例
    ```makefile
    # 声明变量
    CXX = g++                       # 编译器命令
    CXXFLAGS = -std=c++26 -O2       # 编译选项
    TARGET = main                   # 目标可执行文件名
    SRCS = main.cpp                 # 源文件列表

    all: $(TARGET)                  # 默认目标规则

    $(TARGET): $(SRCS)              # 生成可执行文件的规则
            $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

    clean:                          # 清理生成的文件
            rm -f $(TARGET)

    .PHONY: all clean               # 声明伪目标，避免与文件名冲突
    ```

* `Makefile` 连接动态库
    ```makefile
    # 声明变量
    CXX = g++
    CXXFLAGS = -std=c++26
    TARGET = main
    SRCS = main.cpp

    # 需要链接的动态库列表
    LIBS = -lssl -lcrypto -lz       # OpenSSL 的 SSL 库、加密库和 zlib 库

    # 头文件和库文件路径
    INC_DIR = /usr/local/XYZ/include
    LIB_DIR = /usr/local/XYZ/lib /usr/lib

    all: $(TARGET)                  # 默认目标规则

    $(TARGET): $(SRCS)              # 生成可执行文件的规则
        $(CXX) $(CXXFLAGS) -I$(INC_DIR) -L$(LIB_DIR) -o $(TARGET) $ (SRCS) $(LIBS)

    clean:                          # 清理生成的文件
        rm -f $(TARGET)

    .PHONY: all clean               # 声明伪目标，避免与文件名冲突
    ```


## Windows-setup

* **安装**
    1. 下载 [Make](https://gnuwin32.sourceforge.net/downlinks/make.php)
    2. 安装
    3. 添加环境变量 `GnuWin32\bin`


<br>

---

# **CMake**

## Linux-setup

* **安装**
    1. 下载 [CMake](https://cmake.org/download/)
    2. 解压缩
    3. 设置环境变量

## Linux-use

* 当前目录下存在 `CMakeLists.txt` 文件
    1. `mkdir build && cd build` 通常做法，避免中间文件污染源代码目录（out-of-source）
    2. `cmake ..` 生成构建系统文件
    3. `cmake --build .` 执行相应的构建命令（例如 `make`）

* 开始
    ```c
    cmake_minimum_required(VERSION 3.29)    # 指定 CMake 的最低版本要求

    project(main VERSION 1.0)               # 设置项目名称和版本号

    set(CMAKE_CXX_STANDARD 23)              # 指定 C++ 标准版本
    set(CMAKE_CXX_STANDARD_REQUIRED True)   # 编译器必须严格遵循指定的 C++ 标准版本
    ```

* 生成可执行文件
    ```c
    add_executable(main main.cpp)           # 生成可执行文件
    ```

* 生成库目标
    ```c
    add_library(util STATIC util.cpp)       # 生成静态库 libutil.a
    add_library(util SHARED util.cpp)       # 生成动态库 libutil.so
    ```

* 链接动态库
    ```c
    LINK_DIRECTORIES(/usr/local/xyz/lib)    # 添加动态库目录
    target_link_libraries(main libssl.so)   # 链接库到 main
    ```

* 选择判断
    ```c
    if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
        set(LIB_PATH "/usr/local/xyz/lib")
    elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
        set(LIB_PATH "C:/Path/To/Your/Libraries")
    endif()

    LINK_DIRECTORIES(${LIB_PATH})
    ```


## Win-setup



<br>

---

# **openssl**

## Linux-setup

## Linux-use

[官方手册](https://www.feistyduck.com/library/openssl-cookbook/online/)

* 生成密钥对
    ```bash
    openssl genpkey -out pri.key -algorithm RSA -pkeyopt rsa_keygen_bits:2048
    openssl pkey -in pri.key -pubout -out pub.key
    ```

## Linux-dev-setup

* 安装
    ```bash
    sudo apt install libssl-dev
    g++ main.cpp -lssl -lcrypto
    ```

* 手动安装
    1. 下载 [openssl](https://www.openssl.org/source/)
    2. 解压，进入解压后的目录
    3. 配置安装选项
        ```bash
        ./config shared --prefix=/opt/openssl-x.y.z --openssldir=/opt/openssl-x.y.z
        ```
        ```bash
        ./config -fPIC no-shared
        # fPIC 指生成位置无关代码
        # 生成静态文件
        # 直接在当前目录下生成
        ```
    4. 安装
        ```bash
        make && sudo make install
        ```
    5. 测试
        ```c
        #include <stdio.h>
        #include <openssl/opensslv.h>
        #include <openssl/crypto.h>

        int main() {
            // 输出 OpenSSL 版本信息
            printf("OpenSSL version: %s\n", OpenSSL_version(OPENSSL_VERSION));
            printf("OpenSSL version number: %lx\n", OpenSSL_version_num());
            return 0;
        }
        ```
        * 编译
            ```bash
            gcc a.c -I/opt/openssl-x.y.z/include -L/opt/openssl-x.y.z/lib64 -Wl,-rpath=/opt/openssl-x.y.z/lib64 -lssl -lcrypto
            ./a.out
            ```
        
        * 编译
            ```bash
            g++ test.cpp -I/openssl-x.y.z/include -L/openssl-x.y.z -lssl -lcrypto
            ```

## Linux-dev-use

[官方手册 3.0](https://www.openssl.org/docs/man3.0/man7/) / [加密部分](https://www.openssl.org/docs/manmaster/man3/EVP_PKEY_encrypt.html)



## Win-setup

## Win-dev-setup

<br>

---



# **Boost**

## Linux-setup

1. 下载 [Boost](https://www.boost.org/users/download/)

2. 解压，进入解压后的目录

3. 配置安装选项
    ```bash
    # 需要 g++
    ./bootstrap.sh --prefix=/opt/boost-x.y.z
    ```

4. 安装
    ```bash
    sudo ./b2 -j$(nproc) --prefix=/opt/boost-x.y.z install
    ```

5. 测试
    ```cpp
    #include <boost/version.hpp>
    #include <boost/config.hpp>
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
    * 编译
        ```shell
        g++ test.cpp -I/opt/boost-1.85.0/include -L/opt/boost-1.85.0/lib
        ```

## Windows

1. 下载
    [Boost](https://www.boost.org/users/download/)

2. 解压

3. 进入解压后的目录，执行 `.\bootstrap.bat gcc`
    * 编译前的配置工作

4. 执行 `.\b2.exe install`
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
    * 编译
        ```shell
        g++ -o test test.cpp -I"C:\Boost\include\boost-1_84" -L"C:\Boost\lib"
        ```
    * 如果使用网络库，还需要 `-lws2_32`


<br>

---

# **FFmpeg**

## Linux-setup

* 手动安装
    1. 下载 [ffmpeg](https://ffmpeg.org/download.html)
    2. 解压，进入解压后的目录
    3. 下载编译工具
        ```bash
        sudo apt install nasm
        ```
    4. 配置安装选项
        ```bash
        ./configure --prefix=/opt/ffmpeg-x.y.z
        ```
    5. 编译
        ```sh
        make -j$(nproc)
        ```
    
    6. 安装
        ```sh
        sudo make install
        ```
    
    7. 验证
        ```cpp
        /**
         * 最简单的FFmpeg Helloworld程序
         * Simplest FFmpeg HelloWorld
         *
         * 雷霄骅 Lei Xiaohua
         * leixiaohua1020@126.com
         * 中国传媒大学/数字电视技术
         * Communication University of China / Digital TV Technology
         * http://blog.csdn.net/leixiaohua1020
         *
         * 
         * 本程序是基于FFmpeg函数的最简单的程序。它可以打印出FFmpeg类库的下列信息：
         * Protocol:  FFmpeg类库支持的协议
         * AVFormat:  FFmpeg类库支持的封装格式
         * AVCodec:   FFmpeg类库支持的编解码器
         * AVFilter:  FFmpeg类库支持的滤镜
         * Configure: FFmpeg类库的配置信息
         * 
         * This is the simplest program based on FFmpeg API. It can show        following 
         * informations about FFmpeg library:
         * Protocol:  Protocols supported by FFmpeg.
         * AVFormat:  Container format supported by FFmpeg.
         * AVCodec:   Encoder/Decoder supported by FFmpeg.
         * AVFilter:  Filters supported by FFmpeg.
         * Configure: configure information of FFmpeg.
         *
         */
        
        #include <stdio.h>
        
        #define __STDC_CONSTANT_MACROS
        
        #ifdef _WIN32
        //Windows
        extern "C"
        {
        #include "libavcodec/avcodec.h"
        #include "libavformat/avformat.h"
        #include "libavfilter/avfilter.h"
        };
        #else
        //Linux...
        #ifdef __cplusplus
        extern "C"
        {
        #endif
        #include <libavcodec/avcodec.h>
        #include <libavformat/avformat.h>
        #include <libavfilter/avfilter.h>
        #ifdef __cplusplus
        };
        #endif
        #endif
        
        //FIX
        struct URLProtocol;
        /**
         * Protocol Support Information
         */
        char * urlprotocolinfo(){
        
        	char *info=(char *)malloc(40000);
        	memset(info,0,40000);
        
        	av_register_all();
        
        	struct URLProtocol *pup = NULL;
        	//Input
        	struct URLProtocol **p_temp = &pup;
        	avio_enum_protocols((void **)p_temp, 0);
        	while ((*p_temp) != NULL){
        		sprintf(info, "%s[In ][%10s]\n", info, avio_enum_protocols      ((void **)p_temp, 0));
        	}
        	pup = NULL;
        	//Output
        	avio_enum_protocols((void **)p_temp, 1);
        	while ((*p_temp) != NULL){
        		sprintf(info, "%s[Out][%10s]\n", info, avio_enum_protocols      ((void **)p_temp, 1));
        	}
        
        	return info;
        }
        
        /**
         * AVFormat Support Information
         */
        char * avformatinfo(){
        
        	char *info=(char *)malloc(40000);
        	memset(info,0,40000);
        
        	av_register_all();
        
        	AVInputFormat *if_temp = av_iformat_next(NULL);
        	AVOutputFormat *of_temp = av_oformat_next(NULL);
        	//Input
        	while(if_temp!=NULL){
        		sprintf(info, "%s[In ] %10s\n", info, if_temp->name);
        		if_temp=if_temp->next;
        	}
        	//Output
        	while (of_temp != NULL){
        		sprintf(info, "%s[Out] %10s\n", info, of_temp->name);
        		of_temp = of_temp->next;
        	}
        	return info;
        }
        
        /**
         * AVCodec Support Information
         */
        char * avcodecinfo()
        {
        	char *info=(char *)malloc(40000);
        	memset(info,0,40000);
        
        	av_register_all();
        
        	AVCodec *c_temp = av_codec_next(NULL);
        
        	while(c_temp!=NULL){
        		if (c_temp->decode!=NULL){
        			sprintf(info, "%s[Dec]", info);
        		}
        		else{
        			sprintf(info, "%s[Enc]", info);
        		}
        		switch (c_temp->type){
        		case AVMEDIA_TYPE_VIDEO:
        			sprintf(info, "%s[Video]", info);
        			break;
        		case AVMEDIA_TYPE_AUDIO:
        			sprintf(info, "%s[Audio]", info);
        			break;
        		default:
        			sprintf(info, "%s[Other]", info);
        			break;
        		}
        
        		sprintf(info, "%s %10s\n", info, c_temp->name);
        
        		c_temp=c_temp->next;
        	}
        	return info;
        }
        
        /**
         * AVFilter Support Information
         */
        char * avfilterinfo()
        {
        	char *info=(char *)malloc(40000);
        	memset(info,0,40000);
        
        	avfilter_register_all();
        
        	AVFilter *f_temp = (AVFilter *)avfilter_next(NULL);
        
        	while (f_temp != NULL){
        		sprintf(info, "%s[%15s]\n", info, f_temp->name);
        		f_temp=f_temp->next;
        	}
        	return info;
        }
        
        /**
         * Configuration Information
         */
        char * configurationinfo()
        {
        	char *info=(char *)malloc(40000);
        	memset(info,0,40000);
        
        	av_register_all();
        
        	sprintf(info, "%s\n", avcodec_configuration());
        
        	return info;
        }
        
        int main(int argc, char* argv[])
        {
        	char *infostr=NULL;
        	infostr=configurationinfo();
        	printf("\n<<Configuration>>\n%s",infostr);
        	free(infostr);
        
        	infostr=urlprotocolinfo();
        	printf("\n<<URLProtocol>>\n%s",infostr);
        	free(infostr);
        
        	infostr=avformatinfo();
        	printf("\n<<AVFormat>>\n%s",infostr);
        	free(infostr);
        
        	infostr=avcodecinfo();
        	printf("\n<<AVCodec>>\n%s",infostr);
        	free(infostr);
        
        	infostr=avfilterinfo();
        	printf("\n<<AVFilter>>\n%s",infostr);
        	free(infostr);
        
        	return 0;
        }
        ```

        * 编译
            ```bash
            g++ test.cpp -I/opt/ffmpeg-x.y.z/include -L/opt/ffmpeg-x.y.z/lib -lavformat -lavcodec -lavutil
            ```


## 安装

1. 安装
    **Linux**
    `sudo apt install ffmpeg libavformat-dev libavcodec-dev libavdevice-dev libavutil-dev libswscale-dev`

    * `libavformat-dev` 格式处理库
    * `libavcodec-dev` 编解码库
    * `libswresample` 音频格式转换库
    * `libswscale-dev` 视频格式转换库
        
    * `libavdevice-dev` 设备操作库
        
    * `libavutil-dev` Utility辅助库
    * `libavfilter` 音视频滤镜

2. 测试
    ```cpp
    extern "C"{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavutil/dict.h>
    }

    int main(int argc, char *argv[]) {
        avformat_network_init(); // 替换 av_register_all()

        AVFormatContext *formatContext = NULL;

        // 打开视频文件
        if (avformat_open_input(&formatContext, argv[1], NULL, NULL) !=     0) {
            fprintf(stderr, "无法打开视频文件\n");
            return -1;
        }

        // 获取视频文件信息
        if (avformat_find_stream_info(formatContext, NULL) < 0) {
            fprintf(stderr, "无法获取视频文件信息\n");
            return -1;
        }

        // 打印视频文件信息
        av_dump_format(formatContext, 0, argv[1], 0);

        // 关闭视频文件
        avformat_close_input(&formatContext);

        return 0;
    }
    ```
    ```
    g++ main.cpp -o main -lavcodec -lavformat -lavutil -lswscale
    ```

<br>

---


# **Qt**

[官网](https://www.qt.io/zh-cn/) 注册账号

## Linux-setup

* 在线安装

    1. 下载 [在线安装器](https://mirrors.tuna.tsinghua.edu.cn/qt/official_releases/online_installers/)
    2. 使用镜像启动
        ```shell
        sudo ./Qt
        ```
        * 启动过程 **可能** 出现依赖缺失问题：~~*不知道装什么，那就全装*~~
            ```bash
            sudo apt install libxcb*
            sudo apt install libgl1-mesa-dev
            ```
    3. 检测是否安装成功
        ```shell
        /opt/Qt/x.y.z/gcc_64/bin/qmake -v
        ```

    4. 添加用户级环境变量 `~/.bashrc`
        ```bash
        export PATH=$PATH:/opt/Qt/x.y.z/gcc_64/bin
        ```
        > 可能会出现 `qmake: could not exec '/usr/lib/x86_64-linux-gnu/qt4/bin/qmake': No such file or directory` 的错误，这是因为系统中存在多个版本的 QT，解决方法是：`sudo apt remove qt4-qmake`。

        > 另外一方案是，修改 `/usr/lib/x86_64-linux-gnu/qt-default/qtchooser/default.conf` 文件，将 `qt4` 的路径修改为 `/opt/Qt/x.y.z/gcc_64/bin`。


<br>

---


# **git**

[廖雪峰的git教程](https://www.liaoxuefeng.com/wiki/896043488029600)

## License

[参考](https://opensource.org/licenses)

### MIT 

`Massachusetts Institute of Technology License`

> 我只想安安静静写代码，你干嘛都与我无关

1. 版权申明
    * 文档和软件中需保留原始版权信息

2. 免责条款
    * 原始作者对软件使用引发的任何损害不负责

3. 使用
    * 随便用

4. 修改
    * 随便改

5. 再分发
    * 随意

### BSD 

`Berkeley Software Distribution License`

> 打广告的时候，别说你是基于我的，丢脸

1. 版权申明
    * 文档和软件中需保留原始版权信息

2. 免责条款
    * 原始作者对软件使用引发的任何损害不负责

3. 使用
    * 随便用，但是宣传软件的时候，不要带上我

4. 修改
    * 随便改

5. 再分发
    * 随意

### GPL

`GNU General Public License`

> 一日GPL，一生GPL

1. 版权申明
    * 文档和软件中需保留原始版权信息

2. 免责条款
    * 原始作者对软件使用引发的任何损害不负责

3. 使用
    * 随便用

4. 修改
    * 随便改，但是改了之后的代码不能闭源

5. 再分发
    * 依旧遵循 GPL

### LGPL

`GNU Lesser General Public License`

> 更灵活的GPL

* 允许动态连接闭源库

* 虽然灵活，但这并不意味着你可以闭源

### Apache

1. 版权申明
    * 文档和软件中需保留原始版权信息

2. 免责条款
    * 原始作者对软件使用引发的任何损害不负责

3. 使用
    * 随便用

4. 修改
    * 随便改

5. 再分发
    * 修改后的软件，分发时需要带上原始版权信息

<br>

---

## Linux
```shell
sudo apt install git # 安装 git
git --version        # 验证 git 安装成功
```

## Windows

[git 官网](https://git-scm.com/downloads)

<br>

---

## 首次使用

### 初始化仓库

在需要管理的目录（工作区）下，执行以下命令：

```shell
git init
```

> 将目标目录初始化成 git 可以管理的仓库，会生成一个 `.git` 目录
> 同时，会创建一个 `master` 分支

### 设置名字和邮箱

此操作的目的，是为了追踪每次操作，究竟是谁做的，我们一般将其存储在 `config` 中，也就是配置文件

配置文件有三个级别，权重从高到底：

1. 仓库 `local`，此配置文件只对 **当前仓库** 有效
2. 全局 `global`，此配置文件对 **当前用户** 有效
3. 系统 `system`，此配置文件对 **全局** 有效

**Windows**：

1. `local`： `.git/config`
2. `global`：`C:\Users\username\.gitconfig`
3. `system`：`C:\Program Files\Git\etc\gitconfig`


**Linux**：
1. `local`：`.git/config` 
2. `global`：`~/.gitconfig`
3. `system`：`/etc/gitconfig`

> 设置名字和邮箱；后续修改也直接使用此命令
```shell
git config --级别 user.name "名字"
git config --级别 user.email "邮箱"
```

### 将目标文件移动到暂存区

> 追踪目标文件

```shell
git add 目标文件
```

### 将暂存区提交到本地仓库

> 目标文件提交到本地仓库的当前分支
```shell
git commit -m "提交说明"
```

### 将本地仓库推送到远程仓库

将本地仓库推送到远程仓库，需要使用 `SSH key` 进行身份验证
私钥存储在本地，公钥存储在远程仓库
当你推送的时候，远程仓库会验证你的身份，如果验证通过，就可以推送

1. 生成 `SSH key`

    **Windows**：

    ```shell
    ssh-keygen -t rsa -C "email"
    ```

    > `-t rsa`：指定加密算法为 RSA
    > `-C "email"`：指定注释，一般填邮箱

    **Linux**：

    ```shell
    ssh-keygen -t rsa -C "email"
    ```

2. 将公钥添加到远程仓库（[github](https://github.com/) or [gitee](https://gitee.com/)）
    **Windows**：`C:\Users\username\.ssh\id_rsa.pub`
    **Linux**：`~/.ssh/id_rsa.pub`

    > 登录远程仓库，`setting` -> `SSH keys` -> `New SSH key`
    > `title`：填写公钥的名字
    > `key`：填写公钥的内容

3. 在远程仓库中新建仓库
    > 名称和本地仓库可以不一样，但建议一致
    > 开源和私有暂且不论，但建议开源
    > 复制仓库地址，使用 `ssh`

4. 添加远程仓库
    ```shell
    git remote add origin 远程仓库地址
    ```

    > `origin` 是远程仓库的别名，可以自定义

5. 推送到远程仓库
    ```shell
    git push origin master
    ```

> 注意，以上操作只是将本地仓库推送到远程仓库，但是远程仓库并不会自动创建分支

### 将远程仓库拉取到本地仓库

1. `git fetch origin`
    * 拉取远程仓库的所有分支到本地仓库，但是不会自动合并

    * `git merge origin/master`
        * 将远程仓库的 `master` 合并到本地仓库的当前分支

2. `git pull origin`
    * 拉取远程仓库的所有分支到本地仓库，并自动合并

3. `git clone 远程仓库地址`
    * 在本地创建一个远程仓库的克隆（副本）

<br>

---

## 查看状态


### 查看仓库的状态
```shell
git status
```
> 1. 显示位于哪个 **分支**
> 2. 显示 **暂存区** 的信息
> 3. 显示 **未跟踪** 的文件

### 查看仓库设置
```shell
git config --级别 -l
```
> `--级别` 可以省略，会显示最终三个配置文件计算后的配置信息

### 查看所有分支
```shell
git branch
```
> `*` 表示当前分支

### 查看远程仓库
```shell
git remote -v
```
> 查看远程仓库的详细信息

### 查看提交历史
```shell
git log
```
> 显示从最近到最远的提交日志
> 简化输出：`git log --pretty=oneline`

### 查看命令历史
```shell
git reflog
```
> 显示从最近到最远的命令日志
> 可以看到每一次命令的 `commit id`


<br>

---

## 撤销操作

### 从暂存区移除文件

```shell
git reset 目标文件
```

这个命令本质上是

```shell
git reset --mixed commit_id
```

> 从暂存区移除文件，但是不会删除文件
> `commit_id` 可以省略，默认是 `HEAD`
> 意思是将暂存区的文件恢复到 `commit_id` 的状态


### 撤销本次提交

1. 保留工作区的修改
    ```shell
    git reset --soft HEAD^
    ```
    > 撤销本次提交，但是保留工作区的修改
    > `HEAD^` 表示上一次提交，`HEAD^^` 表示上上次提交，以此类推

1. 删除工作区的修改
    ```shell
    git reset --hard HEAD^
    ```
    > 撤销本次提交，同时删除工作区的修改

### 删除远程仓库地址

```shell
git remote rm origin
```

> 删除远程仓库的别名为 `origin` 的仓库（地址）
> 仅仅是删除了别名，远程仓库并没有被删除


<br> 

---

## 国区操作

### 代理

**设置代理**

```shell
git config --global http.proxy http://127.0.0.1:7890
git config --global https.proxy https://127.0.0.1:7890
```

**取消代理**

```shell
git config --global --unset http.proxy
git config --global --unset https.proxy
```



### 同时推送到多个远程仓库

1. 再添加一个需要推送的远程仓库
    ```shell
    git remote set-url --add origin 远程仓库地址
    ```

2. 推送到远程仓库
    ```shell
    git push origin
    ```

> 注意，此方案只适用于多个远程仓库的代码完全一致的情况
> 因为我们只是给 `origin` 添加了多个 `URL`
> 虽然效果上看起来是推送到了多个仓库，但是实际上只是推送到了一个仓库


# **VM**

## Linux-setup

* [下载](https://support.broadcom.com/group/ecx/productdownloads?subfamily=VMware%20Workstation%20Pro)

## Win-setup

* [下载](https://support.broadcom.com/group/ecx/productdownloads?subfamily=VMware%20Workstation%20Pro)

## Mac-setup

* [下载](https://support.broadcom.com/group/ecx/productdownloads?subfamily=VMware%20Fusion)

# **docker**

**Docker**

* **轻量化**：在操作系统层面上实现虚拟化
* **分布式**：可以在同一台机器上运行多个容器，每个容器之间相互隔离
* **无状态**：容器每次创建都是全新的，容器内的进程也是全新的，容器内的内容不可持久化

**Virtual Machines** 

* **更强的隔离性**：在硬件层面上实现虚拟化
* **文件特性**：硬盘文件、快照都是文件，可以持久化

## 安装 Docker

使用官方安装脚本（[参考文档](https://docs.docker.com/engine/install/ubuntu/)）：

```sh
 curl -fsSL https://test.docker.com -o test-docker.sh
 sudo sh test-docker.sh
```

## 镜像 IMAGE

是一个只读模板，用来创建容器，类似于：

* 面向对象中的类，容器是对象
* 虚拟机中的 `.iso`，容器是虚拟机

### Docker Hub 下载镜像

[Docker Hub](https://hub.docker.com/search?q=)

```sh
docker pull IMAGE_NAME[:TAG]
```

* `IMAGE_NAME` 镜像名称
* `TAG` 可选，镜像版本或标签，默认为 `latest`

### Dockerfile 构建镜像

```sh
docker build -t IMAGE_NAME[:TAG] PATH_TO_DOCKERFILE
```

* `IMAGE_NAME` 镜像名称
* `TAG` 可选，镜像版本或标签
* `PATH_TO_DOCKERFILE` Dockerfile 所在路径

### 查看镜像

```sh
docker images
```

* `REPOSITORY` 镜像名称
* `TAG` 镜像版本或标签
* `IMAGE ID` 镜像 ID：**唯一标识**
* `CREATED` 创建时间
* `SIZE` 镜像大小

### 删除镜像

```sh
docker rmi IMAGE_NAME[:TAG]
```



## 容器 CONTAINER

### 查看容器

```sh
docker ps [-a]
```

### 创建 / 删除容器

**删除容器**

> 删除容器前需要先停止容器

```sh
docker rm CONTAINER_ID
```

**创建容器**

```sh
docker run \
    [OPTIONS] \
    IMAGE_NAME[:TAG] \
    [COMMAND] \
    [ARG...]
```

1. **OPTIONS** 命令选项
    * `-it` 进入容器终端，通常与 `/bin/bash` 一起使用
    * `-d` 后台运行容器，通常与 `sleep infinity` 一起使用
    * `--name` 容器名称
    * `--restart` 容器停止后自动重启
        * `no`（默认），不重启
        * `on-failure`，非 0 退出时重启
        * `always`，总是重启
    * `--net` 网络模式
        * `bridge`（默认），需要端口映射
        * `host`，直接使用宿主机端口
        * `none`，无网络
    * `--rm` 容器停止后自动删除
    * `-p` 端口映射，`HOST_PORT:CONTAINER_PORT`，`外:内`
    * `-v` 挂载目录，`HOST_DIR:CONTAINER_DIR`，`外:内`
    * `-e` 环境变量，`KEY=VALUE`
    * `-w` 工作目录，`WORK_DIR`，指定容器内的工作目录


### 进入 / 退出容器

**进入容器**

```sh
docker exec -it CONTAINER_ID /bin/bash
```

**退出容器**

```sh
exit
```

### 启动 / 停止容器

**启动容器**

```sh
docker start CONTAINER_ID
```

**停止容器**

```sh
docker stop CONTAINER_ID
```

## Dockerfile

<br>

---

# **nginx**

## nginx的使用

* 安装nginx
```sh
apt install nginx
```

* nginx配置反向代理
  修改 `/etc/nginx/nginx.conf`

```sh
http {
  server {
    listen 本地端口;
    server_name 监听ip;
    
    location / {
      proxy_pass 目标ip:端口;
    }
  }
}
```

* 验证是否正确

```sh
nginx -t
```

* 重启并加载新的配置文件
```sh
nginx -s reload
```

<br>

---

# **nmap**

[官方中文文档](https://nmap.org/man/zh/index.html)

`nmap [ <扫描类型> ...] [ <选项> ] { <扫描目标说明> }`

## nmap 端口状态

### open（开放的）

应用程序正在监听端口，或者响应一个请求来自已连接的客户端。接收TCP连接或者UDP报文。

### closed（关闭的）

没有应用程序监听端口。但是此端口可以被探测到，因为没有应用程序监听，所以会返回一个 RST 包或者 ICMP 端口不可达消息。

### filtered（屏蔽的）

防火墙或者 ACL 屏蔽了端口，所以无法确定端口是否开放。目标端口可能有以下几种情况：
* 未响应，屏蔽器丢弃了探测包，此举会让 nmap 误认为探测包丢失，导致扫描时间变长。
* 丢弃了探测包，但是返回了 ICMP 错误消息。

### unfiltered（未屏蔽的）

防火墙或者 ACL 没有屏蔽端口，但是 nmap 无法确定端口开放或者关闭。用其它类型的扫描，如窗口扫描，SYN 扫描，或者 FIN 扫描可以帮助确定端口是否开放。

### open|filtered（开放或者屏蔽的）

开放的端口不响应探测包，屏蔽的端口也不响应探测包。所以无法确定端口是否开放。

### closed|filtered（关闭或者屏蔽的）

只可能出现在 IPID Idle 扫描中，因为此扫描类型需要发送两个探测包，如果两个探测包都没有响应，那么就无法确定端口是否开放。

---

## nmap 扫描技术


### 1 默认扫描

`nmap dxll.love`

默认扫描是 nmap 的最基本的扫描方式，它会扫描 1000 个最常用的端口，扫描方式是 SYN 扫描。

```sh
nmap -T0 dxll.love
nmap -T1 dxll.love
nmap -T2 dxll.love
nmap -T3 dxll.love
nmap -T4 dxll.love
nmap -T5 dxll.love
```

`-T0` 是最慢的扫描方式，`-T5` 是最快的扫描方式，`-T3` 是默认的扫描方式，`-T4` 是常用的扫描方式。

`nmap -6 dxll.love`

开启 IPv6 扫描。

`nmap -v dxll.love`

开启详细模式，显示扫描过程。

`nmap -A dxll.love`

全面扫描，包括 1-10000 端口扫描，服务版本探测，操作系统探测，脚本扫描等。

### 2 扫描多个 IP

```sh
nmap spacex.com dxll.love   # 扫描多个域名
nmap 192.168.31.100,101,102 # 扫描同一网段的多个 IP，可以用逗号分隔
nmap 192.168.31.*           # 扫描同一网段的多个 IP，可以用通配符
nmap 192.168.31.1/24        # 扫描同一网段的多个 IP，可以用 CIDR 表示法
```

### 3 扫描指定端口

```sh
nmap -p 80 dxll.love        # 扫描单个端口
nmap -p 80,443 dxll.love    # 扫描多个端口
nmap -p 1-100 dxll.love     # 扫描端口范围
nmap -p-                    # 扫描所有端口 等价于 nmap -p 1-65535
```

### 4 TCP扫描

#### TCP SYN 扫描

`nmap -sS dxll.love`

此方式不完成 TCP 三次握手，而是发送一个 SYN 包，如果目标端口开放，那么会返回一个 SYN/ACK 包，如果端口关闭，那么会返回一个 RST 包。

#### TCP Connect 扫描

`nmap -sT dxll.love`

此方式完成 TCP 三次握手，如果目标端口开放，那么会返回一个 SYN/ACK 包，如果端口关闭，那么会返回一个 RST 包。
目标主机可能会记录下连接，所以此方式不太隐蔽。

#### TCP 隐秘扫描

如果收到 RST 响应，则端口关闭，否则判定端口开放或被屏蔽。

`nmap -sN dxll.love`

不设置任何标志位。

`nmap -sF dxll.love`

只设置TCP FIN标志位。

`nmap -sX dxll.love`

flags的FIN、URG、PUSH都为1的包。

#### TCP ping 扫描

`nmap -sP dxll.love`

通过发送ICMP Echo请求（也称为Ping请求）到目标主机，命令将检测主机是否响应了请求并返回IP地址。如果主机响应，则表示主机是在线的。在这个扫描中，Nmap只检查是否有响应，而不扫描主机的任何端口。

### 5 UDP 扫描

`namp -sU dxll.love`

UDP 扫描需要发送 UDP 包，如果目标端口开放，那么会返回一个 ICMP 端口不可达消息，如果端口关闭，那么会返回一个 ICMP 端口不可达消息或者没有响应。


### 6 路由跟踪

`nmap --traceroute dxll.love`

查出从本地计算机到目标之间所经过的网络节点，并可以看到通过各个节点的时间。

### 7 操作系统探测

`nmap -O dxll.love`

nmap 会发送一系列的 TCP 和 UDP 包，然后分析返回的包，从而判断目标主机的操作系统。


# **Wireshark**




# todo

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

# todo

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