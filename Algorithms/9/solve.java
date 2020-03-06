class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) return false;
        int len=0,buf[]=new int[15];
        while(x>0){
            buf[len++]=x%10;
            x/=10;
        }
        for(int i=0;i<len/2;++i)
            if(buf[i]!=buf[len-1-i]) return false;
        return true;    
    }
}