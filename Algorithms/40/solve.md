## 思路

先统计每个元素出现的个数，然后搜索+剪枝.

### C++

```c++
class Solution {
public:
    int n,target;
    vector<int> candidates,cnt,val,cur;
    vector<vector<int>> ans;

    void dfs(int pos,int now){
        if(now==target){
            ans.push_back(cur);
            return;
        }
        if(now>target || pos>=n) return;
        dfs(pos+1,now);
        for(int i=1;i<=cnt[pos];++i){
            cur.push_back(val[pos]);
            dfs(pos+1,now+i*val[pos]);
        }
        for(int i=1;i<=cnt[pos];++i) cur.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates=candidates;
        this->target=target;
        this->n=0;
        for(int i=0;i<(int)candidates.size();){
            int j=i;
            while(j<(int)candidates.size() && candidates[j]==candidates[i]) ++j;
            cnt.push_back(j-i);
            val.push_back(candidates[i]);
            n+=1;
            i=j;
        }
        dfs(0,0);
        return ans;
    }
};
```

### Java

```java
class Solution {
    int n,target;
    List<Integer> cnt=new ArrayList<>(),val=new ArrayList<>();
    Deque<Integer> cur=new ArrayDeque<>();
    List<List<Integer>> ans=new ArrayList<>();
    
    public void dfs(int pos,int now){
        if(now==target){
            ans.add(new ArrayList<>(cur));
            return;
        }
        if(now>target || pos>=n) return;
        dfs(pos+1,now);
        for(int i=1;i<=cnt.get(pos);++i){
            cur.addLast(val.get(pos));
            dfs(pos+1,now+i*val.get(pos));
        }
        for(int i=1;i<=cnt.get(pos);++i) cur.removeLast();
    }
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.n=0;
        this.target=target;
        for(int i=0;i<candidates.length;){
            int j=i;
            while(j<candidates.length && candidates[j]==candidates[i]) ++j;
            cnt.add(j-i);
            val.add(candidates[i]);
            this.n+=1;
            i=j;
        }
        dfs(0,0);
        return ans;
    }
}
```

### Python

```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans,cur,cnt,val=[],[],[],[]
        n=0
        i=0
        while i<len(candidates):
            j=i
            while j<len(candidates) and candidates[j]==candidates[i]:j+=1
            cnt.append(j-i)
            val.append(candidates[i])
            n+=1
            i=j

        def dfs(pos,now):
            if now==target:
                ans.append(cur.copy())
                return
            if now>target or pos>=n:return
            dfs(pos+1,now)
            for i in range(1,cnt[pos]+1):
                cur.append(val[pos])
                dfs(pos+1,now+i*val[pos])
            for i in range(1,cnt[pos]+1):cur.pop()

        dfs(0,0)
        return ans
```

