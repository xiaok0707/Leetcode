## 思路

和 [LeetCode15](https://github.com/xiaok0707/Leetcode/blob/master/Algorithms/15/solve.md) 的思路大致一样，先排序，然后遍历排序后的数组作为第一个元素位置，第二个元素和第三个元素的位置用双指针来确定.

时间复杂度 $O(n^2)$

### C++

```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=nums[0]+nums[1]+nums[2];
        int len=nums.size();
        sort(nums.begin(),nums.end());
        for(int pos=0;pos<len;++pos){
            if(pos>0 && nums[pos-1]==nums[pos]) continue;
            int le=pos+1,ri=len-1;
            while(le<ri){
                int cur=nums[pos]+nums[le]+nums[ri];
                if(abs(cur-target)<abs(ans-target)) ans=cur;
                if(cur<target) ++le;
                else if(cur>target) --ri;
                else return target;
            }
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int ans=nums[0]+nums[1]+nums[2];
        Arrays.sort(nums);
        int len=nums.length;
        for(int pos=0;pos<len;++pos){
            if(pos>0 && nums[pos-1]==nums[pos]) continue;
            int le=pos+1,ri=len-1;
            while(le<ri){
                int cur=nums[pos]+nums[le]+nums[ri];
                if(Math.abs(cur-target)<Math.abs(ans-target)) ans=cur;
                if(cur<target) ++le;
                else if(cur>target) --ri;
                else return target;
            }
        }
        return ans;
    }
}
```

### Python

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans=sum(nums[0:3])
        L=len(nums)
        list.sort(nums)
        for pos in range(L):
            if pos>0 and nums[pos-1]==nums[pos]:
                continue
            le=pos+1
            ri=L-1
            while le<ri:
                cur=nums[pos]+nums[le]+nums[ri]
                if abs(cur-target)<abs(ans-target):
                    ans=cur
                if cur<target:
                    le+=1
                elif cur>target:
                    ri-=1
                else:
                    return target
        return ans
```

