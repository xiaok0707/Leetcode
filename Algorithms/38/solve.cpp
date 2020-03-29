class Solution {
public:
    string res[35];
    
    string int2str(int x){
        string ans="";
        while(x){
            ans+='0'+x%10;
            x/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    Solution(){
        res[1]="1";
        for(int i=2;i<=30;++i){
            res[i]="";
            string str=res[i-1];
            for(int le=0;le<(int)str.size();){
                int ri=le;
                while(ri<(int)str.size() && str[ri]==str[le]) ++ri;
                res[i]+=int2str(ri-le);
                res[i]+=str[le];
                le=ri;
            }
        }
    }

    string countAndSay(int n) {
        return res[n];
    }
};