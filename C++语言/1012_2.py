# 13 1 2 3 4 5 6 7 8 9 10 20 16 18
l = input().split()
A1,A2,A3,A4,A5 = [],[],[],[],[]
a1,a2,a3,a4,a5 = 0,0,0,0,0
m = 1
for i in range(1, int(l[0])+1):
    tmp = int(l[i])
    if tmp % 5 == 0 and tmp % 2 == 0:
        a1 += tmp
        A1 = True
#         A1.append(tmp) 
    if tmp % 5 == 1:
        A2.append(tmp)
        a2 += tmp * m
        m *= -1
    if tmp % 5 == 2:
        A3.append(tmp)
        a3 += 1
    if tmp % 5 == 3:
        A4.append(tmp)

    if tmp % 5 == 4:
        A5.append(tmp)

if A1:
    a1 = str(a1)
else:
    a1 = 'N'
if A2:
    a2 = str(a2)
else:
    a2 = 'N'
if A3:
    a3 = str(len(A3))
else:
    a3 = 'N'
if A4:
    a4 = sum(A4) * 1.0 / len(A4)
    a4 = str(round(a4,1))
else:
    a4 = 'N'
if A5:
    a5 = str(max(A5))
else:
    a5 = 'N'
print("{0} {1} {2} {3} {4}".format(a1,a2,a3,a4,a5))


