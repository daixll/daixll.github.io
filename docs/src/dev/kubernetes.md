## 参考

* [Kubernetes一小时轻松入门](https://www.youtube.com/watch?v=SL83f7Nzxr0/)

* [Kubernetes 进阶训练营(第3期)](https://www.qikqiak.com/k3s/)

* [Kubernetes 基础教程](https://jimmysong.io/book/kubernetes-handbook/)

* [Kubernetes 中文社区](http://docs.kubernetes.org.cn/)

* [Kubernetes 官方教程](https://kubernetes.io/zh-cn/docs/tutorials/)



## 架构

```
├── Master Node (主节点，也称为 Control Plane 控制平面)
│   ├── kube-apiserver          (API 服务器)
│   ├── kube-scheduler          (调度器)
│   ├── kube-controller-manager (控制器管理器)
│   └── etcd                    (分布式键值存储)
│
├── Worker Node (工作节点，一台物理/虚拟机上可以有多个工作节点)
│   │
│   ├── Kubelet                 
│   ├── kube-proxy              (网络代理, 负载均衡)
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

### 节点

1. 安装环境：[文档](https://kubernetes.io/docs/setup/production-environment/tools/kubeadm/install-kubeadm/#k8s-install-0) / [参考](https://www.cnblogs.com/Sunzz/p/15184167.html)

```shell
curl -fsSL https://pkgs.k8s.io/core:/stable:/v1.31/deb/Release.key | sudo gpg --dearmor -o /etc/apt/keyrings/kubernetes-apt-keyring.gpg
echo 'deb [signed-by=/etc/apt/keyrings/kubernetes-apt-keyring.gpg] https://pkgs.k8s.io/core:/stable:/v1.31/deb/ /' | sudo tee /etc/apt/sources.list.d/kubernetes.list
sudo apt-get update
sudo apt-get install -y kubelet kubeadm kubectl
sudo apt-mark hold kubelet kubeadm kubectl
sudo systemctl enable --now kubelet
```

2. 安装 Container Runtime：[Containerd](./containerd.md)

3. 检查环境

```shell
kubeadm version
kubectl version
containerd --version
```



### 控制平面




<br>

---


### Minikube

小小的容器编排平台：[文档](https://minikube.sigs.k8s.io/docs/start/)

```sh
curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
sudo install minikube-linux-amd64 /usr/local/bin/minikube && rm minikube-linux-amd64
```
