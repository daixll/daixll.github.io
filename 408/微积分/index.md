---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

[画图工具](https://www.geogebra.org/graphing?lang=zh_CN)

---

微积分之前先 **化简** $\left\{
\begin{aligned}
    拆项、提项、同乘、同除 \\
    对数公式 \\
    三角公式 \\
\end{aligned}
\right.$


**对数公式**
1. $▢ = e^{\ln ▢} = \ln e^▢$
2. $\ln ab = \ln a + \ln b$
3. $\ln \frac{a}{b} = \ln a - \ln b$
4. $\log _a ^b = \frac{\ln b}{\ln a}$

# 第一节 函数与极限

要多近有多近（柯西 cauchy 说的）

* 数列极限
    1. 单调有界
    2. 夹逼定理
    3. 定积分定义（用无穷个长方形的面积逼近曲线下的面积）

* 函数极限
    1. 洛必达（简单函数，容易求导，越求越简单）
    2. 等价代换（3组）
    3. 泰勒公式（8个）
    4. 导数定义（导数是变换率的极限，牛顿研究加速度）
    5. 拉格朗日中值定理（导数的几何意义，切线斜率）


## 函数

单调性

有界性

奇偶性

周期性

---

##  数列极限


**数列极限概念** 

定义：$\lim_{n \to \infty} a_n = a$

**${\forall} {\epsilon} > 0, {\exists}  N > 0$，当$n > N$时，$|a_n - a| < {\epsilon}$**

注意：$|a_n - a| < {\epsilon}$ 中的 ${\epsilon}$ 是任意小的正数，不是固定的，如果不是任意小，那么就不是极限了。

> $|a_n - a| < e^{\frac{\epsilon}{10}}$
> 这个不是极限，因为 $e^{\frac{\epsilon}{10}}$ 不是任意小的正数
> * ${\frac{\epsilon}{10}}$ 的值域 $(0, +\infty)$
> * $e^{\frac{\epsilon}{10}}$ 的值域 $(1, +\infty)$
>
> 所以 $e^{\frac{\epsilon}{10}}$ 不是任意小的正数。


**数列极限的充要条件**

**$\lim_{n \to \infty} a_n = a <=> {\forall} 子列均收敛于 a$**

$\lim_{n \to \infty} a_n = a <=> \lim_{n \to \infty} a_{2n} = \lim_{n \to \infty} a_{2n+1} = a$

$\lim_{n \to \infty} a_n = a <=> \lim_{n \to \infty} a_{3n} = \lim_{n \to \infty} a_{3n+1} = \lim_{n \to \infty} a_{3n+2} = a$

**数列极限的性质**

1. 唯一性：$\lim_{n \to \infty} a_n = a$，$\lim_{n \to \infty} a_n = b$，则 $a = b$
2. 有界性：$\lim_{n \to \infty} a_n {\exists}$，则 ${a_n}$ 有界
3. 局部保号性：$\lim_{n \to \infty} a_n = a > 0$，则 ${\exists} N > 0$，当 $n > N$ 时，$a_n > 0$


---

## 函数极限



**函数极限概念** 

定义：

1. $x -> x_0$
    * $\lim_{x \to x_0} f(x) = A$：${\forall} {\epsilon} > 0, {\exists} {\delta} > 0$，当 $0 < |x - x_0| < {\delta}$ 时，$|f(x) - A| < {\epsilon}$
    函数极限 $x->x_0$ 但不允许 $x=x_0$（函数在 $x_0$ 处不一定有定义）。

    * $\lim_{x \to x_0^+} f(x) = A$：${\forall} {\epsilon} > 0, {\exists} {\delta} > 0$，当 $0 < x - x_0 < {\delta}$ 时，$|f(x) - A| < {\epsilon}$

    * $\lim_{x \to x_0^-} f(x) = A$：${\forall} {\epsilon} > 0, {\exists} {\delta} > 0$，当 $0 < x_0 - x < {\delta}$ 时，$|f(x) - A| < {\epsilon}$

2. $x -> \infty$
    * $\lim_{x \to \infty} f(x) = A$：${\forall} {\epsilon} > 0, {\exists} X > 0$，当 $|x| > X$ 时，$|f(x) - A| < {\epsilon}$
    * $\lim_{x \to \infty^+} f(x) = A$：${\forall} {\epsilon} > 0, {\exists} X > 0$，当 $x > X$ 时，$|f(x) - A| < {\epsilon}$
    * $\lim_{x \to \infty^-} f(x) = A$：${\forall} {\epsilon} > 0, {\exists} X > 0$，当 $x < -X$ 时，$|f(x) - A| < {\epsilon}$

**函数极限的充要条件**

$\lim_{x \to x_0} f(x) = A <=> \lim_{x \to x_0^+} f(x) = \lim_{x \to x_0^-} f(x) = A$

$\lim_{x \to \infty} f(x) = A <=> \lim_{x \to \infty^+} f(x) = \lim_{x \to \infty^-} f(x) = A$

**函数极限的性质**

1. 唯一性：$\lim_{x \to x_0} f(x) = A$，$\lim_{x \to x_0} f(x) = B$，则 $A = B$
2. 局部有界性：$\lim_{x \to x_0} f(x) = A$，则 ${\exists} {\delta} > 0$， $M > 0$，当 $0 < |x - x_0| < {\delta}$ 时，$|f(x)| <= M$
3. 局部保号性：$\lim_{x \to x_0} f(x) = A > 0$，则 ${\exists} {\delta} > 0$，当 $0 < |x - x_0| < {\delta}$ 时，$f(x) > 0$
    推论：
    $f(x) >= 0$，且 $\lim_{x \to x_0} f(x) = A$，则 $A >= 0$

>$ f(x) > 0$，且 $\lim_{n \to \infty} f(n) = A$，则 $A >= 0$
>$f(x) = 1/x$，且 $\lim_{x \to 0} f(x) = A$，则 $A >= 0$ 


**四则运算法则**

1. $\lim_{x \to x_0} [f(x) \pm g(x)] = \lim_{x \to x_0} f(x) \pm \lim_{x \to x_0} g(x)$

2. $\lim_{x \to x_0} f(x) \cdot g(x) = \lim_{x \to x_0} f(x) \cdot \lim_{x \to x_0} g(x)$

3. $\lim_{x \to x_0} \frac{f(x)}{g(x)} = \frac{\lim_{x \to x_0} f(x)}{\lim_{x \to x_0} g(x)}$，其中 $\lim_{x \to x_0} g(x) \neq 0$

推论：（提非零因子）
设 $\lim_{x \to x_0} f(x) = A \neq 0$，
则 $\lim_{x \to x_0} f(x) \cdot g(x) = A \cdot \lim_{x \to x_0} g(x)$

注意：四则运算法则（加减乘除拆开）求极限时，要求：
1. 极限存在
2. 极限值有意义（除数不为0）

> $  \lim_{x \to \infty}  \frac{2x^3+3x-4}{3x^3-4x+3} \overset{ 同除x^3 }{=} \lim_{x \to \infty} \frac{2 + \frac{3}{x^2} - \frac{4}{x^3}}{3 - \frac{4}{x^2} + \frac{3}{x^3}} = \frac{2}{3}$

---

## 无穷小

**无穷小概念**

定义：$ \lim_{x \to x_0} f(x) = 0$，则称 $f(x)$ 为 $x \to x_0$ 时的无穷小

**无穷小的性质**

1. 有限个无穷小的和是无穷小（注意，不是无穷）
2. 有限个无穷小的积是无穷小
3. 无穷小乘以有界量是无穷小

> 有界量：$|f(x)| <= M$，$M$ 是常数
> $ \lim_{x \to {\infty}} \frac{sinx}{x} = \lim_{x \to {\infty}} \frac{1}{x} \cdot sinx = 0 \cdot sinx = 0$

**无穷小阶的比较**

$ \lim_{x \to x_0} f(x) = 0$，$ \lim_{x \to x_0} g(x) = 0$，则：

1. $ \lim_{x \to x_0} \frac{f(x)}{g(x)} = 0$，称 $f(x)$ 为 $g(x)$ 的 **高阶** 无穷小，记作 $f(x) = o(g(x))$
    特别的，0是任意无穷小的高阶无穷小

> $ \lim_{x \to 0} \frac{x^4}{x^3} = 0$，$x^4$ 是 $x^3$ 的高阶无穷小，记作 $x^4 = o(x^3)$
> **$o$ 的本质是阶数高的一类函数的集合，故有 $ {\{x^5, x^6, ...\}} ∈ o(x^3)$**

2. $ \lim_{x \to x_0} \frac{f(x)}{g(x)} = A \neq 0$，称 $f(x)$ 为 $g(x)$ 的 **同阶** 无穷小
    特别的，当 $A = 1$ 时，称 $f(x)$ 为 $g(x)$ 的 **等价** 无穷小，记作 $f(x) \sim g(x)$

3. $ \lim_{x \to x_0} \frac{f(x)}{g^k(x)} = C \neq 0$，称 $f(x)$ 为 $g(x)$ 的 **k阶** 无穷小

**高阶无穷小的性质** $x \to 0$

1. $o(x^m) + o(x^n) = o(x^l)$，其中 $l = min(m, n)$

> $o(x^3) + o(x^2) = o(x^2)$

> $o(x^2) - o(x^2) = o(x^2)$
> 因为 $o(x^2.1) - o(x^2) = o(x^2)$，$o(x^2.1)$ 是 $o(x^2)$ 的高阶无穷小

2. $k \cdot o(x^n) = o(x^n)$

> $2 \cdot o(x^3) = o(x^3)$

3. $x^m \cdot o(x^n) = o(x^m) \cdot x^n = o(x^m) \cdot o(x^n) = o(x^{m+n})$


4. $\frac{o(x^m)}{x^n} = o(x^{m-n}) \ \ 条件：(m>n)$

## 无穷大

**无穷大的概念**

定义：

1. $ \lim_{x \to x_0} f(x) = \infty$，则称 $f(x)$ 为 $x \to x_0$ 时的无穷大
    $\forall M>0, \exists \delta > 0$，当 $ 0<|x-x_0|< \delta$ 时，有 $f(x) > M$

2. $ \lim_{x \to \infty} f(x) = \infty$，则称 $f(x)$ 为 $x \to \infty$ 时的无穷大
    $\forall M>0, \exists X > 0$，当 $ |x| > X$ 时，有 $|f(x)| > M$


**无穷大的性质**

1. 无穷大的倒数为无穷小
   **非零**无穷小的倒数为无穷大

2. 无穷大一定是无界量（$ \forall M > 0, \exists x_0$，使得 $|f(x)| > M$）
   无界量不一定是无穷大
> $f(x) = x \cdot sinx, x \to \infty$
> 令 $x_n = 2n\pi + \frac{\pi}{x}$，则 $f(x_n) = 2n\pi + \frac{\pi}{2}$，$f(x_n) = (2n\pi + \frac{\pi}{2}) \cdot 1 \to \infty$
> 令 $x_n = 2n\pi$，则 $f(x_n) = 0$，故$f(x)$为无界量，但不是无穷大



**无穷大阶的比较**

1. $x \to +\infty$
   $ln^\alpha x \ll x^\beta \ll a^x \ll x^x$，其中，$ \alpha $ 和 $\beta > 0$, $a>1$
   对数函数也叫伪无穷大（最弱的无穷大）

2. $n \to \infty$  数列的 n 趋于无穷，都是 $\to + \infty$
   $ln^\alpha n \ll n^\beta \ll a^n \ll n! \ll n^n$，其中，$ \alpha $ 和 $\beta > 0$, $a>1$
   > $\lim_{n \to \infty} \frac{a^n}{n!} = 0$


## 洛必达法则

若：

1. $\lim_{x \to x_0} \frac{f(x)}{g(x)} = \frac{0}{0}$ 或 $ = \frac{\infty}{\infty}$
2. $f(x), g(x) 可导$
3. $\lim_{x \to x_0} \frac{f^{'}(x)}{g^{'}(x)}$ 存在 或 无穷

则可洛必达：

$ \lim_{x \to x_0} \frac{f(x)}{g(x)} = \lim_{x \to x_0} \frac{f^{'}(x)}{g^{'}(x)}$


> $ \lim_{x \to \infty} \frac{x+sinx}{x} \overset{\frac{\infty}{\infty}} = \lim_{x \to \infty}(1+cosx)$ 震荡。（不存在了，不能使用洛必达）


> $\lim_{x \to 0} \frac{ \sqrt{1+x} + \sqrt{1-x} - 2}{x^2}$
=$ \lim_{x \to 0} \frac{ \frac{1}{2 \sqrt{1+x}} - \frac{1}{2 \sqrt{1-x}}}{2x} $
=$ \frac{1}{4} \lim_{x \to 0} \frac{\sqrt{1-x} - \sqrt{1+x}}{x \sqrt{1+x} \sqrt{1-x}}$


## 等价代换 x->0

1. $x \sim sinx \sim tanx$
    $\sim arcsinx \sim arctanx$
    $\sim ln(1+x) \sim e^x-1$

2. $(1+x)^2-1 \sim 2x$
    特别的，$\sqrt{1+x}-1 \sim \frac{x}{2}$
    所以有，$\sqrt[n]{1+x}-1 \sim \frac{x}{n}$

    $a^x-1 \sim xlna$

    $x-ln(1+x) \sim 1-cosx \sim \frac{x^2}{2}$
    
3. $x-sinx \sim arcsinx-x \sim \frac{x^3}{6}$ 弦
    $tanx-x \sim x-arctanx \sim \frac{x^3}{3}$ 切
    $tanx-sinx \sim arcsinx-arctanx \sim \frac{x^3}{2}$ 弦+切

* 等价代换求极限
    1. 乘除可以代换，加减最简形式 $(x, x^2...)$ 不抵消时可以代换
    > $ln(1+x) - sinx$ 
    > 经典错误：
    > $\sim x-x=0$
    > $\sim x-sinx \sim \frac{x^3}{6}$
    > 法1：Taylor
    > $= x - \frac{x^2}{2} + o(x^2) - [x-\frac{x^3}{3!} + o(x^3)]$
    > $= -\frac{x^2}{2} + o(x^2) \sim -\frac{x^2}{2}$
    > 法2：拆项等价
    > $ln(1+x) - x + x -sinx$
    > $-\frac{x^2}{2} + \frac{x^3}{3!} \sim -\frac{x^2}{2}$

    > $1-cosx+x^2 \sim \frac{x^2}{2}+x^2 = \frac{3x^2}{2}$

    2. $x \to 0$ 可以推广为 $ ▢ \to 0$
    
    > $▢ = x^2$ 随便装，不过要趋于0
    > $ln(1+▢) \sim ▢, ▢ \to 0$

    > $▢ - sin▢ \sim \frac{x^3}{6}, ▢ \to 0$
    
    > $\lim_{x \to 0} \frac{(sinx - sinsinx)sinx}{x^4}$
    > $= \lim_{x \to 0} \frac{ \frac{sin^3x}{6} sinx}{x^4}$
    > $= \lim_{x \to 0} \frac{ \frac{sin^4x}{6}}{x^4}$
    > $= \frac{1}{6}$

    > $\lim_{x \to 0} \frac{arctanx - x}{ln(1+2x^3)}$
    > $= \lim_{x \to 0} \frac{- \frac{x^3}{3}}{2x^3}$ 
    > $= - \frac{1}{6}$

    > $\lim_{x \to 0} \frac{arctanx -sinx}{x^3}$
    > $= \lim_{x \to 0} \frac{arctanx - x + x - sinx}{x^3}$
    > $= \lim_{x \to 0} \frac{- \frac{x^3}{3} + \frac{x^3}{6} }{x^3}$ 
    > $= - \frac{1}{6}$


## 泰勒公式

Taylor

**泰勒公式**：$f(x)$ 在 $x=x_0$ 的某邻域内 $n+1$ 阶可导，则有：

$f(x) = f(x_0) + f'(x_0)(x - x_0) + \frac{f''(x_0)}{2!}(x - x_0)^2 + \ldots + \frac{f^{(n)}(x_0)}{n!}(x - x_0)^n + R_n(x)$ 

$R_n(x)$ 有两种：

* 拉格朗日（Lagrange）余项：$ \frac{f^{(n+1)}(\xi)}{(n+1)!}(x-x_0)^{n+1}$，$ \xi $ 在 $x_0$ 与 $x$ 之间

* 佩亚诺（Peano）余项：$ o((x-x_0)^n)$


麦克劳林公式 Maclaurin：$f(x)$ 在 $x=0$ 的某邻域内 $n+1$ 阶可导，则有：

$f(x) = f(0) + f'(0)x + \frac{f''(0)}{2!}x^2 + \ldots + \frac{f^{(n)}(0)}{n!}x^n + R_n(x)$



**八个常见函数的泰勒公式**

1. $e^x = 1 + x + \frac{x^2}{2!} + o(x^2)$

2. $\ln(1+x) = x - \frac{x^2}{2} + \frac{x^3}{3} + o(x^3)$

3. $(1+x)^\alpha = 1 + \alpha x + \frac{\alpha(\alpha-1)}{2!} x^2 + o(x^2)$
    特别地：$\sqrt{1+x} = 1 + \frac{x}{2} - \frac{x^2}{8} + o(x^2)$

4. $ cosx = 1 - \frac{x^2}{2!} + \frac{x^4}{4!} + o(x^4)$
    $ cosx = 1 - \frac{x^2}{2!} + o(x^2)$

<br>

5. $ sinx = x - \frac{x^3}{3!} + o(x^3)$

6. $ arcsinx = x + \frac{x^3}{3!} + o(x^3)$ *（正负互换）*

7. $ tanx = x + \frac{x^3}{3} + o(x^3)$ *（去掉阶乘）*

8. $ arctanx = x - \frac{x^3}{3} + o(x^3)$ *（正负互换）*



**泰勒公式求极限**

1. $x \to 0$ 可以推广为 $▢ \to 0$

> $e^{x^2} = 1 + x^2 + \frac{(x^2)^2}{2!} + o((x^2)^2)$

> $\lim_{x \to 0} \frac{ \sqrt{1+x} + \sqrt{1-x} - 2}{x^2}$
> $= \lim_{x \to 0} \frac{1+ \frac{x}{2} - \frac{x^2}{8} + o(x^2) + 1 - \frac{x}{2} - \frac{x^2}{8} + o(x^2) - 2}{x^2}$
> $= \lim_{x \to 0} \frac{- \frac{x^2}{4} + o(x^2)}{x^2}$
> $= - \frac{1}{4}$


2. 分子分母同阶原则，加减不抵消原则

> $\lim_{x \to 0} \frac{cosx - e^{- \frac{x^2}{2}}}{x^4}$
> $= \lim_{x \to 0} \frac{1 - \frac{x^2}{2} + \frac{x^4}{4!} + o(x^4) - (1 - \frac{x^2}{2} + \frac{x^4}{2!} + o(x^4))}{x^4}$


> $\lim_{x \to 0} \frac{cosx - e^{-\frac{x^2}{2}}}{x^4}$
> $= \lim_{x \to 0} \frac{1 - \frac{x^2}{2} + \frac{x^4}{4!} + o(x^4) - (1 - \frac{x^2}{2} + \frac{x^4}{2!*4} + o(x^4))}{x^4}$
> $= \lim_{x \to 0} \frac{ \frac{x^4}{4!} - \frac{x^4}{2!*4} + o(x^4)}{x^4}$
> $= \frac{1}{12}$


## 七类不定式

1. **$\frac{0}{0}$**

    * 洛必达 -> 等价 -> 泰勒

2. **$\frac{\infty}{\infty}$**

    * 洛必达 -> 同除（最高次幂） -> 抓大头（每个因式保留高阶无穷大）

3. **$0 \cdot \infty$**

    * 同除简单因式（转换为 $\frac{0}{0} \frac{\infty}{\infty}$） -> 拆项等价 -> 洛必达

4. **$\infty - \infty$**

    * 通分（有分数） -> 有理化（有根式） -> 倒带换（令 $x = \frac{1}{t}$ ）

5. **$0^0$**
6. **$\infty^0$**

    * $\lim_{x \to ▢}u^v = \lim_{x \to ▢} e ^ {v \ln u} \overset{ 极限交换, e^x连续 }{=} e ^{\lim_{x \to ▢}v \ln u}$

> $\lim_{x \to 0^+} x^\alpha \ln ^ \beta x = 0 (\alpha, \beta > 0)$


7. **$1^\infty$**

    * $\lim_{x \to ▢}(1 + u)^v = e ^ {\lim_{x \to ▢} v \ln (1+u)} = e^{\lim_{x \to ▢} u v} (u \to 0, v \to \infty)$

    * $\lim_{x \to ▢}u^v = \lim_{x \to ▢}(1 + (u-1))^v = e^{\lim_{x \to ▢} (u-1) v} (u \to 1, v \to \infty)$



## 单调有界定理


$\{x_n\} \uparrow$ 有上界或 $\{x_n\} \downarrow$ 有下界，则 $\lim_{n \to \infty} x_n$ 存在。
注：上界或下界不唯一



## 夹逼定理

## 定积分定义


<br>

---

# 第二节 导数与微分

## 导数

### 连续

### 间断

## 微分

## 【求导公式】基本初等函数

## 【求导公式】四则运算

## 【求导公式】复合函数

## 【求导公式】隐函数

## 【求导公式】反函数

## 【求导公式】参数方程

## 【求导公式】对数

## 【求导公式】高阶导数












<br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br>