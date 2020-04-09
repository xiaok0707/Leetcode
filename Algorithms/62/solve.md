## 思路

$dp[i][j]$ 表示走到位置 $(i,j)$ 的不同方案数，那么根据题意 $dp[i][j]=dp[i-1][j]+dp[i][j-1]$.

### C++

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(!i && !j) continue;
                if(i-1>=0) dp[i][j]+=dp[i-1][j];
                if(j-1>=0) dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
```

排列组合，从 $(0,0)$ 到 $(m,n)$ 需要向下走 m-1 步，向右走 n-1 步，等价于问 m-1 个红球和 n-1 个白球有多少种不同的排列方式，根据可重拍列公式，
$$
ans=\frac{(m+n-2)!}{(m-1)!(n-1)!}
$$

### Python

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return math.factorial(m+n-2)//math.factorial(m-1)//math.factorial(n-1)
```

