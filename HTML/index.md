---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子


<br>

---


# HTML

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8"> 
        <title> 网页名称 </title>
    </head>
    <body>
        网页内容
    </body>
</html>
```

## 小区块

```html
<span style="color: red;"> 红色 </span><span style="color: green;"> 绿色 </span>
```

> <span style="color: red;"> 红色 </span><span style="color: green;"> 绿色 </span>

## 大区块

```html
<div style="color: red;"> 红色 </div><div style="color: green;"> 绿色 </div>
```

> <div style="color: red;"> 红色 </div><div style="color: green;"> 绿色 </div>

## 段落

```html
<p> 段落 1 </p>
<p> 段落 2 </p>
```

> <p> 段落 1 </p>
> <p> 段落 2 </p>

## 超链接

```html
<a href="https://www.google.com"> 点击跳转谷歌 </a>
```
> <a href="https://www.google.com"> 点击跳转谷歌 </a>

## 图片

```html
<img src="https://codeforces.org/s/26754/images/codeforces-sponsored-by-ton.png" alt="图片无法显示" width="200" height="100">
```

> <img src="https://codeforces.org/s/26754/images/codeforces-sponsored-by-ton.png" alt="图片无法显示" width="200" height="100">

<br>

---


# CSS

## id 选择器

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8"> 
        <title> 网页名称 </title>

        <style>
            #one
            {
                color:red;
            }

            #two
            {
                color:green;
            }
        </style>

    </head>

    <body>
        <p id="one"> 网页内容 </p>
        <p id="two"> 网页内容 </p>
    </body>
</html>
```

## class 选择器

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8"> 
        <title> 网页名称 </title>

        <style>
            .one{
                color:red;
            }

            p.two{
                color:green;
            }

            .center{
                text-align:center;
            }
        </style>
    </head>
    <body>
        <p> 网页内容 </p>
        <p class = "one"> 网页内容 </p>
        <p class = "two center"> 网页内容 </p>
    </body>
</html>
```

## 盒子模型

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8"> 
        <title> 网页名称 </title>

        <style>
            div{
                background-color: lightgrey;/* 背景颜色 */
                
                margin: 100px;                /* 边框外面一层 */
                border: 50px solid green;   /* 边框大小 */
                padding: 100px ;              /* 边框里面一层 */
                
                text-align:center;
            }
        </style>
    </head>
    <body>
        <div>网页内容</div>
    </body>
</html>
```


<br>

---



# JS

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8"> 
        <title> 网页名称 </title>

        <script>
            function one(){
                document.getElementById("demo").innerHTML=Date();
            }

            // 每一秒重新调用 one() 函数
            setInterval(one, 1000);
        </script>
    </head>    
    
    <body>
        <p id="demo"></p>
    </body>
</html>
```

## 操纵 html 元素

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8"> 
        <title> 网页名称 </title>
    </head>    
    
    <body>
        <p id="one"> hhh </p>

        <script>
            document.getElementById("one").innerHTML="666";
        </script>
    </body>
</html>
```



<br>

---

# VUE

