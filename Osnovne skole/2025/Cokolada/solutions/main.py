n = int(input())
k = (n & (-n))

d = 0
while k < n:
    k = (k << 1)
    d += 1

print(k)
print(d)