## 思路

$dp[i][j]$ 表示将 $word1[0...i-1]$ 转换为 $word2[0...j-1]$ 的最少次数，最终答案是 $dp[len(word1)][len(word2)]$

- 若 $word1[i-1]=word2[j-1]$，则 $dp[i][j]=dp[i-1][j-1]$.
- 若 $word1[i-1] \neq word2[j-1]$，则 $dp[i][j]$ 应当是以下三者的最小值：
  - $dp[i][j-1]+1$，意义是将 $word1[0...i-1]$ 转换为 $word2[0...j-2]$，然后再在末尾添加一个字符 $word2[j-1]$
  - $dp[i-1][j]+1$，意义是将 $word1[0...i-2]$ 转换为 $word2[0...j-1]$，然后再删除末尾的 $word1[i-1]$
  - $dp[i-1][j-1]+1$，意义是将 $word1[0...i-2]$ 转换为 $word2[0...j-2]$，然后再把末尾的 $word1[i-1]$ 替换成 $word2[j-1]$.

初始状态 $dp[0][0]=0,dp[i][0]=i,dp[0][j]=j$.

### Python

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix)==0: return []
        ans=[]
        start_row,end_row=0,len(matrix)-1
        start_col,end_col=0,len(matrix[0])-1
        while start_row<=end_row and start_col<=end_col:
            if start_row==end_row:
                i=start_row
                for j in range(start_col,end_col+1): ans.append(matrix[i][j])
                break
            if start_col==end_col:
                j=start_col
                for i in range(start_row,end_row+1): ans.append(matrix[i][j])
                break
            i=start_row
            for j in range(start_col,end_col): ans.append(matrix[i][j])
            j=end_col
            for i in range(start_row,end_row): ans.append(matrix[i][j])
            i=end_row
            for j in range(end_col,start_col,-1): ans.append(matrix[i][j])
            j=start_col
            for i in range(end_row,start_row,-1): ans.append(matrix[i][j])
            start_row+=1
            end_row-=1
            start_col+=1
            end_col-=1
        return ans
```

