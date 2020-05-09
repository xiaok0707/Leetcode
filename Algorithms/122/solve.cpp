class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0,j,ans=0;
        while(i+1<n){
            j=i+1;
            if(prices[j]<=prices[i]){
                i+=1;
                continue;
            }
            while(j+1<n && prices[j]<prices[j+1]) j+=1;
            ans+=prices[j]-prices[i];
            i=j+1;
        }
        return ans;
    }
};