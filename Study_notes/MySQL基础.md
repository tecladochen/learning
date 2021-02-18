#    MySQL基础

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

```mysql
SELECT prod_name
FROM products
WHERE prod_name REGEXP '\\([0-9] sticks?\\)'
ORDER BY prod_name;
-- \\表示转义，俩边的转义表示匹配一对小括号
-- ？表示前一个字符匹配零次或一次，简单说？前的字符是可有可无的
```

| 重复元字符 |            说明             |
| :--------: | :-------------------------: |
|    `*`     |        0个或多个匹配        |
|    `+`     | 1个或多个匹配( 等于`{1,}` ) |
|    `?`     | 0个或1个匹配( 等于`{0,1}` ) |
|   `{n}`    |        指定数目匹配         |
|   `{n,}`   |    不少于指定数目的匹配     |
|  `{n,m}`   | 匹配数目的范围( m不超过255) |

```mysql
SELECT prod_name
FROM products
WHERE prod_name REGEXP '[[:digit:]]{4}'
ORDER BY prod_name;
-- [:digit:]属于匹配字符类，是预定义的字符类，经常需要使用字符的常用类
-- {4}表示匹配次数
```

|    字符类    |                         说明                         |
| :----------: | :--------------------------------------------------: |
| `[:alnum:]`  |           任意字母和数字(同`[a-zA-Z0-9]`)            |
| `[:alpha:]`  |                任意字符(同`[a-zA-Z]`)                |
| `[:blank:]`  |                 空格和制表(`[\\t]`)                  |
| `[:cntrl:]`  |           ASCII控制字符(ASCII 0到31和127)            |
| `[:digit:]`  |                  任意数字(`[0-9]`)                   |
| `[:graph:]`  |           与`[:print:]`相同，但不包含空格            |
| `[:lower:]`  |               任意小写字母(同`[a-z]`)                |
| `[:print:]`  |                    任意可打印字符                    |
| `[:punct:]`  | 既不在(同`[:alnum:]`)又不在(同`[:cntrl:]`)的任意字符 |
| `[:space:]`  |  包括空格在内的任意空白字符(同`[\\f\\n\\r\\t\\v]`)   |
| `[:upper:]`  |               任意大写字母(同`[A-Z]`)                |
| `[:xdigit:]` |          任意十六进制数字(同`[a-fA-F0-9]`)           |

> **注意**：`[:digit:]`匹配任意数字，因而它为一个集合，所以`[[:digit:]]{4}`中需要在`[:digit:]`外加一       				个中括号使成为限定一个匹配

```mysql
SELECT prod_name
FROM products
WHERE prod_name REGEXP '^[0-9\\.]'
ORDER BY prod_name;
-- ^ 是定位元字符，表示匹配串的开始
```

| 定位元字符 |    说明    |
| :--------: | :--------: |
|    `^`     | 文本的开始 |
|    `$`     | 文本的结尾 |
| `[[:<:]]`  |  词的开始  |
| `[[:>:]]`  |  词的结尾  |

> **注意**：`^` 有俩种用法，一种是作为定位元字符，表示匹配文本的开始；另一种是和`[]`	一起表示否定该集	 				合，例如`[^123]`

> **注意**：`REGEXP`可以和`LIKE`有类似功能，利用定位符，每个正则表达式用`^`开始，用`$`结束，即作用和		    			`LIKE`一样

```mysql
SELECT 'hello' REGEXP '[0-9]';
-- 若可以匹配则返回1，否则返回0
```

> **提示**：简单的正则表达式测试，测试表达式的准确性

## 8.创建计算字段

### 拼接字段

```mysql
-- Concat()函数用来把多个串连接生成一个串
SELECT Concat(vend_name,' (',vend_country,')')
FROM vendors
ORDER BY vend_name;
```

### 使用别名

```mysql
-- as 关键字赋予一个字段或值的别名
SELECT Concat(Rtrim(vend_name),' (',Rtrim(vend_country),')') AS
vend_title
FROM vendors
ORDER BY vend_name;
```

### 算术计算

```mysql
-- 可以把计算式作为字段使用别名来处理
SELECT prod_id,
	   quantity,
	   item_price,
	   quantity * item_price AS expanded_price
FROM orderitems
WHERE order_num = 2005;
```

## 9.处理函数

### 文本处理函数

```mysql
SELECT vend_name, Upper(vend_name) AS vend_name_upcase
FROM vendors
ORDER BY vend_name;
```

|    函数    |       说明       |
| :--------: | :--------------: |
| `Length()` | 返回一个串的长度 |
| `Lower()`  |  将串转化成小写  |
| `LTrim()`  |  去掉左边的空格  |
| `RTrim()`  |  去掉右边的空格  |
| `Upper()`  |  将串转化为大写  |

