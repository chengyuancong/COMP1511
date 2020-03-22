// z5285978
// a program that reads in information about 2 pieces from a game 
// and prints out whether they are equal.

#include<stdio.h>
#include<stdlib.h>

typedef struct piece Piece;
struct piece
{
    char color;
    char symbol;
};


//Returns 1 if p1 and p2 have the same colour and symbol
//Returns 0 otherwise
int areEqual(Piece p1,Piece p2);

// Prints out a piece in the following format
// colour/symbol eg. R/*
void printPiece(Piece pi);

// Reads in a piece from stdin and checks it is valid
// If a valid piece was read in, it returns 1
// Returns 0 otherwise
int readPiece(Piece * pi);

int main(void) {
    Piece pie1, pie2;
    Piece *pi1 = &pie1;
    Piece *pi2 = &pie2;
    printf("Enter 2 pieces: ");
    if (readPiece(pi1) == 0) {
        fprintf(stderr,"Invalid Input\n");
        return EXIT_FAILURE;
    }

    getchar();
    if (readPiece(pi2) == 0) {
        fprintf(stderr,"Invalid Input\n");
        return EXIT_FAILURE;
    }
    printPiece(pie1);
    if (areEqual(pie1, pie2)) {
        printf(" equals ");
    } else {
        printf(" does not equal ");
    }
    printPiece(pie2);
    printf("\n");
    return EXIT_SUCCESS;
}

int areEqual(Piece p1,Piece p2) {
    if (p1.color == p2.color && p1.symbol == p2.symbol) {
        return 1;
    }
    return 0;
}

void printPiece(Piece pi) {
    printf("%c/%c", pi.color, pi.symbol);
}

int readPiece(Piece * pi) {
    if (scanf("%c %c", &pi->color, &pi->symbol) != 2) {
        return 0;
    }
    if (pi->color != 'R'
        && pi->color != 'B'
        && pi->color != 'Y'
        && pi->color != 'G')
    {
        return 0;
    }
    if(pi->symbol != '*'
       && pi->symbol != '^'
       && pi->symbol != '#'
       && pi->symbol != '$')
    {
        return 0;
    }
    return 1;
}