class Solution:
    def reverse(self, x: int) -> int:
        flag=-1 if x<0 else 1
        ans=0
        y=x*flag
        while y>0:
            ans=ans*10+y%10
            y//=10
        ans*=flag
        if ans<-0x80000000 or ans>0x7fffffff:
            return 0
        return ans