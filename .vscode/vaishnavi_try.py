l = [12, 43, 44, 22, 88, 55]
mx =l[0]
smx =l[0]
for i in l:
    if(i>mx):
        smx=mx
        mx=i
    elif(i>smx and i<mx):
        smx=i
print(smx)