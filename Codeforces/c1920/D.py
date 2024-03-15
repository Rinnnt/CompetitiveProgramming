import sys
from bisect import bisect_left
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

t = inp()
for tt in range(t):
    n, q = invr()
    szs = [(0, -1, -1)]
    for i in range(n):
        b, x = invr()
        if szs[-1][0] < 1e18:
            if b == 1:
                szs.append((szs[-1][0] + 1, 1, x))
            else:
                if (szs[-1][1] == 2):
                    szs[-1] = (szs[-1][0] * (x + 1), 2, x * (szs[-1][2] + 1) - 1)
                else:
                    szs.append((szs[-1][0] * (x + 1), 2, x))

    print(szs)
    ks = inlt()
    for k in ks:
        idx = bisect_left(szs, (k, -1, -1))
        print("kidx: ", k, idx)
        while (szs[idx][0] != k or szs[idx][1] == 2):
            print("k, szs: ", k, szs[idx - 1])
            k %= szs[idx - 1][0]
            if (k == 0):
                k = szs[idx - 1][0]
            idx = bisect_left(szs, (k, -1, -1), lo = 0, hi = idx)
        print("kidx: ", k, idx)
        print(szs[idx][2], end=' ')
    print()


