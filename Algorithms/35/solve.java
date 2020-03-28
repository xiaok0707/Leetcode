class Solution {
    public int searchInsert(int[] nums, int target) {
        return upper_bound(nums,target-1);
    }

    public int upper_bound(int[] nums, int target) {
        if(nums.length==0 || nums[0]>target) return 0;
        int le=0,ri=nums.length;
        while(le+1<ri){
            int mid=(le+ri)>>1;
            if(nums[mid]<=target) le=mid;
            else ri=mid;
        }
        return ri;
    }
}