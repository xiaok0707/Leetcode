## 区间DP

令 $dp[i][j]$ 表示字符串 $s[i...j]$ 是否为回文串，有如下递推公式
$$
dp[i][j]=
\begin{equation}  
\left\{  
             \begin{array}  
             true, & dp[i+1][j-1]=true \  \and \ s[i]=s[j] \\  
             false, & else\\  
             \end{array}  
\right.  
\end{equation}
$$
初始化所有的 $dp[i][i]=true,dp[i][i+1]=(s[i]=s[j]?true:false)$，然后进行递推，最后双重循环遍历所有子串，确定最长回文子串。

时间复杂度 $O(n^2)$

### C++

```c++
class Solution {
public:
    static const int N=1050;
    bool dp[N][N];//dp[i][j]表示s[i...j]是否为回文串
    
    string longestPalindrome(string s) {
        int n=s.length();
        for(int i=0;i<n;++i) dp[i][i]=true;
        for(int i=0;i+1<n;++i) dp[i][i+1]=s[i]==s[i+1];
        for(int len=2;len<n;++len){
            for(int i=0;i+len<n;++i){
                int j=i+len;
                if(dp[i+1][j-1] && s[i]==s[j]) dp[i][j]=true;
                else dp[i][j]=false;
            }
        }
        int le,ri,mx=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(dp[i][j] && j-i+1>mx){
                    mx=j-i+1;
                    le=i;
                    ri=j;
                }
            }
        }
        string ans="";
        for(int i=le;i<=ri;++i) ans+=s[i];
        return ans;
    }
};
```

### Java

```java
class Solution {
    public static int N=1050;
    public boolean dp[][]=new boolean[N][N];
    public String longestPalindrome(String s) {
        int n=s.length();
        for(int i=0;i<n;++i) dp[i][i]=true;
        for(int i=0;i+1<n;++i) dp[i][i+1]=s.charAt(i)==s.charAt(i+1);
        for(int len=2;len<n;++len){
            for(int i=0;i+len<n;++i){
                int j=i+len;
                if(dp[i+1][j-1] && s.charAt(i)==s.charAt(j)) dp[i][j]=true;
                else dp[i][j]=false;
            }
        }
        int le=0,ri=-1,mx=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(dp[i][j] && j-i+1>mx){
                    mx=j-i+1;
                    le=i;
                    ri=j;
                }
            }
        }
        String ans="";
        for(int i=le;i<=ri;++i) ans+=s.charAt(i);
        return ans;
    }
}
```

### Python

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n=len(s)
        dp=[[ False for i in range(n)] for j in range(n)]
        for i in range(n):
            dp[i][i]=True
        for i in range(n-1):
            dp[i][i+1]=True if s[i]==s[i+1] else False
        for l in range(2,n):
            for i in range(n-l):
                j=i+l
                if dp[i+1][j-1] and s[i]==s[j]:
                    dp[i][j]=True
                else:
                    dp[i][j]=False

        le=0
        ri=-1
        mx=0
        for i in range(n):
            for j in range(i,n):
                if dp[i][j] and j-i+1>mx:
                    mx=j-i+1
                    le=i
                    ri=j
        if le>ri:
            return ''
        else:
            return s[le:ri+1]
```

## Manacher  O(n) 计算最长回文子串

首先填充分隔符，将所有可能为奇数或偶数长度的回文子串都转换成了奇数长度：在每个字符的两边都插入一个特殊的符号。比如 "abba" 变成 "#a#b#b#a#"， "aba" 变成 "#a#b#a#" 。为了进一步减少编码的复杂度，可以在字符串的开始加入另一个特殊字符，利于代码编写，不用特殊处理越界问题，比如 "$#a#b#a#"

下面以字符串 "12212321" 为例，经过上一步，变成了 S[] = "$#1#2#2#1#2#3#2#1#"

然后用一个数组 P[i] 来记录以字符 S[i] 为中心的最长回文子串向左右扩展的长度（包含 S[i] ）

> `S # 1 # 2 # 2 # 1 # 2 # 3 # 2 # 1 #`
> `P 1 2 1 2 5 2 1 4 1 2 1 6 1 2 1 2 1`
> (p.s. 可以看出，P[i]-1正好是原字符串中回文串的总长度）

如何计算P[i]呢？该算法增加两个辅助变量 id 和 mx，其中 id 为**已知的右边界最大的**回文子串的中心下标，mx=id+P[id]，也就是这个子串的右边界（严格来说，mx已经超出了右边界，是这个回文串右边第一个字符的位置）。

可以推算得到一个非常神奇的结论，算法的关键点就在这里：

如果 $mx > i$，那么 $P[i] >= min(P[2*id- i], mx-i)$，$2*id-i$ 指 $i$ 关于 $id$ 的对称点，也就是 $id-(i-id)=2*id-i$，便于理解，也可以这样来写：

```c++
if(P[2*id-i]<mx-i)
    P[i]=P[2*id-i];
else //P[2*id-i]>=mx-i
    P[i]=mx-i;
```

- $i<mx$ 时

  - $P[j]<mx - i$ 时，以 S[j] 为中心的回文子串包含在以S[id]为中心的回文子串中，由于 i 和 j 对称，以S[i]为中心的回文子串必然包含在以 S[id] 为中心的回文子串中，所以必有 P[i] = P[j]，如下图。

    ![1.png](https://i.loli.net/2020/03/03/HynUma1QqFMcejf.png)

  - $P[j] >= mx - i$ 时，以 S[j] 为中心的回文子串不一定完全包含于以 S[id] 为中心的回文子串中，但是基于对称性可知，下图中两个绿框所包围的部分是相同的，也就是说以S[i]为中心的回文子串，其向右至少会扩张到 mx 的位置，也就是说 P[i] >= mx - i。至于mx之后的部分是否对称，需要继续暴力匹配。

![2.png](https://i.loli.net/2020/03/03/MqnEFkNiLoHPRe9.png)

- $i>=mx$ 时，以 i 为中心，暴力向左右匹配。

### 时间复杂度分析

因为算法只有遇到还没有匹配的位置时才进行匹配，已经匹配过的位置不再进行匹配，所以对于字符串中的每一个位置，只进行一次匹配，所以 Manacher 算法的总体时间复杂度为 $O(n)$，其中 n 为字符串的长度，填充分隔符后长度是原来的两倍，所以时间复杂度依然是线性的。

### C++

```c++
class Solution {
public:
    const static int N=1050;
    int P[N<<1];//数组开两倍

    string init(string s){//预处理，填充分隔符
        string ans="$#";
        for(int i=0;i<(int)s.size();++i){
            ans+=s[i];
            ans+="#";
        }
        return ans;
    }

    string longestPalindrome(string str) {
        string s=init(str);
        int id=0,mx=0;
        memset(P,0,sizeof(P));
        for(int i=1;s[i];++i){//计算P[i]
            P[i]=mx>i?min(P[2*id-i],mx-i):1;
            while(s[i+P[i]]==s[i-P[i]]) ++P[i];
            if(i+P[i]>mx){
                mx=i+P[i];
                id=i;
            }
        }
		//找P[i]的最大值，取出对应的回文串
        int pos=0,MaxP=0;
        for(int i=1;i<(int)s.size();++i){
            if(P[i]>MaxP){
                MaxP=P[i];
                pos=i;
            }
        }
        string ans="";
        for(int i=pos-P[pos]+1;i<=pos+P[pos]-1;++i){
            if(s[i]!='#') ans+=s[i];
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    public static final int N=1050;
    public int P[]=new int[N<<1];

    public String init(String s){
        String ans="$#";
        for(int i=0;i<s.length();++i){
            ans+=s.charAt(i);
            ans+="#";
        }
        return ans;
    }

    public String longestPalindrome(String str) {
        String s=init(str);
        for(int i=0;i<s.length();++i) P[i]=0;
        int id=0,mx=0;
        for(int i=1;i<s.length();++i){
            P[i]=mx>i?Math.min(P[2*id-i],mx-i):1;
            while(i+P[i]<s.length() && s.charAt(i+P[i])==s.charAt(i-P[i])) ++P[i];
            if(i+P[i]>mx){
                mx=i+P[i];
                id=i;
            }
        }

        int pos=0,maxP=0;
        for(int i=0;i<s.length();++i){
            if(P[i]>maxP){
                maxP=P[i];
                pos=i;
            }
        }
        String ans="";
        for(int i=pos-maxP+1;i<=pos+maxP-1;++i){
            if(s.charAt(i)!='#') ans+=s.charAt(i);
        }
        return ans;
    }
}	
```

### Python

```python
class Solution:
    def init(self, s: str) -> str:
        ans='$#'
        for i in range(len(s)):
            ans+=s[i]+'#'
        return ans

    def longestPalindrome(self, string: str) -> str:
        s=self.init(string)
        P=[0 for i in range(len(s))]
        id=mx=0
        for i in range(1,len(s)):
            P[i]=min(P[2*id-i],mx-i) if mx>i else 1
            while i+P[i]<len(s) and s[i+P[i]]==s[i-P[i]]:
                P[i]+=1
            if i+P[i]>mx:
                mx=i+P[i]
                id=i

        pos=maxP=0
        for i in range(len(s)):
            if P[i]>maxP:
                maxP=P[i]
                pos=i
        
        ans=''
        for i in range(pos-maxP+1,pos+maxP):
            if s[i]!='#':
                ans+=s[i]
        return ans
```

