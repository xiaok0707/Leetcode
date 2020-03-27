public class Solution {
    public int longestValidParentheses(String s) {
        int le=0,ri=0,ans=0;
        for(int i=0;i<s.length();++i){
            if(s.charAt(i)=='(') le+=1;
            else ri+=1;
            if(le==ri) ans=Math.max(ans,le*2);
            if(le<ri) le=ri=0;
        }
        le=ri=0;
        for(int i=s.length()-1;i>=0;--i){
            if(s.charAt(i)=='(') le+=1;
            else ri+=1;
            if(le==ri) ans=Math.max(ans,le*2);
            if(le>ri) le=ri=0;
        }
        return ans;
    }
}