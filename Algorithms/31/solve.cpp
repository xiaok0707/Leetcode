class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return;
        int pos=n-1;
        while(pos-1>=0 && nums[pos-1]>=nums[pos]) --pos;
        if(!pos){
            sort(nums.begin(),nums.end());
            return;
        }
        int pos2=n-1;
        while(nums[pos2]<=nums[pos-1]) --pos2;
        swap(nums[pos-1],nums[pos2]);
        sort(nums.begin()+pos,nums.end());
    }
};