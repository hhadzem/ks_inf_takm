a, b = [int(x) for x in input().split()]
brojac = 0

while a > b:
    a = a // 2
    brojac += 1

print(brojac + (b - a))