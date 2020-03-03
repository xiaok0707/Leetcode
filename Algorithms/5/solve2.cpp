class Solution {
public:
    const static int N=1050;
    int P[N<<1];//数组开两倍

    string init(string s){//预处理，填充分隔符
        string ans="$#";
        for(int i=0;i<(int)s.size();++i){
            ans+=s[i];
            ans+="#";
        }
        return ans;
    }

    string longestPalindrome(string str) {
        string s=init(str);
        int id=0,mx=0;
        memset(P,0,sizeof(P));
        for(int i=1;s[i];++i){//计算P[i]
            P[i]=mx>i?min(P[2*id-i],mx-i):1;
            while(s[i+P[i]]==s[i-P[i]]) ++P[i];
            if(i+P[i]>mx){
                mx=i+P[i];
                id=i;
            }
        }
        //找P[i]的最大值，取出对应的回文串
        int pos=0,MaxP=0;
        for(int i=1;i<(int)s.size();++i){
            if(P[i]>MaxP){
                MaxP=P[i];
                pos=i;
            }
        }
        string ans="";
        for(int i=pos-P[pos]+1;i<=pos+P[pos]-1;++i){
            if(s[i]!='#') ans+=s[i];
        }
        return ans;
    }
};