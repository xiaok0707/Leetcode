## 思路

使用vector模拟。

### C++

```c++
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> v(numRows);
        int row=0;
        bool down=true;
        for(int i=0;i<(int)s.size();++i){
            v[row]+=s[i];
            if(down){
                if(row+1==numRows){
                    row-=1;
                    down=false;
                }
                else row+=1;
            }
            else{
                if(row==0){
                    row+=1;
                    down=true;
                }
                else row-=1;
            }
        }
        string ans="";
        for(int i=0;i<numRows;++i) ans+=v[i];
        return ans;
    }
};
```

### Java

```java
import java.util.Vector;

class Solution {
    public String convert(String s, int numRows) {
        if(numRows==1) return s;
        Vector<String> v=new Vector<>(numRows);
        for(int i=0;i<numRows;++i) v.add("");
        int row=0;
        boolean down=true;
        for(int i=0;i<s.length();++i){
            String str=v.get(row);
            v.set(row,str+s.charAt(i));
            if(down){
                if(row+1==numRows){
                    row-=1;
                    down=false;
                }
                else row+=1;
            }
            else{
                if(row==0){
                    row+=1;
                    down=true;
                }
                else row-=1;
            }
        }
        String ans="";
        for(int i=0;i<numRows;++i) ans+=v.get(i);
        return ans;
    }
}
```

### Python

```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1:
            return s

        L=['' for i in range(numRows)]
        row=0
        down=True
        for i in range(len(s)):
            L[row]+=s[i]
            if down:
                if row+1==numRows:
                    row-=1
                    down=False
                else:
                    row+=1
            else:
                if row==0:
                    row+=1
                    down=True
                else:
                    row-=1

        ans=''
        for i in range(numRows):
            ans+=L[i]
        return ans
```

