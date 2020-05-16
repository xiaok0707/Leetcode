## 思路

DFS找连通块.

### C++

```c++
class Solution {
public:
    int n,m;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};

    void dfs(vector<vector<char>>& g, int r,int c){
        g[r][c]='A';
        for(int k=0;k<4;++k){
            int newr=dx[k]+r;
            int newc=dy[k]+c;
            if(newr<0 || newr>=n || newc<0 || newc>=m) continue;
            if(g[newr][newc]!='O') continue;
            dfs(g,newr,newc);
        }
    }

    void solve(vector<vector<char>>& board) {
        n=board.size();
        if(!n) return;
        m=board[0].size();
        if(!m) return;
        for(int i=0;i<n;++i){
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][m-1]=='O') dfs(board,i,m-1);
        }
        for(int j=0;j<m;++j){
            if(board[0][j]=='O') dfs(board,0,j);
            if(board[n-1][j]=='O') dfs(board,n-1,j);
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='A') board[i][j]='O';
            }
        }
    }
};
```

