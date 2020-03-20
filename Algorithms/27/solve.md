## 思路

简单模拟.

### C++

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=0,len=nums.size();
        for(int i=0;i<len;++i){
            if(nums[i]!=val)
                nums[ans++]=nums[i];
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int ans=0,len=nums.length;
        for(int i=0;i<len;++i){
            if(nums[i]!=val)
                nums[ans++]=nums[i];
        }
        return ans;
    }
}
```

### Python

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        length=len(nums)
        ans=0
        for i in range(length):
            if nums[i]!=val:
                nums[ans]=nums[i]
                ans+=1
        return ans
```

