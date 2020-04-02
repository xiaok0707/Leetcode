## 思路

简单模拟.

### C++

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int start_row=0,end_row=n-1;
        int start_col=0,end_col=n-1;
        while(start_row<=end_row){
            for(int col=start_col;col<end_col;++col){
                int i=start_row,j=col;
                int tmp=matrix[i][j];
                for(int cnt=0;cnt<3;++cnt){
                    int newi=n-1-j,newj=i;
                    matrix[i][j]=matrix[newi][newj];
                    i=newi,j=newj;
                }
                matrix[i][j]=tmp;
            }
            ++start_row;
            --end_row;
            ++start_col;
            --end_col;
        }
    }
};
```

### Java

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n=matrix.length;
        int start_row=0,end_row=n-1;
        int start_col=0,end_col=n-1;
        while(start_row<=end_row){
            for(int col=start_col;col<end_col;++col){
                int i=start_row,j=col;
                int tmp=matrix[i][j];
                for(int cnt=0;cnt<3;++cnt){
                    int newi=n-1-j,newj=i;
                    matrix[i][j]=matrix[newi][newj];
                    i=newi;j=newj;
                }
                matrix[i][j]=tmp;
            }
            ++start_row;
            --end_row;
            ++start_col;
            --end_col;
        }
    }
}
```

### Python

```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix)
        start_row,start_col,end_row,end_col=0,0,n-1,n-1
        while start_row<=end_row:
            for col in range(start_col,end_col):
                i,j=start_row,col
                tmp=matrix[i][j]
                for cnt in range(3):
                    newi,newj=n-1-j,i
                    matrix[i][j]=matrix[newi][newj]
                    i,j=newi,newj
                matrix[i][j]=tmp
            start_row+=1
            start_col+=1
            end_row-=1
            end_col-=1
```

