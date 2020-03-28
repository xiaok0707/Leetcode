class Solution {
    public boolean used[]=new boolean[10];
    public boolean isValidSudoku(char[][] board) {
        for(int i=0;i<9;++i){
            Arrays.fill(used,false);
            for(int j=0;j<9;++j){
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'0';
                if(used[x]) return false;
                used[x]=true;
            }
        }
        for(int j=0;j<9;++j){
            Arrays.fill(used,false);
            for(int i=0;i<9;++i){
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'0';
                if(used[x]) return false;
                used[x]=true;
            }
        }
        for(int r=0;r<9;r+=3){
            for(int c=0;c<9;c+=3){
                Arrays.fill(used,false);
                for(int i=r;i<r+3;++i){
                    for(int j=c;j<c+3;++j){
                        if(board[i][j]=='.') continue;
                        int x=board[i][j]-'0';
                        if(used[x]) return false;
                        used[x]=true;
                    }
                }
            }
        }
        return true;
    }
}