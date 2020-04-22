class Solution:
    def numDecodings(self, s: str) -> int:
        n=len(s)
        if n==0: return 0
        dp=[0 for i in range(n)]
        dp[0]=0 if s[0]=='0' else 1
        if n==1: return dp[0]
        
        if s[1]!='0': dp[1]+=dp[0]
        if s[0]!='0' and 1<=int(s[:2])<=26: dp[1]+=1
        for i in range(2,n):
            if s[i]!='0': dp[i]+=dp[i-1]
            if 1<=int(s[i-1:i+1])<=26 and s[i-1]!='0': dp[i]+=dp[i-2]
        return dp[n-1]