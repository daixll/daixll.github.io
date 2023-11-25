---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 通过源码构建特定版本的 Python

以下是在 `Ubuntu 20.04` 上构建 `Python 3.12.0` 的步骤。

1. 下载源码包

```bash
wget https://www.python.org/ftp/python/3.12.0/Python-3.12.0.tar.xz
```

2. 下载依赖包

```bash
apt install build-essential zlib1g-dev libncurses5-dev libgdbm-dev libnss3-dev libssl-dev libreadline-dev libffi-dev libsqlite3-dev wget libbz2-dev
```

3. 解压源码包

```bash
tar -xvf Python-3.12.0.tar.xz
```

4. 运行配置脚本

```bash
cd Python-3.12.0
./configure --enable-optimizations
```

5. 编译

```bash
make -j 8   # 多线程编译
```

6. 安装

```bash
make altinstall
```

7. 验证

```bash
python3.12 -V
```

# 虚拟环境

虚拟环境在 Python 中是一个非常重要的概念，起到项目隔离的作用：
* 项目 A 使用 Python 2.7，项目 B 使用 Python 3.6
* 项目 A 使用 Django 1.11，项目 B 使用 Django 2.0

