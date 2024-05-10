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

### org / dxl / controller

> **控制器**
> * 处理 HTTP 请求，返回 HTTP 响应
> * 调用业务逻辑返回结果

<details><summary><a href="" target="_blank"></a><span style="color: blue">Controller.java</span></summary><br>

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

### org / dxl / mapper

> **映射器**
> * MyBatis 等组件使用

<details><summary><a href="" target="_blank"></a><span style="color: blue">Mapper.java</span></summary><br>

* `@Mapper` 使用 MyBatis 框架为接口生成对应实现类

```java
@Mapper
public interface EmpMapper {
    List<Emp> getEmpList();             // select * from emp;
    Emp selectById(int id);             // select * from emp where id = ?;
    List<Emp> selectByName(String name, Short gender, LocalDate begin, LocalDate end);
                                        // select * from emp where name like ?
    
    void insertEmp(Emp emp);            // insert into emp values(...);
    
    void updateEmp(Emp emp);            // update emp set ... where id = ?;
    
    void deleteById(int id);            // delete from emp where id = ?;
    void deleteByIds(List<Integer> ids);// delete from emp where id in (...);
}
```
</details>

<br>

---


### org / dxl / pojo

> **普通 Java 对象**
> * 常用于封装数据传输对象

<details><summary><a href="" target="_blank"></a><span style="color: blue">Result.java</span></summary><br>

* `@Override` 重写父类方法

```java
package org.dxl.pojo;

/**
 * 统一响应结果封装类
 */
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


<details><summary><a href="" target="_blank"></a><span style="color: blue">Emp.java</span></summary><br>

`Lombok` 提供的注解

* `@Data` 用于自动生成类的 `toString()` 等
* `@NoArgsConstructor` 自动生成无参构造方法
* `@AllArgsConstructor`自动生成包含所有成员变量的构造方法

```java
package org.dxl.pojo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;
import java.time.LocalDateTime;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class Emp {
    private Integer id;
    private String userName;
    private String password;
    private String name;
    private Short gender;
    private String image;
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


### org / dxl / service

> **服务层**
> * 封装业务逻辑和数据处理，提供给 Controller 使用
> * 调用 DAO 层实现对数据的访问和操作

<details><summary><a href="" target="_blank"></a><span style="color: blue">Service.java</span></summary><br>

```java
// EmpService.java
public interface EmpService {
    List<Emp> getEmpList();
}
```
</details>

<details><summary><a href="" target="_blank"></a><span style="color: blue">impl / ServiceImpl.java</span></summary><br>

* `@Server` 标识为 Spring Bean，由 Spring 管理的服务类
* `@Resource` 依赖注入
* `@Override` 重写父类方法

```java
// EmpServiceImpl.java
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



### org / dxl / dao

> **数据访问对象**
> * CRUD
> * 数据访问与业务逻辑分离

<br>

---

### Application


<br>

---

## **resources**

### org / dxl / mapper

> 

<details><summary><a href="" target="_blank"></a><span style="color: blue">EmpMapper.xml</span></summary><br>

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "https://mybatis.org/dtd/mybatis-3-mapper.dtd">

<mapper namespace="org.dxl.EmpMapper">

    <resultMap id="empResultMap" type="org.dxl.pojo.Emp">
        <result property="实体类中的属性名" column="数据库表中列名"/>
    </resultMap>

    <!-- 查询所有 -->
    <select id="getEmpList" resultMap="empResultMap">
        select * from 表名
    </select>



</mapper>
```


</details>


<br>

---

### static

<br>

---

### application.properties

> **配置文件**

<details><summary><a href="" target="_blank"></a><span style="color: blue"> application.properties</span></summary><br>

```sh
spring.application.name=项目名字

# mysql 配置
spring.datasource.driver-class-name=com.mysql.cj.jdbc.Driver
spring.datasource.url=jdbc:mysql://localhost:3306/数据库名字
spring.datasource.username=root
spring.datasource.password=1234
```
</details>

<br>

---


# **test**

## **java**

### org / dxl / ApplicationTests


<details><summary><a href="" target="_blank"></a><span style="color: blue">Tests</span></summary><br>

```java
package org.dxl;

import jakarta.annotation.Resource;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.dxl.mapper.EmpMapper;
import org.dxl.pojo.Emp;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

@SpringBootTest
class SpringbootWebMybatisCrudApplicationTests {

    @Resource
    EmpMapper empMapper;

    @Test
    void testGetEmpList(){
        List<Emp> list = empMapper.getEmpList();
        for (Emp e : list){
            System.out.println(e);
        }
    }


}
```
</details>
