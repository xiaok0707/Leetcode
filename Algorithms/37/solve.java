class Solution {
    char g[][]=new char[10][10];
    boolean usedrow[][]=new boolean[10][10],usedcol[][]=new boolean[10][10],usedblock[][]=new boolean[10][10],ok;

    public void dfs(int x,int y){
        if(x==9){
            ok=true;
            return;
        }
        if(ok) return;
        int r=x/3,c=y/3,num=r*3+c;
        int newx=0,newy=0;
        if(y+1<(c+1)*3) { newx=x;newy=y+1; }
        else if(x+1<(r+1)*3) { newx=x+1;newy=c*3; }
        else{
            if(num==2 || num==5 || num==8) { newx=x+1;newy=0; }
            else { newx=x-2;newy=y+1; }
        }
        if(g[x][y]!='.' && !ok){
            dfs(newx,newy);
            return;
        }
        for(int a=1;a<=9;++a){
            if(!usedrow[x][a] && !usedcol[y][a] && !usedblock[num][a] && !ok){
                usedrow[x][a]=usedcol[y][a]=usedblock[num][a]=true;
                g[x][y]=String.valueOf(a).charAt(0);
                dfs(newx,newy);
                if(ok) return;
                usedrow[x][a]=usedcol[y][a]=usedblock[num][a]=false;
                g[x][y]='.';
            }
        }
    }

    public void solveSudoku(char[][] board) {
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                g[i][j]=board[i][j];
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'0';
                usedrow[i][x]=true;
                usedcol[j][x]=true;
                usedblock[(i/3)*3+j/3][x]=true;
            }
        }
        ok=false;
        dfs(0,0);
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                board[i][j]=g[i][j];
            }
        }
    }
}