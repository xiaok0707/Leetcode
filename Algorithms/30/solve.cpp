class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};
        int one_len=words[0].size();
        int all_num=words.size();
        unordered_map<string,int> words_map;
        for(int i=0;i<all_num;++i)
            words_map[words[i]]+=1;
        vector<int> ans;
        for(int i=0;i<one_len;++i){
            int cnt=0,le=i,ri=i;
            unordered_map<string,int> cur_map;
            while(ri+one_len<=(int)s.size()){
                string r_word=s.substr(ri,one_len);
                cur_map[r_word]+=1;
                cnt+=1;
                ri+=one_len;
                while(cur_map[r_word]>words_map[r_word]){
                    string l_word=s.substr(le,one_len);
                    cur_map[l_word]-=1;
                    cnt-=1;
                    le+=one_len;
                }
                if(cnt==all_num) ans.push_back(le);
            }
        }
        return ans;
    }
};