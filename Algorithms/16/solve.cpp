class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=nums[0]+nums[1]+nums[2];
        int len=nums.size();
        sort(nums.begin(),nums.end());
        for(int pos=0;pos<len;++pos){
            if(pos>0 && nums[pos-1]==nums[pos]) continue;
            int le=pos+1,ri=len-1;
            while(le<ri){
                int cur=nums[pos]+nums[le]+nums[ri];
                if(abs(cur-target)<abs(ans-target)) ans=cur;
                if(cur<target) ++le;
                else if(cur>target) --ri;
                else return target;
            }
        }
        return ans;
    }
};