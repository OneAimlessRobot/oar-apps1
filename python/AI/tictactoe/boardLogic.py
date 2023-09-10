
def countPlayer(board,player):
        ammount=0
        for i in range(3):
            for j in range(3):
                if(board[i][j]==player):
                    ammount+=1
        return ammount

def countInRow(board,player):
    max=0
    current=0
    for i in range(3):
        for j in range(3):
            if board[i][j]==player:
                current+=1
                if current==3:
                    return current
        max=current
        current=0
    return max


def countInColumn(board,player):
    max=0
    current=0
    for i in range(3):
        for j in range(3):
            if board[j][i]==player:
                current+=1
                if current==3:
                    return current
        max=current
        current=0
    return max
    
def countInDiagonalLeftRight(board,player):
    current=0
    for i in range(3):
        if board[i][i]==player:
            current+=1
    return current
    
def countInDiagonalRightLeft(board,player):
    current=0
    for i in range(3):
        if board[2-i][i]==player:
            current+=1
    return current
    
def playerWon(board,player):
    return countInColumn(board,player)==3 or countInRow(board,player)==3 or countInDiagonalRightLeft(board,player)==3 or countInDiagonalLeftRight(board,player)==3
