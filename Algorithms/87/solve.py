class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1)!=len(s2): return False
        if len(s1)==0: return True
        n=len(s1)
        dp=[[[False]*(n+1) for i in range(n)] for j in range(n)]

        # 初始状态dp[i][j][1]
        for i in range(n):
            for j in range(n):
                dp[i][j][1]=s1[i]==s2[j]

        # 递推计算dp[i][j][2~n]
        for k in range(2,n+1):
            for i in range(0,n-k+1):
                for j in range(0,n-k+1):
                    for w in range(1,k):
                        if dp[i][j][w] and dp[i+w][j+w][k-w]:
                            dp[i][j][k]=True
                            break
                        if dp[i][j+k-w][w] and dp[i+w][j][k-w]:
                            dp[i][j][k]=True
                            break

        return dp[0][0][n]