class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        int cnt[26],tot=0;
        unordered_map<string,int> mp;
        vector<vector<string>> ans;
        for(int i=0;i<n;++i){
            memset(cnt,0,sizeof(cnt));
            for(int j=0;j<(int)strs[i].size();++j) ++cnt[strs[i][j]-'a'];
            string tmp="";
            for(int j=0;j<26;++j) tmp+='0'+cnt[j];
            if(!mp[tmp]){
                mp[tmp]=++tot;
                ans.push_back(vector<string>(1,strs[i]));
            }
            else{
                int pos=mp[tmp]-1;
                ans[pos].push_back(strs[i]);
            }
        }
        return ans;
    }
};