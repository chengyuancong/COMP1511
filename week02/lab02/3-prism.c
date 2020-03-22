//z5285978
#include<stdio.h>
int main(void){
    int length, width, height;
    printf("Please enter prism length: ");
    scanf("%d", &length);
    printf("Please enter prism width: ");
    scanf("%d", &width);
    printf("Please enter prism height: ");
    scanf("%d", &height);
    int volume = length*width*height;
    int area = 2*length*width + 2*width*height + 2*length*height;
    int edge_length = 4*(length+width+height);
    printf("A prism with sides %d %d %d has:\n", length, width, height);
    printf("Volume      = %d\n", volume);
    printf("Area        = %d\n", area);
    printf("Edge length = %d\n", edge_length);
    return 0;
}
//when length width height all equal 2000,the results is over 32 bits and overflow