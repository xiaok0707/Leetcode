class Solution {
public:
    bool used[10];

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i){
            memset(used,false,sizeof(used));
            for(int j=0;j<9;++j){
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'0';
                if(used[x]) return false;
                used[x]=true;
            }
        }
        for(int j=0;j<9;++j){
            memset(used,false,sizeof(used));
            for(int i=0;i<9;++i){
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'0';
                if(used[x]) return false;
                used[x]=true;
            }
        }
        for(int r=0;r<9;r+=3){
            for(int c=0;c<9;c+=3){
                memset(used,false,sizeof(used));
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
};