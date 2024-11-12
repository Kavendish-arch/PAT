

while 1:
    a = []
    s = input()

    if  s!= "":
        for x in s.split():
            a.append(int(x))
        
        print(sum(a))
    
    else:
        break
