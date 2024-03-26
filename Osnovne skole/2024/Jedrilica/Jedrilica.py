n = int(input())
lista = []
for i in range(n):
    lista.append(int(input()))

result = 0
for i in range(n - 1):
    diff = max(lista[i], lista[i+1]) - min(lista[i], lista[i+1])
    if diff > 180: diff = 360 - diff
    result += diff

print(result)