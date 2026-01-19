N, M = [int(x) for x in input().split()]

if N % 2 == 1 or M % 2 == 1:
    print(-1)
else:
    print(N * M / 4)