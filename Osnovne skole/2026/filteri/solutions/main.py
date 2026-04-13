import sys

input = sys.stdin.readline

def prefix_sum_2d(mat, H, W):
    # Row-wise prefix sums
    for i in range(H + 1):
        row = mat[i]
        s = 0
        for j in range(W + 1):
            s += row[j]
            row[j] = s
    # Column-wise prefix sums
    for j in range(W + 1):
        s = 0
        for i in range(H + 1):
            s += mat[i][j]
            mat[i][j] = s

def main():
    H, W = map(int, input().split())

    filteri_A = [[0] * (W + 2) for _ in range(H + 2)]
    filteri_B = [[0] * (W + 2) for _ in range(H + 2)]

    A = int(input())
    for _ in range(A):
        r1, c1, r2, c2 = map(int, input().split())
        filteri_A[r1][c1] += 1
        filteri_A[r2 + 1][c1] -= 1
        filteri_A[r1][c2 + 1] -= 1
        filteri_A[r2 + 1][c2 + 1] += 1

    B = int(input())
    for _ in range(B):
        r1, c1, r2, c2 = map(int, input().split())
        filteri_B[r1][c1] += 1
        filteri_B[r2 + 1][c1] -= 1
        filteri_B[r1][c2 + 1] -= 1
        filteri_B[r2 + 1][c2 + 1] += 1

    prefix_sum_2d(filteri_A, H, W)
    prefix_sum_2d(filteri_B, H, W)

    out = []
    for i in range(H):
        row_a = filteri_A[i]
        row_b = filteri_B[i]
        row = []
        for j in range(W):
            a = row_a[j]
            b = row_b[j]
            if a > 0 and b > 0:
                row.append('#')
            elif a > 0 or b > 0:
                row.append('/')
            else:
                row.append('.')
        out.append(''.join(row))
    sys.stdout.write('\n'.join(out) + '\n')

main()
