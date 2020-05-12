// Read annual rainfall and plot as bar graph
// This is a second draft that reads in the values
// stores them into two arrays and prints out the bar graph

// We still need to check users are not going to try to overfill the arrays
// We still need to error check
// We still need to use functions for reading in data etc!
// Andrew Taylor - andrewt@cse.unsw.edu.au
// 13/4/2014

// To feed in data from the file sydney_annual_rainfall.txt run like
// ./plotRainfall < sydney_annual_rainfall.txt
/*

How many years of rainfall totals? 10
Enter year: 2005
Enter rainfall(mm): 816
Enter year: 2006
Enter rainfall(mm): 994.0
Enter year: 2007
Enter rainfall(mm): 1499.2
Enter year: 2008
Enter rainfall(mm): 1082.6
Enter year: 2009
Enter rainfall(mm): 956.2
Enter year: 2010
Enter rainfall(mm): 1153.8
Enter year: 2011
Enter rainfall(mm): 1369.2
Enter year: 2012
Enter rainfall(mm): 1213.6
Enter year: 2013
Enter rainfall(mm): 1344.4
Enter year: 2014
Enter rainfall(mm): 893.8

1 asterisk == 100 mm of rainfall
2005 ********
2006 *********
2007 **************
2008 **********
2009 *********
2010 ***********
2011 *************
2012 ************
2013 *************
2014 ********
*/

#include <stdio.h>

#define N_YEARS  200000
#define SCALE    100

void printStars(int n);

//       0     1     2     3    4   5 .... 199999
//years 2005  2006  2007  2008
//rain  816    994
int main(void) {
    int years[N_YEARS];
    double rainfall[N_YEARS];
    int numYears;  
    printf("How many years of rainfall totals? ");
    scanf("%d",&numYears);
    
    int i = 0;
    while( i < numYears){
        
        printf("Enter year: ");
        scanf("%d",&years[i]);
        printf("Enter rainfall(mm):");          
        scanf("%lf",&rainfall[i]);
        i = i + 1;           
    }

    printf("1 asterisk == 100 mm of rainfall\n");
    i = 0;
    while( i < numYears){
        int numStars = rainfall[i]/100;
        printf("%d: ",years[i]);
        printStars(numStars);
        i = i + 1;
    }
    

    return 0;
}

//print n stars
void printStars(int n){
    int j = 0;
    while(j < n){
        printf("*");
        j = j + 1;
    } 
    printf("\n");
}