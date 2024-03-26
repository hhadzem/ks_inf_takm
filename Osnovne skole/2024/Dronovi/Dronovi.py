import math
sqrt_2 = math.sqrt(2)

def parse(dir):
    if dir == "S":
        return 0.0, 1.0
    elif dir == "J":
        return 0.0, -1.0
    elif dir == "I":
        return 1.0, 0.0
    elif dir == "Z":
        return -1.0, 0.0
    elif dir == "SI":
        return 1.0/sqrt_2, 1.0/sqrt_2
    elif dir == "SZ":
        return -1.0/sqrt_2, 1.0/sqrt_2
    elif dir == "JI":
        return 1.0/sqrt_2, -1.0/sqrt_2
    elif dir == "JZ":
        return -1.0/sqrt_2, -1.0/sqrt_2
    
xm = 0.0
ym = 0.0
xh = 1.0
yh = 0.0

M = int(input())
for i in range(M):
    dir, value = input().split()
    value = float(value)

    x_sign, y_sign = parse(dir)
    xm += x_sign * value
    ym += y_sign * value

H = int(input())
for i in range(H):
    dir, value = input().split()
    value = float(value)

    x_sign, y_sign = parse(dir)
    xh += x_sign * value
    yh += y_sign * value

diff = math.sqrt((xm - xh) ** 2 + (ym - yh) ** 2)
print(diff)
