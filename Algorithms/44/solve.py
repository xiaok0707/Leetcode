class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n,m=len(s),len(p)
        i,j,istar,jstar=0,0,-1,-1
        while i<n:
            if j<m and (s[i]==p[j] or '?'==p[j]):
                i+=1
                j+=1
            elif j<m and '*'==p[j]:
                istar=i
                jstar=j
                j+=1
            elif istar>=0:
                istar+=1
                i=istar
                j=jstar+1
            else:return False
        while j<m and p[j]=='*':j+=1
        return j==m