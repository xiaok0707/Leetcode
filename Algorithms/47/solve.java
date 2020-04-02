class Solution {
    int n,nums[];
    List<List<Integer>> ans=new ArrayList<>();

    public void swap(int i,int j){
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }

    public void dfs(int pos){
        if(pos+1==n){
            List<Integer> e=new ArrayList<>();
            for(int i=0;i<n;++i) e.add(nums[i]);
            ans.add(e);
            return;
        }
        HashMap<Integer,Boolean> mp=new HashMap<>();
        for(int i=pos;i<n;++i){
            swap(pos,i);
            if(!mp.getOrDefault(nums[pos],false)){
                mp.put(nums[pos],true);
                dfs(pos+1);
            }
            swap(pos,i);
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        this.n=nums.length;
        this.nums=nums;
        dfs(0);
        return ans;
    }
}