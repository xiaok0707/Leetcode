## 思路

根据行列转换成一维数组，然后二分查找.

### C++

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(!n) return false;
        int m=matrix[0].size();
        if(!m) return false;
        if(matrix[0][0]>target) return false;
        int le=0,ri=n*m;
        while(le+1<ri){
            int mid=(le+ri)>>1;
            int r=mid/m;
            int c=mid%m;
            if(matrix[r][c]<=target) le=mid;
            else ri=mid;
        }
        int r=le/m,c=le%m;
        return matrix[r][c]==target;
    }
};
```

从左上角开始将当前元素与目标元素比较，每次减少1行或1列的搜索范围.

### Python

```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix)==0: return False
        n,m=len(matrix),len(matrix[0])
        r,c=0,m-1
        while r<n and c>=0:
            if matrix[r][c]==target: return True
            elif matrix[r][c]<target: r+=1
            else: c-=1
        return False
```

