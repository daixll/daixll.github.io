## setup

### linux

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

### windows

1. [下载](https://dev.mysql.com/downloads/installer/)

2. 默认安装即可


<br>

---

## ues