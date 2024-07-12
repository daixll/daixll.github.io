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

## socketio

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8"> 
        <title> c </title>
        
        <script src="https://cdn.socket.io/4.0.1/socket.io.min.js"></script>
        <script>
            document.addEventListener('DOMContentLoaded', function() {
                // 创建一个 socketio 对象，指定连接的服务器地址
                var sock = io('http://localhost:5000');
                
                // 当连接建立时，如果服务器发送 response 消息，弹出提示
                sock.on('response', function (data) {
                    alert('server: ' + data);
                });

                // 当点击按钮时，向服务器发送消息
                document.getElementById('sss').addEventListener('click', function () {
                    sock.send(document.getElementById('ttt').value);
                });
            });
        </script>
    </head>    

    <body>
        <input type="text" id="ttt">
        <button type="submit" id="sss">Send</button>
    </body>
</html>
```

```py
from flask import Flask
from flask_socketio import SocketIO, send, emit

app = Flask(__name__)               # 创建一个 Flask 实例
socketio = SocketIO(app, cors_allowed_origins="http://127.0.0.1:2024")                

@socketio.on('connect')             # 监听 connect 事件
def handle_connect():
    emit('response', 'connected')   # 发送 response 事件，内容为 Connected

@socketio.on('message')             # 监听 message 事件
def handle_message(msg):            # 如果收到 message 事件，执行此函数            
    emit('response', msg)           # 发送 response 事件

if __name__ == '__main__':
    socketio.run(app, debug=True, host='127.0.0.1', port=5000)
```


## 下面未整理

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


## VUE

```
my-vue-project
├── node_modules/       # 项目依赖包
├── public/             # 静态文件
├── src/                # 源代码
│   ├── assets/         # 静态资源（图片、字体等）
│   ├── components/     # 公共组件
│   ├── router/         # 路由配置
│   │   └── index.js    # 路由定义
│   ├── views/          # 视图组件
│   │   ├── Home.vue    # Home 视图
│   │   └── About.vue   # About 视图
│   ├── App.vue         # 根组件
│   └── main.js         # 入口文件
├── .gitignore          # Git 忽略文件
├── babel.config.js     # Babel 配置
├── package.json        # 项目信息和依赖
└── README.md           # 项目说明

```

### 本地运行

1. 下载 [Node.js](https://nodejs.org/en)
    * 终端验证 `node -v`

2. 创建 `vue` 项目
    * `npm create vue@latest`
    * 不知道就全 `No`

3. 运行 `vue` 项目
    * `cd 项目`
    * `npm install`
    * `npm run dev`
    
### CDN 运行

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

### v-bind

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

### v-for

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

### v-if



<br>

---

### v-show


<br>

---


### v-model


<br>

---


### v-on


<br>

---

## AXIOS

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

### get

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