[Kubernetes 基础教程](https://jimmysong.io/book/kubernetes-handbook/)

* 对于每个 asdasd

    * 控制面调度整个集群
    * 节点负责运行应用
    * 部署到多台物理机上
        

    ```
    Control Plane (控制平面)
        |
        ├── Master Node (主节点)
        |   |
        |   ├── kube-apiserver (API 服务器)
        |   ├── kube-scheduler (调度器)
        |   ├── kube-controller-manager (控制器管理器)
        |   └── etcd (分布式键值存储)
        |
        ├── Worker Node (工作节点)
        |   |
        |   ├── Pod (k8s 最小部署单元)
        |   |   ├── Container (容器)
        |   |   └── Container
        |   |
        |   ├── Pod
        |   └── Pod
        |
        └── Worker Node (工作节点)
    ```

<br>

---

## Kubectl

* 对集群进行操作的玩意儿

### 安装



<br>

---

## Minikube

* 小小的容器编排平台

### 安装

[文档](https://minikube.sigs.k8s.io/docs/start/)

```sh
curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
sudo install minikube-linux-amd64 /usr/local/bin/minikube && rm minikube-linux-amd64
```

<br>

---

## Kubernetes

* 容器编排平台

### 安装

[文档](https://kubernetes.io/docs/tasks/tools/install-kubectl-linux/)

```sh
curl -LO "https://dl.k8s.io/release/$(curl -L -s https://dl.k8s.io/release/stable.txt)/bin/linux/amd64/kubectl"
sudo install -o root -g root -m 0755 kubectl /usr/local/bin/kubectl
kubectl version --client --output=yaml
```
