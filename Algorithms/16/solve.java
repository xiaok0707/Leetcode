class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int ans=nums[0]+nums[1]+nums[2];
        Arrays.sort(nums);
        int len=nums.length;
        for(int pos=0;pos<len;++pos){
            if(pos>0 && nums[pos-1]==nums[pos]) continue;
            int le=pos+1,ri=len-1;
            while(le<ri){
                int cur=nums[pos]+nums[le]+nums[ri];
                if(Math.abs(cur-target)<Math.abs(ans-target)) ans=cur;
                if(cur<target) ++le;
                else if(cur>target) --ri;
                else return target;
            }
        }
        return ans;
    }
}