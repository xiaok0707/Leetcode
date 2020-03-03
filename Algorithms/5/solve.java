class Solution {
    public static int N=1050;
    public boolean dp[][]=new boolean[N][N];
    public String longestPalindrome(String s) {
        int n=s.length();
        for(int i=0;i<n;++i) dp[i][i]=true;
        for(int i=0;i+1<n;++i) dp[i][i+1]=s.charAt(i)==s.charAt(i+1);
        for(int len=2;len<n;++len){
            for(int i=0;i+len<n;++i){
                int j=i+len;
                if(dp[i+1][j-1] && s.charAt(i)==s.charAt(j)) dp[i][j]=true;
                else dp[i][j]=false;
            }
        }
        int le=0,ri=-1,mx=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(dp[i][j] && j-i+1>mx){
                    mx=j-i+1;
                    le=i;
                    ri=j;
                }
            }
        }
        String ans="";
        for(int i=le;i<=ri;++i) ans+=s.charAt(i);
        return ans;
    }
}