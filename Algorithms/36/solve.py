class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            used=[False for a in range(10)]
            for j in range(9):
                if board[i][j]=='.':continue
                x=int(board[i][j])
                if used[x]:return False
                used[x]=True
        for j in range(9):
            used=[False for a in range(10)]
            for i in range(9):
                if board[i][j]=='.':continue
                x=int(board[i][j])
                if used[x]:return False
                used[x]=True
        for r in range(0,9,3):
            for c in range(0,9,3):
                used=[False for a in range(10)]
                for i in range(r,r+3):
                    for j in range(c,c+3):
                        if board[i][j]=='.':continue
                        x=int(board[i][j])
                        if used[x]:return False
                        used[x]=True
        return True