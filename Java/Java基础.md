

# 基本数据类型 (内置数据类型)
Java语言提供了八种基本类型。
(六种数字类型（四个整数型，两个浮点型），一种字符类型，还有一种布尔型。)

数字——整型：
1. byte：

byte 数据类型是8位、有符号的，以二进制补码表示的整数；
最小值是 -128（-2^7）；
最大值是 127（2^7-1）；
默认值是 0；
byte 类型用在大型数组中节约空间，主要代替整数，因为 byte 变量占用的空间只有 int 类型的四分之一；
例子：byte a = 100，byte b = -50。
2. short：

short 数据类型是 16 位、有符号的以二进制补码表示的整数
最小值是 -32768（-2^15）；
最大值是 32767（2^15 - 1）；
Short 数据类型也可以像 byte 那样节省空间。一个short变量是int型变量所占空间的二分之一；
默认值是 0；
例子：short s = 1000，short r = -20000。
int：

3. int 数据类型是32位、有符号的以二进制补码表示的整数；
最小值是 -2,147,483,648（-2^31）；
最大值是 2,147,483,647（2^31 - 1）；
一般地整型变量默认为 int 类型；
默认值是 0 ；
例子：int a = 100000, int b = -200000。
4. long：

long 数据类型是 64 位、有符号的以二进制补码表示的整数；
最小值是 -9,223,372,036,854,775,808（-2^63）；
最大值是 9,223,372,036,854,775,807（2^63 -1）；
这种类型主要使用在需要比较大整数的系统上；
默认值是 0L；
例子： long a = 100000L，Long b = -200000L。
"L"理论上不分大小写，但是若写成"l"容易与数字"1"混淆，不容易分辩。所以最好大写。

数字——浮点型：
1. float：

float 数据类型是单精度、32位、符合IEEE 754标准的浮点数；
float 在储存大型浮点数组的时候可节省内存空间；
默认值是 0.0f；
浮点数不能用来表示精确的值，如货币；
例子：float f1 = 234.5f。

2. double：
double 数据类型是双精度、64 位、符合IEEE 754标准的浮点数；
浮点数的默认类型为double类型；
double类型同样不能表示精确的值，如货币；
默认值是 0.0d；
例子：double d1 = 123.4。

boolean：
boolean数据类型表示一位的信息；
只有两个取值：true 和 false；
这种类型只作为一种标志来记录 true/false 情况；
默认值是 false；
例子：boolean one = true。

char：
char类型是一个单一的 16 位 Unicode 字符；
最小值是 \u0000（即为0）；
最大值是 \uffff（即为65,535）；
char 数据类型可以储存任何字符；
例子：char letter = 'A';。


| 数据类型               | 默认值  |
| ---------------------- | ------- |
| byte                   | 0       |
| short                  | 0       |
| int                    | 0       |  |  |  |
| long                   | 0L      |  |  |  |
| float                  | 0.0f    |  |  |  |
| double                 | 0.0d    |  |  |  |
| char                   | 'u0000' |  |  |  |
| String (or any object) | null    |  |  |  |
| boolean                | false   |  |  |  |
# 引用数据类型 （包装类型）
引用类型
在Java中，引用类型的变量非常类似于C/C++的指针。引用类型指向一个对象，指向对象的变量是引用变量。这些变量在声明时被指定为一个特定的类型，比如 Employee、Puppy 等。变量一旦声明后，类型就不能被改变了。
对象、数组都是引用数据类型。
所有引用类型的默认值都是null。
一个引用变量可以用来引用任何与之兼容的类型。
例子：Site site = new Site("Nowcoder")。
# Java 常量
常量在程序运行时是不能被修改的。

在 Java 中使用 final 关键字来修饰常量，声明方式和变量类似：

final double PI = 3.1415927;
虽然常量名也可以用小写，但为了便于识别，通常使用大写字母表示常量。

字面量可以赋给任何内置类型的变量。例如：
byte a = 68;
char a = 'A'
byte、int、long、和short都可以用十进制、16进制以及8进制的方式来表示。

当使用常量的时候，前缀 0 表示 8 进制，而前缀 0x 代表 16 进制, 例如：
int decimal = 100;
int octal = 0144;
int hexa =  0x64;
和其他语言一样，Java的字符串常量也是包含在两个引号之间的字符序列。下面是字符串型字面量的例子：
"Hello World"
"two\nlines"
"\"This is in quotes\""

