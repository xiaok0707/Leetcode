class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix)
        start_row,start_col,end_row,end_col=0,0,n-1,n-1
        while start_row<=end_row:
            for col in range(start_col,end_col):
                i,j=start_row,col
                tmp=matrix[i][j]
                for cnt in range(3):
                    newi,newj=n-1-j,i
                    matrix[i][j]=matrix[newi][newj]
                    i,j=newi,newj
                matrix[i][j]=tmp
            start_row+=1
            start_col+=1
            end_row-=1
            end_col-=1