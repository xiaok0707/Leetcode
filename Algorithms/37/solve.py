class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        usedrow = [[False for i in range(10)] for j in range(10)]
        usedcol = [[False for i in range(10)] for j in range(10)]
        usedblock = [[False for i in range(10)] for j in range(10)]
        ok = False

        def dfs(x: int, y: int) -> None:
            nonlocal ok
            if x==9:ok=True
            if ok:return
            r,c=x//3,y//3
            num=r*3+c
            newx,newy=0,0
            if y+1<(c+1)*3:newx,newy=x,y+1
            elif x+1<(r+1)*3:newx,newy=x+1,c*3
            else:
                if num==2 or num==5 or num==8:newx,newy=x+1,0
                else:newx,newy=x-2,y+1
            if board[x][y]!='.' and not ok:
                dfs(newx,newy)
                return
            for v in range(1,10):
                if not usedrow[x][v] and not usedcol[y][v] and not usedblock[num][v] and not ok:
                    usedrow[x][v]=usedcol[y][v]=usedblock[num][v]=True
                    board[x][y]=str(v)
                    dfs(newx,newy)
                    if ok:return
                    usedrow[x][v]=usedcol[y][v]=usedblock[num][v]=False
                    board[x][y]='.'

        for i in range(9):
            for j in range(9):
                if board[i][j]=='.':continue
                v=int(board[i][j])
                usedrow[i][v],usedcol[j][v],usedblock[(i//3)*3+j//3][v]=True,True,True
        dfs(0,0)
