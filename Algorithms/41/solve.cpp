class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int maxval=1,n=nums.size();
        for(int i=0;i<n;++i){
            maxval=max(maxval,nums[i]);
            mp[nums[i]]=true;
        }
        int ans=1;
        for(int i=1;i<=n+1;++i){
            if(!mp[i]){
                ans=i;
                break;
            }
        }
        return ans;
    }
};