## 思路

一共 n 个数字，首次缺失的数字一定小于等于 n+1.

直接用哈希表会比较简单，把数组中的值作为索引，然后遍历 1 到 n，看哪个数字没出现，但这样做空间复杂度是 $O(n)$ 的.

可以直接将题目给的这个数组当成哈希表，首先预处理将所有不在 [1,n] 的数字变成1，然后把数组下标当成原来的数值，负数表示出现过，正数表示没出现过.

### C++

```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int maxval=1,n=nums.size();
        for(int i=0;i<n;++i){
            maxval=max(maxval,nums[i]);
            mp[nums[i]]=true;
        }
        int ans=1;
        for(int i=1;i<=n+1;++i){
            if(!mp[i]){
                ans=i;
                break;
            }
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n=nums.length;
        if(n==0) return 1;
        boolean flag=false;
        for(int i=0;i<n;++i){
            if(nums[i]==1) flag=true;
            else if(nums[i]<=0 || nums[i]>n) nums[i]=1;
        }
        if(!flag) return 1;
        
        for(int i=0;i<n;++i){
            int pos=Math.abs(nums[i])%n;
            nums[pos]=nums[pos]<0?nums[pos]:-nums[pos];
        }
        for(int i=1;i<n;++i){
            if(nums[i]>0) return i;
        }
        if(nums[0]>0) return n;
        return n+1;
    }
}
```

### Python

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if not 1 in nums:return 1
        n=len(nums)
        for i in range(n):
            if nums[i]<=0 or nums[i]>n:nums[i]=1
        for i in range(n):
            pos=abs(nums[i])%n
            if nums[pos]>0: nums[pos]=-nums[pos]
        for i in range(1,n):
            if nums[i]>0:return i
        if nums[0]>0:return n
        return n+1
```

