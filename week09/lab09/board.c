//z5285978

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

typedef struct piece Piece;
struct piece
{
    char color;
    char symbol;
    Piece *next;
};

void printPiece(Piece pi);
int readPiece(Piece * pi);
Piece *connectPiece(Piece *pi, char str[MAX_LENGTH], int i);

int main(void) {
    Piece head;
    Piece *pie;
    pie = &head;
    int i = 0;
    char str[MAX_LENGTH];
    printf("Enter pieces: ");
    fgets(str, MAX_LENGTH, stdin);
    while (str[i] != '\0' && str[i] != '\n') {
        pie = connectPiece(pie, str, i);
        i = i + 3;
    }
    pie->next = NULL;
    printPiece(head);
    return EXIT_SUCCESS;
}

int readPiece(Piece * pi) {
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
void printPiece(Piece pi) {
    int i;
    Piece *pie = &pi;
    for(i = 1; pie->next != NULL; i++) {
        printf("%c/%c ", pie->color, pie->symbol);
        pie = pie->next;
        if (i % 4 == 0) {
            printf("\n");
        }
    }
}

Piece *connectPiece (Piece *pie, char str[MAX_LENGTH], int i) {
    Piece *element = (Piece*) malloc (sizeof (Piece));
    pie->color = str[i];
    pie->symbol = str[i + 1];
    pie->next = element;
    if (readPiece(pie) == 0) {
        fprintf (stderr,"Invalid Input\n");
        exit (EXIT_FAILURE);
    }
    pie = element;
    return pie;
}