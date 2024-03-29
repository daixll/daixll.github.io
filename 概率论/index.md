---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

> 如果不挂科，不考数一、三，大抵是不会更新了

> 尼玛，挂了。。。

概率论研究 **不确定** 事件发生的 **可能性**

事件可以推导出概率，概率 **不可以** 推导出事件

<br>

---

# 一、概率论的基本概念

## 0、题

### 全概率与贝叶斯(1)

全概率公式：
    
**$$P(B) = \sum_{i=1}^n P(B|A_i) P(A_i)$$**

贝叶斯公式：

**$$P(A_j|B) = \frac{P(B|A_j) P(A_j)}{\sum_{i=1}^n P(B|A_i) P(A_i)}$$**

<br>

> 有 $10$ 箱产品，$1, 2, 3$ 分别有 $5, 3, 2$ 箱，次品率为 $0.1, 0.2, 0.3$，任选一箱，再取一个产品，为良品的概率

$A$ 为抽到某家的概率
$B$ 为良品的概率

$P(A_1) = 0.5, P(B_1 | A_1) = 0.9$
$P(A_2) = 0.3, P(B_2 | A_2) = 0.8$
$P(A_3) = 0.2, P(B_3 | A_3) = 0.7$

$P(B) = 0.9*0.5 + 0.8*0.3 + 0.7*0.2 = 0.83$

<br>

> $1, 2, 3$ 三车间加工一产品，加工量占总量的 $0.25, 0.35, 0.40$，次品率分别为 $0.03, 0.02, 0.01$，现从所有产品中抽取一个产品：（1）求产品为次品的概率；（2）是次品，次品来自 $2$ 车间的概率

$A$ 为抽到某家的概率
$B$ 为次品的概率

$P(A_1) = 0.25, P(B_1 | A_1) = 0.03$
$P(A_2) = 0.35, P(B_2 | A_2) = 0.02$
$P(A_3) = 0.40, P(B_3 | A_3) = 0.01$

$P(B) = 0.03 * 0.25 + 0.02 * 0.35 + 0.01 * 0.40 = 0.0185$

$P(A_2|B) = \frac{0.02*0.35}{0.0185} = 0.378$


<br>

> 三个箱子，第 $1$ 箱有 $7$ 个黑球和 $1$ 个白球，第 $2$ 箱有 $3$ 个黑球和 $3$ 个白球，第 $3$ 箱有 $5$ 个黑球和 $3$ 个白球，现任取一箱（取到每个箱子是等可能的），再任取一球：（1）求取到的是白球的概率；（2）是白球，则属于第 $2$ 箱的概率

$A$ 为抽到某箱的概率
$B$ 为抽到白球的概率

$P(A_1) = \frac{1}{3}, P(B_1 | A_1) = \frac{1}{8}$
$P(A_2) = \frac{1}{3}, P(B_2 | A_2) = \frac{3}{6}$
$P(A_3) = \frac{1}{3}, P(B_3 | A_3) = \frac{3}{8}$

$P(B) = \frac{1}{8}*\frac{1}{3} + \frac{3}{6}*\frac{1}{3} + \frac{3}{8}*\frac{1}{3} = \frac{1}{3}$

$P(A_2|B) = \frac{\frac{3}{6} * \frac{1}{3}}{ \frac{1}{3} } = \frac{1}{2}$

<br>

> 甲乙丙三人同时向一架飞机射击，设击中飞机的概率分别为 $0.4, 0.5, 0.7$，若只有 $1$ 人击中飞机，则飞机被击落的概率为 $0.2$，若有 $2$ 人击中飞机，则飞机被击落的概率为 $0.6$，若三人击中飞机，则飞机一定被击落，求飞机被击落的概率

$A$ 有几人击中飞机的概率
$B$ 飞机被击落的概率

$P(A_1) = 0.4(中)*0.5*0.3 + 0.6*0.5(中)*0.3 + 0.6*0.5*0.7(中) = 0.36$
$P(A_2) = 0.4(中)*0.5(中)*0.3 + 0.6*0.5(中)*0.7(中) + 0.4(中)*0.5*0.7(中) = 0.41$
$P(A_3) = 0.4(中)*0.5(中)*0.7(中) = 0.14$

$P(B_1 | A_1) = 0.2$
$P(B_2 | A_2) = 0.6$
$P(B_3 | A_3) = 1$

$P(B) = 0.2*0.36 + 0.6*0.41 + 1*0.14 = 0.458$

<br>

> 某道单项选择题（$4$ 个选项），不会做的学生从中随机选择，假定学生会做此题的概率为 $0.7$：（1）学生答对此题的概率；（2）答对此题的学生确实会做的概率

$A$ 为确实会做的概率
$B$ 为答对此题的概率

$P(A) = 0.7, P(B|A) = 1$
$P(\bar A) = 0.3, P(B|\bar A) = \frac{1}{4}$

$P(B) = 1*0.7 + \frac{1}{4}*0.3 = 0.775$

$P(A|B) = \frac{1*0.7}{0.775} = \frac{28}{31}$

<br>

> 某病人发烧，认为病人患 $A, B, C$ 三种病的概率分别为 $0.5, 0.2, 0.3$，在这三种病之下，发烧的概率分别为 $0.2, 0.5, 0.8$，请推断该病人发烧由那一种病引起的可能性比较大

$D$ 为病人患病的概率
$E$ 为病人发烧的概率

$P(D_A)=0.5, P(E|D_A) = 0.2$
$P(D_B)=0.2, P(E|D_B) = 0.5$
$P(D_C)=0.3, P(E|D_C) = 0.8$

$P(E) = 0.2 * 0.5 + 0.5 * 0.2 + 0.8 * 0.3 = 0.44$

$P(D_A|E) = \frac{0.2 * 0.5}{0.44} = 0.227$

$P(D_B|E) = \frac{0.5 * 0.2}{0.44} = 0.227$

$P(D_C|E) = \frac{0.8 * 0.3}{0.44} = 0.545$

病人发烧由 $C$ 病引发的可能性大

<br>

> $A$ 患者占 $0.35$，$B$ 患者占 $0.6$，$C$ 患者占 $0.05$，又知患 $A, B, C$ 三种病的病人阳性的可能性分别为 $0.8, 0.3, 0.85$，每位患者只可能患一种病，现确认阳性，求该病人确实换 $A$ 病的概率

$A$ 为患者患病的概率
$B$ 为确认阳性的概率

$P(A_A) = 0.35, P(B_A | A_A) = 0.8$
$P(A_B) = 0.6, P(B_B | A_B) = 0.3$
$P(A_C) = 0.05, P(B_C | A_C) = 0.85$

$P(B) = 0.8*0.35 + 0.3*0.6 + 0.85*0.05 = 0.5025$

$P(A_A|B) = \frac{0.8*0.35}{0.5025} = 0.5572$


<br>

> 某地区肥胖者占 $0.1$，正常者占 $0.82$，瘦者占 $0.08$，又知肥胖患者高血压的概率为 $0.2$，正常者为 $0.1$，瘦者为 $0.05$：（1）求该地区高血压的概率；（2）患高血压，属于肥胖的概率

肥胖：$1$
正常：$2$
瘦弱：$3$

$A$ 为各种体型的概率
$B$ 为高血压的概率

$P(A_1) = 0.1, P(B_1|A_1) = 0.2$
$P(A_2) = 0.82, P(B_2|A_2) = 0.1$
$P(A_3) = 0.08, P(B_3|A_3) = 0.05$

$P(B) = 0.2*0.1 + 0.1*0.82 + 0.05*0.08 = 0.106$

$P(A_1|B) = \frac{0.2*0.1}{0.106} = 0.1886$

### 古典概率

> 已知 $P(A)=P(B)=P(C)=0.25$，$P(A \cap B) = P(B \cap C) = 0$，$P(A \cap C) = \frac{1}{8}$，（1）$A,B,C$ 同时发生的概率；（2）$A,B,C$ 至少发生一个的概率

