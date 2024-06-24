# main/java

## org/dxl/pojo

**普通 Java 对象**，常用于封装数据传输对象

* `@Override` 重写父类方法

* `Lombok` 提供的注解：
    * `@Data` 用于自动生成类的 `toString()` 等
    * `@NoArgsConstructor` 自动生成无参构造方法
    * `@AllArgsConstructor`自动生成包含所有成员变量的构造方法

<details><summary>Result.java</summary>

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

<details><summary>PageBean.java</summary>

```java
package org.dxl.pojo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

/**
 * 分页查询结果封装类
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
public class PageBean {
    private Long total;     // 总记录数
    private List<Emp> rows; // 当前页数据列表
}
```
</details>

<details><summary>Emp.java</summary>

```java
package org.dxl.pojo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;
import java.time.LocalDateTime;

/**
 * 普通用户类
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
public class Emp {
    private Integer id;                 // 员工编号
    private String userName;            // 用户名
    private String password;            // 密码
    private String name;                // 姓名
    private Short gender;               // 性别
    private String image;               // 头像
    private Short job;                  // 职务
    private LocalDate entryDate;        // 入职日期
    private Integer deptId;             // 部门编号
    private LocalDateTime createTime;   // 创建时间
    private LocalDateTime updateTime;   // 更新时间
}
```
</details>

<details><summary>Dept.java</summary>

```java
package org.dxl.pojo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import java.time.LocalDateTime;

/**
 * 普通部门类
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
public class Dept {
    private Integer id;                 // ID
    private String name;                // 部门名称
    private LocalDateTime createTime;   // 创建时间
    private LocalDateTime updateTime;   // 修改时间
}
```
</details>


<br>

---


## org/dxl/mapper

**映射器**，`MyBatis` 等组件使用

* `@Mapper` 使用 `MyBatis` 框架为接口生成对应实现类

<details><summary>Mapper.java</summary>

```java
// EmpMapper.java
package org.dxl.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Result;
import org.apache.ibatis.annotations.Results;
import org.apache.ibatis.annotations.Select;
import org.springframework.cglib.core.Local;
import org.dxl.pojo.Emp;

import java.time.LocalDate;
import java.util.List;

@Mapper
public interface EmpMapper {
    // 增
    void insertEmp(Emp emp);            // insert into emp values(...);
    // 删
    void deleteById(int id);            // delete from emp where id = ?;
    void deleteByIds(List<Integer> ids);// delete from emp where id in (...);
    // 改
    void updateEmp(Emp emp);            // update emp set ... where id = ?;
    // 查
    List<Emp> getEmpList();             // select * from emp;
    Emp selectById(int id);             // select * from emp where id = ?;
    List<Emp> selectByName(String name, Short gender, LocalDate begin, LocalDate end);
                                        // select * from emp where name like ?
}
```
</details>


<br>

---


## org/dxl/service

**服务层**，封装业务逻辑和数据处理，提供给 `Controller` 使用

调用 `DAO` 层实现对数据的访问和操作

* `@Server` 标识为 `Spring Bean`，由 `Spring` 管理的服务类
* `@Resource` 依赖注入

<details><summary>Service.java</summary>

```java
// EmpService.java
package org.dxl.service;

import org.dxl.pojo.Emp;
import java.util.List;

public interface EmpService {
    List<Emp> getEmpList();
}
```
</details>

<details><summary>impl/ServiceImpl.java</summary>

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


## org/dxl/controller

**控制器**，处理 `HTTP` 请求，返回 `HTTP` 响应，调用业务逻辑返回结果

* `@RestController` 处理 HTTP 请求并返回响应数据
* `@Resource` 依赖注入，解耦一个类对其依赖对象的创建和管理过程
* `@GetMapping` 处理 HTTP GET 请求
* `@RequestParam` 从请求中获取 key 的 value，并且赋值给某个变量

<details><summary>Controller.java</summary>

```java
// EmpController.java
package org.dxl.controller;

import jakarta.annotation.Resource;
import org.dxl.pojo.Emp;
import org.dxl.pojo.Result;
import org.dxl.service.EmpService;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class EmpController {
    @Resource
    EmpService empService;              // 暂时按照自动实例化、智能指针理解吧

    @GetMapping("/list")                // 处理客户端对 "/list" 路径的 GET 请求
    public Result getEmpList() {        // 返回一个 Result
        List<Emp> emps = empService.getEmpList();       // 调用服务层
        return Result.success(emps);
    }
}
```
</details>