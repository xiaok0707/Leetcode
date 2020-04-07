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