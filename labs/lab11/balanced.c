// z5285978

#include <stdio.h>
#include "Stack.h"

struct stack{
    int items[MAX_SIZE];
    int size;
};

int main(void)
{
    int letter = (int) getchar();
    Stack stack = stackCreate();
    while (letter != EOF)
    {
        stackPush(stack, letter);
        letter = (int)getchar();
    }
    int round_match = 0, square_match = 0, curly_match = 0;
    while (stack->size > 0)
    {
        letter = stackPop(stack);
        if (letter == '(')
        {
            round_match++;
        }
        if (letter == ')')
        {
            round_match--;
        }
        if (letter == '[')
        {
            square_match++;
        }
        if (letter == ']')
        {
            square_match--;
        }
        if (letter == '{')
        {
            curly_match++;
        }
        if (letter == '}')
        {
            curly_match--;
        }
    }
    stackDestroy(stack);
    if (round_match == 0 && square_match == 0 && curly_match == 0)
    {
        printf("Yes, balanced.\n");
    }
    else
    {
        printf("No, not balanced.\n");
    }
    return 0;
}
