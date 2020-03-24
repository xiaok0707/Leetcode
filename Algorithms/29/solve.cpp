class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        if(dividend==INT_MIN && divisor==1){
            return INT_MIN;
        }
        int ans=0,flag=(dividend^divisor)<0?-1:1;
        long long a=abs(dividend),b=abs(divisor);
        for(int i=31;i>=0;--i){
            if((a>>i)>=b){
                ans+=1<<i;
                a-=b<<i;
            }
        }
        return flag==-1?-ans:ans;
    }
};