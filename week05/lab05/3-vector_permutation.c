//z5285978

#include <stdio.h>

int array(int vector[], int permutation[], int output[], int size);

int main(void) {
    int size, i, valid;
    printf("Enter vector length: ");
    scanf("%d", &size);
    
    int vector[size], permutation[size], output[size];
    
    printf("Enter vector: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &vector[i]);
    }
    
    printf("Enter permutation: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &permutation[i]);
    }
    
    valid = array(vector, permutation, output, size);
    
    if (valid == 1) {
        for(i = 0; i < size; i++) {
            printf("%d", output[i]);
            if (i != size - 1) {
                printf(" ");
            }
        }
        printf("\n");
    } else {
        printf("Invalid permutation\n");
    }
    return 0;
}

int array(int vector[], int permutation[], int output[],  int size) {
    int i;
    for(i = 0; i < size; i++) {
        if (permutation[i] >= size || permutation[i] < 0) {
            return 0;
        }
        output[i] = vector[permutation[i]];
    }
    return 1;
}