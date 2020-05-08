## 思路

根据组合数递推式 $C(i,j)=C(i-1,j)+C(i-1,j-1)$ 模拟即可.

### Python

```python
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if 0==numRows: return []
        C=[[1]]
        for i in range(1,numRows):
            tmp=[1]
            for j in range(1,i):
                tmp.append(C[i-1][j-1]+C[i-1][j])
            tmp.append(1)
            C.append(tmp[:])
        return C
```

