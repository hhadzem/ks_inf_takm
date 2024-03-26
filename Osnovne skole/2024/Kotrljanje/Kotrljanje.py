def t_zapad(conf):
    conf[0], conf[1], conf[2], conf[3] = conf[1], conf[2], conf[3], conf[0]

def t_istok(conf):
    conf[0], conf[3], conf[2], conf[1] = conf[3], conf[2], conf[1], conf[0]

def t_jug(conf):
    conf[1], conf[5], conf[3], conf[4] = conf[5], conf[3], conf[4], conf[1]

def t_sjever(conf):
    conf[1], conf[4], conf[3], conf[5] = conf[4], conf[3], conf[5], conf[1]

if __name__ == "__main__":
    M, N = map(int, input().split())

    B = []
    for _ in range(M):
        row = list(map(int, input().split()))
        B.append(row)

    start_x, start_y = map(int, input().split())
    start_x -= 1
    start_y -= 1

    k = int(input())
    arr = input().split()

    values = [0] * 6
    conf = [0, 1, 2, 3, 4, 5]
    values[1] += B[start_x][start_y]

    for i in range(k):
        if arr[i] == 'J':
            t_jug(conf)
            start_x += 1
        elif arr[i] == 'S':
            t_sjever(conf)
            start_x -= 1
        elif arr[i] == 'I':
            t_istok(conf)
            start_y += 1
        else:
            t_zapad(conf)
            start_y -= 1
        values[conf[1]] += B[start_x][start_y]

    values.sort(reverse=True)
    print(*values)
