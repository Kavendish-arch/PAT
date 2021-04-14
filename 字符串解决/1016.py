A,Da,B,Db = input().split()
Pa,Pb = "0","0"
for i in A:
    if i == Da:
        Pa += i
for i in B:
    if i == Db:
        Pb += i
# 当 Pa,Pb = "" 时
print(int(Pa)+int(Pb))
    
