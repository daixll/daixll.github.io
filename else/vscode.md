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


# C++

win10 22H2 使用 wsl 下的 gcc 编译器，配置竞赛友好的环境

1. 微软商店下载 `ubuntu`，vscode 下载拓展 `WSL`

2. `控制面板\程序\启用或关闭 Windows 功能`：
    * `Hyper-V`
    * `虚拟机平台`
    * `适用于 Linux 的 Windows 子系统`

3. vscode 连接到 WSL，下载拓展 `C++`
    * 我们仅需 `C++` 的代码提示（IntelliSense）功能
    * 如果你不需要代码提示也可以不下

4. 进入 ubuntu 环境，下载 `gcc`
    * `sudo apt install gcc`

5. 创建配置文件 `.vscode/tasks.json`
```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "AC",    // 任务名
      "type": "shell",  // 此任务在 shell 下执行；（command）执行命令
      "command": "g++ -std=c++17 '${file}' -o '${fileDirname}/exes/${fileBasenameNoExtension}' && cat '${fileDirname}/exes/in' | '${fileDirname}/exes/${fileBasenameNoExtension}' > '${fileDirname}/exes/out' && sync",
      "problemMatcher": [   // 捕捉错误
        "$gcc"
      ]
    }
  ]
}
```

文件结构如此
```
├── .vscode/
|   ├── tasks.json   
|
└── exes/
|   ├── ac
|   ├── in
|   ├── out
|
├── ac.cpp
```

使用 `g++` 编译源文件 `ac.cpp`，生成可执行文件 `ac`，
将 `in` 的数据输入到 `ac`，`ac` 再输出到 `out`。

6. 配置快捷方式，f5一键执行命令
    修改 `C:\Users\用户名\AppData\Roaming\Code\User\keybindings.json` 文件
    ```json
    // 将键绑定放在此文件中以覆盖默认值auto[]
    [
    {
        "key": "f5",
        "command": "workbench.action.tasks.runTask",
        "args": "AC"
    }
    ]
    ```