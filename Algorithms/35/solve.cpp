class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos=upper_bound(nums.begin(),nums.end(),target-1)-nums.begin();
        return pos;
    }
};