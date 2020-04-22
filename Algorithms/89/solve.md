## 思路

构造. 设 $n$ 阶格雷码为 $G(n)$，则 $G(n+1)$ 可以通过如下方式构造

1. 给 $G(n)$ 的每个元素二进制前面添加 $0$.
2. 将 $G(n)$ 倒序得到 $R(n)$，给 $R(n)$ 的每个元素二进制前面添加 $1$.
3. 将上面两步拼接得到 $G(n+1)$.

例如当前 $G(2)=[0,1]$，将其倒序得到 $R(2)=[1,0]$，$R(2)+2^1=[3,2]$，拼接后得到 $G(3)=[0,1,3,2]$.

### Python

```python
class Solution:
    def grayCode(self, n: int) -> List[int]:
        ans=[0]
        pw=1
        for i in range(n):
            ans.extend([e+pw for e in ans[::-1]])
            pw<<=1
        return ans
```

