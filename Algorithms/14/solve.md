## 思路

可以首先对所有字符串按字典序排序，直接计算字典序最小和字典序最大的两个串的最长公共前缀.

正解是构建字典树，求最长公共前缀也是字典树的标准用法，假设共有n个字符串，随便取出某个串，从根结点不断向下搜索，当字典树上的某个结点被覆盖了n次，说明该结点对应的字符串是最长公共前缀. 细节见C++，Java代码.

### C++

```c++
struct Trie{
    Trie* nxt[26];
    int cnt;
    Trie(int cnt=1){
        for(int i=0;i<26;++i) nxt[i]=NULL;
        this->cnt=cnt;
    }
}*root;

int n;

void insert(string s){
    Trie *cur=root,*pnew;
    for(int i=0;s[i];++i){
        int id=s[i]-'a';
        if(!cur->nxt[id]){
            pnew=new Trie();
            cur->nxt[id]=pnew;
        }
        else cur->nxt[id]->cnt+=1;
        cur=cur->nxt[id];
    }
}

string search(string s){
    string ans="";
    Trie* cur=root;
    for(int i=0;s[i];++i){
        int id=s[i]-'a';
        if(cur->nxt[id]->cnt==n){
            ans+=s[i];
        }
        cur=cur->nxt[id];
    }
    return ans;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        n=strs.size();
        if(!n) return "";
        root=new Trie(0);
        for(int i=0;i<n;++i) insert(strs[i]);
        return search(strs[0]);
    }
};
```

### Java

```java
class Trie{
    Trie[] nxt;
    int cnt;
    Trie(){
        nxt=new Trie[26];
        for(int i=0;i<26;++i) nxt[i]=null;
        cnt=1;
    }
}

public class Solution {
    Trie root=new Trie();
    int n;

    void Insert(String str){
        Trie cur=root,pnew=null;
        for(int i=0;i<str.length();++i){
            int id=str.charAt(i)-'a';
            if(cur.nxt[id]==null){
                pnew=new Trie();
                cur.nxt[id]=pnew;
            }
            else cur.nxt[id].cnt+=1;
            cur=cur.nxt[id];
        }
    }

    String Search(String str){
        Trie cur=root;
        String ans="";
        for(int i=0;i<str.length();++i){
            int id=str.charAt(i)-'a';
            if(cur.nxt[id].cnt==n){
                ans+=str.charAt(i);
            }
            cur=cur.nxt[id];
        }
        return ans;
    }

    public String longestCommonPrefix(String[] strs) {
        n=strs.length;
        if(0==n) return "";
        for(int i=0;i<n;++i) Insert(strs[i]);
        return Search(strs[0]);
    }
}
```

### Python

```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs)==0:
            return ''
        s1=min(strs)
        s2=max(strs)
        ans=''
        for id,val in enumerate(s1):
            if id<len(s2) and s2[id]==val:
                ans+=s1[id]
            else:
                break
        return ans
```

