## 思路

二分搜索实现upper_bound函数即可.

### C++

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos=upper_bound(nums.begin(),nums.end(),target-1)-nums.begin();
        return pos;
    }
};
```

### Java

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        return upper_bound(nums,target-1);
    }

    public int upper_bound(int[] nums, int target) {
        if(nums.length==0 || nums[0]>target) return 0;
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
    def searchInsert(self, nums: List[int], target: int) -> int:
        return self.upper_bound(nums,target-1)
        
    def upper_bound(self, nums: List[int], target: int) -> int:
        if not len(nums) or nums[0]>target:return 0
        le,ri=0,len(nums)
        while le+1<ri:
            mid=(le+ri)//2
            if nums[mid]<=target:le=mid
            else:ri=mid
        return ri
```

