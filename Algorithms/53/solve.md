## 思路

### 分治

求解 $[le,ri]$ 中的最大子段和，可以将区间 $[le,ri]$ 等分为两端 $[le,mid],[mid+1,ri]$， $[le,ri]$ 中的最大子段和一定是以下三者之一：

- $[le,mid]$ 中的最大子段和.
- $[mid+1,ri]$ 中的最大子段和.
- $[le,mid]$ 中的最大后缀和 + $[mid+1,ri]$ 的最大前缀和.

时间复杂度 $O(nlogn)$.

### C++

```c++
class Solution {
public:
    int solve(vector<int>&nums,int le,int ri){
        if(le==ri) return nums[le];
        int mid=(le+ri)>>1;

        int le_maxsum=solve(nums,le,mid);
        int ri_maxsum=solve(nums,mid+1,ri);
        
        int le_sum=0,le_max=INT_MIN;
        for(int i=mid;i>=le;--i){
            le_sum+=nums[i];
            le_max=max(le_max,le_sum);
        }
        int ri_sum=0,ri_max=INT_MIN;
        for(int i=mid+1;i<=ri;++i){
            ri_sum+=nums[i];
            ri_max=max(ri_max,ri_sum);
        }
        int mid_maxsum=le_max+ri_max;

        return max(max(le_maxsum,ri_maxsum),mid_maxsum);
    }

    int maxSubArray(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};
```

### DP

设 $dp[i]$ 表示以 $nums[i]$ 结尾的最大子段和，那么有如下递推公式：

- 若 $dp[i-1]>0$ ，则 $dp[i]=dp[i-1]+nums[i]$
- 若 $dp[i-1]<=0$，则 $dp[i]=nums[i]$

返回 $max(dp)$ 即可. 

时间复杂度 $O(n)$.

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n=len(nums)
        if 0==n: return 0
        dp,ans=nums[0],nums[0]
        for i in range(1,n):
            if dp>0: dp+=nums[i]
            else: dp=nums[i]
            ans=max(ans,dp)
        return ans
```

