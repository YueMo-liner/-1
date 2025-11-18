n=int(input("请输入要猜测的值"))
a=1
b=99
guess=(a+b)//2
cnt=1
while True:
    if guess==n:
        print(guess)
        break
    elif guess>n:
        print(guess)
        cnt+=1
        b=guess
        guess=(a+b)//2
    else :
        print(guess)
        cnt+=1
        a=guess
        guess=(a+b)//2
print("你猜了%d次"%cnt)


