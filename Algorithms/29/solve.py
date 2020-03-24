class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend==-0x80000000 and divisor==-1:
            return 0x7fffffff
        flag=-1 if (dividend^divisor)<0 else 1
        a,b=abs(dividend),abs(divisor)
        ans=0
        for i in range(31,-1,-1):
            if (a>>i)>=b:
                ans+=1<<i
                a-=b<<i
        return ans if flag==1 else -ans