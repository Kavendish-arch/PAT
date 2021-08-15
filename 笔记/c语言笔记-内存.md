# C语言内存操作
### void malloc (unsigned size)
* 动态申请内存的函数
* 申请尺寸为size
* 返回值 NULL 申请失败

### void calloc (unsigned n, unsigned size);
* 在内存动态存储区中分配n块长度为size的连续区域
* 函数返回值为该区域的首地址
* 返回值 NULL 申请失败

### void free (void * pre)
* 释放内存

## 注意
* 区别malloc() 申请一块size大小的区域，calloc() 申请n块size大小的区域
* C/C++编译器对地址的划分，该区域在heap中
* malloc and calloc 的返回值需要进行判断，当返回值为零时，内存申请失败
* malloc and free 函数要配套使用，申请的空间及时的释放
* 释放内存后，将该指针指向NULL，切勿生成野指针

# 内存模型 堆栈
1. stack 由编译器在需要时分配，不需要时释放
2. heap 由程序员负责分配和释放也就是malloc calloc new 动态负责申请, 使用完毕后使用free() 和 delete() 进行释放
3. static 全局区，也称静态区，是程序中的全局变量和静态变量的存储区域，
4. 常量区，这块区域时存放常量的区域
5. 代码区，存放源程序编译后的二进制代码，为只读属性，程序进程死亡后由操作系统负责回收，

# 内存操作函数

1. memcpy
void* memcpy(void* dest,const void* src,size_t num)
内存拷贝，可以拷贝任意类型,不考虑’\0’
功能：函数memcpy从src的位置开始向后复制num个字节的数据到dest的内存位置
说明：这个函数在遇到’\0’不会停下来;如果src与dest任何的重叠，复制结果都是未定义的

2. memmove
void* memmove(void* dest,const void* src,size_t num)
功能：和memcpy区别在于dest与src内存块可以重叠

3. memcmp
int memcmp(const void* ptr1,const void* ptr2,size_t num)
功能：比较内存区域buf1和buf2的前count个字节。该函数是按字节比较的
返回值：
当buf1 < buf2时，返回值<0
当buf1 = buf2时，返回值=0
当buf1 > buf2时，返回值>0

4. memchr
void* memchr(const char* ptr ,int value,sizez_t num)
功能：从buf所指内存区域的前count个字节查找字符ch。
返回值：当第一次遇到字符ch时停止查找。如果成功，返回指向字符ch的指针；否则返回NULL

5. memset
void* memset(void* str,int value,size_t num)
按字节设置，进行赋值
功能：以str的起始位置开始的n个字节的内存区域用整数value进行填充
返回值：目标str内存起始地址
说明：memset用来对一段内存空间全部设置为某个字符，一般用在对定义的字符串进行初始化为‘ ’或‘/0’

注意：如果用malloc分配的内存，一般只能使用memset来初始化
memset可以方便的清空一个结构类型的变量或数组,它可以一字节一字节地把整个数组设置为一个指定的值

一般说的内存泄漏指的堆区空间，在申请空间没有释放或者对一块空间释放多次的时候，比如delete数组没加[]，拷贝构造只赋值指针没有拷贝指向的内存、父类析构没有设成虚函数等。
如何发现：
1. 有些简单的内存泄漏在检查时期可以发现，人工检查代码
2.不同的系统都带有内存监视工具，我们可以从监视工具收集一段时间内的堆栈内存信息，观测增长趋势，来确定是否有内存泄漏。在 Linux 平台可以用 ps /top命令，来监视内存的使用，比如下面的命令 (观测指定进程的VSZ值)
ps -aux
3.或者使用内嵌程序自动检测，可以重载内存分配和释放函数 new 和 delete,然后编写程序定期统计内存的分配和释放，从中找出可能的内存泄漏。或者调用系统函数定期监视程序堆的大小，关键要确定堆的增长是泄漏而不是合理的内存使用。这类方法比较复杂，在这就不给出详细例子了。
4.代码静态扫描和分析的工具比较多，比如 splint, PC-LINT, BEAM 等。因为 BEAM 支持的平台比较多，这以 BEAM 为例，BEAM 可以检测四类问题: 没有初始化的变量；废弃的空指针；内存泄漏；冗余计算。而且支持的平台比较多。
比如CCMalloc和dmalloc
1.ccmalloc－Linux和Solaris下对C和C++程序的简单的使用内存泄漏和malloc调试库。
2.Dmalloc－Debug Malloc Library.

如何避免：
1、程序员要养成良好习惯，保证malloc/new和free/delete匹配；
2、使用智能指针
3、使用链表记录所有的申请出的指向堆区空间指针，在析构函数中检查是否泄露。

### 字符串和整数之间的转换，
int auoi(const char *nptr);
long auol(const char *nptr);

long int strtol(const char *p);
unsigned long int stroul(const char *p);

//字符串和实数之间的转换
double atof (const char *p);
double strtod (const char *p);

输入和输出
C语言不提供输入输出语句，输入输出由函数操作
Stdio.h: printf() scanf() putchar() getchar()
Int printf( const char *，)

