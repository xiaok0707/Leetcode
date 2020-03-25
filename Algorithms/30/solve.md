## 思路

最直接的方法是在 s 中遍历所有长度为 words 中单词总长度的子串，然后判断 s 中的每个单词出现的数量和 words 中的是否完全相等.

更好的方法是可以使用滑动窗口，每次在窗口右边新加入一个单词，然后将窗口左边界向后移动，直到窗口中该新单词的数量与 words 中的相同. 每次操作完成之后，如果窗口中单词的数量与 words 中单词的数量相同，即找到了一个符合要求的子串. 这一过程中需要利用哈希来统计单词出现的次数.

### C++

```c++
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};
        int one_len=words[0].size();
        int all_num=words.size();
        unordered_map<string,int> words_map;
        for(int i=0;i<all_num;++i)
            words_map[words[i]]+=1;
        vector<int> ans;
        for(int i=0;i<one_len;++i){
            int cnt=0,le=i,ri=i;
            unordered_map<string,int> cur_map;
            while(ri+one_len<=(int)s.size()){
                string r_word=s.substr(ri,one_len);
                cur_map[r_word]+=1;
                cnt+=1;
                ri+=one_len;
                while(cur_map[r_word]>words_map[r_word]){
                    string l_word=s.substr(le,one_len);
                    cur_map[l_word]-=1;
                    cnt-=1;
                    le+=one_len;
                }
                if(cnt==all_num) ans.push_back(le);
            }
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> ans=new ArrayList<>();
        if(s.isEmpty() || 0==words.length) return ans;
        int one_len=words[0].length();
        int all_num=words.length;
        HashMap<String,Integer> words_map=new HashMap<>();
        for(int i=0;i<all_num;++i)
            words_map.put(words[i],1+words_map.getOrDefault(words[i],0));
        for(int i=0;i<one_len;++i){
            int cnt=0,le=i,ri=i;
            HashMap<String,Integer> cur_map=new HashMap<>();
            while(ri+one_len<=s.length()){
                String r_word=s.substring(ri,ri+one_len);
                cur_map.put(r_word,1+cur_map.getOrDefault(r_word,0));
                cnt+=1;
                ri+=one_len;
                while(cur_map.getOrDefault(r_word,0)>words_map.getOrDefault(r_word,0)){
                    String l_word=s.substring(le,le+one_len);
                    cur_map.put(l_word,cur_map.get(l_word)-1);
                    cnt-=1;
                    le+=one_len;
                }
                if(cnt==all_num) ans.add(le);
            }
        }
        return ans;
    }
}
```

### Python

```python
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:return []
        from collections import Counter
        one_len = len(words[0])
        size=len(words)
        words=Counter(words)
        ans=[]
        for i in range(one_len):
            cnt,le,ri=0,i,i
            cur=Counter()
            while ri+one_len<=len(s):
                r_word=s[ri:ri+one_len]
                cur[r_word]+=1
                cnt+=1
                ri+=one_len
                while cur[r_word]>words[r_word]:
                    l_word=s[le:le+one_len]
                    cur[l_word]-=1
                    cnt-=1
                    le+=one_len
                if cnt==size:
                    ans.append(le)
        return ans
```

