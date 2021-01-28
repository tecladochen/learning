# MySQL基础

> **说明**：SQL语句不区分大小写，但在执行过程中所有SQL语句都会被转化成大写在执行，所有养成大写的良好				习惯可以优化语句的性能。

## 1.了解数据库和表

```mysql
-- 选择数据库
USE databasename;	
```

```mysql
-- 返回可用数据库的列表
SHOW DATABASES;		
```

```mysql
-- 获取一个数据库内表的列表
SHOW TABLES;		
```

```mysql
-- 返回一个表的列属性
SHOW COLUMNS FROM tablename;	
-- 功能同上，是另一种简捷语法
DESCRIBE tablename;				
```

## 2.SELECT 语句

```mysql
-- distinct选择表示不同的项
-- limit表示限制输出
SELECT DISTINCT columname		
FROM tablename					
LIMIT 1;						
-- limit 1 表示只输出1条
 
SELECT DISTINCT columnname		
FROM database.tablename			
LIMIT 3 OFFSET 4;
-- 表示从第4行开始输出3行
```

## 3.ORDER BY 语句

```mysql
SELECT columnname
FROM tablename
ORDER BY columnname;	
-- 根据column属性进行升序排序

SELECT columnname
FROM tablename
ORDER BY columnname1,columnname2;	
-- 先进行第一个属性的升序，若存在相同属性在使用第二个排序

SELECT columnname
FROM tablename
ORDER BY columnname1 DESC,columnname2;	
-- 在一个column后使用DESC表示降序排序
-- 若需要多个降序需要在每一项后面加DESC

SELECT columnname
FROM tablename
ORDER BY columnname DESC		
LIMIT 1;
-- 得到表的最大值
-- 利用排序和限制输出可以得到表值最大和最小项
```

## 4.WHERE 语句

```mysql
-- 数据根据where子句指定的搜索条件进行过滤
-- where子句一般在from子句后面，在group by之前

SELECT prod_name,prod_price
FROM products
WHERE prod_price = 2.50;		

SELECT prod_name,prod_price
FROM products
WHERE prod_name = `fuses`;
-- 需要用单引号对字符串进行限定

SELECT prod_name,prod_id
FROM products
WHERE prod_id != 1003;
-- 在mysql中 <> 和 != 都表示不相等

SELECT prod_name, prod_price
FROM products
WHERE prod_price BETWEEN 5 AND 10;	
-- between..and..表示匹配范围，包括端点是闭区间

SELECT columnname
FROM tablename
WHERE columnname IS NULL;	
-- is 是对空值检查的特殊关键字
```

## 5.组合 WHERE 子句

```mysql
-- 通过组合where子句建立功能更强的搜索条件

SELECT prod_id, prod_price, prod_name
FROM products
WHERE vend_id = 1003 AND prod_price <= 10;
-- and 表示条件都必须满足

SELECT prod_name, prod_price
FROM products
WHERE vend_id = 1002 OR vend_id = 1003;
-- or 表示只要满足其中一个条件即可

SELECT prod_name, prod_price
FROM products
WHERE (vend_id = 1002 OR vend_id = 1003) AND prod_price >= 10;
-- 在计算次序中 and 的优先级高于 or ，若需要更改次序需要利用小括号
-- 即使次序正确，多利用小括号可以提高代码可读性，方便维护

SELECT prod_name, prod_price
FROM products
WHERE vend_id IN (1002,1003)
ORDER BY prod_name;
-- in 操作符可以对指定条件范围中，每一个条件进行匹配
-- in 操作符一般都可以转化成 多个 or 子句，但 in 操作符更快

SELECT prod_name, prod_price
FROM products
WHERE vend_id NOT IN (1002,1003)
ORDER BY prod_name;
-- not 操作符用以否定跟在它之后的条件，有时候取反操作很方便
-- MySQL支持使用 not 对 in,between,exists等取反 
```

## 6.通配符

> * 搜索模式   MySQL存在俩种搜索模式，直接相等匹配 搜索和通配符搜索
> * LIKE 操作符 表示后面跟的是通配符搜索的搜索模式
> * MySQL 支持的通配符有 `%` 和 `_` 俩种

```mysql
SELECT prod_id, prod_name
FROM products
WHERE prod_name LIKE 'jet%';	
-- % 号表示任意字符可以出现任意次数
-- 该语句表示以 jet 开头所有字符
```

> **注意** ：通配符可以出现在搜索模式的任意位置，像 `%anvil`,`%anvil%`,`an%vil`.
>
>    ​      	` %`通配符除了匹配一个和多个，还可以匹配零个字符.

```mysql
SELECT prod_id,prod_name
FROM products
WHERE prod_name LIKE '_ton anvil';		
--  _ 号表示只匹配一个字符
```

> **注意** ：`_`通配符只能匹配一个字符，不能多也不能少

## 7.正则表达式

> * 正则表达式被用来匹配文本的特殊的串(字符集合)
> * MySQL支持的正则表达式是其的一个子集，只是其本身的一小部分

```mysql
SELECT prod_name
FROM products
WHERE prod_name REGEXP '.000'
ORDER BY prod_name;
```

> * `REGEXP`关键字表示后面的搜索模式是正则表达式匹配搜索(regular expression)
> * `'.000'`单引号里是待匹配字符串
> * `.`号是正则表达式的特殊符号，表示匹配任意一个字符

> **注意** ：`LIKE`和`REGEXP`用法有很大的差异，`LIKE`表示匹配到与模式串相符合的文本，`REGEXP`表示匹配到文本带有模式串相符的串的文本，差异在正则表达式是查找文本是否存在符合的串。

```mysql
SELECT prod_name
FROM products
WHERE prod_name REGEXP '1000|2000'
ORDER BY prod_name;
```

> * `|`也是正则表达式的特殊符号，表示搜索俩个串之一(或者为这个串，或者为另一个串)
> * `|`可以多个一起使用，像 `'1000|2000|3000'`也是可以的

```mysql
SELECT prod_name
FROM products
WHERE prod_name REGEXP '[123] Ton'
ORDER BY prod_name;				
-- 表示匹配 '1 Ton','2 Ton','3 Ton'
```

> * `[]`是正则表达式用来匹配特定字符
> * `'[123]'`是`'[1|2|3]'`的缩写，表示匹配 1 或 2 或 3
> * `'[123] Ton'`和`'1|2|3 Ton'`表示的意义是不同的
> * `[123]`的否定是`[^123]`，表示除123以外的文本

```mysql
SELECT prod_name
FROM products
WHERE prod_name REGEXP '[1-5] Ton'
ORDER BY prod_name;
```

> `'[1-5]'`是`'[12345]'`的 简化，`-`表示 一个匹配范围

```mysql
SELECT vend_name
FROM vendors
WHERE vend_name REGEXP '\\.'	表示匹配 . 这个符号 
ORDER BY vend_name;
-- 表示匹配 . 这个符号
-- 匹配特殊字符，MySQL使用俩个反斜杠表示转义，一个是正则表达式的，一个是MySQL自身的
```

## 8.计算字段

```mysql
SELECT Concat(vend_name,' (',vend_country,')')
FROM vendors
 
```

## 9.