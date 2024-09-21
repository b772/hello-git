import random
a=int(input("输入整数"))
overflag=False
ans1=0
ans2=0
times=1
tmp=0
while not overflag:
    random.seed(a)
    tmp=random.random()
    print(tmp)
    ans1=int(tmp*123546*times)%6
    ans2=int(tmp*7891011*times)%6
    t=ans1+ans2
    lastt=0
    print(ans1,ans2)
    if times == 1 :
        if t==7 or t==11:
            print("you win")
            break
        if t==2 or t==3 or t==12:
            print("you lost")
            break
    
    
    elif t==7:
        print("you lost")
    elif t==lastt:
        print("you win")
        break
    lastt=t
    times+=1
    input()
