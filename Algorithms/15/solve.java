class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans=new LinkedList<>();
        ans.clear();
        int len=nums.length;
        Arrays.sort(nums);

        for(int pos=0;pos<len;++pos){
            if(nums[pos]>0) break;
            if(pos>0 && nums[pos-1]==nums[pos]) continue;
            int val=-nums[pos];
            int le=pos+1,ri=len-1;
            while(le<ri){
                if(nums[le]+nums[ri]==val){
                    List<Integer> e=new LinkedList<>();
                    e.add(nums[pos]);
                    e.add(nums[le]);
                    e.add(nums[ri]);
                    ans.add(e);
                    while(le<ri && nums[le+1]==nums[le]) ++le;
                    ++le;
                    while(le<ri && nums[ri-1]==nums[ri]) --ri;
                    --ri;
                }
                else{
                    if(nums[le]+nums[ri]<val) ++le;
                    else --ri;
                }
            }
        }
        return ans;
    }
}