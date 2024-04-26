---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

<br>

---


# 1

## Controller

> **控制器**
> * 处理 HTTP 请求，返回 HTTP 响应
> * 调用业务逻辑返回结果

* `@RestController`
    

* `@GetMapping`


* `@RequestParam`
    从请求中获取 key 的 value，并且赋值给某个变量

<br>

---

## Server

> **服务层**
> * 封装业务逻辑和数据处理，提供给 Controller 使用
> * 调用 DAO 层实现对数据的访问和操作

<br>

---

## DAO

> **数据访问对象**
> * CRUD
> * 数据访问与业务逻辑分离

<br>

---

## Mapper

> **映射器**
> * MyBatis 等组件使用


<br>

---

## POJO

> **普通 Java 对象**
> 常用于封装数据传输对象

<br>

---