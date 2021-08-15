# 跨平台 • 内存 • 库• 缺少什么功能

## 数据类型
其中每行区别在于范围不一样
整数   int short long
浮点数 float daouble
字符   char
布尔类型  c语言中 1 0  表示 true false
## 如何获取我们的数据，输出我们的数据
输入语句
1. 键盘输入
2. 文件输入
输出语句
2. 输出到屏幕
3. 文件输出

## 运算
+ - * /

## 程序控制
* 顺序  只有一条路
* 循环 for do-while while
```
    // 你知道循环次数条件下
    for (x = 0 ; x < 10; x ++){
        cout << " 第 " << x << " 次 " << endl;
    }
    // 真 true
    while(y < 20){
        y++;
        y = y + 1; y += 1;
        cout << "Hello world!" << y << endl;
    }
    //y++ 和 ++y
    //先用 然后+1 ++y 先加1 再用
    while 先判断 再执行  进入判断
    do-while 先执行一次 然后判断 出去的时候判断

    while(1){
        if(y++ > 20)
            break;

        cout << "Hello world!" << y << endl;
    }
    do {

    }while();

```
## 分支 判断语句，让你走哪一条路
* if else
* if else if else
* switch case case default

c++ 可以用c语言的东西，但是c不能用c++

## 函数
y = kx 对于输入的x 有唯一的y对应
C++ 特殊：字符串 string 
int function(int x);
y = x + 4
y = function(x);

数学.c文件中
int function(int x){
    return x + 4;
}
//函数的具体实现
//执行什么功能 你就找对应的函数

//参数 输入
//返回值 输出

## 类 对象
## new 对象

## 数组
c里面没有字符串 ，没有文本
char 字符对中文不支持
char 数组 来保存文本信息
    char s = 's';
    char ch[20] = "你好吗 ";
    
顺序表 数据有个保存的形式

* 逻辑连续
* 存储的连续
* 同一类数据，连续
## 数据结构
    都是成绩 这样就有关系 关系
    身份证号
    int x = 10;  数据
    int y = 29; 数据
年龄
int z = 33;
顺序表 逻辑上连续的数据机构
    根据 物理上的连续，存储地址的连续
1. 线性表
     4公寓 直接工具下标去找，马上
2. 链表 查找麻烦，但是插入，和三处简单
     4. 先找绳头，1公寓 -> 2公寓 -> 3公寓 -> 四公寓
int num[] 
    

## C语言编译过程
    1.gcc .c -E .i :宏替换 展开文件插入， 删除注释，添加行号
    2.gcc .i -S .s :翻译成汇编语言
    3.gcc .s -o .o :翻译成二进制文件
    4.gcc .o -o a  :.o -> .o  link .o
 * 预处理  .cpp 头文件展开  .i
 * 编译    .i compile 语法分析，代码生成 .o
 * asm -> bin cpp编译过程，计算机体系结构————冯诺依曼架构
 *  程序指令存储器和数据存储器合并在一起的存储结构
 *  程序指令和数据宽度相同  intel8086中央处理器 -> X86架构
 *  计算机三基本原则：*二进制逻辑 *程序存储执行 *计算机五大部件（控制器、运算器、存储器、输入、输出设备）
     *  单处理器结构、机器以运算器为核心
     *  采用程序存储思想
     *  指令和数据一样可以参与运算
     *  数据以二级制表示
     *  软件和硬件分离
     *  指令由操作码和数据组成
     *  指令顺序执行
     *  哈佛结构（ARM9) 计算机体系结构
 * 链接       .so(linux) .dll(windows) obj   link
 * 执行可执行文件  .exe   
   
#include <iostream>
//包含头文件 引用的头文件 为什么要引用呢，因为要使用 cout 函数
using namespace std;

//命名空间 cout 定义在std命名空间里

main()
int main(){
    cout << "hello world";
    return 0; //程序结束状态返回
}

## 调试技术：
    GDB 直接调试 gdb --tui
    Emacs+GUD GDB使用入门
    {
        list 显示代码
        
        start 执行
        {
            n（next）可以单步执行程序，
            s（step）命令可以跳入函数中查看函数执行的细节
            bt（backtrace）命令查看程序栈帧，可以在不同栈帧中切换来查看不同环境的变量值。
            使用i（info）查看变量值
            切换至main堆栈，查看main函数中本地变量的值
            p（print）打印某变量的值
            display可以现实每步程序运行之后某变量的值
                不再需要display的结果，可以使用undisplay取消显示
            finish使当前函数运行至return返回
            set var name=value
            break命令在某行设置一个断点
            delete breakpoints num删除断点，使用break（b）查看当前断点分布
        }
    }

## 内存模型：
    C++:强类型语言
    面向过程语言、内存机制
    对象
    类型：什么数据类型
    变量
    值
    
    2 8 16 进制
    Big Endian  Little Endian
    小      大   大         小
> 内存机制：
虚拟内存和内存分页
    内存数据货架 0x00000001 
    地址的范围和地址总线位数相关

    真实内存 --> 虚拟内存 
    真实地址 --> 虚拟地址
    0x00000011 --> 0x00110011
    0x00110011 --> 0x00110011 

    借助虚拟内存，程序无法访问真实地址，减少地址操作出错的问题
    真实内存 和 虚拟内存的 映射 产生了 内存分页

    一个虚拟内存需要多大？ $getconf PAGE_SIZE
    偏移量 4kb = x 12次方
    例如 4096(4kb)(0x000 ---- 0xfff)

        虚拟内存     偏移量     对应关系              真实内存     偏移量
        0x0 0 0 1 a  0x0 1 1   0x0001a -- 0x00006   0x0 0 0 0 6 0x0 1 1  
        范围(0x0001a 0x000 - 0xfff)                 (0x00006 0x000 - 0xfff)
        0x0 0 0 2 b  0x0 1 1   0x0001a -- 0x00007    0x0 0 0 0 7 0x0 1 1
    多级分页表,偏移量(多级)
        虚拟内存2   --->    虚拟内存1 --->      真实内存
        0x00 0x01a 0x011

# C++面向对象
### 类
ADT{
    data
    数据成员
    函数操作
    operation
}
### C++的类 
成员 
构造函数 (explicit) 
析构函数 
初始化列表来初始化字段
Explicit 构造函数 • 解决隐式类型转换问题 
// Explicit constructor Vector v1 = 7; 
// OK: v1 has 7 elements class Vector { public: explicit Vector(int s); 
// no implicit conversion from int to Vector 
// ... };Vector v1(7); 
// OK: v1 has 7 elements Vector v2 = 7; 
// error: no implicit conversion from int to Vector

### 对象，由类生成的实体
* 拷贝构造函数 解决对象拷贝问题，如果对象内部有指针必须使用，编译器自动生成，指针？
* 所有包含动态生成的指针需要拷贝函数

## 结构体
* 没有操作
* 没有封装
