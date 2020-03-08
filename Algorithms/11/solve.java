class Solution {
    public int maxArea(int[] height) {
        int n=height.length;
        int le=0,ri=n-1,ans=0;
        while(le<ri){
            ans=Math.max(ans,(ri-le)*Math.min(height[le],height[ri]));
            if(height[le]<height[ri]) ++le;
            else --ri;
        }
        return ans;
    }
}