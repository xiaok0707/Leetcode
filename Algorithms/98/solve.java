class Solution {
    public void rotate(int[][] matrix) {
        int n=matrix.length;
        int start_row=0,end_row=n-1;
        int start_col=0,end_col=n-1;
        while(start_row<=end_row){
            for(int col=start_col;col<end_col;++col){
                int i=start_row,j=col;
                int tmp=matrix[i][j];
                for(int cnt=0;cnt<3;++cnt){
                    int newi=n-1-j,newj=i;
                    matrix[i][j]=matrix[newi][newj];
                    i=newi;j=newj;
                }
                matrix[i][j]=tmp;
            }
            ++start_row;
            --end_row;
            ++start_col;
            --end_col;
        }
    }
}