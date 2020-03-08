class Solution:
    def maxArea(self, height: List[int]) -> int:
        le=ans=0
        ri=len(height)-1
        while le<ri:
            ans=max(ans,(ri-le)*min(height[le],height[ri]))
            if height[le]<height[ri]:
                le+=1
            else:
                ri-=1
        return ans