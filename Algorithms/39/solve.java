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