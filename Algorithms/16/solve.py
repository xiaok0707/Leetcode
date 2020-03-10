class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans=sum(nums[0:3])
        L=len(nums)
        list.sort(nums)
        for pos in range(L):
            if pos>0 and nums[pos-1]==nums[pos]:
                continue
            le=pos+1
            ri=L-1
            while le<ri:
                cur=nums[pos]+nums[le]+nums[ri]
                if abs(cur-target)<abs(ans-target):
                    ans=cur
                if cur<target:
                    le+=1
                elif cur>target:
                    ri-=1
                else:
                    return target
        return ans