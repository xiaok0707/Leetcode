class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans=[]
        length=len(nums)
        list.sort(nums)
        for pos1 in range(length):
            if pos1>0 and nums[pos1-1]==nums[pos1]:
                continue
            for pos2 in range(pos1+1,length):
                if pos2>pos1+1 and nums[pos2-1]==nums[pos2]:
                    continue
                le=pos2+1
                ri=length-1
                while le<ri:
                    cur=nums[pos1]+nums[pos2]+nums[le]+nums[ri]
                    if cur==target:
                        ans.append([nums[pos1],nums[pos2],nums[le],nums[ri]])
                        while le<ri and nums[le+1]==nums[le]:
                            le+=1
                        while le<ri and nums[ri-1]==nums[ri]:
                            ri-=1
                        le+=1
                        ri-=1
                    elif cur<target:
                        le+=1
                    else:
                        ri-=1
        return ans