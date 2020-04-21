class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(!n) return 0;
        int m=matrix[0].size();
        if(!m) return 0;
        vector<vector<int> > g(n,vector<int>(m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]=='1') g[i][j]=1;
            }
        }
        for(int j=0;j<m;++j){
            for(int i=0;i<n;++i){
                if(i && g[i][j]) g[i][j]+=g[i-1][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;++i){
            stack<int> st;
            vector<int> le(m,-1),ri(m,m);
            for(int j=0;j<m;++j){
                while(st.size() && g[i][st.top()]>=g[i][j]) st.pop();
                if(st.size()) le[j]=st.top();
                st.push(j);
            }
            while(st.size()) st.pop();
            for(int j=m-1;j>=0;--j){
                while(st.size() && g[i][st.top()]>=g[i][j]) st.pop();
                if(st.size()) ri[j]=st.top();
                st.push(j);
            }
            for(int j=0;j<m;++j){
                ans=max(ans,g[i][j]*(ri[j]-le[j]-1));
            }
        }
        return ans;
    }
};