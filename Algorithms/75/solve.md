## 思路

计数排序.

### Python

```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        cnt=[0,0,0]
        for e in nums: cnt[e]+=1
        pos=0
        for val in range(3):
            for num in range(cnt[val]):
                nums[pos]=val
                pos+=1
```

