def solve1(n):
    dp=[1]*(n+1)
    dp[1]=0
    for i in range(5,n+1):
        dp[i]=not dp[i-1]
        if not dp[i-2]:dp[i]=1
        if not dp[i-3]:dp[i]=1
    return dp[n]
def solve2(n):
    return (n%4) != 1
n = int(input())
result = ''
if solve2(n):
    result = "WIN"
else:
    result = "LOSE"
print(result)