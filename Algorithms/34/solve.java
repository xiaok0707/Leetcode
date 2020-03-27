class Solution {
    public int[] searchRange(int[] nums, int target) {
        int n=nums.length;
        if(0==n) return new int[]{-1,-1};
        int p1=upper_bound(nums,target-1);
        int p2=upper_bound(nums,target);
        if(p1<n && nums[p1]==target) return new int[]{p1,p2-1};
        else return new int[]{-1,-1};
    }

    public int upper_bound(int[] nums,int target) {
        if(target<nums[0]) return 0;
        int le=0,ri=nums.length;
        while(le+1<ri){
            int mid=(le+ri)>>1;
            if(nums[mid]<=target) le=mid;
            else ri=mid;
        }
        return ri;
    }
}