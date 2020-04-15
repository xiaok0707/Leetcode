## 思路

简单搜索.

### Python

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans,tmp,n=[],[],len(nums)

        def dfs(cur):
            if cur==n:
                ans.append(tmp[:])
                return
            dfs(cur+1)
            tmp.append(nums[cur])
            dfs(cur+1)
            tmp.pop()

        dfs(0)
        return ans
```

