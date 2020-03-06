class Solution {
    public int reverse(int x) {
        int flag=x<0?-1:1;
        long ans=0,y=1L*x*flag;
        while(y>0){
            ans=ans*10+y%10;
            y/=10;
        }
        ans*=flag;
        if(ans<Integer.MIN_VALUE || ans>Integer.MAX_VALUE) return 0;
        return (int)ans;
    }
}