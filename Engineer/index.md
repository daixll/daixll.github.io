---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

内容确实太多，把握不了重点

每天几道题，根据题目所涉及的知识点去完善知识点

主要是内容不深，贵在全面

---

# 2 基础

## 2.5 计算机网络

> 网络延迟

服务器延迟的主要影响因素是队列延迟和磁盘IO延迟
对等网络中，终端数量越多，延迟越大
交换机（直接转发）的延迟低于路由器（存储转发）



<br>


<br>

---

# 3 信息系统

> 企业数字化的五个阶段

1. 初始（引入信息技术，但没有发挥对主营业务的支持作用）
2. 单元（部分业务通过信息技术得到了效率提升）
3. 流程（整个业务流程通过信息技术得到了集成优化）
4. 网络（企业内实现以数据为驱动模式创新）
5. 生态（企业与外部合作伙伴、客户、供应商等形成生态圈）

<br>

## 3.7 企业资源规划 ERP

> ERP 

对物流、资金流、信息流进行全面管理的一种信息系统

<br>

> 企业资源规划结构

1. 生产预测（市场的需求）
2. 销售计划
3. 生产计划大纲（根据经营计划的生产目标制定）
4. 主生产计划（对大纲的细化，一定时期的产量计划）
5. 物料需求计划
6. 能力需求计划（能够及时发现能力的瓶颈）
7. 车间作业计划（根据生产优先级制定）
8. 采购与库存管理
9. 质量与设备管理
10. 财务管理
11. 扩展模块（客户关系管理、分销资源管理、供应链管理）

<br>

> CRM 客户关系管理

* 销售自动化是 CRM 中的基础模块
* 营销自动化是销售自动化的补充，含营销计划的编制与执行，计划结果分析等
* CRM 可以与 ERP（财务，制造，库存）等连接形成一定的闭环
* 客户服务与支持是CRM的重要功能，通过呼叫中心与互联网实现


<br>

---

# 4 信息安全

> 证书颁发、验证机构

* CA（证书颁发，负责生成和签署数字证书）
* RA（负责用户身份的验证）


<br>

---

# 5 软件工程

> 遗留系统

* 淘汰（低技术水平，低业务价值）
* 继承（低技术水平，高业务价值）
* 集成（高技术水平，低业务价值）
* 改造（高技术水平，高业务价值）


## 5.1 软件工程

> 瀑布模型

1. 顺序性，工作流程自顶向下
2. 阶段性，每个阶段有明确的任务和成果

缺点：

1. 软件需求的完整性、正确性难以确定
2. 当出现需求变更时，瀑布模型难以适应


<br>

> 原型化模型

过程：

1. 原型开发阶段（实现核心功能，需求确认阶段）
2. 目标软件开发阶段（明确需求，原型大概率抛弃）

<br>

> 螺旋模型

整个开发过程分为多个迭代周期，每个周期包括四个阶段：

1. 目标设定（明确这一周期的目标）
2. 风险分析
3. 开发和有效性验证（进行原型开发，开发具体的软件）
4. 评审（总结，展望）

<br>

## 5.2 需求工程

> 软件需求三个层次

1. 业务需求（用户要使用此软件达到什么目的）
2. 用户需求（用户使用此软件的具体功能）
3. 功能需求（软件的具体功能）

<br>

> 需求工程的主要阶段

1. 需求获取
2. 需求分析
3. 形成需求规格
4. 需求确认与验证
5. 需求管理

<br>

> 需求管理的主要活动

1. 变更控制
2. 版本控制
3. 需求跟踪
4. 需求状态跟踪

<br>

> 维护活动

* 改正性维护（修复bug）
* 适应性维护（外部环境、数据环境发生变化）
* 完善性维护（扩充功能，改善性能）
* 预防性维护（例专用改为通用，防止被淘汰）

<br>

## 5.7 软件项目管理

> 软件项目管理的主要内容

对人员、产品、过程、项目进行分析和管理

> 产品项目范围

产品项目范围是值信息系统产品或者服务所应包含的所有功能和特性

> 项目范围

项目范围是生产项目计划的基础

> 项目范围管理中，范围定义的输入

1. 项目章程
2. 项目范围说明书
3. 组织过程资产
4. 批准的变更申请

<br>

---

# 6 数据库

> 数据挖掘的方法

* 关联分析
* 序列分析
* 聚类分析
* 分类分析
* 预测
* 时间序列分析

<br>

* 异常分析
* 特异群组分析
* 演变分析




<br>

---


# 7 系统架构

## 7.2 基于架构的软件设计方法

> 基于体系结构的软件设计方法

* 视角和视图描述软件架构
* 用例描述功能需求
* 质量场景描述质量需求


<br>


## 7.3 架构风格

> 风格

一个体系结构定义一个词汇表和一组约束，词汇表中包含一些构件和连接件类型，约束指出构件和连接件的组合方式，反应了众多系统所共有的结构和语义特性

<br>

#### 数据流体系

> 批处理

一步一步的走完整个流程

构件：独立的应用程序
连接件：文件

> 管道-过滤器

数据流经过一系列的过滤器，每个过滤器都对数据进行处理

构件：过滤器
连接件：管道

<br>

#### 调用/返回

> 主程序/子程序

> 面向对象

> 层次

> 客户端/服务器

<br>

#### 数据为中心

> 仓库体系



> 黑板体系

语音识别、知识推理、解空间大、求解过程不确定

<br>

#### 虚拟机

#### 独立构件


<br>

---

# 8 质量属性与架构评估

> 机器性能评价准确度

1. 真实程序
2. 核心程序
3. 小型基准程序
4. 合成基准程序（为了覆盖面广，所以准确度降低）

