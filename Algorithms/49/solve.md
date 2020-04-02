## 思路

统计每个单词中个字母出现的次数，以此作为哈希键值对单词分类.

### C++

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        int cnt[26],tot=0;
        unordered_map<string,int> mp;
        vector<vector<string>> ans;
        for(int i=0;i<n;++i){
            memset(cnt,0,sizeof(cnt));
            for(int j=0;j<(int)strs[i].size();++j) ++cnt[strs[i][j]-'a'];
            string tmp="";
            for(int j=0;j<26;++j) tmp+='0'+cnt[j];
            if(!mp[tmp]){
                mp[tmp]=++tot;
                ans.push_back(vector<string>(1,strs[i]));
            }
            else{
                int pos=mp[tmp]-1;
                ans[pos].push_back(strs[i]);
            }
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0) return new ArrayList();
        Map<String, List> ans = new HashMap<String, List>();
        int[] count = new int[26];
        for (String s : strs) {
            Arrays.fill(count, 0);
            for (char c : s.toCharArray()) count[c - 'a']++;
            StringBuilder sb = new StringBuilder("");
            for (int i = 0; i < 26; i++) {
                sb.append(String.valueOf(count[i]));
            }
            String key = sb.toString();
            if (!ans.containsKey(key)) ans.put(key, new ArrayList());
            ans.get(key).add(s);
        }
        return new ArrayList(ans.values());
    }
}
```

### Python

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d={}
        for s in strs:
            cnt=[0]*26
            for ch in s:cnt[ord(ch)-ord('a')]+=1
            if d.get(tuple(cnt))!=None:
                d[tuple(cnt)].append(s)
            else:
                d[tuple(cnt)]=[s]
        return list(d.values())
```

