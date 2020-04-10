class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n,m=len(obstacleGrid),len(obstacleGrid[0])
        dp=[[0 for j in range(m)] for i in range(n)]
        dp[0][0]=0 if obstacleGrid[0][0] else 1
        for i in range(n):
            for j in range(m):
                if obstacleGrid[i][j]: continue
                if i-1>=0: dp[i][j]+=dp[i-1][j]
                if j-1>=0: dp[i][j]+=dp[i][j-1]
        return dp[n-1][m-1]