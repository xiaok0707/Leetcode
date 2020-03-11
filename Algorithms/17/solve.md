## 思路

简单深搜.

### C++

```c++
class Solution {
public:
    string str[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"},digits,cur;
    int len;
    vector<string> ans;

    void dfs(int pos){
        if(pos==len){
            ans.push_back(cur);
            return;
        }
        int id=digits[pos]-'0';
        for(int i=0;i<(int)str[id].length();++i){
            cur.push_back(str[id][i]);
            dfs(pos+1);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        this->digits=digits;
        len=digits.length();
        if(!len) return {};
        ans.clear();
        cur.clear();
        dfs(0);
        return ans;
    }
};
```

### Java

```java
class Solution {
    Map<String, String> phone = new HashMap<String, String>() {{
        put("2", "abc");
        put("3", "def");
        put("4", "ghi");
        put("5", "jkl");
        put("6", "mno");
        put("7", "pqrs");
        put("8", "tuv");
        put("9", "wxyz");
    }};
    List<String> ans=new LinkedList<>();
    String digits,cur;
    int len;

    public void dfs(int pos){
        if(pos==len){
            ans.add(cur);
            return;
        }
        String key=digits.substring(pos,pos+1);
        for(int i=0;i<phone.get(key).length();++i){
            char ch=phone.get(key).charAt(i);
            cur+=ch;
            dfs(pos+1);
            cur=cur.substring(0,cur.length()-1);
        }
    }

    public List<String> letterCombinations(String digits) {
        this.digits=digits;
        len=digits.length();
        ans.clear();
        cur="";
        if(len>0) dfs(0);
        return ans;
    }
}
```

### Python

```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        phone = {'2': ['a', 'b', 'c'],
                 '3': ['d', 'e', 'f'],
                 '4': ['g', 'h', 'i'],
                 '5': ['j', 'k', 'l'],
                 '6': ['m', 'n', 'o'],
                 '7': ['p', 'q', 'r', 's'],
                 '8': ['t', 'u', 'v'],
                 '9': ['w', 'x', 'y', 'z']}
        ans = []
        length = len(digits)

        def dfs(pos: int, cur: str):
            if pos==length:
                ans.append(cur)
                return
            for ch in phone[digits[pos]]:
                dfs(pos+1,cur+ch)

        if length>0:
            dfs(0,"")
        return ans
```

