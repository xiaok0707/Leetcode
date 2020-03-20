class Solution {
    public int removeDuplicates(int[] nums) {
        int len=nums.length;
        if(len==0) return 0;
        int ans=1,pos=1;
        for(int i=1;i<len;++i){
            if(nums[i]!=nums[i-1]){
                nums[pos++]=nums[i];
                ++ans;
            }
        }
        return ans;
    }
}