class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(),ans=0,pos=0,i=0;
        while(pos<n-1){
            ans+=1;
            int maxr=0;
            for(;i<=pos;++i) maxr=max(maxr,i+nums[i]);
            pos=maxr;
        }
        return ans;
    }
};