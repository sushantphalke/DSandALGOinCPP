# rows = int(input())
# for i in range(1, rows+1):
#     for j in range(0, i):
#         print(i, end="")
#         if(j < i-1):
#             print("*", end="")
#         else:
#             print()

# for i in range(rows, 0, -1):
#     for j in range(0, i):
#         print(i, end="")
#         if(j < i-1):
#             print("*", end="")
#         else:
#             print()

rows = int(input())  
for i in range(1, rows + 1):
    print('*'.join([str(i)] * i))
for i in range(rows, 0, -1):
    print('*'.join([str(i)] * i))