#
# 使用python 处理不考虑大数

n = int(input())

for i in range(1,n+1):
    a,b,c = input().split()
    if (int(a) + int(b)) > int(c):
        print("Case #%d: true"%i)
    else:
        print("Case #%d: false"%i)

# 提交结果
# 提交时间	            状态	      分数	题目	编译器	            耗时	用户
# 2021/04/12 12:57:33	  答案正确    15	编程题	Python (python3)   29 ms	chen
# 测试点	结果	分数	耗时	内存
# 0	  答案正确    9	29 ms	3252 KB
# 1	  答案正确    3	24 ms	3120 KB
# 2	  答案正确    3	14 ms	3136 KB
