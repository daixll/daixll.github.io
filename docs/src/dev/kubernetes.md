## 参考

* [Kubernetes一小时轻松入门](https://www.youtube.com/watch?v=SL83f7Nzxr0/)

* [Kubernetes 进阶训练营(第3期)](https://www.qikqiak.com/k3s/)

* [Kubernetes 基础教程](https://jimmysong.io/book/kubernetes-handbook/)

* [Kubernetes 中文社区](http://docs.kubernetes.org.cn/)

* [Kubernetes 官方教程](https://kubernetes.io/zh-cn/docs/tutorials/)



## 架构

```
├── remote
│   ├── kubectl
│   └── kubectl-convert
│
│
├── Master Node (主节点，也称为 Control Plane 控制平面)
│   ├── kube-apiserver          (API 服务器)
│   ├── apiextensions-apiserver (API 扩展)
│   ├── kube-aggregator         (API 聚合器)
│   ├── kube-log-runner         (日志调试)
│   ├── kube-scheduler          (调度器)
│   ├── kube-controller-manager (控制器管理器)
│   └── etcd                    (分布式键值存储)
│
├── Worker Node (工作节点，一台物理/虚拟机上可以有多个工作节点)
│   │
│   ├── Kubeadm                 (初始化集群)
│   ├── Kubelet                 (管理节点上的 Pod)
│   ├── kube-proxy              (网络代理, 负载均衡)
│   ├── mounter                 (挂载器, 管理存储卷的挂载和卸载)
│   └── Container-Runtime       (容器运行时, 如 Docker)
│       ├── Pod                 (k8s 最小部署单元)
│       │   └── Container       (容器, 建议一个 Pod 一个 Container)
│       ├── Pod
│       └── Pod
│
└── Worker Node (工作节点)
```

<br>

---

## Getting started

[文档](https://kubernetes.io/zh-cn/docs/setup/production-environment/tools/kubeadm/install-kubeadm/)

1. 禁用交换空间

    ```shell
    sed -i '/\bswap\b/ s/^/#/' /etc/fstab
    swapoff -a
    ```

    > 在 `/etc/fstab` 文件中查找所有包含 `swap` 的行，并在行首添加 `#`，将这些行注释掉，然后关闭交换空间

    ```shell
    free -h
    cat /proc/swaps
    ```

    > 成功关闭后，应该是 `0`

2. 启用 IPv4 转发

    ```shell
    cat <<EOF | sudo tee /etc/sysctl.d/k8s.conf
    net.ipv4.ip_forward = 1
    EOF
    
    sudo sysctl --system
    ```

    > 在 `/etc/sysctl.d/` 目录下创建一个 `k8s.conf` 文件，写入 `net.ipv4.ip_forward = 1`，然后重新加载配置

    ```shell
    sysctl net.ipv4.ip_forward
    ```

    > 检查是否启用成功，应该是 `1`
    

3. 安装 Container Runtime

    * 安装 [Containerd](./containerd.md) 后配置 `containerd`
    
        ```shell
        sudo mkdir -p /etc/containerd
        containerd config default | sudo tee /etc/containerd/config.toml
        sudo vim /etc/containerd/config.toml
        ```

        > ```toml
        > [plugins."io.containerd.grpc.v1.cri".containerd.runtimes.runc]
        >   runtime_type = "io.containerd.runc.v2"
        >   [plugins."io.containerd.grpc.v1.cri".containerd.runtimes.runc.options]
        >     SystemdCgroup = true
        > ```
        > 
        > > 确保 `SystemdCgroup` 为 `true`
        >
        > ```toml
        > disabled_plugins = []
        > ```
        >
        > > 确保 `disabled_plugins` 中没有 `cri` 插件

        ```shell
        sudo systemctl restart containerd
        ```

        > 重启 `containerd` 服务

4. 安装 `kubeadm` `kubelet` 和 `kubectl`

    ```shell
    curl -fsSL https://pkgs.k8s.io/core:/stable:/v1.31/deb/Release.key | sudo gpg --dearmor -o /etc/apt/keyrings/kubernetes-apt-keyring.gpg
    echo 'deb [signed-by=/etc/apt/keyrings/kubernetes-apt-keyring.gpg] https://pkgs.k8s.io/core:/stable:/v1.31/deb/ /' | sudo tee /etc/apt/sources.list.d/kubernetes.list
    sudo apt-get update
    sudo apt-get install -y kubelet kubeadm kubectl
    sudo apt-mark hold kubelet kubeadm kubectl
    sudo systemctl enable --now kubelet
    systemctl enable kubelet
    ```

    > 官网的脚本，只增加了一个开机自启

5. 初始化 / 加入集群

    ```shell
    kubeadm init
    ```

    ```shell
    mkdir -p $HOME/.kube
    sudo cp -i /etc/kubernetes/admin.conf $HOME/.kube/config
    sudo chown $(id -u):$(id -g) $HOME/.kube/config
    ```

    > 在 **控制平面** 上执行上述命令会初始化一个 Kubernetes 集群，输出的最后会有一个 `kubeadm join` 命令，用于将其他节点加入集群
    > 
    > 在 **控制平面** 上执行上述命令，将 `kubeconfig` 文件拷贝到用户目录下

    ```shell
    kubeadm join <control-plane-host>:<control-plane-port> --token <token> --discovery-token-ca-cert-hash sha256:<hash>
    ```

    > 在 **工作节点** 上执行上述命令，将节点加入集群

6. 安装 `cni` 网络插件

    ```shell
    kubectl apply -f https://reweave.azurewebsites.net/k8s/v1.29/net.yaml
    ```

    > 安装网络插件，这里使用的是 `weave` 插件

7. 在控制平面上查看集群状态

    ```shell
    kubectl get nodes
    ```

    > 查看节点状态

8. 

<br>

---


## kubelet

与容器运行时交互，依赖 `CRI` 容器运行时接口

<br>

---

## kubeadm

用于初始化集群、加入节点、重置集群等操作

### 通过配置文件部署

```yaml
apiVersion: kubeadm.k8s.io/v1beta3
kind: ClusterConfiguration
kubernetesVersion: "stable-1.31"
controllerManagerExtraArgs:
  horizontal-pod-autoscaler-use-rest-clients: "true"
  horizontal-pod-autoscaler-sync-period: "10s"
  node-monitor-grace-period: "10s"
apiServerExtraArgs:
  runtime-config: "api/all=true"
```


### 完整清理 k8s 集群

```shell
sudo kubeadm reset
sudo rm -rf /etc/kubernetes /var/lib/etcd
sudo rm -rf $HOME/.kube
```


<br>

---

## kubectl

用于控制平面进行操作，如创建、删除、更新资源

### 查看集群相关信息

获取集群信息，包括 API 服务器地址、DNS 等

```shell
kubectl cluster-info
```
获取节点信息

```shell
kubectl get nodes
```

获取组件信息

```shell
kubectl get cs
```

### 查看 Pod 相关信息

获取系统级别的 Pod 信息

```shell
kubectl get pods -n kube-system
```

