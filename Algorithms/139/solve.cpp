class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length(),m=wordDict.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=0;i<=n;++i){
            if(!dp[i]) continue;
            for(int j=0;j<m;++j){
                int len=wordDict[j].length();
                if(i+len>n) continue;
                if(s.substr(i,len)==wordDict[j]){
                    dp[i+len]=true;
                }
            }
        }
        return dp[n];
    }
};