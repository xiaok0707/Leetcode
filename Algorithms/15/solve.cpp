class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len=nums.size();
        sort(nums.begin(),nums.end());
        if(len<3 || nums[0]>0 || nums[len-1]<0) return {};
        for(int pos=0;pos<len;++pos){
            if(nums[pos]>0) break;
            if(pos>0 && nums[pos-1]==nums[pos]) continue;
            int val=-nums[pos];
            int le=pos+1,ri=len-1;
            while(le<ri){
                if(nums[le]+nums[ri]==val){
                    ans.push_back({nums[pos],nums[le],nums[ri]});
                    while(le<ri && nums[le+1]==nums[le]) ++le;
                    while(le<ri && nums[ri-1]==nums[ri]) --ri;
                    ++le;--ri;
                }
                else{
                    if(nums[le]+nums[ri]<val) ++le;
                    else --ri;
                }
            }
        }
        return ans;
    }
};