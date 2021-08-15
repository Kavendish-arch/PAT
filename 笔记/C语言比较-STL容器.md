## 容器和数据结构
STL 数据结构和算法
模板类
容器、算法、迭代器
### Containers deque list vector map
1. 顺序容器：vector deque list
2. 关联容器：set multiset map multimap
3. hashtable：unordered_map unordered_set
4. 其他：stack(LIFO)堆栈, queue(FIFO)队列, priority_queue

### Algorithms

### iterators


 * vector  可变数组
 * 访问 下标和迭代器 iterator it  *it
 * 1) push_back() 2)pop_back() 3)size() 4)clear() 5)insert() 6)erase()
 * 1.可变数组 2.数组输出在同一行 3.邻接表存储图
如何分配内存：
doubling: 双倍增长的内存分配
Elem: 头
Space: 尾部
Last: 预留的空间
size 是当前 vector 容器真实占用的大小，也就是容器当前拥有多少个容器。
capacity 是指在发生 realloc 前能允许的最大元素数，即预分配的内存空间。
当然，这两个属性分别对应两个方法：resize() 和 reserve()。
使用 resize() 容器内的对象内存空间是真正存在的。
使用 reserve() 仅仅只是修改了 capacity 的值，容器内的对象并没有真实的内存空间(空间是"野"的)。
此时切记使用 [] 操作符访问容器内的对象，很可能出现数组越界的问题。

 set      不可重复的容器
 * 访问： 只能使用迭代器
 * insert() find() erase() size() clear()
 * 用途：自动去重 升序排序

 string 字符串
 * 访问 下标、迭代器 使用cin cout 或者转换为字符
 * operator +=   compare operator()     length() size()     insert()    erase()
 * clear() substr()

 map
 * find() erase() size() clear()
 * 建立字符和整数之间的映射 减少代码量

 queue 先进先出的队列
 * 访问：只能访问头部，和尾部
 * 1.push()   2.front()、back()  3.pop()   4.empty()     5.size()
 * 用途：广度优先搜索，不用手动创建队列
 *      priority_queue  优先队列 队首元素优先级最高
 *      没有front() back() 只能是由 top()
 *      1.push() 2.top() 3.pop() 4.empty() 5.size()
 *      内部元素优先级设定； 基本数据类型 int double char
 *      解决一些贪心问题

 stack 栈后进先出
 * 访问：只能使用top()
 * 1.push() 2.top() 3.pop() 4.empty() 5.size()
 * 模拟实现递归防止程序对栈内存的限制而出错

 pair 头文件 utility
 * struct pair{
 *  typeName;
 *  typeName;
 * }

pair< typeName1, typeName2, > name;
 * 当作结构体使用
 * pair.first pair.second
 * 比较：first second 用 == < > <= >= 比较
 * 用途代替二元结构体和构造函数，
 * 作为map的键值

priority_queue 结构体的优先级设置
  * 优先级队列和sort() 的cmp相反

 algorithm 头文件
 * max() min()两个数
 * abs()整数
 * swap()交换
 * reverse(it, it2)在it和it2元素和容器之间反转
 * next_permutation()全排列中下一个序列
 * fill()数组容器某一段赋值为某个相同的值
 * sort()排序
 * lower_bound()第一个小于等于 value的值
 * upper_bound()第一个大于等于value的值


Collection
    Vector 可增长对象数组 线程同步
    Stack
    Set   无序不可重复
     *    HashSet
     *    TreeSet
     *    LinkedSet
     *    EnumSet
    List 有序数列 大小可变数组 线程不同步
     *    LinkedList 数组实现
     *    ArrayList  链表实现
    Queue
    Deque
     *    ArrayDeque
    Map   无序，可重复，key-vale对应 字典
     *    HashMap
     *    TreeMap
