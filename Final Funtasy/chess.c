#include <stdio.h>​
#include <stdlib.h>​

#define ligne 12
#define colonne 10

typedef enum PieceType PieceType;
enum PieceType
{
  NONE, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, KING
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
  Coordonnees coords;
};

typedef struct Field Field;
struct Field
{
  Piece piece;
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
void init();
void drawBoard();
char ccouleur(Field f);
char ctype(Field f);

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
	for(j=0;j<ligne;j++)
	{
	    if (j<= 1 || j >= ligne-2)
	    {
            for(i=0;i<colonne;i++)
            {
                gameBoard.board[i][j].piece.color=BLACK;
                gameBoard.board[i][j].piece.pieceType=NONE;
                gameBoard.board[i][j].piece.coords.x=i;
                gameBoard.board[i][j].piece.coords.y=j-1;
            }
	    }
	    else
	    {
                gameBoard.board[0][j].piece.color=BLACK;
                gameBoard.board[0][j].piece.pieceType=NONE;
                gameBoard.board[0][j].piece.coords.x=0;
                gameBoard.board[0][j].piece.coords.y=j-1;
                gameBoard.board[colonne-1][j].piece.color=BLACK;
                gameBoard.board[colonne-1][j].piece.pieceType=NONE;
                gameBoard.board[colonne-1][j].piece.coords.x=colonne-1;
                gameBoard.board[colonne-1][j].piece.coords.y=j-1;

                if (j == 3)
                {
                    for(i=1;i<colonne-1;i++)
                    {
                        gameBoard.board[i][j].piece.color=BLACK;
                        gameBoard.board[i][j].piece.pieceType=PAWN;
                        gameBoard.board[i][j].piece.coords.x=i;
                        gameBoard.board[i][j].piece.coords.y=j-1;
                    }
                }
                else if (j == 8)
                {
                    for(i=1;i<colonne-1;i++)
                    {
                        gameBoard.board[i][j].piece.color=WHITE;
                        gameBoard.board[i][j].piece.pieceType=PAWN;
                        gameBoard.board[i][j].piece.coords.x=i;
                        gameBoard.board[i][j].piece.coords.y=j-1;
                    }
                }
                else if(j>3 && j<6)
                {
                    for(i=1;i<colonne-1;i++)
                    {
                        gameBoard.board[i][j].piece.color=WHITE;
                        gameBoard.board[i][j].piece.pieceType=NONE;
                        gameBoard.board[i][j].piece.coords.x=i;
                        gameBoard.board[i][j].piece.coords.y=j-1;
                    }
                }

	    }
	}

	gameBoard.board[1][2].piece.color = BLACK;
    gameBoard.board[1][2].piece.pieceType = ROOK;
    gameBoard.board[1][2].piece.coords.x = 1;
    gameBoard.board[1][2].piece.coords.y = 1;

    gameBoard.board[2][2].piece.color = BLACK;
    gameBoard.board[2][2].piece.pieceType = KNIGHT;
    gameBoard.board[2][2].piece.coords.x = 2;
    gameBoard.board[2][2].piece.coords.y = 1;

	gameBoard.board[3][2].piece.color = BLACK;
    gameBoard.board[3][2].piece.pieceType = BISHOP;
    gameBoard.board[3][2].piece.coords.x = 3;
    gameBoard.board[3][2].piece.coords.y = 1;

	gameBoard.board[4][2].piece.color = BLACK;
    gameBoard.board[4][2].piece.pieceType = QUEEN;
    gameBoard.board[4][2].piece.coords.x = 4;
    gameBoard.board[4][2].piece.coords.y = 1;

	gameBoard.board[5][2].piece.color = BLACK;
    gameBoard.board[5][2].piece.pieceType = KING;
    gameBoard.board[5][2].piece.coords.x = 5;
    gameBoard.board[5][2].piece.coords.y = 1;

	gameBoard.board[6][2].piece.color = BLACK;
    gameBoard.board[6][2].piece.pieceType = BISHOP;
    gameBoard.board[6][2].piece.coords.x = 6;
    gameBoard.board[6][2].piece.coords.y = 1;

	gameBoard.board[7][2].piece.color = BLACK;
    gameBoard.board[7][2].piece.pieceType = KNIGHT;
    gameBoard.board[7][2].piece.coords.x = 7;
    gameBoard.board[7][2].piece.coords.y = 1;

	gameBoard.board[8][2].piece.color = BLACK;
    gameBoard.board[8][2].piece.pieceType = ROOK;
    gameBoard.board[8][2].piece.coords.x = 8;
    gameBoard.board[8][2].piece.coords.y = 1;



	gameBoard.board[1][9].piece.color = WHITE;
    gameBoard.board[1][9].piece.pieceType = ROOK;
    gameBoard.board[1][9].piece.coords.x = 1;
    gameBoard.board[1][9].piece.coords.y = 8;

