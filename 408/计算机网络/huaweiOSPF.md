---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

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