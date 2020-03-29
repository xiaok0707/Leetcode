class Solution {
    String res[]=new String[35];

    Solution(){
        res[1]="1";
        for(int i=2;i<=30;++i){
            res[i]="";
            String str=res[i-1];
            for(int le=0;le<str.length();){
                int ri=le;
                while(ri<str.length() && str.charAt(le)==str.charAt(ri)) ++ri;
                res[i]+=String.valueOf(ri-le);
                res[i]+=str.charAt(le);
                le=ri;
            }
        }
    }

    public String countAndSay(int n) {
        return res[n];
    }
}