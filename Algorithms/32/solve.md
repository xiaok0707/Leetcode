## 思路

最简单的方法是借助一个栈来处理，栈中首先存储一个边界下标，然后依次存储左括号的下标，在遇到右括号时首先从栈中弹出与其匹配的左括号，然后更新答案. 如果栈中只剩下了边界下标，即不存在匹配的左括号，那么就将该右括号的下标作为新的边界值压入栈中.

### C++

```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans=0;
        for(int i=0;i<(int)s.length();++i){
            if(s[i]=='(') st.push(i);
            else{
                int x=st.top();
                st.pop();
                if(st.empty()) st.push(i);
                else ans=max(ans,i-st.top());
            }
        }
        return ans;
    }
};
```

也可以只用两个变量 le, ri 来统计左右括号的数量.

第一次从左往右扫描字符串，当 le==ri 时统计答案，当 le<ri 时将它们同时清零，继续向后扫描.

第二次从右往左扫描字符串，当 le==ri 时统计答案，当 le>ri 时将它们同时清零，继续向前扫描.

### Java

```java
public class Solution {
    public int longestValidParentheses(String s) {
        int le=0,ri=0,ans=0;
        for(int i=0;i<s.length();++i){
            if(s.charAt(i)=='(') le+=1;
            else ri+=1;
            if(le==ri) ans=Math.max(ans,le*2);
            if(le<ri) le=ri=0;
        }
        le=ri=0;
        for(int i=s.length()-1;i>=0;--i){
            if(s.charAt(i)=='(') le+=1;
            else ri+=1;
            if(le==ri) ans=Math.max(ans,le*2);
            if(le>ri) le=ri=0;
        }
        return ans;
    }
}
```

也可以利用动态规划求解.

令 $dp[i]$ 表示以 $s_i$ 结尾的最长合法子串长度，有如下递推公式.

- 若 $s_i=‘(’$ ，则 $dp[i]=0$
- 若 $s_i=')'$，
  - 若 $s_{i-1}='('$ ，则 $dp[i]=dp[i-2]+2$
  - 若 $s_{i-1}==')'$，
    - 若 $s_{i-1-dp[i-1]}='('$，则 $dp[i]=dp[i-1]+dp[i-2-dp[i-1]]+2$
    - 若 $s_{i-1-dp[i-1]}=')'$，则 $dp[i]=0$

### Python

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n=len(s)
        s=' '+s
        dp=[0 for i in range(n+1)]
        for i in range(2,n+1):
            if s[i]==')':
                if s[i-1]=='(':
                    dp[i]=dp[i-2]+2
                elif s[i-1-dp[i-1]]=='(':
                    dp[i]=dp[i-1]+dp[i-2-dp[i-1]]+2
        return max(dp)
```

