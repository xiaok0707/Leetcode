class Solution {
public:
    int n,target;
    vector<int> candidates,cnt,val,cur;
    vector<vector<int>> ans;

    void dfs(int pos,int now){
        if(now==target){
            ans.push_back(cur);
            return;
        }
        if(now>target || pos>=n) return;
        dfs(pos+1,now);
        for(int i=1;i<=cnt[pos];++i){
            cur.push_back(val[pos]);
            dfs(pos+1,now+i*val[pos]);
        }
        for(int i=1;i<=cnt[pos];++i) cur.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates=candidates;
        this->target=target;
        this->n=0;
        for(int i=0;i<(int)candidates.size();){
            int j=i;
            while(j<(int)candidates.size() && candidates[j]==candidates[i]) ++j;
            cnt.push_back(j-i);
            val.push_back(candidates[i]);
            n+=1;
            i=j;
        }
        dfs(0,0);
        return ans;
    }
};