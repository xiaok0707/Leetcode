## 思路

处理后缀最大值即可.

### C++

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(!n) return 0;
        int ans=0,Maxval=prices[n-1];
        for(int i=n-2;i>=0;--i){
            ans=max(ans,Maxval-prices[i]);
            Maxval=max(Maxval,prices[i]);
        }
        return ans;
    }
};
```

