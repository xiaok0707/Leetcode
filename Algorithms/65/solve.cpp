class Solution {
public:
    const int dfa[10][6]={
        { 1,-1, 2, 3, 0,-1 },
        { 1, 5,-1, 4, 9,-1 },
        { 1,-1,-1, 3,-1,-1 },
        { 6,-1,-1,-1,-1,-1 },
        { 6, 5,-1,-1, 9,-1 },
        { 8,-1, 7,-1,-1,-1 },
        { 6, 5,-1,-1, 9,-1 },
        { 8,-1,-1,-1,-1,-1 },
        { 8,-1,-1,-1, 9,-1 },
        {-1,-1,-1,-1, 9,-1 }
    };

    int getid(char ch){
        if(ch>='0' && ch<='9') return 0;
        if(ch=='e') return 1;
        if(ch=='+' || ch=='-') return 2;
        if(ch=='.') return 3;
        if(ch==' ') return 4;
        return 5;
    }

    bool isNumber(string s) {
        int cur=0;
        for(int i=0;i<(int)s.length();++i){
            int id=getid(s[i]);
            cur=dfa[cur][id];
            if(cur<0) return false;
        }
        return cur==1 || cur==4 || cur==6 || cur==8 || cur==9;
    }
};