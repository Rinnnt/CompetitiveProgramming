x = input()
m = int(input())

if len(x) == 1:
    print(1 if int(x) <= m else 0)
else:
    left = max([ord(c) - ord('0') for c in x])
    l = left
    r = 1000000000000000001

    while l + 1 < r:
        mid = (l + r) // 2

        val = 0
        digitval = 1
        for c in x[::-1]:
            val += (ord(c) - ord('0')) * digitval
            digitval *= mid

        if val <= m:
            l = mid
        else:
            r = mid

    print(l - left)
