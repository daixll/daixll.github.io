## setup

### linux

1. 下载 
    
    ```
    https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz
    ```

2. 解压
    
    ```
    tar -xvf googletest*
    ```

3. 编译

    ```sh
    cd googletest*
    mkdir build && cd build
    cmake ..
    make
    ```

4. 安装

    ```sh
    sudo make install
    ```

    相当于将其复制到 `/usr/local` 目录下


## use