//z5285978
#include<stdio.h>
int main(void){
    int number; //number
    printf("Enter number: ");
    scanf("%d", &number);
    int quotient = number; //initialise quotient
    int factor = 2;
   
    
    //find the first factor
    for (; quotient % factor != 0; factor ++) {     
    }
    
    quotient = quotient / factor;
    
    //output first factor or output prime
    if (quotient == 1) {
        printf("%d is prime\n", number);
    } else { 
        printf("The prime factorization of %d is:\n", number);
        printf("%d ", factor);
        //repeat the factor or find the next factor
        
        //ends when quotient = 1
        while (quotient != 1) {
            //when can be divided, print and repeat the factor   
            if (quotient % factor == 0) { 
                printf("* %d ", factor);
                quotient = quotient / factor;
            
            } else {  //if can't, factor + 1 until can be divided
                for (; quotient % factor != 0; factor ++) {
                }
            }
        }
        //ends the factorization process
        printf("= %d\n", number);
    }
    return 0;
}           