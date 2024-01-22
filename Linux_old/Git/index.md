---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

[廖雪峰的git教程](https://www.liaoxuefeng.com/wiki/896043488029600)

# 安装

## Linux
```shell
apt install git     # 安装 git
git --version       # 验证 git 安装成功
```

## Windows

[git 官网](https://git-scm.com/downloads)

<br>

---

# 首次使用

## 初始化仓库

在需要管理的目录（工作区）下，执行以下命令：

```shell
git init
```

> 将目标目录初始化成 git 可以管理的仓库，会生成一个 `.git` 目录
> 同时，会创建一个 `master` 分支

## 设置名字和邮箱

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

## 将目标文件移动到暂存区

> 追踪目标文件

```shell
git add 目标文件
```

## 将暂存区提交到本地仓库

> 目标文件提交到本地仓库的当前分支
```shell
git commit -m "提交说明"
```

## 将本地仓库推送到远程仓库

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

## 将远程仓库拉取到本地仓库

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

# 查看状态


## 查看仓库的状态
```shell
git status
```
> 1. 显示位于哪个 **分支**
> 2. 显示 **暂存区** 的信息
> 3. 显示 **未跟踪** 的文件

## 查看仓库设置
```shell
git config --级别 -l
```
> `--级别` 可以省略，会显示最终三个配置文件计算后的配置信息

## 查看所有分支
```shell
git branch
```
> `*` 表示当前分支

## 查看远程仓库
```shell
git remote -v
```
> 查看远程仓库的详细信息

## 查看提交历史
```shell
git log
```
> 显示从最近到最远的提交日志
> 简化输出：`git log --pretty=oneline`

## 查看命令历史
```shell
git reflog
```
> 显示从最近到最远的命令日志
> 可以看到每一次命令的 `commit id`


<br>

---

# 撤销操作

## 从暂存区移除文件

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


## 撤销本次提交

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

## 删除远程仓库地址

```shell
git remote rm origin
```

> 删除远程仓库的别名为 `origin` 的仓库（地址）
> 仅仅是删除了别名，远程仓库并没有被删除


<br> 

---

# 国区操作

## 代理

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



## 同时推送到多个远程仓库

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