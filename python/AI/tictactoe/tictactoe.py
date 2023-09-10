"""
Tic Tac Toe Player
"""

from cmath import inf
from copy import deepcopy
import math
import boardLogic as bL

X = "X"
O = "O"
EMPTY = None
def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):

    if bL.countPlayer(board,X)==bL.countPlayer(board,O):
        return X
    else:
        return O




def actions(board):
    actions = []
    for i in range(3):
        for j in range(3):
            if board[i][j] is EMPTY:
                actions.append((i,j))
    return actions


def result(board, action):

    fakeboard=deepcopy(board)
    if fakeboard[action[0]][action[1]]!=EMPTY:
        raise Exception
    fakeboard[action[0]][action[1]]=player(board)
    return fakeboard
'''    fakeboard=initial_state()
    for i in range(3):
        for j in range (3):
            fakeboard[i][j]=board[i][j]
    fakeboard[action[0]][action[1]]=player(board)
    return fakeboard'''


def winner(board):

    if bL.playerWon(board,X):
        return X
    elif bL.playerWon(board,O):
        return O
    else:
        return None


def terminal(board):
    return winner(board)!=None or bL.countPlayer(board,EMPTY)==0


def utility(board):
    if winner(board)==X:
        return 1
    elif winner(board)==O:
        return -1
    else:
        return 0

def minimax(board):
    global depth
    lista=[]
    if player(board)==X:
        return maximize(board)[1]

            
    if player(board)==O:
        return minimize(board)[1]
        

  

def minimax(board):
    lista=[]
    vPlus=(-9999,(),inf)
    vMinus=(9999,(),inf)
    if player(board)==X:
        return maximize(board)[1]
        for action in actions(board):
            return minimize(board,1)[1]
            triplet=maximize(board,1)
            lista.append((triplet[0],action,triplet[1]))
        print(lista)
        for item in lista:
            if item[0]>vPlus[0]:
                vPlus=item
                if item[2]<vPlus[2]:
                    vPlus=item
                    if item[0]==1:
                        return vPlus[1]
        return vPlus[1]

    if player(board)==O:
        
        return minimize(board)[1]
        '''
        for action in actions(board):
            triplet=minimize(board,1)
            lista.append((triplet[0],action,triplet[1]))

        print(lista)
        for item in lista:
            if item[0]<vMinus[0]:
                vPlus=item
                if item[2]<vPlus[2]:
                    vPlus=item
                    if item[0]==-1:
                        return vMinus[1]
        return vMinus[1]'''

def maximize(board):
    util=-9999
    move=None
    if terminal(board):
        
        return [utility(board),None]
    for action in actions(board):
        aux=minimize(result(board,action))
        if(aux[0]>util):
            util=aux[0]
            move=action
            if util==1:
                return [util,move]

    return [util,move]


def minimize(board):
    util=9999
    move=None
    if terminal(board):
        
        return [utility(board),None]
    for action in actions(board):
        aux=maximize(result(board,action))
        if(aux[0]<util):
            util=aux[0]
            move=action
            if util==-1:
                return [util,move]
    return [util,move]        
'''
def maximize(board):

    move=[-9999,None]
    if terminal(board):
        
        return [utility(board),move[1]]

    for action in actions(board):
        aux=minimize(result(board,action))
        if aux[0]>move[0]:
            move[0]=aux[0]
            move[1]=action
            if move[0]==1:
                return move

    return move

def minimize(board):


    move=[9999,None]
    if terminal(board):
        
        return [utility(board),None]

    for action in actions(board):
        aux=maximize(result(board,action))
        if aux[0]<move[0]:
            move[0]=aux[0]
            move[1]=action
            if move[0]==-1:
                return move

    return move'''