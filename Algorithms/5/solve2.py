class Solution:
    def init(self, s: str) -> str:
        ans='$#'
        for i in range(len(s)):
            ans+=s[i]+'#'
        return ans

    def longestPalindrome(self, string: str) -> str:
        s=self.init(string)
        P=[0 for i in range(len(s))]
        id=mx=0
        for i in range(1,len(s)):
            P[i]=min(P[2*id-i],mx-i) if mx>i else 1
            while i+P[i]<len(s) and s[i+P[i]]==s[i-P[i]]:
                P[i]+=1
            if i+P[i]>mx:
                mx=i+P[i]
                id=i

        pos=maxP=0
        for i in range(len(s)):
            if P[i]>maxP:
                maxP=P[i]
                pos=i
        
        ans=''
        for i in range(pos-maxP+1,pos+maxP):
            if s[i]!='#':
                ans+=s[i]
        return ans