## 思路

简单模拟.

### C++

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans=1,pos=1,len=nums.size();
        for(int i=1;i<len;++i){
            if(nums[i]!=nums[i-1]){
                ++ans;
                nums[pos++]=nums[i];
            }
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int len=nums.length;
        if(len==0) return 0;
        int ans=1,pos=1;
        for(int i=1;i<len;++i){
            if(nums[i]!=nums[i-1]){
                nums[pos++]=nums[i];
                ++ans;
            }
        }
        return ans;
    }
}
```

### Python

```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        length=len(nums)
        if length==0:
            return 0
        ans=1
        for i in range(1,length):
            if nums[i]!=nums[i-1]:
                nums[ans]=nums[i]
                ans+=1
        return ans
```

