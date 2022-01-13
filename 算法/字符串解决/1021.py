# 1021 个位数统计 (15 分)
# 字符统计
n = input()
count = {}
for i in range(0,10):
    count.setdefault(str(i),0)
for i in n:
    if i in count:
        count[i] += 1
for i,j in count.items():
    if j != 0:
        print("%c:%d"%(i,j))
