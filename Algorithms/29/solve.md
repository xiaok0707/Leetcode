## 思路

把商用二进制表示，借助移位运算处理.

### C++

```c++
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
```

### Java

```java
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
```

### Python

```python
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend==-0x80000000 and divisor==-1:
            return 0x7fffffff
        flag=-1 if (dividend^divisor)<0 else 1
        a,b=abs(dividend),abs(divisor)
        ans=0
        for i in range(31,-1,-1):
            if (a>>i)>=b:
                ans+=1<<i
                a-=b<<i
        return ans if flag==1 else -ans
```

