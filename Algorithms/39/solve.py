class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        v,ans=[],[]

        def dfs(start,now):
            if now==target:
                ans.append(v[:])
                return
            if now>target:return 
            for i in range(start,len(candidates)):
                v.append(candidates[i])
                dfs(i,now+candidates[i])
                v.pop()
            
        dfs(0,0)
        return ans