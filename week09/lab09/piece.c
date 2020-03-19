// z5285978
// a program that reads in information about 2 pieces from a game and prints out whether they are equal.

typedef struct piece Piece;

//Returns 1 if p1 and p2 have the same colour and symbol
//Returns 0 otherwise
int areEqual(Piece p1,Piece p2);

// Prints out a piece in the following format
// colour/symbol eg. R/*
void printPiece(Piece p);

// Reads in a piece from stdin and checks it is valid
// If a valid piece was read in, it returns 1
// Returns 0 otherwise
int readPiece(Piece * p);