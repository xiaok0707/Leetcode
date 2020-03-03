class Solution:
    def longestPalindrome(self, s: str) -> str:
        n=len(s)
        dp=[[ False for i in range(n)] for j in range(n)]
        for i in range(n):
            dp[i][i]=True
        for i in range(n-1):
            dp[i][i+1]=True if s[i]==s[i+1] else False
        for l in range(2,n):
            for i in range(n-l):
                j=i+l
                if dp[i+1][j-1] and s[i]==s[j]:
                    dp[i][j]=True
                else:
                    dp[i][j]=False

        le=0
        ri=-1
        mx=0
        for i in range(n):
            for j in range(i,n):
                if dp[i][j] and j-i+1>mx:
                    mx=j-i+1
                    le=i
                    ri=j
        if le>ri:
            return ''
        else:
            return s[le:ri+1]