    gameBoard.board[2][9].piece.color = WHITE;
    gameBoard.board[2][9].piece.pieceType = KNIGHT;
    gameBoard.board[2][9].piece.coords.x = 2;
    gameBoard.board[2][9].piece.coords.y = 8;

	gameBoard.board[3][9].piece.color = WHITE;
    gameBoard.board[3][9].piece.pieceType = BISHOP;
    gameBoard.board[3][9].piece.coords.x = 3;
    gameBoard.board[3][9].piece.coords.y = 8;

	gameBoard.board[4][9].piece.color = WHITE;
    gameBoard.board[4][9].piece.pieceType = QUEEN;
    gameBoard.board[4][9].piece.coords.x = 4;
    gameBoard.board[4][9].piece.coords.y = 8;

	gameBoard.board[5][9].piece.color = WHITE;
    gameBoard.board[5][9].piece.pieceType = KING;
    gameBoard.board[5][9].piece.coords.x = 5;
    gameBoard.board[5][9].piece.coords.y = 8;

	gameBoard.board[6][9].piece.color = WHITE;
    gameBoard.board[6][9].piece.pieceType = BISHOP;
    gameBoard.board[6][9].piece.coords.x = 6;
    gameBoard.board[6][9].piece.coords.y = 8;

	gameBoard.board[7][9].piece.color = WHITE;
    gameBoard.board[7][9].piece.pieceType = KNIGHT;
    gameBoard.board[7][9].piece.coords.x = 7;
    gameBoard.board[7][9].piece.coords.y = 8;

	gameBoard.board[8][9].piece.color = WHITE;
    gameBoard.board[8][9].piece.pieceType = ROOK;
    gameBoard.board[8][9].piece.coords.x = 8;
    gameBoard.board[8][9].piece.coords.y = 8;


	gameBoard.turn = WHITE;
    gameBoard.cas_b.cast1 = 0;
    gameBoard.cas_b.cast2 = 0;
    gameBoard.cas_w.cast1 = 0;
    gameBoard.cas_w.cast2 = 0;
    gameBoard.en_passant = 0;
    gameBoard.prev = NULL;
    gameBoard.irr_change = 0;
    gameBoard.king_b.x = 5;
    gameBoard.king_b.y = 1;
    gameBoard.king_w.x = 4;
    gameBoard.king_w.y = 8;
    gameBoard.number = 0;
    gameBoard.eval = 0;
}

void drawBoard()
{
int a, b, c=0, couleur;

	system ("clear");		/*efface l'ecran*/
	printf("\n\t.________________________________________________________.\n\t");
    printf("||      |      |      |      |      |      |      |      |\n\t");
    printf("||  A   |  B   |  C   |  D   |  E   |  F   |  G   |  H   |\n\t");
	printf("||______|______|______|______|______|______|______|______|\n\t");
	for (a=2;a<10;a++)
	{
	    printf("||      |      |      |      |      |      |      |      |\n\t|");
		for (b=1;b<9;b++)
		{
			c++;
			printf("|  %c%c  ",ccouleur(gameBoard.board[b][a]),ctype(gameBoard.board[b][a]));
			if ( c % 8 == 0)
			printf("| %d\n\t||______|______|______|______|______|______|______|______|\n\t", c/8);
		}
	}
    printf("||      |      |      |      |      |      |      |      |\n\t");
    printf("||  A   |  B   |  C   |  D   |  E   |  F   |  G   |  H   |\n\t");
	printf("||______|______|______|______|______|______|______|______|\n\t");
}

Position jouerCoup(Position dep, Coordonnees depart, Coordonnees arrivee)
{
    Piece piece_vide;
    piece_vide.color = WHITE;
    piece_vide.pieceType = NONE;
    piece_vide.coords = depart;

    Position end = dep;
    end.board[arrivee.x][arrivee.y+1].piece = end.board[depart.x][depart.y+1].piece;
    end.board[arrivee.x][arrivee.y+1].piece.coords = arrivee;
    end.board[depart.x][depart.y+1].piece = piece_vide;
    return end;
}

char ccouleur(Field f)
{
    if(f.piece.pieceType != NONE)
    {
        switch(f.piece.color)
        {
            case(BLACK):
                return 'B';
            case(WHITE):
                return 'W';
        }
    }
    else return ' ';
}

char ctype(Field f)
{
        switch(f.piece.pieceType)
        {
            case(NONE):
                return ' ';
            case(KING):
                return 'K';
            case(QUEEN):
                return 'q';
            case(ROOK):
                return 'r';
            case(BISHOP):
                return 'b';
            case(KNIGHT):
                return 'k';
            case(PAWN):
                return 'p';
        }
}

int main()
{
    init();
    drawBoard();
    Coordonnees depart = {1, 2};
    Coordonnees arrivee = {1, 4};
    gameBoard = jouerCoup(gameBoard,depart, arrivee);
    drawBoard();
    return 0;
}

