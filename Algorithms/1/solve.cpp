class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<(int)nums.size();++i) mp[nums[i]]=i+1;
        for(int i=0;i<(int)nums.size();++i){
            if(mp[target-nums[i]] && mp[target-nums[i]]!=i+1){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]-1);
                break;
            }
        }
        return ans;
    }
};