### 日期和时间处理函数

> **注意**：MySQL 的日期格式必须是 `yyyy-mm-dd`,例如2005年9月1日，必须写成 `2005-09-01`

|    函数    |            说明            |
| :--------: | :------------------------: |
|  `Date()`  |   返回日期时间的日期部分   |
|  `Day()`   |   返回一个日期的天数部分   |
|  `Hour()`  |   返回一个日期的小时部分   |
| `Minute()` |   返回一个日期的分钟部分   |
|  `Now()`   |    返回当前的日期和时间    |
| `Second()` |    返回一个时间的秒部分    |
|  `Time()`  | 返回一个日期时间的时间部分 |
|  `Year()`  |   返回一个日期的年份部分   |



### 数据处理函数

|   函数   |        说明        |
| :------: | :----------------: |
| `Abs()`  |   返回一个绝对值   |
| `Cos()`  | 返回一个角度的余弦 |
| `Exp()`  | 返回一个数的指数值 |
| `Mod()`  |  返回除操作的余数  |
|  `Pi()`  |     返回圆周率     |
| `Rand()` |   返回一个随机数   |
| `Sin()`  | 返回一个角度的正弦 |
| `Sqrt()` | 返回一个数的平方根 |
| `Tan()`  | 返回一个角度的正切 |

## 10.汇总数据

> **注意**：聚集函数不是把数据检索出来，而是把数据汇总得到信息

> **注意**：`COUNT()`函数有俩种用法，`COUNT(*)`表示对行的数目进行统计，`COUNT(column)`表示对特定列具  				有值的行进行统计

| 聚集函数  |       说明       |
| :-------: | :--------------: |
|  `AVG()`  |  返回某列平均值  |
| `COUNT()` |  返回某列的行数  |
|  `MAX()`  | 返回某列的最大值 |
|  `MIN()`  | 返回某列的最小值 |
|  `SUM()`  | 返回某列的值之和 |

```mysql
SELECT AVG(DISTINCT prod_price) AS avg_price
FROM products
WHERE vend_id = 1003;
```

> **注意**：使用`distinct`关键字可以聚集不同的值

## 11.分组数据

 ```mysql
SELECT vend_id, COUNT(*) AS num_prods
FROM products
GROUP BY vend_id;
-- 数据按照 group by 后跟的列排列和分组数据 
 ```

```mysql
SELECT cust_id, COUNT(*) AS orders
FROM orders
GROUP BY cust_id
HAVING COUNT(*) >= 2;
-- having语句用于过滤分组，可以使用where可以用的条件
```

> **注意**：`where`和`having`的差别，`where`是面对行的过滤条件，`having`的面对分组的过滤条件，因此				`having`语句可以使用聚集函数。

> **注意**：`group by`和`order by`都有排序的功能，但有区别。一般情况都需要`order by`来控制排序。

> **SELECT 子句顺序**：使用中必须遵循的次序
>
> 1. `SELECT`						 要返回的列和表达式
> 2. `FROM`                         从中检索的表
> 3. `WHERE`                       行级过滤
> 4. `GROUP BY`                分组说明
> 5. `HAVING`                     组级过滤
> 6. `ORDER BY`                 输出排列顺序
> 7. `LIMIT`                        返回的行数

## 12.子查询

```mysql
SELECT cust_name, cust_contact
FROM customers
WHERE cust_id IN (SELECT cust_id
                  FROM orders
                  WHERE order_num IN (SELECT order_num
                                      FROM orderitems
                                      WHERE prod_id = 'TNT2'));
```

> **注意**：子查询一般和`IN`关键字配合使用，也可以和其他关键字。
>
> ​				子查询一般需要格式化代码，方便阅读和理解。
>
> ​				使用子查询必须保证子查询返回的列和需要匹配的列项匹配

```mysql
SELECT cust_name,
	   cust_state,
	   (SELECT COUNT(*)
        FROM orders
        WHERE cust_id = cust_id) AS orders
FROM customers

```

## 13.联结表

```mysql
SELECT vend_name, prod_name, prod_price
FROM vendors, products
WHERE vendors.vend_id = products.vend_id
ORDER BY vend_name, prod_name;
-- 内部联结
SELECT vend_name, prod_name, prod_price
FROM vendors INNER JOIN products
ON vendors.vend_id = prodcts.vend_id;
-- 俩种写法功能相同
```

```MYSQL
SELECT vend_name, prod_name, prod_price
FROM vendors, products
ORDER BY vend_name, prod_name;
-- 如果没有where语句，则表示俩表的笛卡儿积
```

```MYSQL
SELECT p1.prod_id, p1.prod_name
FROM products AS p1, products AS p2
WHERE p1.vend_id = p2.vend_id
	  AND p2.prod_id = 'DTNTR';
-- 自联结
```

