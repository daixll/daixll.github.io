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



<br>

---

### org / dxl / mapper

> **映射器**
> * MyBatis 等组件使用

<details><summary><a href="" target="_blank"></a><span style="color: orange">Mapper.java</span></summary><br>

* `@Mapper` 使用 MyBatis 框架为接口生成对应实现类

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



<br>

---


### org / dxl / service



<br>

---


### Application


<br>

---

## **resources**

### org / dxl / mapper

> 

<details><summary><a href="" target="_blank"></a><span style="color: orange">EmpMapper.xml</span></summary><br>

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "https://mybatis.org/dtd/mybatis-3-mapper.dtd">

<mapper namespace="org.dxl.mapper.EmpMapper">

    <resultMap id="empResultMap" type="org.dxl.pojo.Emp">
        <result colum="class" property="class_name">
    </resultMap>

    <!-- 查询所有 -->
    <select id="getEmpList" resultMap="empResultMap">
        select * from work
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

<details><summary><a href="" target="_blank"></a><span style="color: orange"> application.properties</span></summary><br>

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


<details><summary><a href="" target="_blank"></a><span style="color: orange">Tests</span></summary><br>

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
