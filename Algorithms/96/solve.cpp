class Solution {
public:
    int numTrees(int n) {
        if(n<=0) return 0;
        int ans=1;
        for(int i=1;i<=n;++i){
            ans=1LL*(4*i-2)*ans/(i+1);
        }
        return ans;
    }
};