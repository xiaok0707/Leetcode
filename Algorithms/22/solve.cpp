class Solution {
public:
    int n;
    string str;
    vector<string> ans;

    void dfs(int a,int b){
        if(a+b==2*n){
            ans.push_back(str);
            return;
        }
        if(a<n){
            str+='(';
            dfs(a+1,b);
            str.pop_back();
        }
        if(a>b && b<n){
            str+=')';
            dfs(a,b+1);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        this->n=n;
        str="";
        ans.clear();
        dfs(0,0);
        return ans;
    }
};