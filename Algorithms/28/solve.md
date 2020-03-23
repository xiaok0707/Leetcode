## 思路

KMP模板，或直接调用相关的内置函数.

### C++

```c++
class Solution {
public:
    string s,p;
    int *next,lens,lenp;

    void getnext(){
        next=new int[lenp];
        next[0]=-1;
        int k=-1,j=0;
        while(j+1<lenp){
            if(k==-1 || p[k]==p[j]){
                ++k;
                ++j;
                next[j]=k;
            }
            else k=next[k];
        }
    }

    int kmp(){
        int i=0,j=0;
        while(i<lens && j<lenp){
            if(j==-1 || s[i]==p[j]){
                ++i;
                ++j;
            }
            else j=next[j];
        }
        if(j>=lenp) return i-j;
        else return -1;
    }

    int strStr(string haystack, string needle) {
        s=haystack,p=needle;
        lens=s.length(),lenp=p.length();
        if(!lenp) return 0;
        getnext();
        return kmp();
    }
};
```

### Java

```java
class Solution {
    String s,p;
    int lens,lenp,next[];

    public void getnext(){
        next=new int[lenp];
        int k=-1,j=0;
        next[0]=-1;
        while(j+1<lenp){
            if(k==-1 || p.charAt(j)==p.charAt(k)){
                ++j;
                ++k;
                next[j]=k;
            }
            else k=next[k];
        }
    }

    public int kmp(){
        int i=0,j=0;
        while(i<lens && j<lenp){
            if(j==-1 || s.charAt(i)==p.charAt(j)){
                ++i;
                ++j;
            }
            else j=next[j];
        }
        return j==lenp?i-j:-1;
    }

    public int strStr(String haystack, String needle) {
        s=haystack;
        p=needle;
        lens=s.length();
        lenp=p.length();
        if(0==lenp) return 0;
        getnext();
        return kmp();
    }
}
```

### Python

```python
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)
```

