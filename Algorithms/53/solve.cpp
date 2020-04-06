class Solution {
public:

    int solve(vector<int>&nums,int le,int ri){
        if(le==ri) return nums[le];
        int mid=(le+ri)>>1;

        int le_maxsum=solve(nums,le,mid);
        int ri_maxsum=solve(nums,mid+1,ri);
        
        int le_sum=0,le_max=INT_MIN;
        for(int i=mid;i>=le;--i){
            le_sum+=nums[i];
            le_max=max(le_max,le_sum);
        }
        int ri_sum=0,ri_max=INT_MIN;
        for(int i=mid+1;i<=ri;++i){
            ri_sum+=nums[i];
            ri_max=max(ri_max,ri_sum);
        }
        int mid_maxsum=le_max+ri_max;

        return max(max(le_maxsum,ri_maxsum),mid_maxsum);
    }

    int maxSubArray(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};