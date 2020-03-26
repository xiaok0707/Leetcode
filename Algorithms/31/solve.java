class Solution {
    public void nextPermutation(int[] nums) {
        int n=nums.length;
        if(n<2) return;
        int i=n-1;
        while(i-1>=0 && nums[i-1]>=nums[i]) --i;
        if(i>0){
            int j=n-1;
            while(nums[i-1]>=nums[j]) --j;
            swap(nums,i-1,j);
        }
        reverse(nums,i);
    }

    public void swap(int[] nums,int i,int j){
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }

    public void reverse(int[] nums,int pos){
        int i=pos,j=nums.length-1;
        while(i<j){
            swap(nums,i,j);
            ++i;
            --j;
        }
    }
}