class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        bool negative=n<0;
        long long m=abs(n);
        while(m){
            if(m&1) ans=ans*x;
            x=x*x;
            m>>=1;
        }
        return negative?1.0/ans:ans;
    }
};