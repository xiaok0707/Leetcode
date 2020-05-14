## 思路

首先想到暴力算法，依次枚举数组中的每一个元素，把它当成连续序列中的第一个元素，然后不断在原数组中找是否有比当前值大1的元素，如果有则 Ans+1 继续找，没有则更新最终答案，很明显复杂度是 $O(n^2)$.

可以利用哈希优化至 $O(n)$，哈希表用来判断某个元素在数组中是否存在，实现 $O(1)$ 查询，同时，我们只对 `当前元素 - 1` 不在哈希表里的数字，作为连续序列的第一个数字去找对应的最长序列，因为如果 `当前元素 - 1` 也存在于哈希表中，那么以`当前元素` 开头的最长连续序列一定不是最优解。

### C++

```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size(),ans=0;
        for(int i=0;i<n;++i) s.insert(nums[i]);
        for(int i=0;i<n;++i){
            if(s.find(nums[i]-1)!=s.end()) continue;
            int len=1,x=nums[i]+1;
            while(s.find(x)!=s.end()){
                len+=1;
                x+=1;
            }
            ans=max(len,ans);
        }
        return ans;
    }
};
```

