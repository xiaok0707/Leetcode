## 思路

回溯法解n皇后，依次在每一行（或者每一列也行）放入和之前不冲突的皇后，记录下之前放入皇后的位置以便检测是否冲突，放入 n 个皇后即找到了一组解.

### C++

```c++
class Solution {
public:
    int n,ans=0;
    vector<int> x;
    vector<string> g;

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
            ans+=1;
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

    int totalNQueens(int n) {
        this->n=n;
        string tmp="";
        for(int i=0;i<n;++i) tmp+=".";
        for(int i=0;i<n;++i) g.push_back(tmp);
        x=vector<int>(n,-1);
        dfs(0);
        return ans;
    }
};
```



### 

