## 思路

令 $dp[i][j]$ 表示 $s[0,i-1]$ 与 $p[0,j-1]$ 是否匹配，则有如下递推公式.
$$
dp[i][j]=\left\{
\begin{aligned}
dp[i-1][j-1] & & (s[i-1]=p[j-1] \ or \ p[j-1]='.')  \\
dp[i][j-2] & & (p[j-1]='*') \\
dp[i-1][j] & & (p[j-1]='*' \ and \ (p[j-2]=s[i-1] \ or \ p[j-2]='.' ))
\end{aligned}
\right.
$$
第二行表示 $p[j-1]$ 起到重复0次的作用，意思是$p[j-2]$ 这个字符出现了0次

第三行表示 $p[j-1]$ 起到重复至少1次的作用，这样 $s[i-1]$ 和 $p[j-2,j-1]$ 是匹配的

Python可以直接用正则，一行搞定.

### C++

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<bool> >dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=0;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(p[j-1]!='*'){
                    if(i-1>=0 && (s[i-1]==p[j-1] || '.'==p[j-1])) dp[i][j]=dp[i-1][j-1];
                }
                else if(j-2>=0){
                    dp[i][j]=dp[i][j-2];
                    if(i-1>=0 && (s[i-1]==p[j-2] || '.'==p[j-2])) dp[i][j]=dp[i][j] || dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
```

### Java

```java
class Solution {
    public boolean isMatch(String s, String p) {
        int n=s.length(),m=p.length();
        boolean dp[][]=new boolean[n+1][m+1];
        dp[0][0]=true;
        for(int i=0;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(p.charAt(j-1)!='*'){
                    if(i-1>=0 && (s.charAt(i-1)==p.charAt(j-1) || '.'==p.charAt(j-1)))
                        dp[i][j]=dp[i-1][j-1];
                    else
                        dp[i][j]=false;
                }
                else if(j-2>=0){
                    dp[i][j]=dp[i][j-2];
                    if(i-1>=0 && (s.charAt(i-1)==p.charAt(j-2) || '.'==p.charAt(j-2)))
                        dp[i][j]=dp[i][j] || dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
}
```

### Python

```python
import re
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        return re.match('^'+p+'$',s)!=None
```

