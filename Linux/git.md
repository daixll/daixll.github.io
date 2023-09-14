---
html:
    toc: true           # 打开侧边目录
    toc_depth: 6        # 打开的目录层级
    toc_float: true     # 侧边悬停
    collapsed: true     # 只显示高级别标题(2)
    smooth_scroll: true # 页面滚动,标题变化
    number_sections: false  # 显示标题编号
    theme: united
---

[廖雪峰的git教程](https://www.liaoxuefeng.com/wiki/896043488029600)

# 设置名字和邮箱

此操作的目的，是为了追踪每次操作，究竟是谁做的。我们一般将其存储在 `config` 中，也就是配置文件。

配置文件有三个级别。权重从高到底，依次是仓库 `local`、全局 `global`、系统 `system`。

1. 仓库级配置文件路径：当前仓库下 `.git/config`。此配置文件只对 **当前仓库** 有效。
2. 全局级配置文件路径：`C:\Users\用户名字\.gitconfig`。此配置文件对 **当前用户** 有效。
3. 系统级配置文件路径：`C:\Program Files\Git\etc\gitconfig`。此配置文件对 **全局** 有效。

> 设置名字和邮箱；后续修改也直接使用此命令。
```shell
git config --级别 user.name "名字"
git config --级别 user.email "邮箱"
```
> 设置好之后查看；其中 `--级别` 可以省略，会显示最终三个配置文件计算后的配置信息。
```shell
git config --级别 -l
```

# 初始化仓库

> 将目标目录初始化成 git 可以管理的仓库，会生成一个 `.git` 目录。
```shell
git init
```

# 将目标文件移动到暂存区

> 将目标文件移动到暂存区
```shell
git add 目标文件
```

# 将目标文件提交更改（提交到当前分支）

> 将目标文件提交更改（提交到当前分支）
```shell
git commit -m "提交说明"
```

# 将目标文件提交到远程仓库

> 创建SSH Key；会在目录 `C:\Users\用户名\.ssh` 中生成 `id_rsa.pub` 文件。
```shell
ssh-keygen -t rsa -C "邮箱"
```

> 登录 github，打开账户设置，进入 `SSH Keys` 页面，点击`Add SSH key`，title填是谁的公钥，key填 `id_rsa.pub` 中的所有内容，点击 Add Key 完成公钥添加。

> 设置远程仓库
```shell
git remote add origin 远程仓库地址
```

> 推送；-u是推送并关联的意思，仅在首次提交使用
```shell
git push -u origin master
```

# 将远程仓库克隆到本地

```shell
git clone 目标地址
```