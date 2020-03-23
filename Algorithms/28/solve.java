class Solution {
    String s,p;
    int lens,lenp,next[];

    public void getnext(){
        next=new int[lenp];
        int k=-1,j=0;
        next[0]=-1;
        while(j+1<lenp){
            if(k==-1 || p.charAt(j)==p.charAt(k)){
                ++j;
                ++k;
                next[j]=k;
            }
            else k=next[k];
        }
    }

    public int kmp(){
        int i=0,j=0;
        while(i<lens && j<lenp){
            if(j==-1 || s.charAt(i)==p.charAt(j)){
                ++i;
                ++j;
            }
            else j=next[j];
        }
        return j==lenp?i-j:-1;
    }

    public int strStr(String haystack, String needle) {
        s=haystack;
        p=needle;
        lens=s.length();
        lenp=p.length();
        if(0==lenp) return 0;
        getnext();
        return kmp();
    }
}