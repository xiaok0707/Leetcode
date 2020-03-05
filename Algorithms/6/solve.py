class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1:
            return s

        L=['' for i in range(numRows)]
        row=0
        down=True
        for i in range(len(s)):
            L[row]+=s[i]
            if down:
                if row+1==numRows:
                    row-=1
                    down=False
                else:
                    row+=1
            else:
                if row==0:
                    row+=1
                    down=True
                else:
                    row-=1

        ans=''
        for i in range(numRows):
            ans+=L[i]
        return ans