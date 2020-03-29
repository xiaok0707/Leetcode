class Solution:
    def countAndSay(self, n: int) -> str:
        res=['' for i in range(n)]
        res[0]='1'
        for i in range(1,n):
            s=res[i-1]
            le=0
            while le<len(s):
                ri=le
                while ri<len(s) and s[le]==s[ri]:ri+=1
                res[i]+=str(ri-le)
                res[i]+=s[le]
                le=ri
        return res[n-1]