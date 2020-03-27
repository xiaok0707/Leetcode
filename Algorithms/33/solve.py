class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n=len(nums)
        if 0==n:return -1
        if 1==n:return 0 if nums[0]==target else -1
        if nums[0]<nums[n-1]:
            le,ri=0,n
            while le+1<ri:
                mid=(le+ri)//2
                if nums[mid]<=target:le=mid
                else:ri=mid
            return le if nums[le]==target else -1
        le,ri=0,n-1
        while le<ri:
            mid=(le+ri)//2
            if nums[mid]>nums[le]:le=mid
            else:ri=mid
        if target>=nums[0]:
            pl,pr=0,le+1
            while pl+1<pr:
                pmid=(pl+pr)//2
                if nums[pmid]<=target:pl=pmid
                else:pr=pmid
            return pl if nums[pl]==target else -1
        else:
            pl,pr=ri,n
            while pl+1<pr:
                pmid=(pl+pr)//2
                if nums[pmid]<=target:pl=pmid
                else:pr=pmid
            return pl if nums[pl]==target else -1