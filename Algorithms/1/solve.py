class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n=len(nums)
        d={}
        for i in range(0,n):
            if target-nums[i] in d and i!=d[target-nums[i]]:
                return [i,d[target-nums[i]]]
            d[nums[i]]=i