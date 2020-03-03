class Solution {
public:
    static const int N=1050;
    bool dp[N][N];//dp[i][j]表示s[i...j]是否为回文串
    
    string longestPalindrome(string s) {
        int n=s.length();
        for(int i=0;i<n;++i) dp[i][i]=true;
        for(int i=0;i+1<n;++i) dp[i][i+1]=s[i]==s[i+1];
        for(int len=2;len<n;++len){
            for(int i=0;i+len<n;++i){
                int j=i+len;
                if(dp[i+1][j-1] && s[i]==s[j]) dp[i][j]=true;
                else dp[i][j]=false;
            }
        }
        int le,ri,mx=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(dp[i][j] && j-i+1>mx){
                    mx=j-i+1;
                    le=i;
                    ri=j;
                }
            }
        }
        string ans="";
        for(int i=le;i<=ri;++i) ans+=s[i];
        return ans;
    }
};