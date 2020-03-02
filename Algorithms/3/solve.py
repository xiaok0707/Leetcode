class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans=i=j=0
        L=len(s)
        d={}
        while i<L and j<L:
            while j<L and (None==d.get(s[j]) or False==d.get(s[j])):
                d[s[j]]=True
                j+=1
            if j-i>ans:
                ans=j-i
            if j<L:
                while s[i]!=s[j]:
                    d[s[i]]=False
                    i+=1
                d[s[i]]=False
                i+=1
        return ans