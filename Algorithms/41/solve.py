class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if not 1 in nums:return 1
        n=len(nums)
        for i in range(n):
            if nums[i]<=0 or nums[i]>n:nums[i]=1
        for i in range(n):
            pos=abs(nums[i])%n
            if nums[pos]>0: nums[pos]=-nums[pos]
        for i in range(1,n):
            if nums[i]>0:return i
        if nums[0]>0:return n
        return n+1