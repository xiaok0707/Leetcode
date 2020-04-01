## 思路

### 动态规划

使用动态规划法，思路和 [Leetcode 4](https://leetcode-cn.com/problems/median-of-two-sorted-arrays) 基本相同.

设 $dp[i][j]$ 表示 $s[0...i-1]$ 和 $p[0...j-1]$ 是否匹配，那么有如下递推公式.

![2020-04-01_180318.png](https://i.loli.net/2020/04/01/AmBVl6C8SbrcZzK.png)

### C++

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<bool> > dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=0;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(p[j-1]!='*'){
                    if(i-1>=0 && (p[j-1]=='?' || s[i-1]==p[j-1])) dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=dp[i][j-1];
                    if(i-1>=0) dp[i][j]=dp[i][j] || dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
```

### 贪心

对于每个 '\*' ，首先让它匹配 0 个字符，然后继续后续的匹配，如果后面失配了，再回到失配位置的前一个 '\*' 处，让其匹配 1 个字符，再继续. 若再次失配则让其匹配 2 个，3 个 ... 更多个字符.

开始进行匹配，若i小于s串的长度，进行 while 循环。若当前两个字符相等，或着p中的字符是问号，则i和j分别加1。若 p[j] 是星号，要记录星号的位置，jStar 赋为j，此时j再自增1，istar 赋为 i。若当前 p[j] 不是星号，并且不能跟 p[i] 匹配上，此时就要靠星号了，若之前星号没出现过，返false，比如 s = "aa" 和 p = "c\*"，此时 s[0] 和 p[0] 无法匹配。如果星号之前出现过，可以尝试使用之前的 '\*'，比如 s = "aa" 和 p = "\*c"，当发现 s[1] 和 p[1] 无法匹配时，但是好在之前 p[0] 出现了星号，把 s[1] 交给 p[0] 的星号去匹配. 至于如何知道之前有没有星号，可以看 istar 的值，因为其初始化为 -1，而遇到星号时就会被更新为i. 

匹配完了s中的所有字符，但是之后还要检查p串，此时没匹配完的p串里只能剩星号，不能有其他的字符，将连续的星号过滤掉，如果j不等于p的长度，则返回 false.

### Java

```java
class Solution {
    public boolean isMatch(String s, String p) {
        int n=s.length(),m=p.length();
        int i=0,j=0,istar=-1,jstar=-1;
        while(i<n){
            if(j<m && (s.charAt(i)==p.charAt(j) || p.charAt(j)=='?')){
                ++i;
                ++j;
            }
            else if(j<m && p.charAt(j)=='*'){
                istar=i;
                jstar=j++;
            }
            else if(istar>=0){
                i=++istar;
                j=jstar+1;
            }
            else return false;
        }
        while(j<m && p.charAt(j)=='*') ++j;
        return j==m;
    }
}
```

### Python

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n,m=len(s),len(p)
        i,j,istar,jstar=0,0,-1,-1
        while i<n:
            if j<m and (s[i]==p[j] or '?'==p[j]):
                i+=1
                j+=1
            elif j<m and '*'==p[j]:
                istar=i
                jstar=j
                j+=1
            elif istar>=0:
                istar+=1
                i=istar
                j=jstar+1
            else:return False
        while j<m and p[j]=='*':j+=1
        return j==m
```

