## 思路

用双指针模拟，右边的指针指向某字符第一次重复出现的位置，更新答案，然后将左边的指针移动到左边重复字符的后一位置，重复这一过程。

时间复杂度 $O(n)$

### C++

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size(),i=0,j=0,ans=0;
        unordered_map<char,bool> vis;
        while(j<len){
            while(j<len && !vis[s[j]]) vis[s[j++]]=true;
            if(j-i>ans) ans=j-i;
            while(j<len && s[i]!=s[j]) vis[s[i++]]=false; 
            if(j<len) vis[s[i++]]=false;
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int i=0,j=0,ans=0,len=s.length();
        Map<Character,Boolean> vis=new HashMap<>();
        vis.clear();
        for(char ch:s.toCharArray()) vis.put(ch,false);
        while(i<len && j<len){
            while(j<len && !vis.get(s.charAt(j))){
                vis.put(s.charAt(j),true);
                ++j;
            }
            ans=Math.max(ans,j-i);
            if(j<len){
                while(s.charAt(i)!=s.charAt(j)){
                    vis.put(s.charAt(i),false);
                    ++i;
                }
                vis.put(s.charAt(i),false);
                ++i;
            }
        }
        return ans;
    }
}
```

### Python

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans=i=j=0
        L=len(s)
        d={}
        while i<L and j<L:
            while j<L and (None==d.get(s[j]) or False==d.get(s[j])):
                d[s[j]]=True
                j+=1
            if j-i>ans:
                ans=j-i
            if j<L:
                while s[i]!=s[j]:
                    d[s[i]]=False
                    i+=1
                d[s[i]]=False
                i+=1
        return ans
```

