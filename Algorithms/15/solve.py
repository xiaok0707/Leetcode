class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans=[]
        list.sort(nums)
        L=len(nums)
        for pos in range(L):
            if nums[pos]>0:
                break
            if pos>0 and nums[pos]==nums[pos-1]:
                continue
            val=-nums[pos]
            le=pos+1
            ri=L-1
            while le<ri:
                if nums[le]+nums[ri]==val:
                    ans.append([nums[pos],nums[le],nums[ri]])
                    while le<ri and nums[le+1]==nums[le]:
                        le+=1
                    while le<ri and nums[ri-1]==nums[ri]:
                        ri-=1
                    le+=1
                    ri-=1
                else:
                    if nums[le]+nums[ri]<val:
                        le+=1
                    else:
                        ri-=1
        return ans