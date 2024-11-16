import sys
import math
sys.setrecursionlimit(1 << 25)


def recursive(depth, sum_val, cnt):
    global answer

    if depth == N:
        if cnt == 0: return
        raw = sum_val / cnt
        avg = math.floor(raw + 0.5)
        answer |= avg == K
        return

    recursive(depth + 1, sum_val, cnt)
    recursive(depth + 1, sum_val + v[depth], cnt + 1)


answer = False
K = int(input())
N = int(input())
v = list(map(int, input().split()))

recursive(0, 0, 0)
print("YES" if answer else "NO")
