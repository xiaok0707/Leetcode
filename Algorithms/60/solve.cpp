const int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};

class Solution {
public:
    string getPermutation(int n, int k) {
        k-=1;
        string ans="";
        vector<bool> used(n+1,false);
        for(int i=1;i<=n;++i){
            int num=k/fac[n-i]+1;
            k%=fac[n-i];
            int cnt=0;
            for(int j=1;j<=n;++j){
                if(!used[j]){
                    ++cnt;
                    if(cnt==num){
                        used[j]=true;
                        ans+='0'+j;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};