## 思路

按照题意简单模拟.

### C++

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int> v;
        while(x){
            v.push_back(x%10);
            x/=10;
        }
        int len=v.size();
        for(int i=0;i<len/2;++i)
            if(v[i]!=v[len-1-i]) return false;
        return true;
    }
};
```

### Java

```java
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
```

### Python

```python
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        s=str(x)
        l=len(s)
        for i in range(0,l//2):
            if s[i]!=s[l-1-i]:
                return False
        return True
```

