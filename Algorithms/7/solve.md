## 思路

直接模拟，注意爆int，C++用long long，Java用long.

### C++

```c++
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
```

### Java

```java
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
```

### Python

```python
class Solution:
    def reverse(self, x: int) -> int:
        flag=-1 if x<0 else 1
        ans=0
        y=x*flag
        while y>0:
            ans=ans*10+y%10
            y//=10
        ans*=flag
        if ans<-0x80000000 or ans>0x7fffffff:
            return 0
        return ans
```

