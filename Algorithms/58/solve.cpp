class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0,n=s.length(),i=n-1;
        while(i>=0 && s[i]==' ') --i;
        for(;i>=0;--i){
            if(s[i]!=' ') ++ans;
            else break;
        }
        return ans;
    }
};