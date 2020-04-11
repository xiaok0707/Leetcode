## 思路

构造一个DFA，明确中止状态.

### C++

```c++
class Solution {
public:
    const int dfa[10][6]={
        { 1,-1, 2, 3, 0,-1 },
        { 1, 5,-1, 4, 9,-1 },
        { 1,-1,-1, 3,-1,-1 },
        { 6,-1,-1,-1,-1,-1 },
        { 6, 5,-1,-1, 9,-1 },
        { 8,-1, 7,-1,-1,-1 },
        { 6, 5,-1,-1, 9,-1 },
        { 8,-1,-1,-1,-1,-1 },
        { 8,-1,-1,-1, 9,-1 },
        {-1,-1,-1,-1, 9,-1 }
    };

    int getid(char ch){
        if(ch>='0' && ch<='9') return 0;
        if(ch=='e') return 1;
        if(ch=='+' || ch=='-') return 2;
        if(ch=='.') return 3;
        if(ch==' ') return 4;
        return 5;
    }

    bool isNumber(string s) {
        int cur=0;
        for(int i=0;i<(int)s.length();++i){
            int id=getid(s[i]);
            cur=dfa[cur][id];
            if(cur<0) return false;
        }
        return cur==1 || cur==4 || cur==6 || cur==8 || cur==9;
    }
};
```

大模拟.

### Python

```python
class Solution:
    def isNumber(self, s: str) -> bool:
        s=s.strip() #去掉两端空格
        if len(s)==0: return False
        if s[0]=='+' or s[0]=='-': s=s[1:] #去掉正负号
        if 'e' in s: #含e
            tmp=s.split('e') #拆分成左右两部分
            if len(tmp)>2: return False
            tmp[0]=tmp[0].replace('.','',1) # 左边除了至多有1个小数点外应该全是数字
            if not tmp[0].isdigit(): return False
            if len(tmp[1])==0: return False # 右边不能是空串
            if tmp[1][0]=='+' or tmp[1][0]=='-': tmp[1]=tmp[1][1:] # 去掉右边的正负号
            return tmp[1].isdigit() # 右边应该全是数字
        else: #不含e
            s=s.replace('.','',1) #去掉1个小数点后应该只剩数字
            return s.isdigit()
```

