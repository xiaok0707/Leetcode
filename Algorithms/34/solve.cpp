class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.end(),target)){
            int p1=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            int p2=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
            vector<int> ans;
            ans.push_back(p1);
            ans.push_back(p2);
            return ans;
        }
        return vector<int>(2,-1);
    }
};