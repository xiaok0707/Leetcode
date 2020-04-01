class Solution {
    public int jump(int[] nums) {
        int ans=0,pos=0,i=0,n=nums.length;
        while(pos<n-1){
            ans+=1;
            int maxr=0;
            for(;i<=pos;++i) maxr=Math.max(maxr,i+nums[i]);
            pos=maxr;
        }
        return ans;
    }
}