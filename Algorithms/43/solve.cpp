class Solution {
public:
    string multiply(string num1, string num2) {
        int len1=num1.length(),len2=num2.length();
        vector<int> a,b,ans(len1+len2,0);
        for(int i=len1-1;i>=0;--i) a.push_back(num1[i]-'0');
        for(int i=len2-1;i>=0;--i) b.push_back(num2[i]-'0');
        for(int i=0;i<len1;++i){
            for(int j=0;j<len2;++j){
                ans[i+j]+=a[i]*b[j];
            }
        }
        int carry=0;
        for(int i=0;i<len1+len2;++i){
            int tmp=ans[i]+carry;
            carry=tmp/10;
            ans[i]=tmp%10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry/=10;
        }
        string res="";
        int i=ans.size()-1;
        while(i>=0 && ans[i]==0) --i;
        for(;i>=0;--i) res+='0'+ans[i];
        if(res=="") res="0";
        return res;
    }
};