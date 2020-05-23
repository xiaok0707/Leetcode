class Solution:
    def candy(self, ratings: List[int]) -> int:
        n=len(ratings)
        le,ri=[1]*n,[1]*n
        for i in range(1,n):
            if ratings[i]>ratings[i-1]:
                le[i]=le[i-1]+1
        for i in range(n-2,-1,-1):
            if ratings[i]>ratings[i+1]:
                ri[i]=ri[i+1]+1
        
        ans=0
        for i in range(n):
            ans+=max(le[i],ri[i])
        return ans