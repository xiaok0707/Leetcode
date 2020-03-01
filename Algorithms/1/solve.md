## 思路

直接 $O(n^2)$ 暴力就可以，可以用哈希表优化成 $O(n)$，先遍历一遍数组，记录一下每个数字出现的位置，再遍历一次，在哈希表中若发现目标值减去当前值对应的数，同时又不是自己，表示找到答案。

### C++

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<(int)nums.size();++i) mp[nums[i]]=i+1;
        for(int i=0;i<(int)nums.size();++i){
            if(mp[target-nums[i]] && mp[target-nums[i]]!=i+1){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]-1);
                break;
            }
        }
        return ans;
    }
};
```

### Java

```java
public int[] twoSum(int[] nums, int target) {
    Map<Integer,Integer> map=new HashMap<>();
    for(int i=0;i<nums.length;++i){
        map.put(nums[i],i);
    }
    int[] ans={0,0};
    for(int i=0;i<nums.length;++i){
        if(map.containsKey(target-nums[i]) && map.get(target-nums[i])!=i){
            ans[0]=i;
            ans[1]=map.get(target-nums[i]);
            break;
        }
    }
    return ans;
}
```

### Python

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n=len(nums)
        d={}
        for i in range(0,n):
            if target-nums[i] in d and i!=d[target-nums[i]]:
                return [i,d[target-nums[i]]]
            d[nums[i]]=i
```

