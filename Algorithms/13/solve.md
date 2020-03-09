## 思路

简单模拟.

### C++

```c++
class Solution {
public:
    string roman[13]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int number[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};

    int romanToInt(string s) {
        int ans=0,len=s.length();
        for(int i=0;i<len;++i){
            string tmp=s.substr(i,1);
            if(i+1<len){
                tmp+=s[i+1];
                bool flag=false;
                for(int j=0;j<13;++j) if(tmp==roman[j]){
                    ans+=number[j];
                    i+=1;
                    flag=true;
                    break;
                }
                if(flag) continue;
            }
            for(int j=0;j<13;++j) if(tmp.substr(0,1)==roman[j]){
                ans+=number[j];
                break;
            }
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    String[] roman=new String[]{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int[] number=new int[]{1,4,5,9,10,40,50,90,100,400,500,900,1000};
    public int romanToInt(String s) {
        int ans=0,len=s.length();
        for(int i=0;i<len;++i){
            String tmp=""+s.charAt(i);
            if(i+1<len){
                tmp+=s.charAt(i+1);
                boolean flag=false;
                for(int j=0;j<13;++j)
                    if(tmp.equals(roman[j])){
                        ans+=number[j];
                        i+=1;
                        flag=true;
                        break;
                    }
                if(flag) continue;
            }
            for(int j=0;j<13;++j) if(tmp.substring(0,1).equals(roman[j])){
                ans+=number[j];
                break;
            }
        }
        return ans;
    }
}
```

### Python

```python
class Solution:
    def romanToInt(self, s: str) -> int:
        roman = ['I','IV','V','IX','X','XL','L','XC','C','CD','D','CM','M']
        number = [1,4,5,9,10,40,50,90,100,400,500,900,1000]
        ans=i=0
        while i<len(s):
            tmp=s[i]
            if i+1<len(s):
                tmp+=s[i+1]
                flag=False
                for j in range(13):
                    if roman[j]==tmp:
                        ans+=number[j]
                        i+=2
                        flag=True
                        break
                if flag:
                    continue
            for j in range(13):
                if roman[j]==tmp[0]:
                    ans+=number[j]
                    i+=1
                    break
        return ans
```

