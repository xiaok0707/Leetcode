class Solution {
    public int firstMissingPositive(int[] nums) {
        int n=nums.length;
        if(n==0) return 1;
        boolean flag=false;
        for(int i=0;i<n;++i){
            if(nums[i]==1) flag=true;
            else if(nums[i]<=0 || nums[i]>n) nums[i]=1;
        }
        if(!flag) return 1;
        
        for(int i=0;i<n;++i){
            int pos=Math.abs(nums[i])%n;
            nums[pos]=nums[pos]<0?nums[pos]:-nums[pos];
        }
        for(int i=1;i<n;++i){
            if(nums[i]>0) return i;
        }
        if(nums[0]>0) return n;
        return n+1;
    }
}