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
            function
        </script>
    </head>    
    
    <body>
        网页内容
    </body>
</html>
```


<br>

---

# VUE



