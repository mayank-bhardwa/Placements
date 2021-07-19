t = int(input())
while t:
    t -= 1
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    for i in range(n):
        if a[i] < b[i]