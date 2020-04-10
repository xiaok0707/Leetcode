## 思路

$dp[i][j]$ 表示走到位置 $(i,j)$ 的不同方案数，那么根据题意 $dp[i][j]=dp[i-1][j]+dp[i][j-1]$. 如果 $(i,j)$ 为障碍物，则直接令 $dp[i][j]=0$.

### Python

```python
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
```

