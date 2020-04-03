class Solution {
public:
    int n;
    vector<int> x;
    vector<string> g;
    vector<vector<string>> ans;

    bool check(int r,int c){
        for(int i=0;i<r;++i){
            int j=x[i];
            if(c==j) return false;
            if(abs(r-i)==abs(c-j)) return false;
        }
        return true;
    }

    void dfs(int r){
        if(r==n){
            ans.push_back(g);
            return;
        }
        for(int c=0;c<n;++c){
            if(check(r,c)){
                g[r][c]='Q';
                x[r]=c;
                dfs(r+1);
                g[r][c]='.';
                x[r]=-1;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        string tmp="";
        for(int i=0;i<n;++i) tmp+=".";
        for(int i=0;i<n;++i) g.push_back(tmp);
        x=vector<int>(n,-1);
        ans.clear();
        dfs(0);
        return ans;
    }
};