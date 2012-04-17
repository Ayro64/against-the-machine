#include <stdio.h>​
#include <stdlib.h>​

#define ligne 12
#define colonne 10

typedef enum PieceType PieceType;
enum PieceType
{
  KING, QUEEN, ROOCK, BISHOP, KNIGHT, PAWN, NONE
};

typedef enum Color Color;
enum Color
{
  WHITE, BLACK
};

typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
  int x;
  int y;
};

typedef struct Piece Piece;
struct Piece
{
  Color color;
  PieceType pieceType;
  Coordonnees coordonnees;
};

typedef struct Field Field;
struct Field
{
  Piece type;
};

typedef struct Can_Castle Can_Castle;
struct Can_Castle
{
  int cast1;
  int cast2;
};

typedef struct Position Position;
struct Position
{
  Field board[colonne][ligne];
  Color turn;
  Can_Castle cas_w, cas_b;
  int en_passant;
  Position* prev;
  int irr_change;
  Coordonnees king_w, king_b;
  int number;
  int eval;
};

Position gameBoard;

int identical_position(Position x, Position y);
int draw_by_repetition_aux(Position pos, Position p, int n);

int identical_position(Position x, Position y)
{
  return (x.eval == y.eval &&
    x.turn == y.turn &&
    x.cas_w.cast1 == y.cas_w.cast1 && x.cas_w.cast2 == y.cas_w.cast2 &&
    x.cas_b.cast1 == y.cas_b.cast1 && x.cas_b.cast2 == y.cas_w.cast2 &&
    x.en_passant == y.en_passant &&
    x.board == y.board);
}

int draw_by_repetition_aux(Position pos, Position p, int n)
{
  if (n<=0)
  {
    return 1;
  }
    else if (2*n > p.irr_change)
    {
        return 0;
    }
    else if (identical_position(*(p.prev),p))
    {
    return 0;
    }
    else if (identical_position(p,pos))
    {
    draw_by_repetition_aux(pos,*(p.prev),n-1);
    }
    else
    {
    draw_by_repetition_aux(pos,*(p.prev),n);
    }
}

void init()
{
    int i,j;
	for(i=0;i<colonne;i++)
	{
	    if (!i || i == colonne-1)
	    {
            for(j=0;j<ligne;j++)
            {
                gameBoard.board[i][j].type.color=BLACK;
                gameBoard.board[i][j].type.color=BLACK;

            }
	    }
		for(j=0,j<2,j++)
		{
			gameBoard.board[i][j]=NULL;
		}
		for(j=ligne-1,j>ligne-3,j--)
		{
		    gameBoard.board[i][j]=NULL;
		}
	}

	gameBoard.board[1][2].type = {BLACK, ROOK, {1, 1}};

	gameBoard.turn = WHITE;
	gameBoard

}

