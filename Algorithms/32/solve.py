class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n=len(s)
        s=' '+s;
        dp=[0 for i in range(n+1)]
        for i in range(2,n+1):
            if s[i]==')':
                if s[i-1]=='(':
                    dp[i]=dp[i-2]+2
                elif s[i-1-dp[i-1]]=='(':
                    dp[i]=dp[i-1]+dp[i-2-dp[i-1]]+2
        return max(dp)