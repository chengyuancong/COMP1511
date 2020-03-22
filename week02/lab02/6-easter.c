//z5285978
#include<stdio.h>
int main(void){
    int year, a, b, c, d, e, f, g, h, i, k, l, m, easter_date, easter_month, p;
    printf("Enter year: ");
    scanf("%d", &year);
    a = year % 19;
    b = year / 100;
    c = year % 100;
    d = b / 4;
    e = b % 4;
    f = (b + 8) / 25;
    g = (b - f + 1) / 3;
    h = (19*a + b - d - g + 15) % 30;
    i = c / 4;
    k = c % 4;
    l = (32 + 2*e + 2*i - h - k) % 7;
    m = (a + 11*h + 22*l) / 451;
    easter_month = (h + l - 7*m + 114) / 31;  //[3=March, 4=April]
    p = (h + l - 7*m + 114) % 31;
    easter_date = p + 1;     //(date in Easter Month)
    if (easter_month == 3) {
        printf("Easter is March %d in %d.\n", easter_date, year);
    } else {
        printf("Easter is April %d in %d.\n", easter_date, year);
    }
    return 0;
}