## 思路

简单模拟.

### Python

```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        g=[[0 for j in range(n)] for i in range(n)]
        sr,sc,er,ec=0,0,n-1,n-1
        x=1
        while sr<=er:
            if sr==er:
                g[sr][sc]=x
                break
            i=sr
            for j in range(sc,ec):
                g[i][j]=x
                x+=1
            j=ec
            for i in range(sr,er):
                g[i][j]=x
                x+=1
            i=er
            for j in range(ec,sc,-1):
                g[i][j]=x
                x+=1
            j=sc
            for i in range(er,sr,-1):
                g[i][j]=x
                x+=1
            sr+=1
            sc+=1
            er-=1
            ec-=1
        return g
```