> **注意**： 自然联结正常来说就是内部联结中全部都是唯一列的联结

```mysql
SELECT customer.cust_id, orders.order_num
FROM customers LEFT OUTER JOIN orders
ON customers.cust_id = orders.cust_id;
-- 左外部联结
SELECT customer.cust_id, orders.order_num
FROM customers RIGHT OUTER JOIN orders
ON customers.cust_id = orders.cust_id;
-- 右外部联结
```

## 14.组合查询

> **注意**：MySQL允许多个查询(多条SELECT语句)的结果作为一个结果集返回

```mysql
SELECT vend_id, prod_id, prod_price
FROM products
WHERE prod_price, prod_id, prod_price
UNION
SELECT vend_id, prod_id, prod_price
FROM products
WHERE vend_id IN (1001,1002);
-- union 在俩条select语句之间，表示结果的并
```

## 15.全文本搜索



## 16.插入数据

```mysql
SELECT INTO customers(cust_name,
                      cust_address,
                      cust_city,
                      cust_state,
                      cust_zip,
                      cust_country,
                      cust_contact,
                      cust_email)
VALUES('Pep E. LaPew',
       '100 Main Street',
       'Los Angeles',
       'CA',
       '90046',
       'USA',
       NULL,
       NUll);
       -- 
```



## 17.更新和删除



## 18.创建和修改



## 19.视图使用



## 20.存储过程



## 21.游标



## 22.触发器

​     

## 23.事务管理处理

> **注意**：事务处理可以用来维护数据库的完整性，它保证MySQL操作要么完全执行，要么完全不执行。

> **关键术语**：
>
> ​	***事务(transaction)***：指一组SQL语句
>
> ​	***回退(rollback)***：指撤销指定的SQL语句的过程
>
> ​	***提交(commit)***：指将未存储的SQL语句结果写入数据库表
>
> ​	***保留点(savepoint)***：指事务处理中设置的临时占位符

```mysql
-- 下面的语句标识的事务的开始
START TRANSACTION
```

```mysql
SELECT * FROM ordertotals;
START TRANSACTION;
DELETE FROM ordertotals;
SELECT * FROM ordertotals;
ROLLBACK;
SELECT * FROM ordertotals;
-- rollback只能在一个事务处理内使用，即在执行了一条start transaction语句后
```

> **注意**：`rollback`语句只能回退`insert`,`update`,`delete`语句，不能回退`create`,`drop`,`select`语句

```mysql
START TRANSACTION;
DELETE FROM orderitems WHERE order_num = 20010;
DELETE FROM orders WHERE order_num = 20010;
COMMIT;
-- 在之前的语句都正确执行后，commit命令把结果写到数据库表中
-- 如果有错误则会自动撤销
```

> **注意**：隐含事务关闭，在`commit`,`rollback`语句执行后，事务会自动关闭。

```mysql
-- 下面语句创建保留点，保留点取标识它的唯一名字
SAVEPOINT delete1;
-- 利用下面语句可以回退到指定的位置
ROLLBACK TO delete1;
```

> **注意**：保留点越多越好，可以使回退更灵活
>
> ​				保留点会在事务处理完成后自动释放，也可以使用`RELEASE SAVEPOINT`语句明确释放保留点

## 24.安全管理

> ***访问控制***：用户应该对他们需要的数据具有适当的访问权，既不能多也不能少

```mysql
-- MySQL用户账户和信息存储在名为mysql的MySQL数据库中
USE mysql;
-- mysql数据库里有一个叫user的表，表里有一个user的列
-- 通过下面语句查看用户账号信息
SELECT user FROM user;
```

> **注意**：`identified by`指定口令为纯文本

```mysql
-- 创建用户
CREATE USER ben IDENTIFIED BY 'password';
-- 重命名用户
RENAME USER ben TO bforta;
-- 删除用户
DROP USER bforta;
```

> ***设置访问权限***：在创建用户账号后，必须接着分配访问权限。

```MYSQL
-- 查看用户账户的权限
SHOW GRANTS FOR bforta;
-- 将对crashcourse数据库的select操作的权限授予bforta用户
GRANT SELECT ON crashcourse.* TO bforta;
-- 将bforta用户对crashcourse数据库的select操作的权限撤销
REVOKE SELECT ON crashcourse.* FROM bforta;
-- 简化多次授权
GRANT SELECT, INSERT ON crashcourse.* TO bforta;
```

> **更改口令**：新口令必须传递到`Password()`函数进行加密。

```mysql
SET PASSWORD FOR bforta = Password('password2');
-- 在不指定用户名的情况下，指更新当前登录用户的口令
SET PASSWORD = Password('password3');
```

## 25.改善性能



## 26.补充

