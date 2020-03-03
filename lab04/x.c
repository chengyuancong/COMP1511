//z5285978
#include<stdio.h>

void draw(int column, int row, int num);

int main(void){
    int num;
    printf("Enter size: ");
    scanf("%d", &num);
    for (int row = 1; row <= num; row ++) {
        for (int column = 1; column <= num; column ++) {
            draw(column, row, num);
        }
        printf("\n");
    }
    return 0;
}

void draw(int column, int row, int num) {
    if (column == row || column == num + 1 -row) {
        printf("*");
    } else {
        printf("-");
    }
}
    