---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

> 如果不挂科，不考数一、三，大抵是不会更新了

> **，挂了。。。

概率论研究 **不确定** 事件发生的 **可能性**

事件可以推导出概率，概率 **不可以** 推导出事件

<br>

---

# 一、概率论的基本概念

## 0、全概率与贝叶斯 **$^1$**

> （1）有 $10$ 箱产品，$1, 2, 3$ 分别有 $5, 3, 2$ 箱，次品率为 $0.1, 0.2, 0.3$，任选一箱，再取一个产品，为良品的概率

$A$ 为抽到某家的概率
$B$ 为良品的概率

$P(A_1) = 0.5, P(B | A_1) = 0.9$
$P(A_2) = 0.3, P(B | A_2) = 0.8$
$P(A_3) = 0.2, P(B | A_3) = 0.7$

由全概率公式 $P(B) = \sum_{i=1}^n P(B|A_i) P(A_i)$

$P(B) = 0.9*0.5 + 0.8*0.3 + 0.7*0.2 = 0.83$

答：任选一箱，再取一个产品，为良品的概率为 $0.83$

<br>

> （2）$1, 2, 3$ 三车间加工一产品，加工量占总量的 $0.25, 0.35, 0.40$，次品率分别为 $0.03, 0.02, 0.01$，现从所有产品中抽取一个产品：（1）求产品为次品的概率；（2）是次品，次品来自 $2$ 车间的概率

$(1)$

$A$ 为抽到某家的概率
$B$ 为次品的概率

$P(A_1) = 0.25, P(B_1 | A_1) = 0.03$
$P(A_2) = 0.35, P(B_2 | A_2) = 0.02$
$P(A_3) = 0.40, P(B_3 | A_3) = 0.01$

由全概率公式 $P(B) = \sum_{i=1}^n P(B|A_i) P(A_i)$

$P(B) = 0.03 * 0.25 + 0.02 * 0.35 + 0.01 * 0.40 = 0.0185$

答：产品为次品的概率为 $0.0185$

$(2)$

由贝叶斯公式 $P(A_j|B) = \frac{P(B|A_j) P(A_j)}{\sum_{i=1}^n P(B|A_i) P(A_i)}$

$P(A_2|B) = \frac{0.02*0.35}{0.0185} = 0.378$

答：是次品，次品来自 $2$ 车间的概率为 $0.378$

<br>

> （3）三个箱子，第 $1$ 箱有 $7$ 个黑球和 $1$ 个白球，第 $2$ 箱有 $3$ 个黑球和 $3$ 个白球，第 $3$ 箱有 $5$ 个黑球和 $3$ 个白球，现任取一箱（取到每个箱子是等可能的），再任取一球：（1）求取到的是白球的概率；（2）是白球，则属于第 $2$ 箱的概率

$(1)$

$A$ 为抽到某箱的概率
$B$ 为抽到白球的概率

$P(A_1) = \frac{1}{3}, P(B | A_1) = \frac{1}{8}$
$P(A_2) = \frac{1}{3}, P(B | A_2) = \frac{3}{6}$
$P(A_3) = \frac{1}{3}, P(B | A_3) = \frac{3}{8}$

$P(B) = \frac{1}{8}*\frac{1}{3} + \frac{3}{6}*\frac{1}{3} + \frac{3}{8}*\frac{1}{3} = \frac{1}{3}$

由全概率公式 $P(B) = \sum_{i=1}^n P(B|A_i) P(A_i)$

答：取到的是白球的概率为 $\frac{1}{3}$

$(2)$

由贝叶斯公式 $P(A_j|B) = \frac{P(B|A_j) P(A_j)}{\sum_{i=1}^n P(B|A_i) P(A_i)}$

$P(A_2|B) = \frac{\frac{3}{6} * \frac{1}{3}}{ \frac{1}{3} } = \frac{1}{2}$

答：是白球，属于第 $2$ 箱的概率为 $\frac{1}{2}$

<br>

> （4）甲乙丙三人同时向一架飞机射击，设击中飞机的概率分别为 $0.4, 0.5, 0.7$，若只有 $1$ 人击中飞机，则飞机被击落的概率为 $0.2$，若有 $2$ 人击中飞机，则飞机被击落的概率为 $0.6$，若三人击中飞机，则飞机一定被击落，求飞机被击落的概率

$A$ 有几人击中飞机的概率
$B$ 飞机被击落的概率

$P(A_1) = 0.4(中)*0.5*0.3 + 0.6*0.5(中)*0.3 + 0.6*0.5*0.7(中) = 0.36$
$P(A_2) = 0.4(中)*0.5(中)*0.3 + 0.6*0.5(中)*0.7(中) + 0.4(中)*0.5*0.7(中) = 0.41$
$P(A_3) = 0.4(中)*0.5(中)*0.7(中) = 0.14$

$P(B | A_1) = 0.2$
$P(B | A_2) = 0.6$
$P(B | A_3) = 1$

由全概率公式 $P(B) = \sum_{i=1}^n P(B|A_i) P(A_i)$

$P(B) = 0.2*0.36 + 0.6*0.41 + 1*0.14 = 0.458$

答：飞机被击落的概率为 $0.458$

<br>

> （5）某道单项选择题（$4$ 个选项），不会做的学生从中随机选择，假定学生会做此题的概率为 $0.7$：（1）学生答对此题的概率；（2）答对此题的学生确实会做的概率

$(1)$

$A$ 为确实会做的概率
$B$ 为答对此题的概率

$P(A) = 0.7, P(B|A) = 1$
$P(\bar A) = 0.3, P(B|\bar A) = \frac{1}{4}$

由全概率公式 $P(B) = \sum_{i=1}^n P(B|A_i) P(A_i)$

$P(B) = 1*0.7 + \frac{1}{4}*0.3 = 0.775$

答：学生答对此题的概率为 $0.775$

$(2)$

