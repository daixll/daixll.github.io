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
        <title> Vue CDN</title>
        <script src="https://lf3-cdn-tos.bytecdntp.com/cdn/expire-1-M/vue/3.2.31/vue.global.min.js"></script>
    </head>
    
    <body>
        <div id="hello-vue" class="demo">
            {{ message }}
        </div>

        <script>
            const HelloVueApp = {
                data() {
                    return {
                        message: 'Hello Vue!!'
                    }
                }
            }
            Vue.createApp(HelloVueApp).mount('#hello-vue')
        </script>
    </body>
</html>
```

## `v-bind`



<br>

---

## `v-for`




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


