[Kubernetes 基础教程](https://jimmysong.io/book/kubernetes-handbook/)
[Kubernetes 中文社区](http://docs.kubernetes.org.cn/)
[Kubernetes 官方教程](https://kubernetes.io/zh-cn/docs/tutorials/)

```
Control Plane (控制平面)
    │
    ├── Master Node (主节点)
    │   │
    │   ├── kube-apiserver (API 服务器)
    │   ├── kube-scheduler (调度器)
    │   ├── kube-controller-manager (控制器管理器)
    │   └── etcd (分布式键值存储)
    │
    ├── Worker Node (工作节点)
    │   │
    │   ├── Pod (k8s 最小部署单元)
    │   │   ├── Container (容器)
    │   │   └── Container
    │   │
    │   ├── Pod
    │   └── Pod
    │
    └── Worker Node (工作节点)
```

对于每个 Cluster

* 控制面调度整个集群
* 节点负责运行应用
* 部署到多台物理机上
* 一个 Node 对应一台物理机（虚拟机）    

<br>

---

## Getting started

[文档](https://kubernetes.io/docs/setup/production-environment/tools/kubeadm/install-kubeadm/#installing-kubeadm-kubelet-and-kubectl)

[参考](https://www.cnblogs.com/Sunzz/p/15184167.html)

1. 下载工具

    ```bash
    sudo apt install -y apt-transport-https ca-certificates curl gpg
    ```
    * `apt-transport-https` 允许 APT 使用 HTTPS 协议来传输包数据
    * `ca-certificates` 安装和维护系统信任的根证书集合
    * `gpg` 验证软件包的签名

2. 下载签名

    ```bash
    curl -fsSL https://pkgs.k8s.io/core:/stable:/v1.30/deb/Release.key │ sudo gpg --dearmor -o /etc/apt/keyrings/kubernetes-apt-keyring.gpg
    ```

3. 添加 `Kubernetes` 的 `apt` 存储库

    ```bash
    echo 'deb [signed-by=/etc/apt/keyrings/kubernetes-apt-keyring.gpg] https://pkgs.k8s.io/core:/stable:/v1.30/deb/ /' │ sudo tee /etc/apt/sources.list.d/kubernetes.list
    ```

4. 更新 `apt` 包索引，安装 `kubelet`、`kubeadm` 和 `kubectl`，并固定其版本

    ```bash
    sudo apt-get update
    sudo apt-get install -y kubelet kubeadm kubectl
    sudo apt-mark hold kubelet kubeadm kubectl
    ```

5. 在运行 `kubeadm` 之前启用 `kubelet` 服务

    ```bash
    sudo systemctl enable --now kubelet
    ```

6. 配置 `Docker` 和 `kubelet` 使用相同的 `cgroup` 驱动程序

7. 

<br>

---

## kubectl


<br>

---

## kubelet




<br>

---

## Kubeadm



<br>

---

## Minikube

小小的容器编排平台

[文档](https://minikube.sigs.k8s.io/docs/start/)

```sh
curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
sudo install minikube-linux-amd64 /usr/local/bin/minikube && rm minikube-linux-amd64
```