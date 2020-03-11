class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans=new ArrayList<>();
        Arrays.sort(nums);
        int len=nums.length;
        for(int pos1=0;pos1<len;++pos1){
            if(pos1>0 && nums[pos1-1]==nums[pos1]) continue;
            for(int pos2=pos1+1;pos2<len;++pos2){
                if(pos2>pos1+1 && nums[pos2-1]==nums[pos2]) continue;
                int le=pos2+1,ri=len-1;
                while(le<ri){
                    int cur=nums[pos1]+nums[pos2]+nums[le]+nums[ri];
                    if(cur==target){
                        List<Integer> e=new ArrayList<>();
                        e.add(nums[pos1]);
                        e.add(nums[pos2]);
                        e.add(nums[le]);
                        e.add(nums[ri]);
                        ans.add(e);
                        while(le<ri && nums[le+1]==nums[le]) ++le;
                        while(le<ri && nums[ri-1]==nums[ri]) --ri;
                        ++le;--ri;
                    }
                    else{
                        if(cur<target) ++le;
                        else --ri;
                    }
                }
            }
        }
        return ans;
    }
}