import sys
dp = [1, 1]
for line in sys.stdin:
    n = int(line)
    while len(dp) < n + 1:
        dp.append(dp[-1] + dp[-2])

    print(dp[n] + dp[n - 2])
