## 思路

简单模拟.

### C++

```c++
class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry=0,len=max(a.length(),b.length());
        for(int i=0;i<len;++i){
            int now=carry;
            if(i<a.length()) now+=a[i]-'0';
            if(i<b.length()) now+=b[i]-'0';
            ans+='0'+now%2;
            carry=now/2;
        }
        if(carry) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```