$P(A \cap B \cap C) = 0$

$1-P(\bar A \cup \bar B \cup \bar C) = $

<br>

> 假设一个家庭中有两个小孩，（1）已知其中一个是女孩，求另外一个也是女孩的概率；（2）已知第一胎是女孩，求第二胎也是女孩的概率

女（姐姐），女（妹妹），女（哥哥），女（弟弟）
已知其中一个是女孩，另外一个也是女孩的概率是 $\frac{1}{2}$

生男生女都一样
已知第一胎是女孩，第二胎也是女孩的概率是 $\frac{1}{2}$

<br>

> 已知有两个口袋，甲袋中有 $2$ 个白球，$1$ 个黑球，乙袋中有 $1$ 个白球，$2$ 个黑球。由甲袋中任取一球放入乙袋，再从乙袋任取一球，问取得白球的概率是多少

<br>

> 假设有两箱同种零件，第一箱装 $50$ 件，其中 $10$ 件一等品；第二箱装 $30$ 件，其中 $18$ 件一等品。现从两箱中随机挑出一箱，然后从该箱中先后随机取两个零件（不放回），试求：（1）第一次取出的零件是一等品的概率；（2）在第一次取出的零件是一等品的条件下，第二次取出的零件仍然是一等品的概率


<br>

## 一、事件

### 事件的关系

* 包含：$A \subset B$，，$B$ 包含 $A$，事件 $A$ 发生必然导致事件 $B$ 发生

* 并：$A \cup B$，事件 $A$ 与 $B$ 至少发生一个

* 交：$A \cap B$，事件 $A$ 与 $B$ 同时发生，有时候也称为积，也写作 $AB$

* 差：$A - B$，事件 $A$ 发生而 $B$ 不发生

* 互斥：$A \cap B = \emptyset$，事件 $A$ 与 $B$ 不可能同时发生

* 逆（对立）：$\bar{A}$，事件 $A$ 不发生

* 互斥：$A \cap \bar{A} = \emptyset$，$A \cup \bar{A} = S$，事件 $A$ 与 $\bar{A}$ 互斥

### <span style="color:orange;">事件的运算</span>

* 交换律：$A \cup B = B \cup A$，$A \cap B = B \cap A$
* 结合律：$(A \cup B) \cup C = A \cup (B \cup C)$，$(A \cap B) \cap C = A \cap (B \cap C)$
* 分配律：$A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$，$A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$
* 德摩根律：$\overline{A \cup B} = \bar{A} \cap \bar{B}$，$\overline{A \cap B} = \bar{A} \cup \bar{B}$


### 频率

在相同条件下，进行了 $n$ 次试验，事件 $A$ 发生的次数 $n_A$ 与 $n$ 的比值

### <span style="color:orange;">概率</span>

事件 $A$ 发生的可能性大小的度量，记作 $P(A)$

性质：

* 非负性：$P(A) \geq 0$
* 规范性：$P(S) = 1$
* 可列可加性：若 $A_1, A_2, \cdots$ 两两互斥，则 $P(\bigcup_{i=1}^{\infty} A_i) = \sum_{i=1}^{\infty} P(A_i)$

根据性质拓展：

* $P(\emptyset) = 0$
* $P(\bar{A}) = 1 - P(A)$
* 若 $A \subset B$，则 $P(A) \leq P(B)$，有 $P(B - A) = P(B) - P(A)$
* <span style="color:red;">$P(A \cup B) = P(A) + P(B) - P(A \cap B)$</span>
    * <span style="color:red;">$P(A \cap B) = P(A|B) P(B)$</span>
    * 若独立，则 <span style="color:red;">$P(A \cap B) = P(A)P(B)$</span>
* <span style="color:red;">$P(A-B) = P(A) - P(A \cap B) = P(A \cap \bar B)$</span>

### <span style="color:orange;">条件概率</span>

在事件 $B$ 已经发生的条件下，事件 $A$ 发生的概率，记作 $P(A|B)$

<span style="color:red;">$P(A|B) = \frac{P(A \cap B)}{P(B)}$</span>

可拓展：
* 全概率公式：
    **<span style="color:red;">$P(A) = \sum_{i=1}^n P(A|B_i) P(B_i)$</span>**

* 贝叶斯公式：
    **<span style="color:red;">$P(B_j|A) = \frac{P(A|B_j) P(B_j)}{\sum_{i=1}^n P(A|B_i) P(B_i)}$</span>**

<br>

---

# 二、随机变量及其分布

## 0、题

### 分布律求分布函数

> 设随机变量 $X$ 与 $Y$ 独立分布，且他们取 $-1, 0, 1$ 三个值的概率分别为 $\frac{1}{6}, \frac{1}{3}, \frac{1}{2}$，则 $P\{X + Y = 0\}$

$P\{X + Y = 0\} = P\{X=-1, Y=1\} + P\{X=0, Y=0\} + P\{X=1, Y=-1\}$
$P\{X + Y = 0\} = \frac{1}{6} * \frac{1}{2} + \frac{1}{3} * \frac{1}{3} + \frac{1}{2} * \frac{1}{6}$
$P\{X + Y = 0\} = \frac{5}{18}$


<br>

### 概率密度求分布函数(2)

> 设随机变量 $X$ 服从 $(0, 2)$ 上的均匀分布，则 $P\{1 < X < 3\}$

$f(x) = \begin{cases} \frac{1}{b-a}, & a < x < b \\ 0, & \text{其他} \end{cases}$

$f(x) = \begin{cases} \frac{1}{2}, & 0 < x < 2 \\ 0, & \text{其他} \end{cases}$

$P\{1 < x < 3\} = \int_1^2 \frac{1}{2} \text{d}x$

$P\{1 < x < 3\} = \frac{1}{2}x |_1^2 = 1 - \frac{1}{2} = \frac{1}{2}$

<br>

> $f(x) = \begin{cases} Ke^{-5x}, x>0 \\ 0, x \leq 0 \end{cases}$，（1）确定 $K$；（2）求 $P\{X>0.2\}$

$\int_0^{+\infty} Ke^{-5x} = \int_0^{+\infty} -\frac{K}{5} e^{-5x} \text{d}(-5x) = 1$

$= -\frac{K}{5}e^{-5x} |_0^{+\infty} = \frac{K}{5} = 1$

$K = 5$

$\int_{0.2}^{+\infty} 5e^{-5x} \text{d}x = \int_{0.2}^{+\infty} -\frac{5}{5} e^{-5x} \text{d}(-5x) = -e^{-5x}|_{0.2}^{+\infty} = e^{-1}$

<br>

### 概率密度求概率密度(4)

> 设 $X \sim f_X(x) = \begin{cases} \frac{x}{8}, 0<x<4\\ 0, 其他\end{cases}$，求 $Y=2X+8$ 的密度函数 $f_Y(y)$

$F_Y(y) = P(Y \leq y) = P(2X+8 \leq y) = P(X \leq \frac{y-8}{2}) = F_X(\frac{y-8}{2})$

