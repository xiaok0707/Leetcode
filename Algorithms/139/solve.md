## 思路

$dp[i]$ 表示原字符串 $s$ 的前 $i$ 个字符是否能被合法拆分，$dp[0]=true$ 指空串是合法的.

假设列表中某个单词 $word$ 长度为 $len(word)$，则 $dp[i+len(word)]=dp[i] \ \and \ s[i,i+len(word)-1]=word$

### C++

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length(),m=wordDict.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=0;i<=n;++i){
            if(!dp[i]) continue;
            for(int j=0;j<m;++j){
                int len=wordDict[j].length();
                if(i+len>n) continue;
                if(s.substr(i,len)==wordDict[j]){
                    dp[i+len]=true;
                }
            }
        }
        return dp[n];
    }
};
```
