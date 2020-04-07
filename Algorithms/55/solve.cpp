class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),i=0,pos=0;
        for(int cnt=0;cnt<n;++cnt){
            int maxr=0;
            for(;i<=pos;++i) maxr=max(maxr,i+nums[i]);
            pos=maxr;
            if(pos>=n-1) return true;
        }
        return false;
    }
};