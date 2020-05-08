## 思路

$dp[i][j]$ 表示到达 $(i,j)$ 的最小路径和，则有
$$
dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j]
$$
计算第 $i$ 行只需要用到第 $i-1$ 行的结果，可以压缩为1维数组.

### Python

```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n=len(triangle)
        if 0==n: return 0
        dp=[0x7fffffff]*n
        dp[0]=triangle[0][0]
        for i in range(1,n):
            for j in range(i,-1,-1):
                if j-1>=0: dp[j]=min(dp[j],dp[j-1])+triangle[i][j]
                else: dp[j]+=triangle[i][j]
        return min(dp)
```

