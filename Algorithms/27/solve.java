class Solution {
    public int removeElement(int[] nums, int val) {
        int ans=0,len=nums.length;
        for(int i=0;i<len;++i){
            if(nums[i]!=val)
                nums[ans++]=nums[i];
        }
        return ans;
    }
}