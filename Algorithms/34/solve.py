class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n=len(nums)
        if 0==n:return [-1,-1]
        p1=self.upper_bound(nums,target-1)
        p2=self.upper_bound(nums,target)
        if p1<n and nums[p1]==target:return [p1,p2-1]
        else:return [-1,-1]
    
    def upper_bound(self, nums: List[int], target: int) -> int:
        if nums[0]>target:return 0
        le,ri=0,len(nums)
        while le+1<ri:
            mid=(le+ri)//2
            if nums[mid]<=target:le=mid
            else:ri=mid
        return ri