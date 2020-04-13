class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0,n=words.size();
        vector<string> ans;
        while(i<n){
            int j=i,len=0,cnt=0;
            while(j<n && len+(int)words[j].size()+cnt<=maxWidth){
                len+=(int)words[j].size();
                cnt+=1;
                ++j;
            }
            if(j<n){
                if(cnt==1){
                    string str=words[i];
                    while((int)str.length()<maxWidth) str+=" ";
                    ans.push_back(str);
                }
                else{
                    string str="";
                    int len_short=(maxWidth-len)/(cnt-1),len_long=len_short+1;
                    int cnt_long=(maxWidth-len)%(cnt-1),cnt_short=(cnt-1)-cnt_long;
                    int id=i;
                    for(int k=0;k<cnt_long;++k){
                        str+=words[id++];
                        for(int p=0;p<len_long;++p) str+=" ";
                    }
                    for(int k=0;k<cnt_short;++k){
                        str+=words[id++];
                        for(int p=0;p<len_short;++p) str+=" ";
                    }
                    str+=words[id];
                    ans.push_back(str);
                }
            }
            else{
                string str="";
                int id=i;
                while(id<n){
                    str+=words[id];
                    if(id+1<n) str+=" ";
                    ++id;
                }
                while((int)str.length()<maxWidth) str+=" ";
                ans.push_back(str);
            }
            i=j;
        }
        return ans;
    }
};