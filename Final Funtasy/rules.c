#include <stdio.h>
#include <stdlib.h>

int canMove (Position pos, Piece p, int x, int y);

int canMove (Position pos, Field p, Field f)
{
	int x = p.piece.coords.x;
	int y = p.piece.coords.y;
	int x1 = f.piece.coords.x;
	int y1 = f.piece.coords.y;
	int a = 0;
	int distX = abs(x-x1);
	int distY = abs(y-y1);
	
	switch (p.pieceType) 
{
case KING :
	//NEED REVOIR COULEUR PION
     if	( (y1==y+1 && x1==x) ||(y1==y-1 && x1==x)||(y1==y+1 &&
	x1==x+1)||(y1==y+1 && x1==x-1)||(y1==y-1 && x1==x+1)||(y1==y-1 &&
x1==x-1)||(y1==y && x1==x+1)||(y1==y && x1==x-1) ) {a = 1;}
	return a;
	break;

case QUEEN :

	break;

case ROOK :
	Liste d'instructions;

	break;
	
case BISHOP :	
	int a=1,i;
	if(abs(x1-x)!=abs(y1-y)){a=0;}
	if((x< p=""><>
	{
		for(i=1;(i+x)< p=""><>{if(pos.board[y+i]		[x+i].piece.pieceType!=NONE)a=0;
	}
	else if((x>x1)&&(y>y1))
	{
		for(i=1;(x-i)>x1;i++)
		{
			if(pos.board[y-i][x-i].piece.pieceType!=NONE) a=0;
		}
	}
	else if((x>x1)&&(y< p=""><>
		for(i=1;(x-i)>x1;i++)
		{
			if(pos.board[y+i][x-i].piece.pieceType!=NONE) a=0;
		}
	}
	else if((xy1))
	{
		for(i=1;(y-i)>y1;i++)
		{
		if(pos.board[y-i][x+i].piece.pieceType!=NONE)a=0;
		}
	}
	return a;	
	break;
	
case KNIGHT :	
	if( (y1==y+2 && x1==x+1)||(y1==y+2 && x1==x-1)||(y1==y+1 &&
x1==x+2)||(y1==y+1 && x1==x-2)||(y1==y-1 && x1==x+2)||(y1==y-1 &&
x1==x-2)||(y1==y-2 && x1==x+1)||(y1==y-2 && x1==x-1) ){a = 1;}
	return a;	
	break;
	
case PAWN :	
	int a=0;
	if(pos.turn==BLACK)
	{
		if(y==1)
		{
			if(y1==(y+2) && x1==x)
			{
				if(pos.board[y1][x1].piece.pieceType!=NONE&&board[y+1][x].piece.pieceType!=NONE){a = 1;}
  			}
		}
		if(y1==y+1 && x1==x)
		{
			if(pos.board[y1][x1].piece.pieceType!=NONE){a = 1;}
		}
		else if ( y1==(y+1) && (x1==(x+1)||x1==(x-1)) )
		{
			if( (pos.board[y][x].piece.pieceType!=NONE)&&(pos.board[y1][x1].piece.color != pos.board[y][x].piece.color)){a = 1;}
 		}
	}	
	else if(pos.turn==1)
	{
		if(y==6)
		{
			if( y1==(y-2) && x1==x)
			{
				if( (pos.board[y1][x1].piece.pieceType!=NONE)&&(board[y-1][x].piece.pieceType!=NONE)){a = 1;}
			}
     		}
 		if( y1==(y-1) && x1==x)
		{
			if(pos.board[y1][x1].piece.pieceType!=NONE){a = 1;}
		}
		else if(y1==(y-1) && (x1==(x-1)||x1==(x+1)))
		{
			if( (pos.board[y1][x1].piece.pieceType!=NONE)&&(board[y-1][x].piece.pieceType!=NONE) ){a = 1;}
 		}
	}
   	if(a==1)
   	{
     		if(turn==0)
     		{
			if(y1==7)
			return 2;
     		}
     		else
     		{
			if(y1==0)
			return 2;
		}
    	}
	return a;
	break;
} 
}
