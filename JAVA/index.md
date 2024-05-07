---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

<br>

**所以，是在写代码还是在 cv api 呢 ;)**


---


# **main**

## **java**

### org.dxl.controller

> **控制器**
> * 处理 HTTP 请求，返回 HTTP 响应
> * 调用业务逻辑返回结果

<details><summary><a href="" target="_blank"></a> 简单 RESTful API 接口 </summary><br>

* `@RestController` 处理 HTTP 请求并返回响应数据
* `@Resource` 依赖注入，解耦一个类对其依赖对象的创建和管理过程
* `@GetMapping` 处理 HTTP GET 请求
* `@RequestParam` 从请求中获取 key 的 value，并且赋值给某个变量

```java
// EmpController.java

@RestController
public class EmpController {
    @Resource
    EmpService empService;              // 暂时按照自动实例化、智能指针理解吧

    @GetMapping("/list")                // 处理客户端对 "/list" 路径的 GET 请求
    public Result getEmpList() {        // 返回一个 Result
        List<Emp> emps = empService.getEmpList();   // 调用服务层
        return Result.success(emps);
    }

    @GetMapping("/")
    public RedirectView index() {
        return new RedirectView("emp.html");    // 重定向
    }
}
```
</details>

<br>

---

### org.dxl.server

> **服务层**
> * 封装业务逻辑和数据处理，提供给 Controller 使用
> * 调用 DAO 层实现对数据的访问和操作

<details><summary><a href="" target="_blank"></a> Server</summary><br>

```java
public interface EmpService {
    List<Emp> getEmpList();
}
```
</details>

<details><summary><a href="" target="_blank"></a> ServerImpl</summary><br>

* `@Server` 标识为 Spring Bean，由 Spring 管理的服务类
* `@Resource` 依赖注入
* `@Override` 重写父类方法

```java
@Service
public class EmpServiceImpl implements EmpService {
    @Resource
    EmpMapper empMapper;

    @Override
    public List<Emp> getEmpList() {
        List<Emp> emps = empMapper.getEmpList();
        return emps;
    }
}
```
</details>


<br>

---


### org.dxl.mapper

> **映射器**
> * MyBatis 等组件使用

<details><summary><a href="" target="_blank"></a> Mapper </summary><br>

* `@Mapper` 使用 MyBatis 框架为接口生成对应实现类

```java
@Mapper
public interface EmpMapper {
    List<Emp> getEmpList();
}
```
</details>

<br>

---

### org.dxl.pojo

> **普通 Java 对象**
> * 常用于封装数据传输对象

<details><summary><a href="" target="_blank"></a> Result 统一响应结果封装类</summary><br>

* `@Override` 重写父类方法

```java
public class Result {
    private Integer code ;//1 成功 , 0 失败
    private String msg; //提示信息
    private Object data; //数据 date

    public Result() {
    }
    public Result(Integer code, String msg, Object data) {
        this.code = code;
        this.msg = msg;
        this.data = data;
    }
    public Integer getCode() {
        return code;
    }
    public void setCode(Integer code) {
        this.code = code;
    }
    public String getMsg() {
        return msg;
    }
    public void setMsg(String msg) {
        this.msg = msg;
    }
    public Object getData() {
        return data;
    }
    public void setData(Object data) {
        this.data = data;
    }

    public static Result success(Object data){
        return new Result(1, "success", data);
    }
    public static Result success(){
        return new Result(1, "success", null);
    }
    public static Result error(String msg){
        return new Result(0, msg, null);
    }

    @Override
    public String toString() {
        return "Result{" +
                "code=" + code +
                ", msg='" + msg + '\'' +
                ", data=" + data +
                '}';
    }
}

```
</details>


<details><summary><a href="" target="_blank"></a> Emp 用于数据库操作的实体类</summary><br>

`Lombok` 提供的注解

* `@Data` 用于自动生成类的 `toString()` 等
* `@NoArgsConstructor` 自动生成无参构造方法
* `@AllArgsConstructor`自动生成包含所有成员变量的构造方法

```java
@Data
@NoArgsConstructor
@AllArgsConstructor
public class Emp {
    private Integer id;
    private String userName;
    private String password;
    private String name;
    private Short gender;
    private Short job;
    private LocalDate entryDate;
    private Integer deptId;
    private LocalDateTime createTime;
    private LocalDateTime updateTime;
}

```
</details>

<br>

---

### org.dxl.dao

> **数据访问对象**
> * CRUD
> * 数据访问与业务逻辑分离

<br>

---

### Application


<br>

---

## **resources**

### org.dxl.mapper

### static

<br>

---

# **test**

## **java**

### org.dxl.ApplicationTests


