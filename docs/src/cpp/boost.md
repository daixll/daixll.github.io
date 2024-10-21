
[官网](https://www.boost.org/) | [下载](https://www.boost.org/users/download/) | [开发文档](https://www.boost.org/doc/)

## setup

### linux

1. 下载 `wget` / 解压 `tar -zxvf` / 提权 `chmod +x`

2. 配置安装选项 `./bootstrap.sh --prefix=/.../boost-x.y.z`

3. 安装 `./b2 -j$(nproc) --prefix=/.../boost-x.y.z install`

4. 编写测试代码
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
5. 编译
    ```shell
    g++ test.cpp -I/.../boost-x.y.z/include -L/.../boost-x.y.z/lib
    ```

### windows

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

---

## dev

