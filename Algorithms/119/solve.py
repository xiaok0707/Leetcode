class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        C=[1]
        for i in range(1,rowIndex+1):
            now=C[i-1]*(rowIndex-i+1)//i
            C.append(now)
        return C