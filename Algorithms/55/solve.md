## 思路

可以和 [LeetCode 45](https://leetcode-cn.com/problems/jump-game-ii) 用一样的思路，贪心地计算跳 i 步最远能到达的位置，如果跳 n 步都无法到达终点，则终点不可达.

### C++

```python
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),i=0,pos=0;
        for(int cnt=0;cnt<n;++cnt){
            int maxr=0;
            for(;i<=pos;++i) maxr=max(maxr,i+nums[i]);
            pos=maxr;
            if(pos>=n-1) return true;
        }
        return false;
    }
};
```

把每个位置抽象成有向图结点，从位置 0 开始搜索，判断终点是否可达.

### Java

```java
class Solution {
    boolean ok[];
    int n,nums[];

    public void dfs(int u){
        if(ok[u]) return;
        ok[u]=true;
        for(int i=1;i<=nums[u];++i){
            if(u+i<n) dfs(u+i);
        }
    }

    public boolean canJump(int[] nums) {
        this.n=nums.length;
        this.nums=nums;
        ok=new boolean[n];
        Arrays.fill(ok,false);
        dfs(0);
        return ok[n-1];
    }
}
```