字符串常量和字符常量都可以包含任何Unicode字符。例如：
char a = '\u0001';
String a = "\u0001";
| 符号 | 字符含义             |
| ------ | ------------------------ |
| \n     | 换行 (0x0a)            |
| \r     | 回车 (0x0d)            |
| \f     | 换页符(0x0c)          |
| \b     | 退格 (0x08)            |
| \0     | 空字符 (0x20)         |
| \s     | 字符串                |
| \t     | 制表符                |
| "      | 双引号                |
| '      | 单引号                |
| \      | 反斜杠                |
| \ddd   | 八进制字符 (ddd)    |
| \uxxxx | 16进制Unicode字符 (xxxx) |
# 自动装箱与拆箱
## 缓存机制

# 数据精度如何保证
在金融计算中，保证数据准确性有两种方案，
1. 一种使用 BigDecimal，
肯定不能使用 float 和 double 类型，它们无法避免浮点数运算中常见的精度问题，因为这些数据类型采用二进制浮点数来表示，无法准确地表示，例如 0.1。
```java
import java.math.BigDecimal;

public class  Main{
    public static void main(String[] args) {
      
        BigDecimal num1 = new BigDecimal("0.1");
        BigDecimal num2 = new BigDecimal("0.2");
        BigDecimal sum = num1.add(num2);
        System.out.println("Sum of 0.1 and 0.2 using BigDecimal: " + sum);  // 输出 0.3，精确计算

        Double d1 = 0.1;
        Double d2 = 0.2;
        Double d3 = d1 + d2;
        double d5 = d1 + d2;

        Float f4 = (float)(d1+d2);
        System.out.println("Sum of 0.1 and 0.2 using Double: " + d3);
        System.out.println("Sum of 0.1 and 0.2 using Double: " + d5);
        System.out.println("Sum of 0.1 and 0.2 using Float: " + f4);
    }
}

```

2. 一种将浮点数转换为整数 int 进行计算。
在处理小额支付或计算时，通过转换为较小的货币单位（如分），这样不仅提高了运算速度，还保证了计算的准确性。
```java



int priceInCents = 199;  // 商品价格199分
int quantity = 3;
int totalInCents = priceInCents * quantity;  // 计算总价
//System.out.println("Total price in cents: " + totalInCents);  // 输出597分
```

Java 面试指南（付费）收录的字节跳动同学 7 Java 后端实习一面的原题：讲一下数据准确性高是怎么保证的？
GitHub 上标星 10000+ 的开源知识库《二哥的 Java 进阶之路》第一版 PDF 终于来了！包括 Java 基础语法、数组&字符串、OOP、集合框架、Java IO、异常处理、Java 新特性、网络编程、NIO、并发编程、JVM 等等，共计 32 万余字，500+张手绘图，可以说是通俗易懂、风趣幽默……详情戳：太赞了，GitHub 上标星 10000+ 的 Java 教程


# String StringBuffer StringBuilder

# Java 创建对象的几种方式


# 抽象类和普通类

# netstat 命令
# this 方法
A. 构造方法中通过 this 调用本类中的方法时，对方法中上下语句的顺序没有要求 - 错误。在构造方法中，使用 this 调用本类中的其他构造方法时，必须将 this 调用作为构造方法中的第一个语句。
B. this 可以调用本类中的普通属性 - 正确。this 关键字可以用来引用当前对象的属性。
C. this 表示当前对象的引用 - 正确。this 关键字在实例方法中代表当前对象的引用。
D. this 可以调用本类中的方法（普通方法、构造方法）- 正确。this 可以用来调用当前类中的其他方法和构造方法。


BConcurrentLinkedDeque
重新标记阶段会发生STW事件
/usr/src/linux-xxx/.config
瀑布模型
直接插入排序
23
内存占用率
ArrayList会存在一定的空间浪费，因为每次扩容都是之前的2倍，而LinkedList中的每个元素要存放直接后继和直接前驱以及数据，所以对于每个元素的存储都要比ArrayList花费更少的空间
其使用的队列是DelayedQueue，实现了BlockingQueue接口
4
CD
Map
接口请求变慢，但CPU占用率不高
右值引用与移动语义
字节流和字符流都可以处理任何的数据，包括图片和视频等。
在敏捷开发的过程中，整个项目是文档驱动的而不是测试驱动的
2
其使用的队列是DelayedQueue，实现了BlockingQueue接
改变了HashMap底层数据结构，引入红黑树;改用分段锁的方式优化了ConCurentHashMap的效率:
yyP
[H,G,E,F,D,B,C,A]
DClassLoader采用继承的方式复用父类加载器
针对每个类建立的动态模型，描述了类实例的生命周期或者运行周期
需求分析

21 D
22 B
23 C
24 D  
25 B
27 B 
28 C
30 C
31 B
32 B
33 B
34 A

36 A
37 A 
38 B
39 C
40 C