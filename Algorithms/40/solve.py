class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans,cur,cnt,val=[],[],[],[]
        n=0
        i=0
        while i<len(candidates):
            j=i
            while j<len(candidates) and candidates[j]==candidates[i]:j+=1
            cnt.append(j-i)
            val.append(candidates[i])
            n+=1
            i=j

        def dfs(pos,now):
            if now==target:
                ans.append(cur.copy())
                return
            if now>target or pos>=n:return
            dfs(pos+1,now)
            for i in range(1,cnt[pos]+1):
                cur.append(val[pos])
                dfs(pos+1,now+i*val[pos])
            for i in range(1,cnt[pos]+1):cur.pop()

        dfs(0,0)
        return ans