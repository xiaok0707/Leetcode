## 思路

简单模拟.

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

