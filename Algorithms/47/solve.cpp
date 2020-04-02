class Solution {
public:
    int n;
    vector<int> nums,used,cur;
    vector<vector<int>> ans;
    
    void dfs(int pos){
        if(pos==n){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<n;++i){
            if(!used[i]){
                if(i>0 && !used[i-1] && nums[i-1]==nums[i]) continue;
                used[i]=1;
                cur.push_back(nums[i]);
                dfs(pos+1);
                used[i]=0;
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->n=nums.size();
        sort(nums.begin(),nums.end());
        this->nums=nums;
        this->used=vector<int>(n,0);
        dfs(0);
        return ans;
    }
};