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