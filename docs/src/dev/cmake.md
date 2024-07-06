## setup

### linux

### windows

<br>

---

## use


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
