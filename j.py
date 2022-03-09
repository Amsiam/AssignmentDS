
a,r,p,n = map(int,input().split(" "))

sum = a

for i in range(1,n+1):
    sum += (a+i*r)**p

print(sum)