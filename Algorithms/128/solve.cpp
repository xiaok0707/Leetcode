class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size(),ans=0;
        for(int i=0;i<n;++i) s.insert(nums[i]);
        for(int i=0;i<n;++i){
            if(s.find(nums[i]-1)!=s.end()) continue;
            int len=1,x=nums[i]+1;
            while(s.find(x)!=s.end()){
                len+=1;
                x+=1;
            }
            ans=max(len,ans);
        }
        return ans;
    }
};