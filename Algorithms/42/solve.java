class Solution {
    public int trap(int[] height) {
        int n=height.length;
        int ans=0,le_max=0,ri_max=0,le=0,ri=n-1;
        while(le<ri){
            if(height[le]<height[ri]){
                if(height[le]>le_max) le_max=height[le];
                ans+=le_max-height[le];
                le+=1;
            }
            else{
                if(height[ri]>ri_max) ri_max=height[ri];
                ans+=ri_max-height[ri];
                ri-=1;
            }
        }
        return ans;
    }
}