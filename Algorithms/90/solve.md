## 思路

统计一下每个元素出现的个数，然后深搜即可.

### Python

```python
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        from collections import Counter
        c=Counter(nums)
        k,v=list(c.keys()),list(c.values())
        ans,tmp=[],[]

        def dfs(pos):
            if pos==len(k):
                ans.append(tmp[:])
                return
            dfs(pos+1)
            for i in range(v[pos]):
                tmp.append(k[pos])
                dfs(pos+1)
            for i in range(v[pos]): tmp.pop()
        
        dfs(0)        
        return ans
```

