[语法速查](https://tonybai.com/2023/02/23/learn-go-in-10-min/)


## 上手

1. [官网](https://golang.google.cn/dl/) 康康最新版本，下载

2. 解压缩至 `/usr/local/`
    * `sudo tar -zxvf go* -C /usr/local/`

3. 配置环境变量
    * `vim ~/.bashrc`
      ```sh
      export PATH=$PATH:/usr/local/go/bin
      ```

    * 刷新
      `source ~/.bashrc`

4. 测试 `go version`

### 单个文件运行

```
── my_project/
   ├── go.mod
   ├── main.go
```

1. `mkdir my_project && cd my_project`

2. `go mod init github.com/daixll/my_project`

3. `vim main.go`

    ```go
    // main.go
    package main
    import "fmt"
    func main() {
        fmt.Println("Hello, World!")
    }
    ```

4. `go run main.go`

<br>

### 多个文件运行

```
── my_project/
   ├── go.mod
   ├── main.go
   ├── one.go
```

1. `vim one.go`

    ```go
    package main  // 在同一目录下，一定要是 main 包
    import "fmt"
    func One() {  // 首字母大写，表示可以被外部调用
        fmt.Println("Hello, one")
    }
    ```

2. `vim main.go`

    ```go
    package main
    func main() {
        One()  // 调用包中的函数
    }
    ```

3. `go run main.go one.go`


<br>

### 调用本地包

```
── my_project/
   ├── go.mod
   ├── main.go
   ├── one.go
   ├── two
       ├── two.go
```

1. `mkdir two && vim two/two.go`
  
      ```go
      package two
      import "fmt"
      func Two() {
          fmt.Println("Hello, two")
      }
      ```
2. `vim main.go`

    ```go
    package main
    import (
        "github.com/daixll/my_project/two"  // 导入本地包
    )
    func main() {
        two.Two()  // 调用包中的函数
    }
    ```

3. `vim go.mod`

    ```sh
    module github.com/daixll/my_project

    go 1.22
    // 重定向到本地
    require github.com/daixll/my_project/two => ./two
    ```

4. `go mod tidy`

5. `go build`

6. `./my_project`