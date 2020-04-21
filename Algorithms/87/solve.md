## 思路

区间DP，设给定的两个字符串是 $s,t$，令 $dp[i][j][k]$ 表示 $s[i,i+k-1]$ 能否转化为 $t[j,j+k-1]$.

将 $s$ 划分为 $s1,s2$，将 $t$ 划分为 $t1,t2$，有如下两种情况.

![image.png](https://pic.leetcode-cn.com/bc453287ed380cf1d8652fdf184508f2106879d1550b1b65f3b7dcd00c21cb32-image.png)

递推公式即为
$$
dp[i][j][k]=(dp[i][j][w] \  \ and \ \ dp[i+w][j+w][k-w]) \ \ or \ \ (dp[i][j+k-w][w] \ \ and \ \ dp[i+w][j][k-w] )
$$
其中 $w$ 是将长度为 $k$ 的 $s$ 划分为两部分后，左半部分的长度，$w \in [1,k-1]$.

初始状态 $dp[i][j][1]=(s[i]==t[j]?True:False)$

### Python

```python
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
```

