class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size(),i=0,j=0,ans=0;
        unordered_map<char,bool> vis;
        while(j<len){
            while(j<len && !vis[s[j]]) vis[s[j++]]=true;
            if(j-i>ans) ans=j-i;
            while(j<len && s[i]!=s[j]) vis[s[i++]]=false; 
            if(j<len) vis[s[i++]]=false;
        }
        return ans;
    }
};