1. 下载 [Node.js](https://nodejs.org/en)
    * 终端验证 `node -v`

2. 创建 `vue` 项目
    * `npm create vue@latest`
    * 不知道就全 `No`

3. 运行 `vue` 项目
    * `cd 项目`
    * `npm install`
    * `npm run dev`
    
## 使用 CDN 运行

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title> Vue CDN </title>
        <script src="https://lf3-cdn-tos.bytecdntp.com/cdn/expire-1-M/vue/3.2.31/vue.global.min.js"></script>
    </head>
    
    <body>
        <div id="one">
            {{ message }}
        </div>

        <script>
            const HelloVueApp = {   // 定义 Vue 应用程序对象
                data() {            // 数据对象
                    return {        // 初始化数据
                        message: 'Hello Vue!'
                    }
                }
            }   // 创建 vue 实例并将其挂载到页面上指定元素上 
            Vue.createApp(HelloVueApp).mount('#one')
        </script>
    </body>
</html>
```

## `v-bind`

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>  v-bind </title>
    <script src="https://lf3-cdn-tos.bytecdntp.com/cdn/expire-1-M/vue/3.2.31/vue.global.min.js"></script>

</head>

<body>
    
    <div id="one">
        <div v-bind:title="V_titleText"> 鼠标悬停这里查看标题 </div>
        <a v-bind:href="V_userName"> 用户资料 </a>
        <div v-bind:style="{ color: V_textColor, fontSize: V_fontSize + 'px' }"> 这是一个动态样式的文本 </div>
        <button v-on:click="V_handleClick"> 点击触发事件 </button>
    </div>

    <script>
        const { createApp } = Vue;

        const app = createApp({
            data() {
                return {
                    V_titleText: '这是一个标题',
                    V_userName: 'https://daixll.github.io',
                    V_textColor: 'red',
                    V_fontSize: 1
                };
            },
            methods: {
                V_handleClick(){
                    this.V_fontSize += 1;
                }
            }
        });

        app.mount('#one');
    </script>

</body>
</html>
```

<br>

---

## `v-for`

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title> v-for 列表 </title>
    <script src="https://lf3-cdn-tos.bytecdntp.com/cdn/expire-1-M/vue/3.2.31/vue.global.min.js"></script>
</head>

<body>
    <ul id="one">
        <!--对 items 数组中的每个元素进行遍历-->
        <li v-for="item in arr" :key="item.id">{{ item.text }}</li>
    </ul>

    <script>
        const app = Vue.createApp({
            data() {
                return {
                    arr: [
                        { id: 1, text: 'Item 1' },
                        { id: 2, text: 'Item 2' },
                        { id: 3, text: 'Item 3' }
                    ]
                };
            }
        });
        app.mount('#one');
    </script>
</body>
</html>
```

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title> v-for 对象 </title>
    <script src="https://lf3-cdn-tos.bytecdntp.com/cdn/expire-1-M/vue/3.2.31/vue.global.min.js"></script>
</head>

<body>
    <ul id="one">
        <li v-for="(value, key) in object" :key="key">{{ key }}: {{ value }}</li>
    </ul>

    <script>
        const app = Vue.createApp({
            data() {
                return {
                    object: {
                        a: 'A',
                        b: 'B',
                        c: 'C'
                    }
                };
            }
        });
        app.mount('#one');
    </script>

</body>
</html>
```

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title> v-for 表格</title>
    <script src="https://lf3-cdn-tos.bytecdntp.com/cdn/expire-1-M/vue/3.2.31/vue.global.min.js"></script>
</head>

<body>

    <div id = "one">
        <table border="1" colspan="0" cellspacing="0">
            <thead>
                <tr>
                    <th>序号</th>
                    <th>学号</th>
                    <th>姓名</th>
                    <th>年龄</th>
                    <th>性别</th>
                    <th>地址</th>
                </tr>
            </thead>
            <tbody>
                <tr v-for="(student, index) in students" :key="index">
                    <td>{{index + 1}}</td>
                    <td>{{student.id}}</td>
                    <td>{{student.name}}</td>
                    <td>{{student.age}}</td>
                    <td>{{student.sex === 1 ? '男' : '女'}}</td>
                    <td>{{student.addr}}</td>
                </tr>
            </tbody>
        </table>
    </div>

    <script>
        const app=Vue.createApp({
            data(){
                return {
                    students:[
                        {
                            id: "101",
                            name: "张三",
                            age: 18,
                            sex: 1,
                            addr: "重庆"
                        },
                        {
                            id: "105",
                            name: "李红",
                            age: 20,
                            sex: 2,
                            addr: "上海"
                        },
                        {
                            id: "217",
                            name: "刘天民",
                            age: 19,
                            sex: 1,
                            addr: "乌鲁木齐"
                        },
                        {
                            id: "301",
                            name: "田田",
                            age: 21,
                            sex: 2,
                            addr: "成都"
                        },
                    ]
                }
            }
        });

        app.mount('#one');
    </script>

</body>
</html>
```

<br>

---

## `v-if`



<br>

---

## `v-show`


<br>

---


## `v-model`


<br>

---


## `v-on`


<br>

---

# AXIOS

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title> axios </title>
    <script src="https://unpkg.com/axios/dist/axios.min.js"></script>
</head>

<body>
    
</body>
</html>
```

## get

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title> axios </title>
    <script src="https://unpkg.com/axios/dist/axios.min.js"></script>
</head>

<body>
    <div>
        <table border="1" colspan="0" cellspacing="0">
            <thead>
                <tr>
                    <th>学号</th>
                    <th>姓名</th>
                    <th>年龄</th>
                    <th>性别</th>
                    <th>地址</th>
                </tr>
            </thead>
            <tbody id="one"></tbody>
        </table>
    </div>

    <script>
        const apiUrl = "https://yapi.pro/mock/152964/students";
        const tableBody = document.getElementById('one');

        axios.get(apiUrl)
            .then(response => {
                // 请求成功，遍历数据并添加到表格中
                response.data.data.forEach(item => {
                    // 创建表格行
                    const row = document.createElement('tr');

                    // 使用循环创建并填充表格单元格
                    ['id', 'name', 'age', 'sex', 'addr'].forEach(key => {
                        const cell = document.createElement('td');
                        cell.textContent = key === 'sex' ? (item[key] === 1 ? '男' : '女') : item[key];
                        row.appendChild(cell);
                    });

                    // 将行添加到表格体中
                    tableBody.appendChild(row);
                });
            })
            .catch(error => {
                // 请求失败，打印错误信息
                console.error('Error fetching data:', error);
            });
    </script>

</body>
</html>
```


<br>

---