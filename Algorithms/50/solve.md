## 思路

快速幂模板.

### C++

```c++
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
```

### Java

```java
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
```

### Python

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        return x**n
```

