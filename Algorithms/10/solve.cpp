class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<bool> >dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=0;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(p[j-1]!='*'){
                    if(i-1>=0 && (s[i-1]==p[j-1] || '.'==p[j-1])) dp[i][j]=dp[i-1][j-1];
                }
                else if(j-2>=0){
                    dp[i][j]=dp[i][j-2];
                    if(i-1>=0 && (s[i-1]==p[j-2] || '.'==p[j-2])) dp[i][j]=dp[i][j] || dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};