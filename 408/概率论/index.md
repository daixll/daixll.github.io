---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---


概率论研究 **不确定** 事件发生的 **可能性**。

事件可以推导出概率，概率 **不可以** 推导出事件。

# 概率论的基本概念

## 术语

### 随机试验

随机试验是指具有以下特点的试验：

1. 可以在相同的条件下重复进行；
2. 试验的结果不止一个，且能事先明确试验的所有可能结果；
3. 进行一次试验之前不能确定哪一个结果会出现。

> 掷骰子、掷硬币、抽签、抽奖、生产产品、检查产品、调查统计等。


### 样本空间 

随机试验的 **所有可能结果组成的集合** 称为随机试验的样本空间，记为 $S$。

集合的全集 -> 事件的所有可能结果 -> 样本空间。

### 随机事件

样本空间 $S$ 的子集称为随机事件。

集合的子集 -> 事件的某些可能结果 -> 随机事件。

### 基本事件

样本空间 $S$ 的单个元素称为基本事件。

集合的单个元素 -> 事件的某一个可能结果 -> 基本事件。

### 必然事件与不可能事件

* 必然事件：样本空间 $S$ 。

* 不可能事件：空集 $\emptyset$ 。

### 事件的关系

* 包含：$A \subset B$，，$B$ 包含 $A$，事件 $A$ 发生必然导致事件 $B$ 发生。

* 并：$A \cup B$，事件 $A$ 与 $B$ 至少发生一个。

* 交：$A \cap B$，事件 $A$ 与 $B$ 同时发生。

* 差：$A - B$，事件 $A$ 发生而 $B$ 不发生。

* 互斥：$A \cap B = \emptyset$，事件 $A$ 与 $B$ 不可能同时发生。

* 逆（对立）：$\bar{A}$，事件 $A$ 不发生。

* 互斥：$A \cap \bar{A} = \emptyset$，$A \cup \bar{A} = S$，事件 $A$ 与 $\bar{A}$ 互斥。

### <span style="color:red;">事件的运算</span>

* 交换律：$A \cup B = B \cup A$，$A \cap B = B \cap A$。
* 结合律：$(A \cup B) \cup C = A \cup (B \cup C)$，$(A \cap B) \cap C = A \cap (B \cap C)$。
* 分配律：$A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$，$A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$。
* 德摩根律：$\overline{A \cup B} = \bar{A} \cap \bar{B}$，$\overline{A \cap B} = \bar{A} \cup \bar{B}$。


### 频率

在相同条件下，进行了 $n$ 次试验，事件 $A$ 发生的次数 $n_A$ 与 $n$ 的比值。

### <span style="color:red;">概率</span>

事件 $A$ 发生的可能性大小的度量，记为 $P(A)$。

性质：

* 非负性：$P(A) \geq 0$。
* 规范性：$P(S) = 1$。
* 可列可加性：若 $A_1, A_2, \cdots$ 两两互斥，则 $P(\bigcup_{i=1}^{\infty} A_i) = \sum_{i=1}^{\infty} P(A_i)$。

根据性质拓展：

* $P(\emptyset) = 0$。
* $P(\bar{A}) = 1 - P(A)$。
* 若 $A \subset B$，则 $P(A) \leq P(B)$，有 $P(B - A) = P(B) - P(A)$。
* **$P(A \cup B) = P(A) + P(B) - P(AB)$**。

### 古典（等可能）概型

样本空间 $S$ 中的基本事件发生的可能性相同。

### <span style="color:red;">条件概率</span>

在事件 $B$ 已经发生的条件下，事件 $A$ 发生的概率，记为 $P(A|B)$。

$P(A|B) = \frac{P(AB)}{P(B)}$。

可拓展：

* 乘法定理：
    **$P(AB) = P(A|B) P(B)$**

* 全概率公式：
    **$P(A) = \sum_{i=1}^n P(A|B_i) P(B_i)$**

* 贝叶斯公式：
    **$P(B_j|A) = \frac{P(A|B_j) P(B_j)}{\sum_{i=1}^n P(A|B_i) P(B_i)}$**

### <span style="color:red;">独立性</span>

若 $P(AB) = P(A) P(B)$，则称事件 $A$ 与 $B$ 相互独立，反之亦然。


## 例题