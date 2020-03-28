## 思路

简单模拟.

### C++

```c++
class Solution {
public:
    bool used[10];

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i){
            memset(used,false,sizeof(used));
            for(int j=0;j<9;++j){
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'0';
                if(used[x]) return false;
                used[x]=true;
            }
        }
        for(int j=0;j<9;++j){
            memset(used,false,sizeof(used));
            for(int i=0;i<9;++i){
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'0';
                if(used[x]) return false;
                used[x]=true;
            }
        }
        for(int r=0;r<9;r+=3){
            for(int c=0;c<9;c+=3){
                memset(used,false,sizeof(used));
                for(int i=r;i<r+3;++i){
                    for(int j=c;j<c+3;++j){
                        if(board[i][j]=='.') continue;
                        int x=board[i][j]-'0';
                        if(used[x]) return false;
                        used[x]=true;
                    }
                }
            }
        }
        return true;
    }
};
```

### Java

```java
class Solution {
    public boolean used[]=new boolean[10];
    public boolean isValidSudoku(char[][] board) {
        for(int i=0;i<9;++i){
            Arrays.fill(used,false);
            for(int j=0;j<9;++j){
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'0';
                if(used[x]) return false;
                used[x]=true;
            }
        }
        for(int j=0;j<9;++j){
            Arrays.fill(used,false);
            for(int i=0;i<9;++i){
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'0';
                if(used[x]) return false;
                used[x]=true;
            }
        }
        for(int r=0;r<9;r+=3){
            for(int c=0;c<9;c+=3){
                Arrays.fill(used,false);
                for(int i=r;i<r+3;++i){
                    for(int j=c;j<c+3;++j){
                        if(board[i][j]=='.') continue;
                        int x=board[i][j]-'0';
                        if(used[x]) return false;
                        used[x]=true;
                    }
                }
            }
        }
        return true;
    }
}
```

### Python

```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            used=[False for a in range(10)]
            for j in range(9):
                if board[i][j]=='.':continue
                x=int(board[i][j])
                if used[x]:return False
                used[x]=True
        for j in range(9):
            used=[False for a in range(10)]
            for i in range(9):
                if board[i][j]=='.':continue
                x=int(board[i][j])
                if used[x]:return False
                used[x]=True
        for r in range(0,9,3):
            for c in range(0,9,3):
                used=[False for a in range(10)]
                for i in range(r,r+3):
                    for j in range(c,c+3):
                        if board[i][j]=='.':continue
                        x=int(board[i][j])
                        if used[x]:return False
                        used[x]=True
        return True
```

