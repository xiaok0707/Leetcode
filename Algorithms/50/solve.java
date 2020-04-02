class Solution {
    public double myPow(double x, int n) {
        long m=Math.abs((long)n);
        boolean flag=n<0;
        double ans=1.0;
        while(m>0){
            if(m%2==1) ans=ans*x;
            x=x*x;
            m>>=1;
        }
        return flag?1.0/ans:ans;
    }
}