由贝叶斯公式 $P(A_j|B) = \frac{P(B|A_j) P(A_j)}{\sum_{i=1}^n P(B|A_i) P(A_i)}$

$P(A|B) = \frac{1*0.7}{0.775} = \frac{28}{31}$

答：答对此题的学生确实会做的概率为 $\frac{28}{31}$

<br>

> （6）某病人发烧，认为病人患 $A, B, C$ 三种病的概率分别为 $0.5, 0.2, 0.3$，在这三种病之下，发烧的概率分别为 $0.2, 0.5, 0.8$，请推断该病人发烧由那一种病引起的可能性比较大

$D$ 为病人患某病的概率
$E$ 为病人发烧的概率

$P(D_A)=0.5, P(E|D_A) = 0.2$
$P(D_B)=0.2, P(E|D_B) = 0.5$
$P(D_C)=0.3, P(E|D_C) = 0.8$

由全概率公式 $P(E) = \sum_{i=1}^n P(E|D_i) P(D_i)$

$P(E) = 0.2 * 0.5 + 0.5 * 0.2 + 0.8 * 0.3 = 0.44$

由贝叶斯公式 $P(D_j|E) = \frac{P(E|D_j) P(D_j)}{\sum_{i=1}^n P(E|D_i) P(D_i)}$

$P(D_A|E) = \frac{0.2 * 0.5}{0.44} = 0.227$

$P(D_B|E) = \frac{0.5 * 0.2}{0.44} = 0.227$

$P(D_C|E) = \frac{0.8 * 0.3}{0.44} = 0.545$

答：病人发烧由 $C$ 病引发的可能性大

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

<br>

---

## 1、事件 **$^*$**

#### 事件的关系

* 包含：$A \subset B$，，$B$ 包含 $A$，事件 $A$ 发生必然导致事件 $B$ 发生

* <span style="color:orange;">并：$A \cup B$，事件 $A$ 与 $B$ 至少发生一个，也写作 $A + B$</span>

* <span style="color:orange;">交：$A \cap B$，事件 $A$ 与 $B$ 同时发生，也写作 $AB$</span>

* 差：$A - B$，事件 $A$ 发生而 $B$ 不发生

* 逆（对立）：$\bar{A}$，事件 $A$ 不发生

* 互斥：$A \cap B = \emptyset$，事件 $A$ 与 $B$ 不可能同时发生

* 互斥：$A \cap \bar{A} = \emptyset$，$A \cup \bar{A} = S$，事件 $A$ 与 $\bar{A}$ 互斥

<span style="color:orange;">对立（概率之和为 1） -> 互斥（互不相容）（概率之和不一定为 1） -> 独立（联合概率为各自乘积）</span>

#### 事件的运算

* 交换律：$A \cup B = B \cup A$，$A \cap B = B \cap A$
* 结合律：$(A \cup B) \cup C = A \cup (B \cup C)$，$(A \cap B) \cap C = A \cap (B \cap C)$
* 分配律：$A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$，$A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$
* 德摩根律：$\overline{A \cup B} = \bar{A} \cap \bar{B}$，$\overline{A \cap B} = \bar{A} \cup \bar{B}$

#### 概率

事件 $A$ 发生的可能性大小的度量，记作 $P(A)$

性质：

* 非负性：$P(A) \geq 0$
* 规范性：$P(S) = 1$
* 可列可加性：若 $A_1, A_2, \cdots$ 两两互斥，则 $P(\bigcup_{i=1}^{\infty} A_i) = \sum_{i=1}^{\infty} P(A_i)$

根据性质拓展：

* $P(\emptyset) = 0$
* $P(\bar{A}) = 1 - P(A)$
* 若 $A \subset B$，则 $P(A) \leq P(B)$，有 $P(B - A) = P(B) - P(A)$
* <span style="color:orange;">$P(A \cup B) = P(A) + P(B) - P(A \cap B)$</span>
* <span style="color:orange;">$P(A-B) = P(A) - P(A \cap B) = P(A \cap \bar B)$</span>
* <span style="color:orange;">$P(A \cap B) = P(A|B) P(B)$</span>
    * 若独立，则 <span style="color:orange;">$P(A \cap B) = P(A)P(B)$</span>

**条件概率**：

在事件 $B$ 已经发生的条件下，事件 $A$ 发生的概率，记作 $P(A|B)$

* <span style="color:orange;">$P(A|B) = \frac{P(A \cap B)}{P(B)}$</span>

可拓展：

* 全概率公式：
    
**<span style="color:orange;">$$P(B) = \sum_{i=1}^n P(B|A_i) P(A_i)$$</span>**

* 贝叶斯公式：

**<span style="color:orange;">$$P(A_j|B) = \frac{P(B|A_j) P(A_j)}{\sum_{i=1}^n P(B|A_i) P(A_i)}$$</span>**

<br>
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

### 概率密度求分布函数 **$^2$**

> 设随机变量 $X$ 服从 $(0, 2)$ 上的均匀分布，则 $P\{1 < X < 3\}$

$f(x) = \begin{cases} \frac{1}{b-a}, & a < x < b \\ 0, & else \end{cases}$

$f(x) = \begin{cases} \frac{1}{2}, & 0 < x < 2 \\ 0, & else \end{cases}$

$P\{1 < x < 3\} = \int_1^2 \frac{1}{2} \text{d}x$

$P\{1 < x < 3\} = \frac{1}{2}x |_1^2 = 1 - \frac{1}{2} = \frac{1}{2}$

<br>

> $f(x) = \begin{cases} Ke^{-5x}, x>0 \\ 0, x \leq 0 \end{cases}$，（1）确定 $K$；（2）求 $P\{X>0.2\}$；（3）求分布函数 $F(x)$

$(1)$

**$\int_{-\infty}^{+\infty}f(x) \text{d} x = 1$**

$\int_0^{+\infty} Ke^{-5x} = \int_0^{+\infty} -\frac{K}{5} e^{-5x} \text{d}(-5x) = 1$

