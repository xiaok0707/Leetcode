class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp=[None for i in range(n+1)]
        dp[0]=['']
        for i in range(1,n+1):
            dp[i]=[]
            for k in range(i):
                for a in dp[i-1-k]:
                    for b in dp[k]:
                        dp[i].append('('+a+')'+b)
        return dp[n]