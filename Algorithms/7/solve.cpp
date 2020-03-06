class Solution {
public:
    int reverse(int x) {
        int flag=x<0?-1:1;
        long long y=1LL*flag*x,ans=0;
        while(y){
            ans=ans*10+y%10;
            y/=10;
        }
        ans*=flag;
        if(ans>INT_MAX || ans<INT_MIN) return 0;
        return ans;
    }
};