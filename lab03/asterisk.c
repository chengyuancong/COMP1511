//z528597
#include<stdio.h>
int main(void){
    
    int num; //n*n, n = num
    printf("Enter size: ");
    scanf("%d", &num);
    
    for (int row = 1; row <= num; row ++) {
        if (row == (num + 1) / 2) {
            for (int column = 1; column <= num; column ++) {
                printf("*");
            }
            printf("\n");
        } else {
            for (int column = 1; column <= num; column ++) {
                if (column == row || column == num + 1 -row || column == (num + 1) / 2) {
                    printf("*");
                } else {
                    printf("-");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
        
        
        