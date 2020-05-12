#include <stdio.h>
#include <stdlib.h>

// detected by dcc
// detected by gcc -O -Wall
// detected by valgrind
void test0(void) {
    int i;
    // accessing uninitialized local variable
    printf("%d\n", i);
}

// detected by dcc
// detected by gcc -fsanitize=address
// detected by valgrind
void test1(void) {
    int *a = malloc(10*sizeof (int));
    // accessing variable outside malloc'ed region
    a[10] = 42;
}

// detected by dcc
// detected by gcc -fsanitize=address
// detected by valgrind
void test2(void) {
    int *a = malloc(10);
    // accessing variable outside malloc'ed region
    a[5] = 42;
}

// detected by dcc
// detected by gcc -fsanitize=address
// detected by valgrind
void test3(void) {
    int *a = NULL;
    // dereferencing NULL pointer
    a[5] = 42;
}

// detected by dcc --valgrind
// detected by valgrind
void test4(void) {
    int i;
    int a[10];
    for (i = 0; i < 10; i++)
        if (i != 4)
            a[i] = i;
    // accessing uninitialized array element (a[4])
    for (i = 0; i < 10; i++)
        printf("%d\n", a[i]);
}

// detected by dcc --valgrind
// detected by valgrind
void test5(void) {
    int i;
    int *a = malloc(10*sizeof (int));
    for (i = 0; i < 10; i++) 
        if (i != 4)
            a[i] = i;
    // accessing uninitialized part of malloc'ed region
    for (i = 0; i < 10; i++)
        printf("%d\n", a[i]);
}

// detected by dcc 
// detected by gcc -fsanitize=address
// detected by valgrind
void test6(void) {
    int *p = malloc(10*sizeof *p);
    int *q = p;
    free(p);
    // accessing free'd area
    q[4] = 42;
}

// detected by dcc --leak-check
// detected by valgrind '--leak-check=yes'
void test7(void) {
    int *p = malloc(10*sizeof *p);
    // malloc'ed space isn't freed
}

// detected by dcc
// detected by gcc  -fsanitize=address
// detected by valgrind
void test8(void) {
    int *p = malloc(10*sizeof *p);
    int *q = p;
    free(p);
    // multiple free
    free(q);
}

int main(int argc, char*argv[]) {
    int test = atoi(argv[1]);
    if(test == 0){
        test0();
    } else if (test == 1){
        test1();
    } else if (test == 2){
        test2();
    } else if (test == 3){
        test3();  
    } else if (test == 4){
        test4();
    } else if (test == 5){
        test5();
    } else if (test == 6){
        test6();
    } else if (test == 7){
        test7();
    } else if (test == 8){
        test8();
    } 
    return 0;
}