class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        int len=str.length(),pos=0;
        while(pos<len && str[pos]==' ') pos+=1;
        if(pos==len) return 0;
        if(str[pos]=='+' || str[pos]=='-'){
            int flag=str[pos]=='+'?1:-1;
            pos+=1;
            if(pos==len || str[pos]<'0' || str[pos]>'9') return 0;
            long long ans=0;
            while(pos<len && str[pos]>='0' && str[pos]<='9'){
                ans=ans*10+(str[pos]-'0');
                if(ans*flag<INT_MIN) return INT_MIN;
                if(ans*flag>INT_MAX) return INT_MAX; 
                pos+=1;
            }
            return ans*flag;
        }
        else if('0'<=str[pos] && str[pos]<='9'){
            long long ans=0;
            while(pos<len && str[pos]>='0' && str[pos]<='9'){
                ans=ans*10+(str[pos]-'0');
                if(ans>INT_MAX) return INT_MAX; 
                pos+=1;
            }
            return ans;
        }
        else return 0;
    }
};