$f_Y(y) = \begin{cases} f_x(h(y))*|h^{'}(y)| , a < y < b\\ 0, 其他\end{cases}$

$f_Y(y) = \begin{cases} \frac{\frac{y-8}{2}}{8}*|(\frac{y-8}{2})^{'}| , a < y < b\\ 0, 其他\end{cases}$

* 错误做法
    $F_Y(y) = \int_0^{\frac{y-8}{2}} \frac{x}{8} \text{d}x = \frac{x^2}{16}|_0^\frac{y-8}{2} = \frac{(y-8)^2}{64}$
    $F_Y^{'}(y) = f_Y(y) = (\frac{1}{64}y^2 - \frac{1}{4}y + 1)^{'} = \frac{y-8}{32}$

$f_Y(y) = \begin{cases} \frac{y-8}{32}, 8<y<16 \\ 0, 其他 \end{cases}$

<br>

> 设 $X \sim f_X(x) = \begin{cases} \frac{x}{8}, 0<x<4\\ 0, 其他\end{cases}$，求 $Y=2X-1$ 的密度函数 $f_Y(y)$

$F_Y(y) = P(Y \leq y) = P(2x-1 \leq y) = P(x \leq \frac{y+1}{2}) = F_X(\frac{y+1}{2})$

$f_Y(y) = \begin{cases} f_x(h(y))*|h^{'}(y)| , a < y < b\\ 0, 其他\end{cases}$

$f_Y(y) = \begin{cases} \frac{\frac{y+1}{2}}{8}*|(\frac{y+1}{2})^{'}| , a < y < b\\ 0, 其他\end{cases}$


* 错误做法

    $F_Y(y) = \int_0^\frac{y+1}{2} \frac{x}{8} \text{d}x = \frac{x^2}{16}|_0^\frac{y+1}{2} = \frac{(y+1)^2}{64}$
    $F_Y^{'}(y) = f_Y(y) = \frac{y+1}{32}$



$f_Y(y) = \begin{cases} \frac{y+1}{32}, -1<y<7 \\ 0, 其他 \end{cases}$

<br>


### P

> 设离散型随机变量 $X$ 的分布律为 $P\{X=k\}=\frac{A}{3^kk!},k=1,2...$，则 $A$

泊松分布 $P\{X=k\} = \frac{\lambda^k}{k!}e^{-\lambda}$

$\frac{\lambda^k e^{-\lambda}}{k!} = \frac{\frac{1}{3^k}A}{k!}$

$\lambda^k e^{-\lambda} = (\frac{1}{3})^kA$，令$ \lambda = \frac{1}{3} $

$ A = e ^ {-\frac{1}{3}}$

<br>

---

## 1、随机变量及分布函数

### 随机变量

随机变量就是随机试验结果的 **数值化**

> 例如：**抛硬币**，正面为 **1**，反面为 **0**
> 例如：**选球**，红球为 **1**，白球为 **2**，黑球为 **3**

数值化后，更有利于建立数学模型，进行数学分析

### 分布函数

对于一个随机变量 $X$，其分布函数 $F(x)$ 定义为： 

$$F(x) = P \{X \leq x\}$$

$F(x)$ 等于 $X$ 的值 $\leq x$ 的 **概率**

> 具体的，假设我们在抛一个六面骰子，那么 $F(x)$ 就是：
> 
> x | 1 | 2 | 3 | 4 | 5 | 6
> :-:|:-:|:-:|:-:|:-:|:-:|:-:
> F(x) | 1/6 | 2/6 | 3/6 | 4/6 | 5/6 | 6/6
> 
> $F(3)$ 指，抛出的骰子的点数小于等于 $3$ 的概率，即 $1/2$
> $F(4)$ 指，抛出的骰子的点数小于等于 $4$ 的概率，即 $2/3$

> [知乎](https://www.zhihu.com/question/26298175/answer/60140036) 上有一个更加形象的解释：
>
> 假设现在有全世界所有人的身高的分布，那么我们可以得到一个分布函数
>
> 我的身高 $180$，那么 $F(180)$ =  $\frac{身高 <= 180 的人数}{全世界人数}$
>
> 姚明身高 $226$，那么 $F(226)$ =  $\frac{身高 <= 226 的人数}{所有的人数}$

其具有以下性质：

* 单调不减：$x_1 < x_2 \Rightarrow F(x_1) \leq F(x_2)$
* 非负性：$0 \leq F(x) \leq 1$
* 规范性：$F(x)$ 是一个概率，$F(-\infty) = 0$，$F(+\infty) = 1$

<br>

---

## 2、离散型随机变量 / 分布律

离散型随机变量：
* 指其取值为 **有限个** 数值的随机变量
* 在取值上是有间隔的
* 通常描述可以数出来、可以分隔的随机现象

离散型随机变量的分布律：
* 一个函数，描述了随机变量的取值和其概率的对应关系
* 表示为：$P(X=x_i) = p_i$，满足：
    * 对于所有的 $i$，$p_i \geq 0$，即概率非负
    * $\sum p_i = 1$，即概率和为 $1$

> 例如，抛一个六面骰子，随机变量 $X$ 表示抛出的点数，那么 $X$ 的分布律为：
> X | 1 | 2 | 3 | 4 | 5 | 6
> :-:|:-:|:-:|:-:|:-:|:-:|:-:
> p(X) | 1/6 | 1/6 | 1/6 | 1/6 | 1/6 | 1/6

### 0-1分布

设随机变量 $X$ 只能取 $0$ 或 $1$，其分布律为：

X | 0 | 1
:-:|:-:|:-:
p(X) | 1-p | p

分布函数：

$$ P \{ X=k \} = p^k (1-p)^{1-k} $$ $$ 其中 (k=0,1), (0<p<1) $$

### 二项分布 $B$

二项分布是 $n$ 重伯努利试验

> * 伯努利试验
>   设试验 $E$ 只有两个可能结果：$A$（事件 $A$ 发生）和 $B$（事件 $A$ 不发生，也称 $\bar{A}$），且 $P(A) = p$，$P(B) = 1-p$，则称 $E$ 为一次伯努利试验
> * n重伯努利试验
> 将上述试验 $E$ 重复 $n$ 次，称为 $n$ 重伯努利试验

设 $X$ 为 $n$ 重伯努利试验中事件 $A$ 发生的次数，则 $X$ 服从参数为 $n$ 和 $p$ 的二项分布，记作：
$$X \sim b(n,p)$$

二项分布的分布函数：

$$P \{ X=k \} = {C_n^k} p^k (1-p)^{n-k}$$ $$其中, k 表示成功的次数, n 表示试验的总次数, p 表示每次试验成功的概率(不变)$$

特殊的，当 $n=1$ 时，二项分布就是 0-1 分布

### 泊松分布 $P$

泊松分布的分布函数：

$$P \{ X=k \} = \frac{\lambda^k}{k!} e^{-\lambda}$$ $$其中, k=0,1,2,..., \lambda > 0$$

记作：

$$ X \sim P(\lambda) $$

> 单位时间内，某一件事情发生的次数
> 常见的：单位时间内，某一机器发生故障的次数，单位时间内，某一服务台接待的顾客数

### 几何分布 $G$

几何分布的分布函数：

$$P \{ X=k \} = (1-p)^{k-1} p$$ $$其中, k=1,2,3,..., 0<p<1$$

记作：

$$ X \sim G(p) $$


<br>

---

## 3、连续型随机变量 / 概率密度

连续型随机变量：

* 指其取值为 **无限个** 数值的随机变量
* 在取值上是无间隔的

> 例如：**时间**，**长度**，**面积**

概率密度函数：

* 计算随机变量落在某个区间内的概率

对于随机变量 $X$，存在非负可积函数 $f(x)$，使得对于任意实数 $x$，有：

$$F(x) = \int_{-\infty}^{x} f(t) dt$$ $$其中, -\infty < x < +\infty$$

$x$ 为连续型随机变量，$f(x)$ 称为 $X$ 的概率密度函数

### 均匀分布 $U$

若连续型随机变量 $X$ 的概率密度函数为：

$$f(x) = \begin{cases} \frac{1}{b-a}, & a < x < b \\ 0, & \text{其他} \end{cases}$$

则 $X$ 在区间 $(a,b)$ 上服从 **均匀分布**，记作：

$$X \sim U(a,b)$$

* 对于随机变量 $X$，落在区间 $a,b$ 中任意 **等长度** 的子区间的概率相等

* 概率密度函数为常数，区间内所有点的概率密度相等


### 指数分布 $E$

若连续型随机变量 $X$ 的概率密度函数为：

$$f(x) = \begin{cases} \lambda e^{-\lambda x}, & x > 0 \\ 0, & x \leq 0 \end{cases}$$ $$其中, \lambda > 0$$

则 $X$ 服从 **指数分布**，记作：

$$X \sim E(\lambda)$$

> 电子原件的寿命分布都近似的服从指数分布

### 正态分布 $N$

若连续型随机变量 $X$ 的概率密度函数为：

$$f(x) = \frac{1}{\sqrt{2\pi}\sigma} e^{-\frac{(x-\mu)^2}{2\sigma^2}}$$ $$其中 \mu 为均值, \sigma 为标准差, -\infty < x < +\infty$$

则 $X$ 服从 **正态分布**，记作：
$$X \sim N(\mu, \sigma^2)$$

<br>

---

# 三、多维随机变量及其分布

## 0、题

### 边缘概率密度(3)

<br>

---

# 四、随机变量的数字特征

## 0、题

### 连续型求期望方差(5)

> 设随机变量 $X$ 的密度函数为 $f(x) = \begin{cases} 2x, 0 \leq x < 1 \\ 0, 其他 \end{cases}$：（1）求 $E(X)$；（2）求 $D(X)$

$E(X) = \int^1_0 x(2x) \text{d}x = \frac{2}{3} x^3 |^1_0 = \frac{2}{3}$

$E(X^2) = \int^1_0 x^2(2x) \text{d}x = \frac{1}{2}x^4 |^1_0 = \frac{1}{2}$

$D(X) = E(X^2) - E^2(X) = \frac{1}{18}$

<br>

### B

> 设随机变量 $X \sim B(n, p), E(X)=1.8, D(X)=1.26$，则参数 $n, p$ 的值为

$E(X) = np = 1.8$

$D(X) = np(1-p) = 1.26$

$n = 6, p = 0.3$

<br>

### P

> 设 $X_i \sim P(\lambda)(i=1,2,3)$，且 $\lambda = 3$，$X_1, X_2, X_3$ 相互独立，则 $D[\frac{1}{3}(X_1 + X_2 + X_3)]$

$D[\frac{1}{3}(X_1 + X_2 + X_3)] = \frac{1}{9} D(X_1 + X_2 + X_3)$

$D(X_1 + X_2 + X_3) = D(X_1) + D(X_2) + D(X_3) + 2(E(X_1 X_2) - E(X_1)E(X_2)) + 2(E(X_1 X_3) - E(X_1)E(X_3)) + 2(E(X_2 X_3) - E(X_2)E(X_3))$

因为独立，$E(XY) = E(X)E(Y)$

所以原式 $= \frac{1}{9}(D(X_1) + D(X_2) + D(X_3)) = 1$

<br>

---

## 1、数学期望 $E(X)$


### 离散型

**离散期望 = 取值乘概率再求和**

$X$：

$$E(X) = \sum_{i=1}^{n} x_i p_i$$

$X^2$：

$$E(X^2) = \sum_{i=1}^{n} x_i^2 p_i$$

$Y=g(X)$：

$$E(Y) = \sum_{i=1}^{n} g(x_i) p_i$$

$Z=g(X, Y)$：

$$E(Z) = \sum_{i=1}^{n} \sum_{j=1}^{m} g(x_i, y_j) p_{ij}$$


### <span style="color:orange;">连续型</span>

**连续期望 = 取值乘密度再积分**

$X$：

$$E(X) = \int_{-\infty}^{+\infty} x f(x) \text{d}x$$

$X^2$：

$$E(X^2) = \int_{-\infty}^{+\infty} x^2 f(x) \text{d}x$$

$Y=g(X)$：

$$E(g(X)) = \int_{-\infty}^{+\infty} g(x) f(x) dx$$

$Z=g(X, Y)$：

$$E(g(X,Y)) = \int_{-\infty}^{+\infty} \int_{-\infty}^{+\infty} g(x, y) f(x, y) dx dy$$

### 性质

$C$ 为常数

* $E(C)=C$

* $E(CX) = CE(X)$

* $E(X+Y) = E(X) + E(Y)$

* 若 $X$ 与 $Y$ 相互独立，则 $E(XY) = E(X)E(Y)$（不能反推）

<br>

---

## 2、方差 $D(X)$

### 硬算

[国家统计局：方差与标准（均方）差](https://www.stats.gov.cn/zs/tjll/sjms/202307/t20230719_1941405.html)

总体方差 = $\sigma^2 = \frac{\sum_{i=1}^n (x_i-\bar x)^2}{n}$

样本方差 = $s^2 = \frac{\sum_{i=1}^n (x_i-\bar x)^2}{n-1}$

### 公式

**$$D(X) = E(X^2) - E^2(X)$$**

$$E(X^2) = D(X) + E^2(X)$$

### 性质

$C$ 为常数

* $D(C)=0$

* $D(X + C) = D(X)$

* $D(CX) = C^2D(X)$

* $D(X \pm Y) = D(X) + D(Y) \pm 2(E(XY) - E(X)E(Y))$
    * 独立，则 $D(X \pm Y) = D(X) + D(Y)$（不能反推）（符号就是这样）

* 若 $D(X)=0$，则 $P\{X=E(X)\}=1$

<br>

---

## 3、常见分布的期望和方差

### 0-1分布

$$E(X) = p$$ $$D(X) = p(1-p)$$

### 二项分布 $B$

$$E(X) = np$$ $$D(X) = np(1-p)$$

### 泊松分布 $P$

$$E(X) = \lambda$$ $$D(X) = \lambda$$

### 均匀分布 $U$

$$E(X) = \frac{a+b}{2}$$ $$D(X) = \frac{(b-a)^2}{12}$$

### 指数分布 $E$

$$E(X) = \frac{1}{\lambda}$$ $$D(X) = \frac{1}{\lambda^2}$$

### 正态分布 $N$

$$E(X) = \mu$$ $$D(X) = \sigma^2$$

<br>

---

## 4、协方差与相关系数 $Cov$

### 协方差

$$Cov(X,Y) = E(XY) - E(X)E(Y)$$ $$Cov(X,X) = D(X)$$

$$D(X+Y) = D(X) + D(Y) + 2Cov(X, Y)$$

### 协方差的性质

* $Cov(X,Y) = Cov(Y, X)$

* $Cov(aX,bY) = abCov(X, Y)$

* $Cov(X+Y,Z) = Cov(X,Z)+Cov(Y,Z)$

<br>

---

# 七、参数估计

## 0、题

### 求矩估计量

> 设总体 $X \sim f(x, \theta) = \begin{cases} (\theta + 1)x^\theta , 0<x<1 \\ 0, 其他\end{cases}, \theta > -1$，$X_1, X_2, X_3 ... X_n$ 是来自总体 $X$ 的样本，求 $\theta$ 的矩估计量 

$E(X) = \int_0^1x(\theta+1)x^\theta \text{d}x = \frac{\theta + 1}{\theta + 2}$

令 $E(X) = \bar X$，$\bar X = \frac{\theta + 1}{\theta + 2}$

解得 $\hat \theta = \frac{1 - 2\bar X}{\bar X - 1}$

<br>


### 求极大似然估计(6)

> 设总体 $X \sim P(x), \lambda > 0$ 且未知，其分布律 $P\{X=k\} = \frac{\lambda^k e^{-\lambda}}{k!}, k=0,1...$， $x_1, x_2, ... , x_n$ 是来自总体 $X$ 的一个样本，求 $\lambda$ 的极大似然估计

$L(x_1, x_2, ... , x_n) = P \{ X=x_1 \} * P \{ X=x_2 \} * ... * P\{ X=x_n \} = \frac{\lambda^{x_1} e^{-\lambda}}{x_1!} * \frac{\lambda^{x_2} e^{-\lambda}}{x_2!} * ... * \frac{\lambda^{x_n} e^{-\lambda}}{x_n!}$

$L(x_1, x_2, ... , x_n) = \frac{\lambda^{\sum_{i=1}^n x_i} e^{-n\lambda}}{x_1!x_2!...x_n!}$

$\ln L(\lambda) = \sum_{i=1}^n x_i \ln \lambda - n\lambda - \ln(x_1!x_2!...x_n!)$

$\frac{\text{d}\ln L(\lambda)}{\text{d} \lambda} = \frac{\sum_{i=1}^n x_i}{\lambda} - n + 0 \triangleq 0$

解得 $\hat \lambda = \frac{\sum_{i=1}^{n} x_i}{n} = \bar x$

<br>

> 设总体 $X \sim N(\mu, \sigma^2)$，$\mu, \sigma^2$ 为未知参数，$x_1, x_2, ... , x_n$ 是来自总体 $X$ 的一组样本值，求 $\mu, \sigma^2$ 的极大似然估计量

$f(x; \mu \sigma^2) = \frac{1}{\sqrt{2\pi} \sigma} e^{-\frac{(x-\mu)^2}{2\sigma^2}}$

$L(\mu, \sigma^2) = \sum_{i=1}^n \frac{1}{\sqrt{2\pi} \sigma} e^{-\frac{(x_i-\mu)^2}{2\sigma^2}}$

<br>

---

## 1、矩估计

### 基本思想

用样本矩 $A_k = \frac{\sum_{i=1}^n X_i^k}{n}$ 代替总体矩 $\mu_k = E(X^k)$ （大数定理）

### 基本步骤

1. 先求出总体矩 $E(X)$

2. 令 $\bar X = E(X)$，解得 $\hat \theta$ 即为矩估计量


<br>

---

## 2、极大似然估计

### 基本思想

使得当前样本 $x_1, x_2, x_3, ... , x_n$ 出现的概率最大的参数值 $\hat \theta$ 即为极大似然估计

### 基本步骤

1. 写出样本似然函数 $L(\theta)$

2. 取对数：$\ln L(\theta)$

3. 求导数，得驻点：$\frac{\text{d}\ln L(\theta) }{\text{d} \theta} \triangleq 0$

<br>

---

## 3、区间估计

<br>

---

# 八、假设检验

## 0、题(7)

> 已知某炼铁厂铁水含量服从正态分布 $N(4.55, 0.108^2)$，现测定了 $9$ 炉铁水，其中平均含碳量为 $4.484$，如果估计方差没有变化，可否认为现在生产的铁水平均含碳量仍为 $4.55$（取显著性水平 $\alpha = 0.05$）

已知，$\mu_0 = 4.55, \sigma = 0.108, n = 9, \bar X = 4.484$

1. 提出假设（通过可否认为）

    $H_0: \mu = \mu_0$
    $H_1: \mu \neq \mu_0$

2. 构造检验统计量

    $Z = \frac{\bar X - \mu_0}{\sigma / \sqrt{n}} = -\frac{11}{6} = -1.83333$

3. 求出拒绝域

    $|Z| = 1.83333$
    $Z_{\frac{\alpha}{2}} = 1.96$（题目会给出）

4. 接受或拒绝

    $1.8333 < 1.96$，所以可以认为现在生产的铁水平均含碳量仍为 $4.55$

    （如果，$|Z| \geq Z_{\frac{\alpha}{2}}$，不能认为现在生产的铁水平均含碳量仍为 $4.55$）

<br>

> 已知某种食品每袋重量应为 $50$ 克，现随机抽查市售的该种食品 $4$ 袋测得重量如下：$45.0, 49.5, 50.5, 46.5$，设每袋重量服从均方差为 $3$ 克的正态分布，试在显著性水平 $a = 0.05$ 下检验该食品平均袋重是否合格

已知：$\bar X = 47.875, \sigma = 3, n = 4, \mu_0 = 50$

1. 提出假设

    $H_0: \mu = \mu_0$
    $H_1: \mu \neq \mu_0$

2. 构建检验统计量

    $Z = \frac{\bar{X}-\mu_0}{\sigma / \sqrt{n}} = 1.416666$

3. 求出拒绝域

    $Z_{\frac{\alpha}{2}} = 1.96$

4. 接受或拒绝

    $1.14 < 1.96$，所以可以认为该食品平均袋重合格

<br>

> 某厂生产的某种产品，由以往经验知其强力方差为 $7.5$ 且强力服从正态分布，改用新原料后，从新产品中抽取 $25$ 件做强力实验，算得 $s = \sqrt{\frac{1}{24} \sum_{i=1}^{25}(x_i-\bar x)^2} = 9.5$ kg，问新产品的强力方差是否有显著变化，即检验假设 $H_0: \sigma^2 \leq 7.5$，$H_1:\sigma^2 > 7.5$ （取显著性水平 $\alpha = 0.05$）

已知：$n = 25, S=9.5, \sigma_0^2 = 7.5$

1. 构建检验统计量

$\chi^2 = \frac{(n-1)S^2}{\sigma_0^2} = 38.5066$

2. 求出拒绝域

$\chi^2_{1-\frac{\alpha}{2}}(n-1) = 12.401$
$\chi^2_{\frac{\alpha}{2}}(n-1) = 39.364$

3. 接受或拒绝

$38.5066 > 12.401$
$38.5066 < 39.364$

所以可以认为新产品强力方差没有显著变化

<br>

> 在排放的工业废气中，某种有害物质不得超过 $0.05‰$，假定有害物质含量 $X$ 服从正态分布现取得 $5$ 份样本，测定该有害物质含量，得如下数据：$0.53‰, 0.542‰, 0.51‰, 0.495‰, 0.515‰$，能否认为有害物质含量超过了规定（显著性水平 $\alpha = 0.05$）

已知：$n = 5, \bar X = 0.5184, \mu_0=0.05, S^2 = 3.303*10^{-4}, S = 0.018174$

1. 提出假设

    $H_0: \mu = \mu_0$
    $H_1: \mu \neq \mu_0$

2. 构建检验统计量

    $T= \frac{\bar X - \mu_0}{S/\sqrt{n}} = 57.63015$

3. 求出拒绝域

    $T_{\alpha}(n-1) = 2.1318$

4. 接受或拒绝

    $57.63015 > 2.1318$，拒绝

    

## <span style="color:orange;">1、公式 </span>

检验统计量：

**$$Z = \frac{\bar X - \mu_0}{\sigma / \sqrt{n}}$$**

**$$T = \frac{\bar X - \mu_0}{S / \sqrt{n}}$$**

**$$\chi^2 = \frac{(n-1)S^2}{\sigma_0^2}$$**

<br>

拒绝域：

**$$|Z| \geq Z_{\frac{\alpha}{2}}, \ |Z| \geq Z_{\alpha} $$**

**$$|T| \geq Z_{\frac{\alpha}{2}}(n-1), \ T \geq T_{\alpha}(n-1)$$**

**$$ \begin{cases} \chi^2 \geq \chi^2_{\frac{\alpha}{2}}(n-1) \\ \chi^2 \leq \chi^2_{1-\frac{\alpha}{2}}(n-1)\end{cases} $$**

<!--

# 最后一题

大抵的意思：

* 已知 总体 $\chi\sim N(\mu,{\sigma}^2)$
* 已知 一组样本，均值为 $\bar{u}$

## 题型一：已知 $\sigma , \bar\mu$，可否认为 $\mu = \bar \mu$

**题目** 根据长期的经验，某工厂生产的特种特种金属丝的折断力服从 $\chi\sim N(\mu,{\sigma}^2)$，已知 $\mu=8kg$，现从该工厂生产的金属丝中随机抽取 $10$ 根，测得样本均值 $\bar{x}=575.2kg$，问这批特种金属丝的平均折断力可否认为是 $570kg$ ？$(\alpha=0.05)$

s: 样本总量


1. 提出假设

    $$
    H_0:\mu=570kg\\
    H_1:\mu\neq570kg
    $$

2. 构造检验统计量

    $$
    Z=\frac{\bar{x}-\mu}{\frac{\sigma}{\sqrt{n}}}
    $$



3. 求出拒绝域

    $$
    |Z| > Z {\frac{\alpha}{2}}
    $$

<br>

----



# 旧题

## 随机试验

随机试验是指具有以下特点的试验：

1. 可以在相同的条件下重复进行；
2. 试验的结果不止一个，且能事先明确试验的所有可能结果；
3. 进行一次试验之前不能确定哪一个结果会出现

> 掷骰子、掷硬币、抽签、抽奖、生产产品、检查产品、调查统计等

## 样本空间 

随机试验的 **所有可能结果组成的集合** 称为随机试验的样本空间，记作 $S$

集合的全集 -> 事件的所有可能结果 -> 样本空间

## 随机事件

样本空间 $S$ 的子集称为随机事件

集合的子集 -> 事件的某些可能结果 -> 随机事件

## 基本事件

样本空间 $S$ 的单个元素称为基本事件

集合的单个元素 -> 事件的某一个可能结果 -> 基本事件

## 必然事件与不可能事件

* 必然事件：样本空间 $S$ 

* 不可能事件：空集 $\emptyset$ 

## 事件的关系

* 包含：$A \subset B$，，$B$ 包含 $A$，事件 $A$ 发生必然导致事件 $B$ 发生

* 并：$A \cup B$，事件 $A$ 与 $B$ 至少发生一个

* 交：$A \cap B$，事件 $A$ 与 $B$ 同时发生，有时候也称为积，也写作 $AB$

* 差：$A - B$，事件 $A$ 发生而 $B$ 不发生

* 互斥：$A \cap B = \emptyset$，事件 $A$ 与 $B$ 不可能同时发生

* 逆（对立）：$\bar{A}$，事件 $A$ 不发生

* 互斥：$A \cap \bar{A} = \emptyset$，$A \cup \bar{A} = S$，事件 $A$ 与 $\bar{A}$ 互斥

## <span style="color:orange;">事件的运算</span>

* 交换律：$A \cup B = B \cup A$，$A \cap B = B \cap A$
* 结合律：$(A \cup B) \cup C = A \cup (B \cup C)$，$(A \cap B) \cap C = A \cap (B \cap C)$
* 分配律：$A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$，$A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$
* 德摩根律：$\overline{A \cup B} = \bar{A} \cap \bar{B}$，$\overline{A \cap B} = \bar{A} \cup \bar{B}$


## 频率

在相同条件下，进行了 $n$ 次试验，事件 $A$ 发生的次数 $n_A$ 与 $n$ 的比值

## <span style="color:orange;">概率</span>

事件 $A$ 发生的可能性大小的度量，记作 $P(A)$

性质：

* 非负性：$P(A) \geq 0$
* 规范性：$P(S) = 1$
* 可列可加性：若 $A_1, A_2, \cdots$ 两两互斥，则 $P(\bigcup_{i=1}^{\infty} A_i) = \sum_{i=1}^{\infty} P(A_i)$

根据性质拓展：

* $P(\emptyset) = 0$
* $P(\bar{A}) = 1 - P(A)$
* 若 $A \subset B$，则 $P(A) \leq P(B)$，有 $P(B - A) = P(B) - P(A)$
* <span style="color:red;">$P(A \cup B) = P(A) + P(B) - P(A \cap B)$</span>
* <span style="color:red;">$P(A-B) = P(A) - P(A \cap B) = P(A \cap \bar B)$</span>

## 古典（等可能）概型

样本空间 $S$ 中的基本事件发生的可能性相同

## <span style="color:orange;">条件概率</span>

在事件 $B$ 已经发生的条件下，事件 $A$ 发生的概率，记作 $P(A|B)$

<span style="color:red;">$P(A|B) = \frac{P(A \cap B)}{P(B)}$</span>

可拓展：

* 乘法定理：
    **$P(A \cap B) = P(A|B) P(B)$**

* 全概率公式：
    **$P(A) = \sum_{i=1}^n P(A|B_i) P(B_i)$**

* 贝叶斯公式：
    **$P(B_j|A) = \frac{P(A|B_j) P(B_j)}{\sum_{i=1}^n P(A|B_i) P(B_i)}$**

## <span style="color:orange;">独立性</span>

若 <span style="color:red;">$P(A \cap B) = P(A)P(B)$</span>，则称事件 $A$ 与 $B$ 相互独立，反之亦然

<br>

## <span style="color:red;">2题</span>

### 分布函数求概率密度

p58 20

> 设随机变量 $X$ 的分布函数为：
> 
>$F(x) = \begin{cases}
    0,      & x < 1         \\ 
    \ln x,  & 1 \leq x < e  \\ 
    1,      & x \geq e      \\ 
\end{cases}$

> **Q1：求 $X$ 的概率密度函数 $f(x)$**

* 分段求导：
    * $x < 1$，$F(x) = 0$$f^{'}(x) = 0$
    * $1 \leq x < e$，$F(x) = \ln x$$f^{'}(x) = \frac{1}{x}$
    * $x \geq e$，$F(x) = 1$$f^{'}(x) = 0$

    因此，有：
    $f(x) = \begin{cases}
    \frac{1}{x},    & 1 \leq x < e  \\
    0,              & 其他    
    \end{cases}$

> **Q2: 求 $P\{X < 2\}$，$P\{0 < X \leq 3\}$，$P\{2 < X < \frac{5}{2}\}$**

> 在概率论中，事件 `X<=2` 与事件 `x<2` 的概率是相等的
> 这是因为在实数轴上，概率为零的点是可忽略的
> 在连续型随机变量的情况下，单个点的概率为零

* $P\{X < 2\} = P\{X \leq 2\} = F(2) = \ln 2$

* $P\{0 < X \leq 3\} = P\{X \leq 3\} - P\{X \leq 0\} = F(3) - F(0) = 1 - 0 = 1$

* $P\{2 < X < \frac{5}{2}\} = P\{X \leq \frac{5}{2}\} - P\{X \leq 2\} = F(\frac{5}{2}) - F(2) = \ln \frac{5}{2} - \ln 2 = \ln \frac{5}{4}$

p59 34

> 设随机变量 $X$ 在区间 $(0,1)$ 上服从均匀分布

> **Q1：求 $Y = e^X$ 的概率密度**

因为 $X$ 在区间 $(0,1)$ 上服从均匀分布，所以：

* $f(x) = \begin{cases}
    1,      & 0 < x < 1     \\ 
    0,      & 其他          \\
\end{cases}$

### ? 概率密度求分布函数

### 正态分布

p59 26

> 设 $X \sim N(3,2^2)$（即 $X$ 服从 **正态分布**，均值为 $3$，方差为 $2^2$）

$\mu = 3$，$\sigma = 2$

$F(x) = \Phi (\frac{x - \mu}{ \sigma })$，其中 $\Phi$ 为标准正态分布的分布函数

> **Q1：求 $P\{2 < X \leq 5\}，P\{-4 < X \leq 10\}，P\{|X| > 2\}，P\{X > 3\}$**

* $P\{2 < X \leq 5\}$ 
    $= P\{X \leq 5\} - P\{X \leq 2\} = F(5) - F(2) $
    $= \Phi (\frac{5 - 3}{2}) - \Phi (\frac{2 - 3}{2}) = \Phi (1) - \Phi (-0.5) = 0.8413 - 0.3085 = 0.5328$

* $P\{-4 < X \leq 10\}$
    $= P\{X \leq 10\} - P\{X \leq -4\} = F(10) - F(-4) $
    $= \Phi (\frac{10 - 3}{2}) - \Phi (\frac{-4 - 3}{2}) = \Phi (3.5) - \Phi (-3.5) = 0.9998 - 0.0002 = 0.9996$

* $P\{|X| > 2\}$
    $= P\{X > 2\} + P\{X < -2\} = 1 - P\{X \leq 2\} + P\{X \leq -2\} $
    $= 1 - F(2) + F(-2) $
    $= 1 - \Phi (\frac{2 - 3}{2}) + \Phi (\frac{-2 - 3}{2}) $
    $= 1 - \Phi (-0.5) + \Phi (-2.5) = 1 - 0.3085 + 0.0062 = 0.6977$

* $P\{X > 3\}$
    $= 1 - P\{X \leq 3\} = 1 - F(3) $
    $= 1 - \Phi (\frac{3 - 3}{2}) = 1 - \Phi (0) = 1 - 0.5 = 0.5$

> **Q2：确定 $c$，使得 $P\{X > c\} = P \{ X \leq c \}$**

$P\{X > c\} = P \{ X \leq c \}$

即

$1 - P \{ X \leq c \} = P \{ X \leq c \}$ 

$P \{ X \leq c \} = \frac{1}{2}$

$\Phi (\frac{c - 3}{2}) = \frac{1}{2} = \Phi (0)$

$\frac{c - 3}{2} = 0$，$c = 3$

> **Q3：$P\{X > d\} \geq 0.9$，求 $d$ 的最大值**

$P\{X > d\} \geq 0.9$

即

$1 - P\{X \leq d\} \geq 0.9$

$P\{X \leq d\} \leq 0.1$

$\Phi (\frac{d - 3}{2}) \leq 0.1 = \Phi (-1.28)$

$\frac{d - 3}{2} \leq -1.28$

$d \leq 0.44$

### 分布律

p59 33

> 设随机变量 $X$ 的分布律为：
>
> X | -2 | -1 | 0 | 1 | 3
> :-:|:-:|:-:|:-:|:-:|:-:
> p(X) | $\frac{1}{5}$ | $\frac{1}{6}$ | $\frac{1}{5}$ | $\frac{1}{15}$ | $\frac{11}{30}$
> 
> _

> **Q1：求$Y = X^2$ 的分布律**

* $Y = (-2)^2 = 4$
    $P\{Y = 4\} = P\{X^2 = 4\}$
    $= P\{X = -2\} = \frac{1}{5}$

* $Y = (-1)^2 = 1$
    $P\{Y = 1\} = P\{X^2 = 1\}$
    $= P\{X = -1\} + P\{X = 1\} = \frac{1}{6} + \frac{1}{15} = \frac{7}{30}$

* $Y = 0^2 = 0$
    $P\{Y = 0\} = P\{X^2 = 0\}$
    $= P\{X = 0\} = \frac{1}{5}$

* $Y = 3^2 = 9$
    $P\{Y = 9\} = P\{X^2 = 9\}$
    $= P\{X = 3\} = \frac{11}{30}$

因此，$Y$ 的分布律为：

Y | 0 | 1 | 4 | 9
:-:|:-:|:-:|:-:|:-:
p(Y) | $\frac{1}{5}$ | $\frac{7}{30}$ | $\frac{1}{5}$ | $\frac{11}{30}$


<br>

---


## <span style="color:red;">3题</span>

### 求联合分布律

p86 1

> 在一箱子中装有 12 只开关，其中 2 只是次品，在其中取两次，每次任取一只，考虑两种试验：（1）放回抽样；（2）不放回抽样，我们定义随机变量 $X, Y$ 如下：
>$X = \begin{cases}
    0,      & \text{第一次取到正品}         \\ 
    1,      & \text{第一次取到次品}         \\
    \end{cases}$
>$Y = \begin{cases}
    0,      & \text{第二次取到正品}         \\
    1,      & \text{第二次取到次品}         \\
    \end{cases}$
> 试分别就（1）、（2）两种情况，写出 $X, Y$ 的联合分布律

（1）

放回抽样，那么第一次和第二次独立，所以：

$P\{X = 0\} = \frac{5}{6}$

$P\{X = 1\} = \frac{1}{6}$

$P\{Y = 0\} = \frac{5}{6}$

$P\{Y = 1\} = \frac{1}{6}$

$P\{X = 0, Y = 0\} = P\{X = 0\} P\{Y = 0\} = \frac{5}{6} \times \frac{5}{6} = \frac{25}{36}$

$P\{X = 0, Y = 1\} = P\{X = 0\} P\{Y = 1\} = \frac{5}{6} \times \frac{1}{6} = \frac{5}{36}$

$P\{X = 1, Y = 0\} = P\{X = 1\} P\{Y = 0\} = \frac{1}{6} \times \frac{5}{6} = \frac{5}{36}$

$P\{X = 1, Y = 1\} = P\{X = 1\} P\{Y = 1\} = \frac{1}{6} \times \frac{1}{6} = \frac{1}{36}$

分布律：

| Y \ X | 0 | 1 | 
|:-:|:-:|:-:|
| 0 | $\frac{25}{36}$ | $\frac{5}{36}$ |
| 1 | $\frac{5}{36}$ | $\frac{1}{36}$ |

（2）

不放回抽样，那么第一次和第二次不独立，所以：

$P\{X = 0\} = \frac{5}{6}$

此时，箱子里有 11 只开关，其中 2 只是次品，所以：

$P\{X = 0, Y = 0\} = \frac{5}{6} \times \frac{9}{11} = \frac{45}{66}$

$P\{X = 0, Y = 1\} = \frac{5}{6} \times \frac{2}{11} = \frac{10}{66}$

因为 $P\{X = 1\} = \frac{1}{6}$

此时，箱子里有 11 只开关，其中 1 只是次品，所以：

$P\{X = 1, Y = 0\} = \frac{1}{6} \times \frac{10}{11} = \frac{10}{66}$

$P\{X = 1, Y = 1\} = \frac{1}{6} \times \frac{1}{11} = \frac{1}{66}$

| Y \ X | 0 | 1 | 
|:-:|:-:|:-:|
| 0 | $\frac{45}{66}$ | $\frac{10}{66}$ |
| 1 | $\frac{10}{66}$ | $\frac{1}{66}$ |

<br>

### ???

p86 3

> 设随机变量 $(X,Y)$ 的概率密度为：
$f(x,y) = \begin{cases}
    k(6 - x - y),       & 0 < x < 2, 2 < y < 4  \\ 
    0,                  & \text{其他}           \\
    \end{cases}$
> （1）确定常数 $k$
> （2）求 $P\{ X<1, Y<3 \}$
> （3）求 $P\{ X<1.5 \}$
> （4）求 $P\{ X+Y \leq 4 \}$

（1）

<br>

### 求边缘概率密度

p87 7

> 设二维随机变量 $(X, Y)$ 的概率密度为：
> 
> $f(x,y) = \begin{cases}
    4.8y(2-x),       & 0 \leq x \leq 1.0, 0 \leq y \leq x  \\ 
    0,                  & \text{其他}           \\
    \end{cases}$
> 求边缘概率密度

<br>

### ？

p87 9

> 

---



## <span style="color:red;">4题</span>

### 常见分布的数字特征（期望，方差）

> 设 $X_1,X_2,X_3$ 相互独立，其中 $X_1 \sim U(0,6)$，$X_2 \sim N(0,4)$，$X_3 \sim P(3)$，则 $D(X_1 - 2 X_2 + 3 X_3)$ = ?

$X_1 \sim U(0,6)$ => $D(X_1) = \frac{(6-0)^2}{12} = 3$

$X_2 \sim N(0,4)$ => $D(X_2) = 4$

$X_3 \sim P(3)$ => $D(X_3) = 3$ 

因为 $X_1,X_2,X_3$ 相互独立，所以：

$D(X_1 - 2 X_2 + 3 X_3) = D(X_1) + D(-2 X_2) + D(3 X_3) = D(X_1) + 4 D(X_2) + 9 D(X_3) = 46$

> 设 $X$ 表示 $10$ 次独立重复射击命中目标的次数，每次命中目标的概率为 $0.4$ ，求 $E(X^2)$

由题意（10次试验，独立，两种结果（命中、丢失）），$X \sim B(n, p) = B(10,0.4)$

$E(X) = np = 10 \times 0.4 = 4$

$D(X) = np(1-p) = 10 \times 0.4 \times 0.6 = 2.4$

$E(X^2) = D(X) + E^2(X) = 2.4 + 4^2 = 18.4$


### 离散型 $R.V.$ 的协方差、相关系数

> 已知离散型变量 $X、Y、XY$ 的分布律如下，求 (1) $cov(X-Y,Y)$；(2) $\rho(X,Y)$
> 
>| $X$ | $0$ | $1$ | $2$ |
>|:-:|:-:|:-:|:-:|
>| 0 | $\frac{1}{2}$ | $\frac{1}{3}$ | $\frac{1}{6}$ |
> 
>| $Y$ | $0$ | $1$ | $2$ |
>|:-:|:-:|:-:|:-:|
>| 0 | $\frac{1}{3}$ | $\frac{1}{3}$ | $\frac{1}{3}$ |
>
>| $XY$ | $0$ | $1$ | $2$ | $4$ |
>|:-:|:-:|:-:|:-:|:-:|
>| 0 | $\frac{7}{12}$ | $\frac{1}{3}$ | $0$ |$\frac{1}{12}$ |

（1）

$cov(X-Y,Y) = cov(X,Y) - cov(Y,Y)$

$cov(X,Y) = E(XY) - E(X)E(Y)$

$cov(Y,Y) = D(Y)$ 

$D(Y) = E(Y^2) - E^2(Y)$

$E(XY) = 0 \times \frac{7}{12} + 1 \times \frac{1}{3} + 2 \times 0 + 4 \times \frac{1}{12} = \frac{2}{3}$

$E(X) = 0 \times \frac{1}{2} + 1 \times \frac{1}{3} + 2 \times \frac{1}{6} = \frac{2}{3}$

$E(Y) = 0 \times \frac{1}{3} + 1 \times \frac{1}{3} + 2 \times \frac{1}{3} = 1$

$E(Y^2) = 0^2 \times \frac{1}{3} + 1^2 \times \frac{1}{3} + 2^2 \times \frac{1}{3} = \frac{5}{3}$

$cov(X,Y) = -\frac{2}{3}$

（2）

$\rho(X,Y) = \frac{cov(X,Y)}{\sqrt{D(X)} \sqrt{D(Y)}} = 0$


### 连续型 $R.V.$ 的协方差、相关系数

> 设 $(x, y)$ 的概率密度为：
> $ f(x,y) = \begin{cases}
>    \frac{3}{4}x^2 y,      & 0 \leq x \leq 2,  0 \leq y \leq 1 \\ 
>    0,      & \text{其他}       \\
>\end{cases}$
> 求 $\rho(x,y)$

$\rho(x, y) = \frac{cov(xy)}{\sqrt{D(x)} \sqrt{D(y)}} = \frac{E(xy) - E(x)E(y)}{\sqrt{D(x)} \sqrt{D(y)}}$

$E(xy) = ?$ 

<br>

---

## <span style="color:red;">6题</span>

### $\chi^2$ （卡方）分布

p149 4

> 设 $X_1, X_2, \cdots, X_6$ 是来自总体 $N(0,1)$ 的样本，$Y = (X_1+X_2+X_3)^2 + (X_4+X_5+X_6)^2$，试确定常数 $C$，使 $CY$ 服从 $\chi^2$ 分布

$CY 服从 \chi^2$ 分布：

* ${(\sqrt{C}(X_1+X_2+X_3))}^2 + {(\sqrt{C}(X_4+X_5+X_6))}^2 \sim \chi^2(2)$

同理：

* ${(\sqrt{C}(X_1+X_2+X_3))}^2 \sim \chi^2(1)$，${(\sqrt{C}(X_4+X_5+X_6))}^2 \sim \chi^2(1)$

因为 $X_1, X_2, \cdots, X_6$ 是来自总体 $N(0,1)$ 的样本，所以：

* $X_1 + X_2 + X_3 \sim N(0,3)$，$X_4 + X_5 + X_6 \sim N(0,3)$

为了将 $X_1 + X_2 + X_3$ 和 $X_4 + X_5 + X_6$ 的方差变为 1：

* 当前方差为3，即 $a^2+b^2+c^2=3$，所以 $a=b=c=1$
* 令 $a^2+b^2+c^2=1$，所以 $a=b=c=\frac{1}{\sqrt{3}}$

因此：

* $\frac{x_1+x_2+x_3}{\sqrt{3}} \sim N(0,1)$，$\frac{x_4+x_5+x_6}{\sqrt{3}} \sim N(0,1)$

由 $\chi^2$ 分布的定义可知：

* ${(\frac{x_1+x_2+x_3}{\sqrt{3}})}^2 \sim \chi^2(1)$，${(\frac{x_4+x_5+x_6}{\sqrt{3}})}^2 \sim \chi^2(1)$

因此：

* $\sqrt{C} = \frac{1}{\sqrt{3}}$，$C = \frac{1}{3}$


### $t$ 分布

* $Y = \frac{C(X_1 + X_2)}{ \sqrt{(X^2_3 + X^2_4 + X^2_5)}}$

因为 $X_1, X_2, \cdots, X_5$ 是来自总体 $N(0,1)$ 的样本，所以：

* $X_1 + X_2 \sim N(0,2)$

为了将 $X_1 + X_2$ 的方差变为 1：

* 当前方差为2，即 $a^2+b^2=2$，所以 $a=b=1$
* 令 $a^2+b^2=1$，所以 $a=b=\frac{1}{\sqrt{2}}$

因此：

* $\frac{x_1+x_2}{\sqrt{2}} \sim N(0,1)$

由 $\chi^2$ 分布的定义可知：

* $X^2_3 + X^2_4 + X^2_5 \sim \chi^2(3)$

由 $t$ 分布的定义可知：

* $Y = \frac{\frac{x_1+x_2}{\sqrt{2}}}{ \sqrt{\frac{X^2_3 + X^2_4 + X^2_5}{3}}} \sim t(3)$

因此，整理一下：

* $Y = \frac{\frac{1}{\sqrt{2}}{(X_1+X_2)} }{ \frac{1}{\sqrt{3}} \sqrt{X^2_3+X^2_4 + X^2_5 }}$

所以：

* $C = \frac{\sqrt{3}}{\sqrt{2}} = \frac{\sqrt{6}}{2}$


### $F$ 分布

> 已知总体 $X \sim t(n)$，求证 $X^2 \sim F(1,n)$

* $X \sim t(n)$，$X^2 \sim t^2(n)$

由 $t$ 分布的定义可知：

* $X = \frac{Z}{\sqrt{\frac{Y}{n}}}$，其中 $Z \sim N(0,1)$，$Y \sim \chi^2(n)$

<br>

* $X^2 = \frac{Z^2}{ Y / n}$

由 $\chi^2$ 分布的定义可知：

* $Z^2 \sim \chi^2(1)$

由 $F$ 分布的定义可知：

* $X^2 = \frac{Z^2}{ Y / n} = \frac{\chi^2(1) / 1}{\chi^2(n) / n} \sim F(1,n)$


### 均值、方差

> 设总体 $X \sim \chi^2(n)$，$X_1, X_2, \cdots, X_{10}$ 是来自总体 $X$ 的样本，求 $E(\bar{X})$，$D(\bar{X})$，$E(S^2)$

> * $E(\bar{X})$：样本均值的期望

对于卡方分布，其均值为自由度，因此，有：

* $E(X) = n$

对于样本均值，样本均值的期望等于总体均值：

* $E(\bar{X}) = E(\frac{1}{n} \sum_{i=1}^n X_i) = \frac{1}{n} \sum_{i=1}^n E(X_i) = \frac{1}{n} \sum_{i=1}^n n = n$

> * $D(\bar{X})$：样本均值的方差

对于卡方分布，其方差为自由度的两倍，因此，有：

* $D(X) = 2n$

对于样本均值，有：

* $D(\bar{X}) = \frac{2n}{10} = \frac{n}{5}$

> * $E(S^2)$：样本方差的期望

对于卡方分布，其方差为自由度的两倍，因此，有：

* $D(X) = 2n$

<br>

---