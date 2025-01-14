n, k = map(int, input().split())
l = list(map(int, input().split()))
print(sum(map(lambda x: x >= l[k-1] and x > 0, l)))