$= -\frac{K}{5}e^{-5x} |_0^{+\infty} = \frac{K}{5} = 1$

$K = 5$

$(2)$

$P\{X>0.2\} = \int_{0.2}^{+\infty} 5e^{-5x} \text{d}x = \int_{0.2}^{+\infty} -\frac{5}{5} e^{-5x} \text{d}(-5x) = -e^{-5x}|_{0.2}^{+\infty} = e^{-1}$

$(3)$

**$F(x) = \int_{-\infty}^{+\infty} f(x) \text{d}x$**

$\begin{cases} 0, & x \leq 0 \\ \int_{0}^{+\infty}5e^{-5x} \text{d}x, & x > 0 \end{cases} \Rightarrow F(x) = \begin{cases} 0, & x \leq 0 \\ 1, & x > 0 \end{cases}$

<br>

> 设连续型随机变量 $X$ 的密度函数为 $f(x) = \begin{cases} Ax, & 0 \leq x \leq 1 \\ A(2-x), & 1 < x \leq 2 \\ 0, & else \end{cases}$，求（1）常数 $A$；（2）$X$ 的分布函数 $F(x)$；（3）$P\{\frac{1}{2} < X < \frac{3}{2}\}$

$(1)$

**$\int_{-\infty}^{+\infty}f(x)\text{d}x = 1$**

$\int_{0}^{1} Ax \text{d}x + \int_{1}^{2} A(2-x) \text{d}x = 1$

$\frac{A}{2} x^2 |_0^1 + (2Ax - \frac{A}{2}x^2)|_1^2 = 1$

$A = 1$

$(2)$

**$F(x) = \int_{-\infty}^{+\infty} f(x) \text{d}x$**

$\begin{cases} 0, & x < 0 \\ \int_{0}^{x} x \text{d}x, & 0 \leq x < 1 \\ \int_0^1 x \text{d}x + \int_1^x (2-x) \text{d}x, & 1 \leq x < 2 \\ \int_{0}^{1}x\text{d}x + \int_1^2 (2-x) \text{d}x, & x \geq 2 \end{cases} \Rightarrow F(x) = \begin{cases} 0, & x < 0 \\ \frac{1}{2}x^2, & 0 \leq x < 1 \\ 2x - \frac{1}{2}x^2-1, & 1 \leq x < 2 \\ 1, & x \geq 2 \end{cases}$

$(3)$

$P\{\frac{1}{2} < X < \frac{3}{2}\} = \int_{\frac{1}{2}}^{\frac{3}{2}} f(x) \text{d}x = \int_{\frac{1}{2}}^{1}x\text{d}x + \int_{1}^{\frac{3}{2}} (2-x) \text{d} x = \frac{3}{4}$

<br>

> 设连续型随机变量 $X$ 的密度为 $f(x) = \begin{cases} A \sin x ,& 0<x< \pi \\ 0, & else\end{cases}$ 求（1）$A$；（2）$X$ 的分布函数 $F(x)$；（3）$P\{0< x < \frac{\pi}{4} \}$

$(1)$

**$\int_{-\infty}^{+\infty}f(x) \text{d}x = 1$**

$\int_0^\pi A \sin x \text{d} x = 1$

$-A \cos x |_0^\pi = 1$

$2A = 1 \Rightarrow A = \frac{1}{2}$

$(2)$

**$F(x) = \int_{-\infty}^{+\infty} f(x) \text{d}x$**

$F(x) = \begin{cases} 0, & x < 0 \\ \int_0^x \frac{1}{2} \sin x \text{d} x , & 0 \leq x < \pi \\ \int_0^\pi \frac{1}{2} \sin x \text{d}x, & x \geq \pi \end{cases} \Rightarrow \begin{cases} 0, & x < 0  \\ 1-\frac{1}{2} \cos x , & 0 \leq x < \pi \\ 1 , & x \geq \pi \end{cases}$

$(3)$

$P\{ 0 < x < \frac{\pi}{4} \} = \int_0^{\frac{\pi}{4}} \frac{1}{2} \sin x \text{d} x = \frac{2 - \sqrt{2}}{4}$

<br>

### 概率密度求概率密度 **$^4$**

> 设随机变量 $X$ 的密度为 $f(x) = \begin{cases} x, & 0 \leq x \leq 1 \\ 2-x , & 1 < x \leq 2 \\ 0 , & else\end{cases}$，求（1）$Y = -2X+1$ 的密度；（2）$Z=e^X$ 的密度

$(1)$

$F(y) = P\{Y \leq y\} = P\{-2X+1 \leq y\} = P\{X \geq \frac{1-y}{2}\} = \int_{\frac{1-y}{2}}^{+\infty} f(x) \text{d} x$

$=\begin{cases} 1, & \frac{1-y}{2} < 0 \\ \int_{\frac{1-y}{2}}^{1} \frac{1-y}{2} \text{d} \frac{1-y}{2} + \int_{1}^{2} (2 - \frac{1-y}{2}) \text{d} \frac{1-y}{2}, & 0 \leq \frac{1-y}{2} < 1 \\ \int_{\frac{1-y}{2}}^{2} ( 2 - \frac{1-y}{2}) \text{d} \frac{1-y}{2}, & 1 \leq \frac{1-y}{2} < 2 \\ 0, & \frac{1-y}{2} \geq 2 \end{cases}$

$=\begin{cases} 1, & \frac{1-y}{2} < 0 \\ 1-\frac{1}{2} * (\frac{1-y}{2})^2, & 0 \leq \frac{1-y}{2} < 1 \\ 2 - 2 * \frac{1-y}{2} + \frac{1}{2}(\frac{1-y}{2})^2, & 1 \leq \frac{1-y}{2} < 2 \\ 0, & \frac{1-y}{2} \geq 2 \end{cases}$

