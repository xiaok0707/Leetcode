class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs)==0:
            return ''
        s1=min(strs)
        s2=max(strs)
        ans=''
        for id,val in enumerate(s1):
            if id<len(s2) and s2[id]==val:
                ans+=s1[id]
            else:
                break
        return ans