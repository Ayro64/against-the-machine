#include <stdio.h>
#include <stdlib.h>
#DEFINE ligne 8
#DEFINE colonne 8

typedef enum PieceType PieceType;
enum PieceType
{
	KING, QUEEN, ROCK, BISHOP, KNIGHT, PAWN	
};
typedef enum Color Color;
enum Color
{
    BLANC, NOIR
};

struct Piece
{
    Color color
};
