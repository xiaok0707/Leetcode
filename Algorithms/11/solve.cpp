class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int le=0,ri=n-1,ans=0;
        while(le<ri){
            ans=max(ans,(ri-le)*min(height[le],height[ri]));
            if(height[le]<height[ri]) ++le;
            else --ri;
        }
        return ans;
    }
};