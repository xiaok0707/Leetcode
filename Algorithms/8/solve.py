class Solution:
    def myAtoi(self, s: str) -> int:
        s=s.lstrip()
        if len(s)==0:
            return 0
        if not s[0].isdigit() and s[0]!='+' and s[0]!='-':
            return 0
        flag=-1 if s[0]=='-' else 1
        pos=0 if s[0].isdigit() else 1
        ans=0
        while pos<len(s) and s[pos].isdigit():
            ans=ans*10+int(s[pos])
            if ans*flag<-0x80000000:
                return -0x80000000
            if ans*flag>0x7fffffff:
                return 0x7fffffff
            pos+=1
        return flag*ans
