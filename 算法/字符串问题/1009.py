"""
python 输入模式
"""

# while True:
    
list = input().split()
list.reverse()
h = ""+list[0]
for i in range(1,len(list)):
    h += " " +list[i]
print(h)
