class Solution {
public:
    unordered_map<string,vector<string> > mp;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return {""};
        if(mp.count(s)) return mp[s];
        vector<string> ans;
        for(string word:wordDict){
            int len=word.length();
            if(s.substr(0,len)!=word) continue;
            vector<string> tmp=wordBreak(s.substr(len),wordDict);
            for(string str:tmp){
                ans.push_back(word+(str.length()>0?" ":"")+str);
            }
        }
        return mp[s]=ans;
    }
};