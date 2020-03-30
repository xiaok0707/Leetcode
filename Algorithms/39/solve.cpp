class Solution {
public:
    int n,target;
    vector<vector<int>> ans;
    vector<int> candidates,v;

    void dfs(int start,int now){
        if(now==target){
            ans.push_back(v);
            return;
        }
        if(now>target) return;
        for(int i=start;i<n;++i){
            v.push_back(candidates[i]);
            dfs(i,now+candidates[i]);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->n=candidates.size();
        this->target=target;
        this->candidates=candidates;
        dfs(0,0);
        return ans;
    }
};