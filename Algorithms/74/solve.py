class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix)==0: return False
        n,m=len(matrix),len(matrix[0])
        r,c=0,m-1
        while r<n and c>=0:
            if matrix[r][c]==target: return True
            elif matrix[r][c]<target: r+=1
            else: c-=1
        return False