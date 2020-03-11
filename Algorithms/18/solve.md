## 思路

双重循环确定前两个位置，然后用双指针确定后两个位置. 和 [LeetCode15](https://github.com/xiaok0707/Leetcode/blob/master/Algorithms/15/solve.md) 原理完全一样.

### C++

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int len=nums.size();
        sort(nums.begin(),nums.end());
        for(int pos1=0;pos1<len;++pos1){
            if(pos1 && nums[pos1-1]==nums[pos1]) continue;
            for(int pos2=pos1+1;pos2<len;++pos2){
                if(pos2>pos1+1 && nums[pos2-1]==nums[pos2]) continue;
                int le=pos2+1,ri=len-1;
                while(le<ri){
                    int cur=nums[pos1]+nums[pos2]+nums[le]+nums[ri];
                    if(cur==target){
                        ans.push_back({nums[pos1],nums[pos2],nums[le],nums[ri]});
                        while(le<ri && nums[le+1]==nums[le]) ++le;
                        while(le<ri && nums[ri-1]==nums[ri]) --ri;
                        ++le;--ri;
                    }
                    else
                        cur<target?++le:--ri;
                }
            }
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans=new ArrayList<>();
        Arrays.sort(nums);
        int len=nums.length;
        for(int pos1=0;pos1<len;++pos1){
            if(pos1>0 && nums[pos1-1]==nums[pos1]) continue;
            for(int pos2=pos1+1;pos2<len;++pos2){
                if(pos2>pos1+1 && nums[pos2-1]==nums[pos2]) continue;
                int le=pos2+1,ri=len-1;
                while(le<ri){
                    int cur=nums[pos1]+nums[pos2]+nums[le]+nums[ri];
                    if(cur==target){
                        List<Integer> e=new ArrayList<>();
                        e.add(nums[pos1]);
                        e.add(nums[pos2]);
                        e.add(nums[le]);
                        e.add(nums[ri]);
                        ans.add(e);
                        while(le<ri && nums[le+1]==nums[le]) ++le;
                        while(le<ri && nums[ri-1]==nums[ri]) --ri;
                        ++le;--ri;
                    }
                    else{
                        if(cur<target) ++le;
                        else --ri;
                    }
                }
            }
        }
        return ans;
    }
}
```

### Python

```python
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans=[]
        length=len(nums)
        list.sort(nums)
        for pos1 in range(length):
            if pos1>0 and nums[pos1-1]==nums[pos1]:
                continue
            for pos2 in range(pos1+1,length):
                if pos2>pos1+1 and nums[pos2-1]==nums[pos2]:
                    continue
                le=pos2+1
                ri=length-1
                while le<ri:
                    cur=nums[pos1]+nums[pos2]+nums[le]+nums[ri]
                    if cur==target:
                        ans.append([nums[pos1],nums[pos2],nums[le],nums[ri]])
                        while le<ri and nums[le+1]==nums[le]:
                            le+=1
                        while le<ri and nums[ri-1]==nums[ri]:
                            ri-=1
                        le+=1
                        ri-=1
                    elif cur<target:
                        le+=1
                    else:
                        ri-=1
        return ans
```

