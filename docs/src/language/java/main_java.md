# main/java

## org/dxl/controller



## org/dxl/mapper


## org/dxl/pojo

**普通 Java 对象**, 常用于封装数据传输对象

* `@Override` 重写父类方法

<details>

<summary>Result.java</summary>

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

`Lombok` 提供的注解

* `@Data` 用于自动生成类的 `toString()` 等
* `@NoArgsConstructor` 自动生成无参构造方法
* `@AllArgsConstructor`自动生成包含所有成员变量的构造方法

<details><summary><a href="" target="_blank"></a>Emp.java</span></summary>

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

<details><summary><a href="" target="_blank"></a>Dept.java</span></summary>

```java
package org.dxl.pojo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import java.time.LocalDateTime;

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

<details><summary><a href="" target="_blank"></a>PageBean.java</span></summary>

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

## org/dxl/service


## Application

