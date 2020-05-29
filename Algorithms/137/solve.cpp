class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0,two=0;
        for(int now:nums){
            int newone=~two & (now^one);
            int newtwo=(one & now) | (~one & ~now & two);
            one=newone;
            two=newtwo;
        }
        return one;
    }
};