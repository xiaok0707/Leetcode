def nextPermutation(nums: List[int]) -> bool:
    n=len(nums)
    if n<2: return False
    i=n-2
    while i>=0 and nums[i]>=nums[i+1]: i-=1
    if i<0: return False
    if i>=0:
        j=n-1
        while nums[i]>=nums[j]: j-=1
        nums[i],nums[j]=nums[j],nums[i]
    nums[i+1:]=[nums[x] for x in range(n-1,i,-1)]
    return True

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans=[nums[:]]
        print(nums)
        while nextPermutation(nums):
            ans.append(nums[:])
            print(nums)
        return ans