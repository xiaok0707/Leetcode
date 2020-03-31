class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3) return 0;
        vector<int> le(n,height[0]),ri(n,height[n-1]);
        for(int i=1;i<n;++i) le[i]=max(le[i-1],height[i]);
        for(int i=n-2;i>=0;--i) ri[i]=max(ri[i+1],height[i]);
        int ans=0;
        for(int i=0;i<n;++i) ans+=min(le[i],ri[i])-height[i];
        return ans;
    }
};