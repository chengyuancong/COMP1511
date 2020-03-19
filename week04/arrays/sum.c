// An example of different prototypes for simple array based functions
// Which function calls work and what do they do?

#include <stdio.h>


#define SIZE 3

int sum1(int nums[]);
int sum2(int nums[SIZE]);
int sum3(int nums[], int size);

int main(void) {
    int nums1[SIZE] = {1, 2, 3};
    int nums2[] = {1,2,3,4,5,6,7,8,9,10,11};
    int nums3[] = {3,1};
    
    int s1 = sum1(nums1);
    int s2 = sum1(nums2);
    int s3 = sum1(nums3);

    printf("%d\n",s1);
    printf("%d\n",s2);
    printf("%d\n",s3);
 
    int s3 = sum2(nums1);
    int s4 = sum2(nums2);
    int s5 = sum2(nums3);

    printf("%d\n",s3);
    printf("%d\n",s4);
    printf("%d\n",s5);
        
    int s6 = sum3(nums1,SIZE);
    int s7 = sum3(nums2, 11);
    int s8 = sum3(nums3,2);    
    int s9 = sum3(nums2,7);
   
    printf("%d\n",s6);
    printf("%d\n",s7);
    printf("%d\n",s8);
    printf("%d\n",s9);
 
    return 0;
}


// This can only be used to sum the first 'SIZE' elements of an array
int sum1(int nums[]){
    int sum = 0;
    int i = 0;
    while ( i < SIZE){
        sum = sum + nums[i];
        i = i + 1;
    }
    return sum;
}

//This can only be used to sum the first 'SIZE' elements of an array
int sum2(int nums[SIZE]){
    int sum = 0;
    int i = 0;
    while ( i < SIZE){
        sum = sum + nums[i];
        i = i + 1;
    }
    return sum;
}

//This can be used for any sized array, or to sum
//the first 'size' elements of an array
int sum3(int nums[], int size){
    int sum = 0;
    int i = 0;
    while ( i < size){
        sum = sum + nums[i];
        i = i + 1;
    }
    return sum;
}
