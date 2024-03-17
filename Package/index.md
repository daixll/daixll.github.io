---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# **引子**

各类软件包的安装（如果 [SoftWare](../SoftWare/index.html) 中没有）、配置、使用等等。

<br>

---

# **Boost**

## Linux

1. 下载
    [Boost](https://www.boost.org/users/download/)

2. 解压

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
    * 编译
        ```shell
        g++ -o test test.cpp
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

# **openssl**

## Linux


## Windows

**openssl** 是一个开源的软件库包，实现了 **SSL** 和 **TLS** 协议，包含了众多密码算法，常用于 **HTTPS** 的服务器端和客户端的实现。

### openssl 命令

[官方手册](https://www.feistyduck.com/library/openssl-cookbook/online/)

### ssllib

[官方手册 3.0](https://www.openssl.org/docs/man3.0/man7/)
[加密部分](https://www.openssl.org/docs/manmaster/man3/EVP_PKEY_encrypt.html)


**安装**

* `ubuntu`
    ```bash
    sudo apt install libssl-dev
    ```
**编译**

* `g++`
    ```bash
    g++ main.cpp -lssl -lcrypto
    ```



<br>

---