class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        length=len(nums)
        ans=0
        for i in range(length):
            if nums[i]!=val:
                nums[ans]=nums[i]
                ans+=1
        return ans