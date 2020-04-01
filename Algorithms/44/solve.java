class Solution {
    public boolean isMatch(String s, String p) {
        int n=s.length(),m=p.length();
        int i=0,j=0,istar=-1,jstar=-1;
        while(i<n){
            if(j<m && (s.charAt(i)==p.charAt(j) || p.charAt(j)=='?')){
                ++i;
                ++j;
            }
            else if(j<m && p.charAt(j)=='*'){
                istar=i;
                jstar=j++;
            }
            else if(istar>=0){
                i=++istar;
                j=jstar+1;
            }
            else return false;
        }
        while(j<m && p.charAt(j)=='*') ++j;
        return j==m;
    }
}