## 思路

确定搜索范围 $[le,ri]$ ，令 $mid=(le+ri)/2$，由于序列中至多出现1处严格递减的位置，所以如果

- $nums[le]<nums[mid]$，则 $[le,mid]$ 这一段一定是有序的.
- $nums[le]>nums[mid]$，则 $[mid,ri]$ 这一段一定是有序的.
- $nums[le]==nums[mid]$，无法确认哪一段有序，只能令 $le+=1$，去掉一个重复项.

由于有重复元素，复杂度在最差的情况下回退化成 $O(n)$.

### C++

```c++
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(!n) return false;
        int le=0,ri=n-1;
        while(le<=ri){
            int mid=(le+ri)>>1;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[le]){
                ++le;
                continue;
            }
            if(nums[mid]>nums[le]){//[le,mid]有序
                if(target>=nums[le] && target<nums[mid]){
                    ri=mid-1;
                }
                else{
                    le=mid+1;
                }
            }
            else{//[mid,ri]有序
                if(target>nums[mid] && target<=nums[n-1]){
                    le=mid+1;
                }
                else{
                    ri=mid-1;
                }
            }
        }
        return false;
    }
};
```

