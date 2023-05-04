n = int(input("enter any no:"))
for i in range(n+1):
    for j in range(i):
        if(j < i-1):
            print(str(i)+"*", end=" ")
        else:
            print(str(i))
for i in range(n, 0, -1):
    for j in range(i,0,-1):
        if(j !=1):
            print(str(i)+"*", end=" ")
        else:
            print(str(i))
# for i in range(n):
#     for j in range(n-i):
#         if(j < n-i-1):
#             print(str(n-i)+"*", end=" ")
#         else:
#             print(str(n-i))
