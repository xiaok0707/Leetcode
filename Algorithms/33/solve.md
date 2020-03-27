## 思路

先二分找断点位置，断点左右两侧都是升序的，分别在两侧二分搜索即可.

### C++

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(0==n) return -1;
        if(1==n) return nums[0]==target?0:-1;
        if(nums[0]<nums[n-1]){
            int pos=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            return pos!=n && nums[pos]==target?pos:-1;
        }
        int le=0,ri=n-1;
        while(le+1<ri){
            int mid=(le+ri)>>1;
            if(nums[mid]>nums[le]) le=mid;
            else ri=mid;
        }
        if(target>=nums[0]){
            int pl=0,pr=le+1;
            while(pl+1<pr){
                int pmid=(pl+pr)>>1;
                if(nums[pmid]<=target) pl=pmid;
                else pr=pmid;
            }
            return nums[pl]==target?pl:-1;
        }
        else{
            int pl=ri,pr=n;
            while(pl+1<pr){
                int pmid=(pl+pr)>>1;
                if(nums[pmid]<=target) pl=pmid;
                else pr=pmid;
            }
            return nums[pl]==target?pl:-1;
        }
    }
};
```

### Java

```java
class Solution {
    public int search(int[] nums, int target) {
        int n=nums.length;
        if(0==n) return -1;
        if(1==n) return nums[0]==target?0:-1;
        if(nums[0]<nums[n-1]){
            int le=0,ri=n;
            while(le+1<ri){
                int mid=(le+ri)>>1;
                if(nums[mid]<=target) le=mid;
                else ri=mid;
            }
            return nums[le]==target?le:-1;
        }
        int le=0,ri=n-1;
        while(le+1<ri){
            int mid=(le+ri)>>1;
            if(nums[mid]>nums[le]) le=mid;
            else ri=mid;
        }
        if(target>=nums[0]){
            int pl=0,pr=le+1;
            while(pl+1<pr){
                int pmid=(pl+pr)>>1;
                if(nums[pmid]<=target) pl=pmid;
                else pr=pmid;
            }
            return nums[pl]==target?pl:-1;
        }
        else{
            int pl=ri,pr=n;
            while(pl+1<pr){
                int pmid=(pl+pr)>>1;
                if(nums[pmid]<=target) pl=pmid;
                else pr=pmid;
            }
            return nums[pl]==target?pl:-1;
        }
    }
}
```

### Python

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n=len(nums)
        if 0==n:return -1
        if 1==n:return 0 if nums[0]==target else -1
        if nums[0]<nums[n-1]:
            le,ri=0,n
            while le+1<ri:
                mid=(le+ri)//2
                if nums[mid]<=target:le=mid
                else:ri=mid
            return le if nums[le]==target else -1
        le,ri=0,n-1
        while le<ri:
            mid=(le+ri)//2
            if nums[mid]>nums[le]:le=mid
            else:ri=mid
        if target>=nums[0]:
            pl,pr=0,le+1
            while pl+1<pr:
                pmid=(pl+pr)//2
                if nums[pmid]<=target:pl=pmid
                else:pr=pmid
            return pl if nums[pl]==target else -1
        else:
            pl,pr=ri,n
            while pl+1<pr:
                pmid=(pl+pr)//2
                if nums[pmid]<=target:pl=pmid
                else:pr=pmid
            return pl if nums[pl]==target else -1
```

