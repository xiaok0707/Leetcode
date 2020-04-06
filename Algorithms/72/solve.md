## 思路

$dp[i][j]$ 表示将 $word1[0...i-1]$ 转换为 $word2[0...j-1]$ 的最少次数，最终答案是 $dp[len(word1)][len(word2)]$

- 若 $word1[i-1]=word2[j-1]$，则 $dp[i][j]=dp[i-1][j-1]$.
- 若 $word1[i-1] \neq word2[j-1]$，则 $dp[i][j]$ 应当是以下三者的最小值：
  - $dp[i][j-1]+1$，意义是将 $word1[0...i-1]$ 转换为 $word2[0...j-2]$，然后再在末尾添加一个字符 $word2[j-1]$
  - $dp[i-1][j]+1$，意义是将 $word1[0...i-2]$ 转换为 $word2[0...j-1]$，然后再删除末尾的 $word1[i-1]$
  - $dp[i-1][j-1]+1$，意义是将 $word1[0...i-2]$ 转换为 $word2[0...j-2]$，然后再把末尾的 $word1[i-1]$ 替换成 $word2[j-1]$.

初始状态 $dp[0][0]=0,dp[i][0]=i,dp[0][j]=j$.

### Python

```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n,m=len(word1),len(word2)
        dp=[[0 for j in range(m+1)] for i in range(n+1)]
        for i in range(n+1): dp[i][0]=i
        for j in range(m+1): dp[0][j]=j
        for i in range(1,n+1):
            for j in range(1,m+1):
                if word1[i-1]==word2[j-1]:
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1
        return dp[n][m]

```

