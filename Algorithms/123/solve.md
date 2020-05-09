## 思路

$dp[i][j][k]$ 表示前 $i$ 天，完成 $j$ 比交易，此时手中有无股票 $(k=1有,k=0无)$.

$dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j-1][1]+price[i])$

$dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j][0]-price[i])$

初始状态 $dp[0][j][k]=-inf$ 表示状态不存在，$dp[0][0][0]=0$

### C++

```c++
const int inf=2e9;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n+1][3][2];
        for(int j=0;j<3;++j) for(int k=0;k<2;++k) dp[0][j][k]=-inf;
        dp[0][0][0]=0;
        for(int i=1;i<=n;++i){
            for(int j=0;j<3;++j){
                dp[i][j][0]=dp[i-1][j][0];
                if(j-1>=0) dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-1][1]+prices[i-1]);

                dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j][0]-prices[i-1]);
            }
        }
        return max(dp[n][0][0],max(dp[n][1][0],dp[n][2][0]));
    }
};
```

