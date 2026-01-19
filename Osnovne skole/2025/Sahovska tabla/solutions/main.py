h, w = [int(x) for x in input().split()]
m, n = [int(x) for x in input().split()]
c = input().split()

for i in range(h * m):
    for j in range(w * n):
        print(c[(i//h + j//w) % 2], end = "")
    print()