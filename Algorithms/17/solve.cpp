class Solution {
public:
    string str[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"},digits,cur;
    int len;
    vector<string> ans;

    void dfs(int pos){
        if(pos==len){
            ans.push_back(cur);
            return;
        }
        int id=digits[pos]-'0';
        for(int i=0;i<(int)str[id].length();++i){
            cur.push_back(str[id][i]);
            dfs(pos+1);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        this->digits=digits;
        len=digits.length();
        if(!len) return {};
        ans.clear();
        cur.clear();
        dfs(0);
        return ans;
    }
};