import sys

input = sys.stdin.readline

def main():
    A, B = map(int, input().split())

    is_prime = [True] * (B + 1)
    if B >= 0:
        is_prime[0] = False
    if B >= 1:
        is_prime[1] = False
    i = 2
    while i * i <= B:
        if is_prime[i]:
            j = i * i
            while j <= B:
                is_prime[j] = False
                j += i
        i += 1

    prime_count = [0] * (B + 1)
    for i in range(1, B + 1):
        prime_count[i] = prime_count[i - 1] + (1 if is_prime[i] else 0)

    count = 0
    for p in range(2, B + 1):
        if not is_prime[p]:
            continue
        lo = max(p + 1, A - p)
        hi = B - p
        if lo > hi or hi < 2 or lo > B:
            continue
        lo = max(lo, 2)
        hi = min(hi, B)
        if lo > hi:
            continue
        count += prime_count[hi] - prime_count[lo - 1]

    print(count)

main()
