class Solution {
    public static final int N=1050;
    public int P[]=new int[N<<1];

    public String init(String s){
        String ans="$#";
        for(int i=0;i<s.length();++i){
            ans+=s.charAt(i);
            ans+="#";
        }
        return ans;
    }

    public String longestPalindrome(String str) {
        String s=init(str);
        for(int i=0;i<s.length();++i) P[i]=0;
        int id=0,mx=0;
        for(int i=1;i<s.length();++i){
            P[i]=mx>i?Math.min(P[2*id-i],mx-i):1;
            while(i+P[i]<s.length() && s.charAt(i+P[i])==s.charAt(i-P[i])) ++P[i];
            if(i+P[i]>mx){
                mx=i+P[i];
                id=i;
            }
        }

        int pos=0,maxP=0;
        for(int i=0;i<s.length();++i){
            if(P[i]>maxP){
                maxP=P[i];
                pos=i;
            }
        }
        String ans="";
        for(int i=pos-maxP+1;i<=pos+maxP-1;++i){
            if(s.charAt(i)!='#') ans+=s.charAt(i);
        }
        return ans;
    }
}   