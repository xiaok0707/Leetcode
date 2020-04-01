## 思路

贪心，用 pos 记录当前最远到达位置，每次在可跳范围内选择可以跳的更远的位置，每次计算如果再跳一步最远能到哪里，然后用最远的位置更新 pos，重复这一过程直到终点.

### C++

```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(),ans=0,pos=0,i=0;
        while(pos<n-1){
            ans+=1;
            int maxr=0;
            for(;i<=pos;++i) maxr=max(maxr,i+nums[i]);
            pos=maxr;
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    public int jump(int[] nums) {
        int ans=0,pos=0,i=0,n=nums.length;
        while(pos<n-1){
            ans+=1;
            int maxr=0;
            for(;i<=pos;++i) maxr=Math.max(maxr,i+nums[i]);
            pos=maxr;
        }
        return ans;
    }
}
```

### Python

```python
class Solution:
    def jump(self, nums: List[int]) -> int:
        pos,ans,i,n=0,0,0,len(nums)
        while pos<n-1:
            ans+=1
            maxr=0
            while i<=pos:
                maxr=max(nums[i]+i,maxr)
                i+=1
            pos=maxr
        return ans
```

