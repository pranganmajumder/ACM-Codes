a , b   = map(int, raw_input().split(" "))
 
if a<b and a-b==-1 :
    print a,b
elif a==b:
    print a*10 , a*10+1 
elif a==9 and b==1:
    print("99 100")
else:
    print -1