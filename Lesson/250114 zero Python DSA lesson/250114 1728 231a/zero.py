n=int(input())
count=0
for i in range(n):
    states = list(map(int, input().split()))
    countOne = 0
    for state in states:
        if state == 1:
            countOne += 1
    if countOne >= 2:
        count += 1
print(count)
