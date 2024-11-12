# 运行超时？？
n = int(input())
school = {}
for i in range(n):
    sch, grade = input().split()
    if sch in school:
        school[sch] += int(grade)
    else:
        school.setdefault(sch, int(grade))

key = 1
value = 1

for i,k in school.items():
    if k > value:
        key = i
        value = k
print(str(key) + " " + str(value))
