## 思路

$$
C(n,m)=\frac{n!}{m!(n-m)!}
$$

$$
C(n,m-1)=\frac{n!}{(m-1)!(n-m+1)!}
$$

因此有
$$
C(n,m)=C(n,m-1)×\frac{n-m+1}{m}
$$
根据上式递推即可.

### Python

```python
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        C=[1]
        for i in range(1,rowIndex+1):
            now=C[i-1]*(rowIndex-i+1)//i
            C.append(now)
        return C
```

