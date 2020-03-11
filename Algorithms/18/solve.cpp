class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int len=nums.size();
        sort(nums.begin(),nums.end());
        for(int pos1=0;pos1<len;++pos1){
            if(pos1 && nums[pos1-1]==nums[pos1]) continue;
            for(int pos2=pos1+1;pos2<len;++pos2){
                if(pos2>pos1+1 && nums[pos2-1]==nums[pos2]) continue;
                int le=pos2+1,ri=len-1;
                while(le<ri){
                    int cur=nums[pos1]+nums[pos2]+nums[le]+nums[ri];
                    if(cur==target){
                        ans.push_back({nums[pos1],nums[pos2],nums[le],nums[ri]});
                        while(le<ri && nums[le+1]==nums[le]) ++le;
                        while(le<ri && nums[ri-1]==nums[ri]) --ri;
                        ++le;--ri;
                    }
                    else
                        cur<target?++le:--ri;
                }
            }
        }
        return ans;
    }
};