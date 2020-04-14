class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n,m,c0,inf=len(matrix),len(matrix[0]),0,2**30
        for i in range(n):
            for j in range(m):
                if matrix[i][j]==0:
                    matrix[i][0]=inf
                    if j: matrix[0][j]=inf
                    else: c0=inf
        for i in range(1,n):
            if inf==matrix[i][0]:
                for j in range(m):
                    matrix[i][j]=0
        for j in range(1,m):
            if inf==matrix[0][j]:
                for i in range(n):
                    matrix[i][j]=0
        if matrix[0][0]==inf:
            for j in range(m): matrix[0][j]=0
        if c0==inf:
            for i in range(n): matrix[i][0]=0