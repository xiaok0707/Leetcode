class Solution:
    def grayCode(self, n: int) -> List[int]:
        ans=[0]
        pw=1
        for i in range(n):
            ans.extend([e+pw for e in ans[::-1]])
            pw<<=1
        return ans