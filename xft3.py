n=int(input())
m=int(input())
ans=m
for i in range(n,1,-1):
    ans=ans*2
    ans=ans+1
print(ans)