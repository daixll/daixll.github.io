---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

## 计算机网络

* [概述]()  
* 网络接口层
  * [物理层]()
  * [数据链路层]()
* 网际层
  * [网络层]() IPV4, IPV6
* 传输层
  * [运输层]() TCP, UDP
* 应用层
  * [会话层]() SMB, DNS
  * [表示层]() telnet, ftp
  * [应用层](./计算机网络/应用层.html) HTTP, DNS

* 实验 H3C
  * [实验1：静态ECMP和浮动路由配置实验](./计算机网络/实验1：静态ECMP和浮动路由配置实验.html)

* [华为 OSPF 的错误](./计算机网络/huaweiOSPF.html)





# 静态ECMP

静态ECMP（Equal-CostMultipathRouting）是一种在网络环境中使用的等值多路径路由协议。

在存在多条不同链路到达同一目的地址的情况下，如果使用传统的路由技术，发往该目的地址的数据包只能利用其中的一条链路，其它链路处于备份状态或无效状态，并且在动态路由环境下相互的切换需要一定时间。而静态ECMP可以在该网络环境下同时使用多条链路，不仅增加了传输带宽，并且可以无时延无丢包地备份失效链路的数据传输。

静态ECMP最大的特点是实现了等值情况下，多路径负载均衡和链路备份的目的。

![Alt text](IMAGE/1.1.png)

配置完成后，`PC_1` `PC_2` 互相 `ping` 通。



* 配置 `PC_1` `PC_2`

* 配置 `MSR36-20_1` 各个接口IP

```shell
# 进入接口配置模式
[MSR36-20_1] interface g0/0 
# 配置接口 IP 地址
[MSR36-20_1-GigabitEthernet0/0] ip address 192.168.0.1 24
# 退出接口 
[MSR36-20_1-GigabitEthernet0/0] quit
```
```cpp
[MSR36-20_1] interface g0/1
[MSR36-20_1-GigabitEthernet0/1] ip address 192.168.1.1 30
[MSR36-20_1-GigabitEthernet0/1] quit
```
```cpp
[MSR36-20_1] interface s4/0
[MSR36-20_1-Serial4/0] ip address 192.168.1.5 30
[MSR36-20_1-Serial4/0] quit
```

* 配置 `MSR36-20_1` 静态路由

```shell
# 进入静态路由配置模式
# 目的网段：192.168.2.0/24，下一跳：192.168.1.2
[MSR36-20_1] ip route-static 192.168.2.0 24 192.168.1.2
[MSR36-20_1] ip route-static 192.168.2.0 24 192.168.1.6
```


<details><summary> 配置 MSR36-20_2 各个接口 IP</summary>

```shell
[MSR36-20_2] interface g0/0
[MSR36-20_2-GigabitEthernet0/0] ip address 192.168.2.1 24
[MSR36-20_2-GigabitEthernet0/0] quit
```
```shell
[MSR36-20_2] interface g0/1
[MSR36-20_2-GigabitEthernet0/1] ip address 192.168.1.2 30
[MSR36-20_2-GigabitEthernet0/1] quit
```
```shell
[MSR36-20_2] interface s4/0
[MSR36-20_2-Serial4/0] ip address 192.168.1.6 30
[MSR36-20_2-Serial4/0] quit
```
</details>

<details><summary> 配置 MSR36-20_2 静态路由</summary>

```shell
[MSR36-20_2] ip route-static 192.168.0.0 24 192.168.1.1
[MSR36-20_2] ip route-static 192.168.0.0 24 192.168.1.5
```

</details>

# 浮动路由




# 杂项

文本写作日期：2023-9-30

相关网站：
* [RFC2328](https://datatracker.ietf.org/doc/html/rfc2328)
* [wiki](https://en.wikipedia.org/wiki/Open_Shortest_Path_First)
* [cisio OSPF](https://www.cisco.com/c/en/us/support/docs/ip/open-shortest-path-first-ospf/7039-1.html#toc-hId--84793321)
* [华为 OSPF EN](https://info.support.huawei.com/info-finder/encyclopedia/en/OSPF.html)
* [华为 OSPF ZH](https://info.support.huawei.com/info-finder/encyclopedia/zh/OSPF.html)
* [新华三 OSPF CN](https://www.h3c.com/cn/d_200805/605874_30003_0.htm)

---
几个概念：

### OSPF：Open Shortest Path First

在路由中，感知网络拓扑，计算最短路径，建立路由表

### SPF：Shortest Path First

通过此算法计算最短路径，此算法也被称为 Dijkstra 算法

### SPT：Shortest Path Tree 最短路径树 

在所有生成树中，最短路径树满足根节点到其他所有点的 **距离之和** 最短

### MST：Minimum Spanning Tree 最小生成树 

在所有生成树中，最小生成树满足 **边权之和** 最小

---
一个样例：

![Alt text](./IMAGE/huaweiospf.png)

由左边的图，以 A 为根结点，可以得到两颗树

* 生成树 1：
    * 距离之和：（由 A 到其他所有点的距离之和为 5）
        A->B：2
        A->C：3
    * 边权之和：（边权之和为 5）
        A->B：2
        A->C：3
    
* 生成树 2：
    * 距离之和：（由 A 到其他所有点的距离之和为 6）
        A->B：2
        A->C：4
    * 边权之和：（边权之和为 4）
        A->B：2
        B->C：2

显然，生成树 1 的距离之和最小，所以生成树 1 是最短路径树
而，生成树 2 的边权之和最小，所以生成树 2 是最小生成树

---

在华为对 OSPF 的中文介绍中，有这样一句话：

![Alt text](./IMAGE/huaweiospf1.png)

这个配图的文字（最小生成树）显然是错的，应当是最短路径树。

值得一提的是，华为对 OSPF 的英文介绍中，却又是对的：

![Alt text](./IMAGE/huaweiospf2.png)


---

![Alt text](./IMAGE/huaweiospf3.png)