# HTML基础

### 标题标签

```html
<h1>一级标题</h1>
<h6>六级标题</h6>
```

### 段落标签

```html
<p>段落</p>
```

### 换行标签

```html
<br />
```

### 文本格式化标签

```html
<strong>加粗</strong>
<em>斜体</em>
<del>删除线</del>
<ins>下划线</ins>
```

### 盒子标签

```html
<div>块级标签</div> <!--大盒子-->
<span>行内元素</span> <!--小盒子-->
```

### 图像标签

```html
<img src="demo.jpg" alt="替换文字" title="提示文字" />
```

### 超链接标签

```html
<a href="http://www.qq.com" target="_blank">腾讯</a>
```

### 锚点定位

```html
<h1 id="001">标题</h1>
<a href="#001">文字</a>
```

### 注释标签

```html
<!--注释-->
```

### 特殊字符

```html
&lt; &gt; &nbsp; 
```

### 表格标签

```html
<table>
    <thead>
        <tr><th>表头</th><th>表头</th></tr>
        <tr><td>内容</td><td>内容</td></tr>
    </thead>
    <tbody>
        <tr><td>内容</td><td>内容</td></tr>
    </tbody>
</table>
```

### 合并单元格

```html
 <table width="500" height="249" border="1" cellspacing="0">
        <tr>
            <td></td>
            <td colspan="2"></td>
           
        </tr>
        <tr>
            <td rowspan="2"></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
           
            <td></td>
            <td></td>
        </tr>
    
    </table>
```

### 无序列表

```html
<ul>
        <li>榴莲</li>
        <li>臭豆腐</li>
        <li>鲱鱼罐头</li>
        <li>
            <p>123</p>
        </li>
</ul>
```

### 有序列表

```html
<ol>
        <li>刘德华 10000</li>
        <li>刘若英 1000</li>
</ol>
```

### 自定义列表

```html
<dl>
        <dt>关注我们</dt>
        <dd>新浪微博</dd>
        <dd>官方微信</dd>
        <dd>联系我们</dd>
        <dt>关注我们</dt>
        <dd>新浪微博</dd>
        <dd>官方微信</dd>
        <dd>联系我们</dd>
</dl>
```

### 表单域

```html
<form action="demo.php" method="POST" name="name1">

</form>
```

### 表单元素

```html
<form action="xxx.php" method="get">
         <!-- text 文本框 用户可以里面输入任何文字 -->
        用户名: <input type="text" name="username" value="请输入用户名" maxlength="6">   <br> 
        <!-- password 密码框 用户看不见输入的密码 -->
        密码: <input type="password" name="pwd" >  <br> 
        <!-- radio 单选按钮  可以实现多选一 -->
        <!-- name 是表单元素名字 这里性别单选按钮必须有相同的名字name 才可以实现多选1 -->
        <!-- 单选按钮和复选框可以设置checked 属性, 当页面打开的时候就可以默认选中这个按钮 -->
        性别: 男 <input type="radio" name="sex" value="男"> 女  <input type="radio" name="sex" 					value="女" checked="checked"> 人妖   <input type="radio" name="sex" value="人				妖">   <br> 
        <!-- checkbox 复选框  可以实现多选 -->
        爱好: 吃饭 <input type="checkbox" name="hobby" value="吃饭"> 睡觉 <input type="checkbox" 			name="hobby">  打豆豆 <input type="checkbox" name="hobby" checked="checked"> 
        <br> 
        <!-- 点击了提交按钮,可以把 表单域 form 里面的表单元素 里面的值 提交给后台服务器 -->
        <input type="submit" value="免费注册">
        <!-- 重置按钮可以还原表单元素初始的默认状态 -->
        <input type="reset" value="重新填写">
        <!-- 普通按钮 button  后期结合js 搭配使用-->
        <input type="button" value="获取短信验证码"> <br>
        <!-- 文件域 使用场景 上传文件使用的 -->
        上传头像:  <input type="file" >
</form>
```

### label标签

```html
<label for="text"> 用户名:</label> <input type="text" id="text" >
<input type="radio" id="nan" name="sex"> <label for="nan">男</label>
<input type="radio" id="nv"  name="sex"> <label for="nv">女</label>
```

### 下拉表单

```html
<select>
        <option>山东</option>
        <option>北京</option>
        <option>天津</option>
        <option selected="selected">火星</option>
</select>
```

### 文本域

```html
<textarea cols="50" rows="5">文字内容 </textarea>
```