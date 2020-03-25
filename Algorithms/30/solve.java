import java.math.*;

class Solution {
    public int divide(int dividend, int divisor) {
        BigInteger a=new BigInteger(String.valueOf(dividend));
        BigInteger b=new BigInteger(String.valueOf(divisor));
        a=a.divide(b);
        BigInteger INT_MAX=new BigInteger(String.valueOf(Integer.MAX_VALUE));
        BigInteger INT_MIN=new BigInteger(String.valueOf(Integer.MIN_VALUE));
        if(a.compareTo(INT_MAX)<=0 && a.compareTo(INT_MIN)>=0){
            return a.intValue();
        }
        else return Integer.MAX_VALUE;
    }
}