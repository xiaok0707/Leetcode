## 思路

按照题意剪枝搜索即可.

### C++

```c++
class Solution {
public:
    char g[10][10];
    bool usedrow[10][10],usedcol[10][10],usedblock[10][10],ok;
    
    Solution(){
        memset(usedrow,false,sizeof(usedrow));
        memset(usedcol,false,sizeof(usedcol));
        memset(usedblock,false,sizeof(usedblock));
    }

    void dfs(int x,int y){
        if(x==9){
            ok=true;
            return;
        }
        if(ok) return;
        int r=x/3,c=y/3,num=r*3+c;
        int newx,newy;
        if(y+1<(c+1)*3) newx=x,newy=y+1;
        else if(x+1<(r+1)*3) newx=x+1,newy=c*3;
        else{
            if(num==2 || num==5 || num==8) newx=x+1,newy=0;
            else newx=x-2,newy=y+1;
        }
        if(g[x][y]!='.' && !ok){
            dfs(newx,newy);
            return;
        }
        for(int a=1;a<=9;++a){
            if(!usedrow[x][a] && !usedcol[y][a] && !usedblock[num][a] && !ok){
                usedrow[x][a]=usedcol[y][a]=usedblock[num][a]=true;
                g[x][y]='0'+a;
                dfs(newx,newy);
                if(ok) return;
                usedrow[x][a]=usedcol[y][a]=usedblock[num][a]=false;
                g[x][y]='.';
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                g[i][j]=board[i][j];
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'0';
                usedrow[i][x]=true;
                usedcol[j][x]=true;
                usedblock[(i/3)*3+j/3][x]=true;
            }
        }
        ok=false;
        dfs(0,0);
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                board[i][j]=g[i][j];
            }
        }
    }
};
```

### Java

```java
class Solution {
    char g[][]=new char[10][10];
    boolean usedrow[][]=new boolean[10][10],usedcol[][]=new boolean[10][10],usedblock[][]=new boolean[10][10],ok;

    public void dfs(int x,int y){
        if(x==9){
            ok=true;
            return;
        }
        if(ok) return;
        int r=x/3,c=y/3,num=r*3+c;
        int newx=0,newy=0;
        if(y+1<(c+1)*3) { newx=x;newy=y+1; }
        else if(x+1<(r+1)*3) { newx=x+1;newy=c*3; }
        else{
            if(num==2 || num==5 || num==8) { newx=x+1;newy=0; }
            else { newx=x-2;newy=y+1; }
        }
        if(g[x][y]!='.' && !ok){
            dfs(newx,newy);
            return;
        }
        for(int a=1;a<=9;++a){
            if(!usedrow[x][a] && !usedcol[y][a] && !usedblock[num][a] && !ok){
                usedrow[x][a]=usedcol[y][a]=usedblock[num][a]=true;
                g[x][y]=String.valueOf(a).charAt(0);
                dfs(newx,newy);
                if(ok) return;
                usedrow[x][a]=usedcol[y][a]=usedblock[num][a]=false;
                g[x][y]='.';
            }
        }
    }

    public void solveSudoku(char[][] board) {
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                g[i][j]=board[i][j];
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'0';
                usedrow[i][x]=true;
                usedcol[j][x]=true;
                usedblock[(i/3)*3+j/3][x]=true;
            }
        }
        ok=false;
        dfs(0,0);
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                board[i][j]=g[i][j];
            }
        }
    }
}
```

### Python

```python
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        usedrow = [[False for i in range(10)] for j in range(10)]
        usedcol = [[False for i in range(10)] for j in range(10)]
        usedblock = [[False for i in range(10)] for j in range(10)]
        ok = False

        def dfs(x: int, y: int) -> None:
            nonlocal ok
            if x==9:ok=True
            if ok:return
            r,c=x//3,y//3
            num=r*3+c
            newx,newy=0,0
            if y+1<(c+1)*3:newx,newy=x,y+1
            elif x+1<(r+1)*3:newx,newy=x+1,c*3
            else:
                if num==2 or num==5 or num==8:newx,newy=x+1,0
                else:newx,newy=x-2,y+1
            if board[x][y]!='.' and not ok:
                dfs(newx,newy)
                return
            for v in range(1,10):
                if not usedrow[x][v] and not usedcol[y][v] and not usedblock[num][v] and not ok:
                    usedrow[x][v]=usedcol[y][v]=usedblock[num][v]=True
                    board[x][y]=str(v)
                    dfs(newx,newy)
                    if ok:return
                    usedrow[x][v]=usedcol[y][v]=usedblock[num][v]=False
                    board[x][y]='.'

        for i in range(9):
            for j in range(9):
                if board[i][j]=='.':continue
                v=int(board[i][j])
                usedrow[i][v],usedcol[j][v],usedblock[(i//3)*3+j//3][v]=True,True,True
        dfs(0,0)
```

