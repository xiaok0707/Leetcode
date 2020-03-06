## 思路

按照题意简单模拟.

### C++

```c++
class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        int len=str.length(),pos=0;
        while(pos<len && str[pos]==' ') pos+=1;
        if(pos==len) return 0;
        if(str[pos]=='+' || str[pos]=='-'){
            int flag=str[pos]=='+'?1:-1;
            pos+=1;
            if(pos==len || str[pos]<'0' || str[pos]>'9') return 0;
            long long ans=0;
            while(pos<len && str[pos]>='0' && str[pos]<='9'){
                ans=ans*10+(str[pos]-'0');
                if(ans*flag<INT_MIN) return INT_MIN;
                if(ans*flag>INT_MAX) return INT_MAX; 
                pos+=1;
            }
            return ans*flag;
        }
        else if('0'<=str[pos] && str[pos]<='9'){
            long long ans=0;
            while(pos<len && str[pos]>='0' && str[pos]<='9'){
                ans=ans*10+(str[pos]-'0');
                if(ans>INT_MAX) return INT_MAX; 
                pos+=1;
            }
            return ans;
        }
        else return 0;
    }
};
```

### Java

```java
class Solution {
    public int myAtoi(String str) {
        if(str.isEmpty()) return 0;
        int len=str.length(),pos=0;
        while(pos<len && str.charAt(pos)==' ') pos+=1;
        if(pos==len) return 0;
        if(str.charAt(pos)=='+' || str.charAt(pos)=='-'){
            long flag=str.charAt(pos)=='+'?1:-1;
            long ans=0;
            pos+=1;
            if(pos==len) return 0;
            if(!Character.isDigit(str.charAt(pos))) return 0;
            while(pos<len && Character.isDigit(str.charAt(pos))){
                ans=ans*10+Integer.parseInt(String.valueOf(str.charAt(pos)));
                if(ans*flag<Integer.MIN_VALUE) return Integer.MIN_VALUE;
                if(ans*flag>Integer.MAX_VALUE) return Integer.MAX_VALUE;
                pos+=1;
            }
            ans*=flag;
            return (int)ans;
        }
        else if(Character.isDigit(str.charAt(pos))){
            long ans=0;
            while(pos<len && Character.isDigit(str.charAt(pos))){
                ans=ans*10+Integer.parseInt(String.valueOf(str.charAt(pos)));
                if(ans>Integer.MAX_VALUE) return Integer.MAX_VALUE;
                pos+=1;
            }
            return (int)ans;
        }
        else return 0;
    }
}
```

### Python

```python
class Solution:
    def myAtoi(self, s: str) -> int:
        s=s.lstrip()
        if len(s)==0:
            return 0
        if not s[0].isdigit() and s[0]!='+' and s[0]!='-':
            return 0
        flag=-1 if s[0]=='-' else 1
        pos=0 if s[0].isdigit() else 1
        ans=0
        while pos<len(s) and s[pos].isdigit():
            ans=ans*10+int(s[pos])
            if ans*flag<-0x80000000:
                return -0x80000000
            if ans*flag>0x7fffffff:
                return 0x7fffffff
            pos+=1
        return flag*ans

```

