#include "Piezas.h"
#include <vector>
using namespace std;
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
 **/

/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and
 * specifies it is X's turn first
 **/
Piezas::Piezas()
{
  board = vector<vector<Piece>>(BOARD_COLS, vector<Piece>(BOARD_ROWS, Blank));
  turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
 **/
void Piezas::reset()
{
  board = vector<vector<Piece>>(BOARD_COLS, vector<Piece>(BOARD_ROWS, Blank));
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
 **/
Piece Piezas::dropPiece(int column)
{
  if (column > BOARD_COLS)
  {
    return Invalid;
  }
  Piece placed = Blank;
  for (int i = 0; i < BOARD_ROWS; i++)
  {
    if (board[column][i] == Blank)
    {
      board[column][i] = turn;
      placed = turn;
      if (turn == X)
      {
        turn = O;
      }
      else
      {
        turn = X;
      }
      break;
    }
  }
  return placed;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
 **/
Piece Piezas::pieceAt(int row, int column)
{
  if (0 > column || column > BOARD_COLS || 0 > row || row > BOARD_ROWS)
  {
    return Invalid;
  }
  else
  {
    return board[column][row];
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
 **/
Piece Piezas::gameState()
{
  int longestX = 0;
  int longestO = 0;
  for (int c = 0; c < BOARD_COLS; c++)
  {
    for (int r = 0; r < BOARD_ROWS; r++)
    {
      if (board[c][r] == Blank)
      {
        return Invalid;
      }
      if (board[c][r] == X)
      {
        bool pr = true;
        bool mr = true;
        bool pc = true;
        bool mc = true;
        for (int i = 0; i < BOARD_COLS; i++)
        {
          if (pc)
          {
            if (c + i < BOARD_COLS)
            {
              if (board[c + i][r] == X)
              {
                longestX = i + 1;
              }
              else
              {
                pc = false;
              }
            }
            else
            {
              pc = false;
            }
          }
          if (mc)
          {
            if (c - i > 0)
            {
              if (board[c - i][r] == X)
              {
                longestX = i + 1;
              }
              else
              {
                mc = false;
              }
            }
            else
            {
              mc = false;
            }
          }
          if (pr)
          {
            if (r + i < BOARD_ROWS)
            {
              if (board[c][r + i] == X)
              {
                longestX = i + 1;
              }
              else
              {
                pr = false;
              }
            }
            else
            {
              pr = false;
            }
          }
          if (mr)
          {
            if (r - i > 0)
            {
              if (board[c][r - i] == X)
              {
                longestX = i + 1;
              }
              else
              {
                mr = false;
              }
            }
            else
            {
              mr = false;
            }
          }
        }
      }
      else
      {
        bool pr = true;
        bool mr = true;
        bool pc = true;
        bool mc = true;
        for (int i = 0; i < BOARD_COLS; i++)
        {
          if (pc)
          {
            if (c + i < BOARD_COLS)
            {
              if (board[c + i][r] == O)
              {
                longestO = i + 1;
              }
              else
              {
                pc = false;
              }
            }
            else
            {
              pc = false;
            }
          }
          if (mc)
          {
            if (c - i > 0)
            {
              if (board[c - i][r] == O)
              {
                longestO = i + 1;
              }
              else
              {
                mc = false;
              }
            }
            else
            {
              mc = false;
            }
          }
          if (pr)
          {
            if (r + i < BOARD_ROWS)
            {
              if (board[c][r + i] == O)
              {
                longestO = i + 1;
              }
              else
              {
                pr = false;
              }
            }
            else
            {
              pr = false;
            }
          }
          if (mr)
          {
            if (r - i > 0)
            {
              if (board[c][r - i] == O)
              {
                longestO = i + 1;
              }
              else
              {
                mr = false;
              }
            }
            else
            {
              mr = false;
            }
          }
        }
      }
    }
  }
  if (longestX > longestO)
  {
    return X;
  }
  else if (longestO > longestX)
  {
    return O;
  }
  return Blank;
}