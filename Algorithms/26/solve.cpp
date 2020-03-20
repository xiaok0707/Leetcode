class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans=1,pos=1,len=nums.size();
        for(int i=1;i<len;++i){
            if(nums[i]!=nums[i-1]){
                ++ans;
                nums[pos++]=nums[i];
            }
        }
        return ans;
    }
};