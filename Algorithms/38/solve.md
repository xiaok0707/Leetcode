## 思路

简单模拟.

### C++

```c++
class Solution {
public:
    string res[35];
    
    string int2str(int x){
        string ans="";
        while(x){
            ans+='0'+x%10;
            x/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    Solution(){
        res[1]="1";
        for(int i=2;i<=30;++i){
            res[i]="";
            string str=res[i-1];
            for(int le=0;le<(int)str.size();){
                int ri=le;
                while(ri<(int)str.size() && str[ri]==str[le]) ++ri;
                res[i]+=int2str(ri-le);
                res[i]+=str[le];
                le=ri;
            }
        }
    }

    string countAndSay(int n) {
        return res[n];
    }
};
```

### Java

```java
class Solution {
    String res[]=new String[35];

    Solution(){
        res[1]="1";
        for(int i=2;i<=30;++i){
            res[i]="";
            String str=res[i-1];
            for(int le=0;le<str.length();){
                int ri=le;
                while(ri<str.length() && str.charAt(le)==str.charAt(ri)) ++ri;
                res[i]+=String.valueOf(ri-le);
                res[i]+=str.charAt(le);
                le=ri;
            }
        }
    }

    public String countAndSay(int n) {
        return res[n];
    }
}
```

### Python

```python
class Solution:
    def countAndSay(self, n: int) -> str:
        res=['' for i in range(n)]
        res[0]='1'
        for i in range(1,n):
            s=res[i-1]
            le=0
            while le<len(s):
                ri=le
                while ri<len(s) and s[le]==s[ri]:ri+=1
                res[i]+=str(ri-le)
                res[i]+=s[le]
                le=ri
        return res[n-1]
```

