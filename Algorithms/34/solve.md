## 思路

二分搜索.

### C++

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.end(),target)){
            int p1=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            int p2=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
            vector<int> ans;
            ans.push_back(p1);
            ans.push_back(p2);
            return ans;
        }
        return vector<int>(2,-1);
    }
};
```

### Java

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int n=nums.length;
        if(0==n) return new int[]{-1,-1};
        int p1=upper_bound(nums,target-1);
        int p2=upper_bound(nums,target);
        if(p1<n && nums[p1]==target) return new int[]{p1,p2-1};
        else return new int[]{-1,-1};
    }

    public int upper_bound(int[] nums,int target) {
        if(target<nums[0]) return 0;
        int le=0,ri=nums.length;
        while(le+1<ri){
            int mid=(le+ri)>>1;
            if(nums[mid]<=target) le=mid;
            else ri=mid;
        }
        return ri;
    }
}
```

### Python

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n=len(nums)
        if 0==n:return [-1,-1]
        p1=self.upper_bound(nums,target-1)
        p2=self.upper_bound(nums,target)
        if p1<n and nums[p1]==target:return [p1,p2-1]
        else:return [-1,-1]
    
    def upper_bound(self, nums: List[int], target: int) -> int:
        if nums[0]>target:return 0
        le,ri=0,len(nums)
        while le+1<ri:
            mid=(le+ri)//2
            if nums[mid]<=target:le=mid
            else:ri=mid
        return ri
```

