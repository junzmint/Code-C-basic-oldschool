#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
    double width, length;
    if(argc != 3){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: RECT <WIDTH> <LENGTH>");
        return 1;
    }
    width = atof(argv[1]);
    length = atof(argv[2]);
    printf("The rectangle's area is %f\n", width * length);
    printf("The rectangle's perimeter is %f\n",2 * (width + length));
    return 0;
}