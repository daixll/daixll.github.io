---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

<br>

---

# 安装

## ubuntu

1. 下载安装
    * `apt install mysql-server`
    * `apt install mysql-client`

2. 初始化
    * `mysql_secure_installation`

3. 启动服务
    * `service mysql start`

4. 登录
    * `mysql -u root -p`

5. 设置密码
    * `use mysql;`
    * `ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY '12345678';`

5. 退出
    * `quit`

## windows

1. 下载



<br>

---


## one



# MySQL 速查

* 查看数据库 `show databases;`
* 使用数据库 `use 库名;`
* 删除数据库 `drop database 库名;`
* 创建数据库 `create database 库名;`

## **C**reate

* 创建表 
    ```sql
    CREATE TABLE 表名(
        列名 类型 约束,
        user_id INT AUTO_INCREMENT PRIMARY KEY,
        username VARCHAR(50) NOT NULL,
        birthdate DATE
    );
    ```

* 创建记录
    ```sql
    INSERT INTO students (student_name, age)
    VALUES ('Alice', 20);
    ```

## **R**ead

* 查看所有表 `show tables;`
* 查看表中所有数据 `select * from 表名;`

## **U**pdate

## **D**elete

* 删除某张表 `drop table 表名;`
* 简单条件删除 `delete from 表名 where 列名 = 值;`