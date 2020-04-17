class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(!n) return false;
        int le=0,ri=n-1;
        while(le<=ri){
            int mid=(le+ri)>>1;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[le]){
                ++le;
                continue;
            }
            if(nums[mid]>nums[le]){//[le,mid]有序
                if(target>=nums[le] && target<nums[mid]){
                    ri=mid-1;
                }
                else{
                    le=mid+1;
                }
            }
            else{//[mid,ri]有序
                if(target>nums[mid] && target<=nums[n-1]){
                    le=mid+1;
                }
                else{
                    ri=mid-1;
                }
            }
        }
        return false;
    }
};