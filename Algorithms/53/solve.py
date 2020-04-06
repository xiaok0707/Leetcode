class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n=len(nums)
        if 0==n: return 0
        dp,ans=nums[0],nums[0]
        for i in range(1,n):
            if dp>0: dp+=nums[i]
            else: dp=nums[i]
            ans=max(ans,dp)
        return ans