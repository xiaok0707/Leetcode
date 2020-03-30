## 思路

搜索+剪枝，注意去重.

### C++

```c++
class Solution {
public:
    int n,target;
    vector<vector<int>> ans;
    vector<int> candidates,v;

    void dfs(int start,int now){
        if(now==target){
            ans.push_back(v);
            return;
        }
        if(now>target) return;
        for(int i=start;i<n;++i){
            v.push_back(candidates[i]);
            dfs(i,now+candidates[i]);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->n=candidates.size();
        this->target=target;
        this->candidates=candidates;
        dfs(0,0);
        return ans;
    }
};
```

### Java

```java
class Solution {
    int n,target;
    int[] candidates;
    List<List<Integer>> ans=new ArrayList<>();
    Deque<Integer> v=new LinkedList<>();

    public void dfs(int start,int now){
        if(now==target){
            ans.add(new ArrayList<>(v));
            return;
        }
        if(now>target) return;
        for(int i=start;i<n;++i){
            v.addLast(candidates[i]);
            dfs(i,now+candidates[i]);
            v.removeLast();
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates=candidates;
        this.n=candidates.length;
        this.target=target;
        dfs(0,0);
        return ans;
    }
}
```

### Python

```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        v,ans=[],[]

        def dfs(start,now):
            if now==target:
                ans.append(v[:])
                return
            if now>target:return 
            for i in range(start,len(candidates)):
                v.append(candidates[i])
                dfs(i,now+candidates[i])
                v.pop()
            
        dfs(0,0)
        return ans
```

