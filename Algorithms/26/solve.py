class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        length=len(nums)
        if length==0:
            return 0
        ans=1
        for i in range(1,length):
            if nums[i]!=nums[i-1]:
                nums[ans]=nums[i]
                ans+=1
        return ans
