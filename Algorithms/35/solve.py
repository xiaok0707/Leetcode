class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        return self.upper_bound(nums,target-1)
        
    def upper_bound(self, nums: List[int], target: int) -> int:
        if not len(nums) or nums[0]>target:return 0
        le,ri=0,len(nums)
        while le+1<ri:
            mid=(le+ri)//2
            if nums[mid]<=target:le=mid
            else:ri=mid
        return ri