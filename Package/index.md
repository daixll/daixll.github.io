---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

各类软件包的安装（如果 [SoftWare](../SoftWare/index.html) 中没有）、配置、使用等等。

<br>

---

# openssl

**openssl** 是一个开源的软件库包，实现了 **SSL** 和 **TLS** 协议，包含了众多密码算法，常用于 **HTTPS** 的服务器端和客户端的实现。

## openssl 命令

[官方手册](https://www.feistyduck.com/library/openssl-cookbook/online/)

## ssllib

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