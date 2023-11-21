---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 参考

**书籍：** [阿里云盘](https://www.aliyundrive.com/s/DesYASZJKet)

**视频：**

* 123

**网站：**

* 123

<br>

---


# Socket

# Boost.Asio

## 下载安装 Boost

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