const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

class Solution {
public:
    int n,m,len;
    vector<vector<char>> g;
    string str;
    bool ok=false;

    void dfs(int r,int c,int now){
        if(now==len){
            ok=true;
            return;
        }
        if(ok) return;
        char ch=g[r][c];
        g[r][c]='#';
        for(int k=0;k<4;++k){
            int newr=r+dx[k];
            int newc=c+dy[k];
            if(newr<0 || newr>=n || newc<0 || newc>=m) continue;
            if(g[newr][newc]!=str[now]) continue;
            dfs(newr,newc,now+1);
        }
        g[r][c]=ch;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        g=board;
        str=word;
        len=word.length();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(g[i][j]==str[0]){
                    dfs(i,j,1);
                    if(ok) return true;
                }
            }
        }
        return false;
    }
};