$f(y) = F^{'}(y) = \begin{cases} \frac{y}{4}-\frac{1}{4}, & -1 < y < 1 \\ \frac{y}{4} + \frac{3}{4} , & -3 < y < -1 \\ 0, & else \end{cases}$

$(2)$

$F(y) = P\{Y \leq y\} = P\{ e^X \leq y\} = P\{ X \leq \ln y \} = \int_{-\infty}^{\ln y} f(x) \text{d} x$

$= \begin{cases} 0, & \ln y < 0\\ \int_{0}^{\ln y} (\ln y)\text{d} \ln y , & 0 \leq \ln y < 1 \\ \int_{0}^{1} (\ln y) \text{d}\ln y + \int_{1}^{\ln y} (2-\ln y) \text{d}\ln y , & 1 \leq \ln y < 2 \\ 1, & \ln y \geq 2 \end{cases} $

$= \begin{cases} 0, & \ln y < 0 \\ \frac{1}{2}(\ln y)^2 , & 0 \leq \ln y < 1 \\ 2 \ln y - \frac{1}{2}(\ln y)^2 - 1, & 1 \leq \ln y < 2 \\ 1, & \ln y \geq 2 \end{cases}$

$f(y) = F^{'}(y) = \begin{cases} \frac{\ln y}{y}, & 0 < y < e \\ \frac{2}{y} - \frac{\ln y}{y}, & e < y < e^2 \\ 0 , & else\end{cases}$

<br>

> 设 $X \sim f_X(x) = \begin{cases} \frac{x}{8}, & 0<x<4\\ 0, & else\end{cases}$，（1）求 $Y=2X+8$ 的密度函数 $f_Y(y)$；（2）求 $Y=2X-1$ 的密度函数 $f_Y(y)$

$(1)$

$F(y) = P\{Y \leq y\} = P\{2X + 8 \leq y\} = P\{X \leq \frac{y-8}{2}\}= \int_{-\infty}^{\frac{y-8}{2}} f(x) \text{d} x $

$= \begin{cases} 0, & \frac{y-8}{2} < 0 \\ \int_0^{\frac{y-8}{2}} (\frac{\frac{y-8}{2}}{8}) \text{d} \frac{y-8}{2}, & 0 \leq \frac{y-8}{2} < 4 \\ 1, & \frac{y-8}{2} \geq 4 \end{cases}$

$= \begin{cases} 0, & \frac{y-8}{2} < 0 \\ \frac{1}{8} * \frac{1}{2} * (\frac{y-8}{2})^2 , & 0 \leq \frac{y-8}{2} < 4 \\ 1, & \frac{y-8}{2} \geq 4 \end{cases}$

$f(y) = F^{'}(y) = \begin{cases} \frac{y-8}{32}, & 8 < y < 16 \\ 0, & else\end{cases}$

$(2)$

$F(y) = P\{Y \leq y\} = P\{2X-1 \leq y\} = P\{X \leq \frac{y+1}{2}\} = \int_{-\infty}^{\frac{y+1}{2}} f(x) \text{d} x$

$= \begin{cases} 0, & \frac{y+1}{2} < 0 \\ \int_{0}^{\frac{y+1}{2}} \frac{\frac{y+1}{2}}{8} \text{d} \frac{y+1}{2}, & 0 \leq \frac{y+1}{2} < 4 \\ 1, & \frac{y+1}{2} \geq 4 \end{cases}$

$= \begin{cases} 0, & \frac{y+1}{2} < 0 \\ \frac{1}{8} * \frac{1}{2} * (\frac{y+1}{2})^2, & 0 \leq \frac{y+1}{2} < 4 \\ 1, & \frac{y+1}{2} \geq 4 \end{cases}$

$f(y) = F^{'}(y) = \begin{cases} \frac{y+1}{32}, & -1 < y < 7 \\ 0, & else\end{cases}$

<br>

> 


<br>

---

## 1、随机变量及分布函数

### 随机变量

随机变量就是随机试验结果的 **数值化**

> 例如：**抛硬币**，正面为 **1**，反面为 **0**
> 例如：**选球**，红球为 **1**，白球为 **2**，黑球为 **3**

数值化后，更有利于建立数学模型，进行数学分析

### 累计分布函数

对于一个随机变量 $X$，其分布函数 $F(x)$ 定义为： 

**<span style="color:orange;">$$F(x) = P \{X \leq x\}$$</span>**

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
* 规范性：$F(x)$ 是一个概率，<span style="color:orange;">$F(-\infty) = 0$，$F(+\infty) = 1$</span>

### 概率分布

<br>

**概率分布** **$f$** 
* 通常是指 **分布律**（离散）和 **概率密度函数**（连续）

**累计分布函数** **$F$**
* 即 $F(x) = P \{X \leq x\}$


<br>

---

## 2、离散型随机变量 / 分布律

离散型随机变量：
* 指其取值为 **有限个** 数值的随机变量
* 在取值上是有间隔的
* 通常描述可以数出来、可以分隔的随机现象

离散型随机变量的分布律：
* 一个函数，描述了随机变量的取值和其概率的对应关系
* 表示为：<span style="color:orange;">$P(X=x_i) = p_i$</span>，满足：
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

<br>

---

# 三、多维随机变量及其分布

## 0、边缘概率密度 **$^3$**

> 设二维随机变量 $(X, Y)$ 的概率密度为 $f(x, y) = \begin{cases} kx^2y , & x^2 \leq y \leq 1 \\ 0 , & else\end{cases}$ 求
> （1）常数 $k$；（2）边缘概率密度；（3）$X$ 与 $Y$ 是否独立

1. 由规范性 $\int_{-\infty}^{+\infty} \int_{-\infty}^{+\infty} f(x, y) \text{d}x \text{d}y = 1$

    $\int_{-1}^{1} \int_{x^2}^{1} kx^2y \text{d}y \text{d}x = 1$

    $k = \frac{21}{4}$

<br>

2. $\begin{cases}f_X(x) = \int_{-\infty}^{+\infty} f(x,y) \text{d}y \\ f_Y(y) = \int_{-\infty}^{+\infty} f(x,y) \text{d}x \end{cases}$

    $f_X(x) = \begin{cases} \int_{x^2}^{1} \frac{21}{4} x^2 y \text{d}y, & -1 \leq x \leq  1 \\ 0, & else\end{cases} = \begin{cases} \frac{21x^2-21x^6}{8}, & -1 \leq x \leq 1 \\ 0, & else\end{cases}$

    $f_Y(y) = \begin{cases} \int_{-\sqrt y}^{ \sqrt y} \frac{21}{4} x^2 y \text{d}x, & 0 \leq y \leq 1 \\ 0, & else\end{cases} = \begin{cases} \frac{21y^2 \sqrt y}{6}, & 0 \leq y \leq 1 \\ 0, & else\end{cases}$

<br>

3. 由于 $f(x,y) \neq f_X(x)f_Y(y)$，所以 $X$ 与 $Y$ 不独立

<br>

> 设二维连续型随机变量 $(X, Y)$ 的联合概率密度函数为 $ f(x,y) = \begin{cases} 4xy, & 0 < x < 1, 0 < y < 1 \\ 0 , & else \end{cases}$ 求（1）边缘密度函数；（2）$X, Y$ 是否独立；（3）求 $P\{Y \leq X^2\}$

1. $\begin{cases}f_X(x) = \int_{-\infty}^{+\infty} f(x,y) \text{d}y \\ f_Y(y) = \int_{-\infty}^{+\infty} f(x,y) \text{d}x \end{cases}$

    $f_X(x) = \begin{cases} \int_0^1 4xy \text{d}y , & 0 < x < 1 \\ 0 , & else \end{cases} = \begin{cases} 2x, & 0 < x < 1 \\ 0 , & else \end{cases}$

    $f_Y(y) = \begin{cases} \int_0^1 4xy \text{d}x , & 0 < y < 1 \\ 0 , & else \end{cases} = \begin{cases} 2y, & 0 < y < 1 \\ 0 , & else \end{cases}$

<br>

2. 由于 $f(x,y) = f_X(x)f_Y(y)$，所以 $X$ 与 $Y$ 独立

<br>

3. $P\{Y \leq X^2 \} = \underset{G^{'}}{\int\int} f(x, y) \text{d} x \text{d} y$

    $\int_0^1 \int_0^{x^2} 4xy \text{d}y \text{d}x = \frac{1}{3}$

<br>

---

# 四、随机变量的数字特征

## 0、求期望方差 **$^5$**

> （1）设随机变量 $X$ 的密度函数为 $f(x) = \begin{cases} 2x, & 0 \leq x < 1 \\ 0, & else \end{cases}$：（1）求 $E(X)$；（2）求 $D(X)$

1. $E(X) = \int_{-\infty}^{+\infty} x f(x) \text{d}x$

    $E(X) = \int^1_0 x(2x) \text{d}x = \frac{2}{3} x^3 |^1_0 = \frac{2}{3}$

2. $D(X) = E(X^2) - E^2(X)$

    $E(X^2) = \int^1_0 x^2(2x) \text{d}x = \frac{1}{2}x^4 |^1_0 = \frac{1}{2}$

    $D(X) = \frac{1}{2} - (\frac{2}{3})^2 = \frac{1}{18}$

<br>

> （2）设随机变量 $X \sim B(n, p), E(X)=1.8, D(X)=1.26$，则参数 $n, p$ 的值为

1. 由二项分布的期望方差

    $E(X) = np = 1.8$

    $D(X) = np(1-p) = 1.26$

    $n = 6, p = 0.3$

<br>

> （3）设 $X_i \sim P(\lambda)(i=1,2,3)$，且 $\lambda = 3$，$X_1, X_2, X_3$ 相互独立，则 $D[\frac{1}{3}(X_1 + X_2 + X_3)]$

$D[\frac{1}{3}(X_1 + X_2 + X_3)] = \frac{1}{9} D(X_1 + X_2 + X_3)$

$D(X_1 + X_2 + X_3) = D(X_1) + D(X_2) + D(X_3) + 2(E(X_1 X_2) - E(X_1)E(X_2)) + 2(E(X_1 X_3) - E(X_1)E(X_3)) + 2(E(X_2 X_3) - E(X_2)E(X_3))$

因为独立，$E(XY) = E(X)E(Y)$

所以原式 $= \frac{1}{9}(D(X_1) + D(X_2) + D(X_3)) = 1$

<br>

---

## 1、数学期望 $E(X)$


#### 离散型

**离散期望 = 取值乘概率再求和**

$X$：

$$E(X) = \sum_{i=1}^{n} x_i p_i$$

$X^2$：

$$E(X^2) = \sum_{i=1}^{n} x_i^2 p_i$$

$Y=g(X)$：

$$E(Y) = \sum_{i=1}^{n} g(x_i) p_i$$

$Z=g(X, Y)$：

$$E(Z) = \sum_{i=1}^{n} \sum_{j=1}^{m} g(x_i, y_j) p_{ij}$$


#### 连续型

**连续期望 = 取值乘密度再积分**

$X$：

$$E(X) = \int_{-\infty}^{+\infty} x f(x) \text{d}x$$

$X^2$：

$$E(X^2) = \int_{-\infty}^{+\infty} x^2 f(x) \text{d}x$$

$Y=g(X)$：

$$E(g(X)) = \int_{-\infty}^{+\infty} g(x) f(x) dx$$

$Z=g(X, Y)$：

$$E(g(X,Y)) = \int_{-\infty}^{+\infty} \int_{-\infty}^{+\infty} g(x, y) f(x, y) dx dy$$

<br>

---

## 2、方差 $D(X)$

#### 硬算

[国家统计局：方差与标准（均方）差](https://www.stats.gov.cn/zs/tjll/sjms/202307/t20230719_1941405.html)

总体方差 = $\sigma^2 = \frac{\sum_{i=1}^n (x_i-\bar x)^2}{n}$

样本方差 = $s^2 = \frac{\sum_{i=1}^n (x_i-\bar x)^2}{n-1}$

#### 公式

**$$D(X) = E(X^2) - E^2(X)$$**

$$E(X^2) = D(X) + E^2(X)$$

<br>

---

## 3、协方差与相关系数 $Cov$

#### 公式

$$Cov(X,Y) = E(XY) - E(X)E(Y)$$ 

$$Cov(X,X) = D(X)$$

$$D(X+Y) = D(X) + D(Y) + 2Cov(X, Y)$$


<br>

---

## 4、性质 **$^*$**

$C$ 为常数

期望：

* $E(C)=C$

* $E(CX) = CE(X)$

* $E(X \pm C) = E(X) \pm C$

* $E(X \pm Y) = E(X) \pm E(Y)$

    * 独立，有 $E(XY) = E(X)E(Y)$（不能反推）

方差：

* $D(C)=0$

* $D(CX) = C^2D(X)$

* $D(X \pm C) = D(X)$

* $D(X \pm Y) = D(X) + D(Y) \pm 2(E(XY) - E(X)E(Y))$
    * 独立，有 $D(X \pm Y) = D(X) + D(Y)$（不能反推）（就是 $+$，没写错）
    * $\rho(X,Y) = \frac{Cov(X,Y)}{\sqrt{D(X)}\sqrt{D(Y)}}$
    * $Cov(X,Y) = E(XY) - E(X)(Y)$

斜方差：

* $Cov(X,Y) = Cov(Y, X)$

* $Cov(aX,bY) = abCov(X, Y)$

* $Cov(X+Y,Z) = Cov(X,Z)+Cov(Y,Z)$

<br>

---

# 七、参数估计

## 0、求矩或极大似然估计 **$^6$**

> （1）设总体 $X \sim B(1, p)$ 其中 $p$ 是未知参数，$X_1, X_2, X_3, X_4, X_5$ 是总体的样本，若样本观测值为 $1, 1, 0, 1, 0$，求 $p$ 的矩估计量

1. 求出总体矩 $E(X)$

    $E(X) = np = p$

2. 令 $\bar X = E(X)$

    $\frac{\sum_{i=1}^5 X_i}{5} = p$

3. 求解方程
    $\hat p = \frac{3}{5}$

<br>

> （2）设总体 $X \sim \pi(\lambda)$，$\lambda$ 未知，$X_1, X_2, ..., X_m$ 是来自总体得简单随机样本，试求参数 $\lambda$ 的矩估计量

1. 求出总体矩 $E(X)$

    $E(X) = \lambda$

2. 令 $\bar X = E(X)$

    $\frac{\sum_{i=1}^{m} X_i}{m} = \lambda$

3. 求解方程

    $\hat \lambda = \frac{\sum_{i=1}^{m} X_i}{m}$


<br>

> （3）设总体 $X$ 的分布律为
> | $X$ | $1$ | $2$ | $3$ |
> |:-:|:-:|:-:|:-:|
> | $P$ | $\theta^2$ | $2\theta(1-\theta)$ | $(1-\theta)^2$ |
> 
> 其中 $\theta ( 0 < \theta < 1 )$ 是未知参数，利用总体 $X$ 的如下样本值：$1, 2, 1$，求 $\theta$ 的矩估计量和最大似然估计量

1. 求出总体矩 $E(X)$

    $E(X) = \sum_{i=1}^k(X_i * P_i) $

    $= \theta^2 + 4\theta(1-\theta) + 3(1-\theta)^2 $

    $= 3 - 2\theta$

2. 令 $\bar X = E(X)$
    
    $\bar X = \frac{1+2+1}{3} = \frac{4}{3}$

    $\frac{4}{3} = 3 - 2\theta$

3. 求解方程

    $\hat \theta = \frac{5}{6}$


<br>

1. 写出样本似然函数 $L (\theta)$

    $L(x, \theta) = \prod_{i=1}^{3} P\{X=x_i\}$

    $ = \theta^2 * 2\theta(1-\theta) *\theta^2$

    $ = 2 \theta^5  - 2 \theta^6$

2. 求导数 $\frac{\text{d} L(\theta) }{\text{d} \theta} = 0$

    $\frac{\text{d} L(x, \theta) }{\text{d} \theta} = 10 \theta^4 - 12\theta^5 = 0$

    $\hat \theta = \frac{5}{6}$

<br>

> （4）设总体 $X$ 的概率密度函数为 $f(x;\theta) = \begin{cases} \theta e^{-\theta x}, & 0 < x \\ 0 , & else \end{cases}$，设 $X_1, X_2, ... , X_n$ 为总体 $X$ 的一个样本，试求参数 $\theta$ 的最大似然估计量 $\hat \theta$

1. 写出样本似然函数 $L (\theta)$
    
    $L(x, \theta) = \prod_{i=1}^{n} f(x_i)$

    $= \prod_{i=1}^{\theta} \theta e^{-\theta x_i}$

    $= \theta ^ n e^{-\theta \sum_{i=1}^{n}x_i}$

2. 对似然函数取对数 $\ln L(\theta)$
    
    $\ln L(x, \theta) = \ln \theta^n + \ln e^{-\theta \sum_{i=1}^{n} x_i}$

    $= n \ln \theta - \theta \sum_{i=1}^{n}x_i$

3. 求导数 $\frac{\text{d}\ln L(\theta) }{\text{d} \theta} = 0$

    $\frac{\text{d}\ln L(x, \theta) }{\text{d} \theta} = \frac{n}{\theta} - \sum_{i=1}^{n}x_i = 0$

    $\hat \theta = \frac{n}{\sum_{n}^{i=1}x_i}$

<br>

---

## 1、矩估计

#### 基本思想

用样本矩 $A_k = \frac{\sum_{i=1}^n X_i^k}{n}$ 代替总体矩 $\mu_k = E(X^k)$ （大数定理）

#### 基本步骤

1. 求出总体矩（期望） $E(X)$

2. 令 $\bar X$ （样本均值） $= E(X)$

3. 解得 $\hat \theta$ 即为矩估计量


<br>

---

## 2、极大似然估计

#### 基本思想

使得当前样本 $x_1, x_2, x_3, ... , x_n$ 出现的概率最大的参数值 $\hat \theta$ 即为极大似然估计

#### 基本步骤

0. 设 $x_1, x_2, x_3, ... , x_n$ 为一组观测值

1. 样本似然函数 $L(x, \theta) = \prod_{i=1}^n f(x_i)$

2. 取对数 $\ln L(\theta)$

3. 求导数 $\frac{\text{d}\ln L(\theta) }{\text{d} \theta} = 0$

> 部分情况 0, 2 可以省略

<br>

---

# 八、假设检验

## 0、假设检验 **$^7$**

> （1）某工厂生产的铜丝的折断力服从正态分布 $N(\mu, \sigma^2)$。从某天所生产的铜丝中抽取 $10$ 根，进行折断力试验，测得其样本均值为 $572.2$，方差为 $75.7$，若 $\mu$ 未知，是否可以认为这一天生产的铜丝折断力的标准差是 $8$？（取显著性水平 $\alpha = 0.05$）

已知：$n = 10, \bar X = 572.2, S^2 = 75.7$

1. 提出假设
$H_0: \sigma_0 = 8$ 
$H_1: \sigma_0 \neq 8$

2. 构建检验统计量
${\chi^2} = \frac{(n-1)S^2}{\sigma_0^2} = 10.645$

3. 求出拒绝域
${\chi^2}_{1-\frac{\alpha}{2}}(n-1) = 2.7$
${\chi^2}_{\frac{\alpha}{2}}(n-1) = 19.022$
拒绝域 $M$：$(-\infty, 2.7) \cup (19.022, +\infty)$

4. 接收或拒绝
$10.645 \notin M$ ，接受原假设 $H_0$

答：可以认为这一天生产的铜丝折断力的标准差是 $8$

<br>

> （2）某切割机在正常工作时，切割每段金属棒的平均长度为 $10.5$，今从一批产品中随机的抽取 $16$ 段进行测试，得样本均值和样本方差分别为 $\bar x, S^2 = 0.237^2$，假定切割的长度服从正态分布，试问该机器工作是否正常？（取显著性水平 $\alpha = 0.05$）$t_{0.025}(15) = 2.131$

已知：$n = 16, \bar X = 10.46, S^2 = 0.237^2$

1. 提出假设
$H_0: \mu_0 = 10.5$
$H_1: \mu_0 \neq 10.5$

2. 构建检验统计量
$T = \frac{\bar X - \mu_0}{S / \sqrt{n}} = -0.675$

3. 求出拒绝域
$T_{\frac{\alpha}{2}}(n-1) = 2.131$
拒绝域 $M$：$(-\infty, -2.131) \cup (2.131, +\infty)$

4. 接受或拒绝
$-0.675 \notin M$，接受原假设 $H_0$

答：可以认为该机器正常

<br>

> （3）测定某种溶液中的硫酸铜，设硫酸铜含量的总体服从正态分布 $N(\mu, \sigma^2)$，得到的 $10$ 个测定值给出 $\bar X = 0.452, S = 0.037$，试问可否认为硫酸铜含量的方差为 $\sigma^2 = 0.04$？（检验水平 $\alpha = 0.05$）

已知：$n = 10, \bar X = 0.452, S = 0.037$

1. 提出假设
$H_0: \sigma_0^2 = 0.04$
$H_1: \sigma_0^2 \neq 0.04$

2. 构建检验统计量
${\chi^2} = \frac{(n-1)S^2}{\sigma_0^2} = 0.308$

3. 求出拒绝域
${\chi^2}_{1-\frac{\alpha}{2}}(n-1) = 2.7$
${\chi^2}_{\frac{\alpha}{2}}(n-1) = 19.022$
拒绝域 $M$：$(-\infty, 2.7) \cup (19.022, +\infty)$

4. 接受或拒绝
$0.308 \in M$，拒绝原假设 $H_0$

答：不可以认为硫酸铜含量的方差为 $\sigma^2 = 0.04$

<br>

> （4）设某味精厂生产的味精在手工包装时的每袋重量 $N(15, 0.05)$。技术革新后，改用机器包装，现抽查 $8$ 个样品测得重量：$14.7, 15.1, 14.8, 15, 15.3, 14.9, 15.2, 14.6$，已知方差不变，问机器包装的味精每袋平均重量是否仍为 $15$？（显著性水平 $\alpha = 0.05$）

已知：$n = 8, \bar X = 14.95, \sigma^2 = 0.05$

1. 提出假设
$H_0: \mu_0 = 15$
$H_1: \mu_0 \neq 15$

2. 构建检验统计量
$Z = \frac{\bar X - \mu_0}{\sigma / \sqrt{n}} = -0.632$

3. 求出拒绝域
$Z_{\frac{\alpha}{2}} = 1.96$
拒绝域 $M$：$(-\infty, -1.96) \cup (1.96, +\infty)$

4. 接受或拒绝
$-0.632 \notin M$，接受原假设 $H_0$

答：可以认为机器包装的味精每袋平均重量仍为 $15$

<br>

> （5）已知某炼铁厂铁水含量服从正态分布 $N(4.55, 0.108^2)$，现测定了 $9$ 炉铁水，其中平均含碳量为 $4.484$，如果估计方差没有变化，可否认为现在生产的铁水平均含碳量仍为 $4.55$（取显著性水平 $\alpha = 0.05$）

已知，$\sigma^2 = 0.108^2, n = 9, \bar X = 4.484$

1. 提出假设

    $H_0: \mu_0 = 4.55$
    $H_1: \mu_0 \neq 4.55$

2. 构建检验统计量

    $Z = \frac{\bar X - \mu_0}{\sigma / \sqrt{n}} = -\frac{11}{6} = -1.833$

3. 求出拒绝域
    $Z_{\frac{\alpha}{2}} = 1.96$
    拒绝域 $M$：$(-\infty, -1.96) \cup (1.96, +\infty)$

4. 接受或拒绝
    $-1.833 \notin M$，接受原假设 $H_0$

答：可以认为现在生产的铁水平均含碳量仍为 $4.55$

<br>

> （6）已知某种食品每袋重量应为 $50$ 克，现随机抽查市售的该种食品 $4$ 袋测得重量如下：$45.0, 49.5, 50.5, 46.5$，设每袋重量服从均方差为 $3$ 克的正态分布，试在显著性水平 $a = 0.05$ 下检验该食品平均袋重是否合格

已知：$\bar X = 47.875, \sigma = 3, n = 4$

1. 提出假设

    $H_0: \mu_0 = 50$
    $H_1: \mu_0 \neq 50$

2. 构建检验统计量

    $Z = \frac{\bar{X}-\mu_0}{\sigma / \sqrt{n}} = 1.416666$

3. 求出拒绝域

    $Z_{\frac{\alpha}{2}} = 1.96$
    拒绝域 $M$：$(-\infty, -1.96) \cup (1.96, +\infty)$

4. 接受或拒绝

    $1.14 \notin M$，接受原假设 $H_0$

答：可以认为该食品平均袋重为 $50$ 克

<br>
    

## 1、公式 **$^*$**

检验统计量：

**$$Z = \frac{\bar X - \mu_0}{\sigma / \sqrt{n}}$$**

**$$T = \frac{\bar X - \mu_0}{S / \sqrt{n}}$$**

**$${\chi^2} = \frac{(n-1)S^2}{\sigma_0^2}$$**

<br>

拒绝域：

**$$(-\infty, -Z_\frac{\alpha}{2}) \cup (Z_\frac{\alpha}{2}, +\infty)$$**

**$$(-\infty, -T_{\frac{\alpha}{2}}(n-1)) \cup (T_{\frac{\alpha}{2}}(n-1), +\infty)$$**

**$$( -\infty, {\chi^2}_{1-\frac{\alpha}{2}}(n-1)) \cup ({\chi^2}_{\frac{\alpha}{2}}(n-1), +\infty)$$**


<br>

---

# 常见分布 **$^*$**

## 二项分布 $B$

二项分布是 $n$ 重伯努利试验

> * 伯努利试验
>   设试验 $E$ 只有两个可能结果：$A$（事件 $A$ 发生）和 $B$（事件 $A$ 不发生，也称 $\bar{A}$），且 $P(A) = p$，$P(B) = 1-p$，则称 $E$ 为一次伯努利试验
> * n重伯努利试验
> 将上述试验 $E$ 重复 $n$ 次，称为 $n$ 重伯努利试验

设 $X$ 为 $n$ 重伯努利试验中事件 $A$ 发生的次数，则 $X$ 服从参数为 $n$ 和 $p$ 的二项分布，记作：

$$X \sim b(n,p)$$

二项分布的分布函数：

$$P \{ X=k \} = {C_n^k} p^k (1-p)^{n-k}$$ $$其中, k 表示成功的次数, n 表示试验的总次数, p 表示每次试验成功的概率(不变)$$

期望方差：

$$E(X) = np$$ $$D(X) = np(1-p)$$

> 特殊的，当 $n=1$ 时，二项分布就是 0-1 分布

## 泊松分布 $P$

泊松分布的分布函数：

$$P \{ X=k \} = \frac{\lambda^k}{k!} e^{-\lambda}$$ $$其中, k=0,1,2,..., \lambda > 0$$

记作：

$$ X \sim P(\lambda) $$

> 单位时间内，某一件事情发生的次数
> 常见的：单位时间内，某一机器发生故障的次数，单位时间内，某一服务台接待的顾客数

期望方差：

$$E(X) = \lambda$$ $$D(X) = \lambda$$

## 均匀分布 $U$

若连续型随机变量 $X$ 的概率密度函数为：

$$f(x) = \begin{cases} \frac{1}{b-a}, & a < x < b \\ 0, & else \end{cases}$$

则 $X$ 在区间 $(a,b)$ 上服从 **均匀分布**，记作：

$$X \sim U(a,b)$$

期望方差：

$$E(X) = \frac{a+b}{2}$$ $$D(X) = \frac{(b-a)^2}{12}$$

> 对于随机变量 $X$，落在区间 $a,b$ 中任意 **等长度** 的子区间的概率相等

> 概率密度函数为常数，区间内所有点的概率密度相等


## 指数分布 $E$

若连续型随机变量 $X$ 的概率密度函数为：

$$f(x) = \begin{cases} \lambda e^{-\lambda x}, & x > 0 \\ 0, & x \leq 0 \end{cases}$$ $$其中, \lambda > 0$$

则 $X$ 服从 **指数分布**，记作：

$$X \sim E(\lambda)$$

期望方差：

$$E(X) = \frac{1}{\lambda}$$ $$D(X) = \frac{1}{\lambda^2}$$

> 电子原件的寿命分布都近似的服从指数分布

## 正态分布 $N$

若连续型随机变量 $X$ 的概率密度函数为：

$$f(x) = \frac{1}{\sqrt{2\pi}\sigma} e^{-\frac{(x-\mu)^2}{2\sigma^2}}$$ $$其中 \mu 为均值, \sigma 为标准差, -\infty < x < +\infty$$

则 $X$ 服从 **正态分布**，记作：
$$X \sim N(\mu, \sigma^2)$$

期望方差：

$$E(X) = \mu$$ $$D(X) = \sigma^2$$