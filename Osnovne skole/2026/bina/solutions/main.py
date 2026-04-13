import sys

input = sys.stdin.readline

def main():
    N = int(input())
    trenutno = 0
    maksimum = 0
    for _ in range(N):
        line = input().split()
        T, K = line[0], int(line[1])
        if T == 'D':
            trenutno += K
            if trenutno > maksimum:
                maksimum = trenutno
        else:
            trenutno -= K
    print(maksimum)

main()
