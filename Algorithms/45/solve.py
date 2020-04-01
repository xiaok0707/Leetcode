class Solution:
    def jump(self, nums: List[int]) -> int:
        pos,ans,i,n=0,0,0,len(nums)
        while pos<n-1:
            ans+=1
            maxr=0
            while i<=pos:
                maxr=max(nums[i]+i,maxr)
                i+=1
            pos=maxr
        return ans