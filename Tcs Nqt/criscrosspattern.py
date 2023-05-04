n = int(input())
for i in range (n):
    for j in range(n+n-i):
        if(j>n):
            print
        print("*",end= " ")
