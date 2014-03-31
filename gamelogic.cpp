#include "gamelogic.h"

GameLogic::GameLogic(QObject *parent) :
    QObject(parent)
{
    reset();
    m_current_player = 1;
}

bool GameLogic::set_cell(int x, int y, int newVal)
{
    int cid = cell_idx(x, y);
    if (val(x,y) == 0)
    {
        m_board[cid] = newVal;
        return newVal;
    }
    else
    {
        return 0;
    }
}

int GameLogic::play(int x, int y)
{
    int result = m_current_player;
    if ( set_cell(x,y,m_current_player) )
    {
        m_current_player = m_current_player == 1 ? 2 : 1;
        return result;
    }
    else
    {
        return 0;
    }
}

int GameLogic::has_winner()
{
    int winner;
    for ( int i=0; i < 3; i++ )
    {
        if ( (winner = has_winner_row(i)) )
        {
            return winner;
        }

        if ( (winner = has_winner_col(i)) )
        {
            return winner;
        }
    }

    return has_winner_diag();
}


void GameLogic::reset()
{
    m_board.clear();
    for ( int i=0; i < 9; i++ )
    {
        m_board << 0;
    }
}


int GameLogic::cell_idx(int x, int y)
{
    return y * 3 + x;
}

int GameLogic::val(int x, int y)
{
    return m_board[cell_idx(x,y)];
}

int GameLogic::has_winner_row(int row)
{
    if ( ( val(0,row) == val(1,row) ) &&
         ( val(1,row) == val(2,row) ) )
    {
        return val(0,row);
    }
    return 0;
}


int GameLogic::has_winner_col(int col)
{
    if ((val(col,0) == val(col,1)) &&
         (val(col,1) == val(col,2)))
    {
        return val(col,1);
    }
    return 0;
}


int GameLogic::has_winner_diag()
{
    // TODO
    return 0;
}

