import sys
dp = [[0 for i in range(0,101)]for j in range(0,101)]

def c(n,r):
    if n==r:
        dp[n][r]=1
        return 1
    elif r==1:
        dp[n][r]=n
        return n
    else:
        if dp[n][r]!=0:
            return dp[n][r]
        dp[n][r] = c(n-1,r-1)+c(n-1,r)
        return dp[n][r]
    
n, m = map(int,sys.stdin.readline().rstrip().split(" "))
print(c(n,m))
