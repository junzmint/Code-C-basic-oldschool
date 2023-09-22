#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1000

typedef struct ponit
{
    double x;
    double y;
}point_t;

typedef struct circle
{
    point_t center;
    double radius;
}circle_t;

int Check(circle_t a, circle_t b){
    double distance =sqrt(pow(abs(a.center.x - b.center.x), 2) + pow(abs(a.center.y - b.center.y), 2));
    if(distance < (a.radius + b.radius)){
        return 1;
    }
    else if(distance== (a.radius + b. radius))
    {
        return 2;
    }
    else{
        return 0;
    }
}

int main(int argc, char *argv[]){
    if(argc != 7){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: ./function_circle <x of circle a> <y of circle a> <radius of circle a> <x of circle b> <y of circle b> <radius of circle b>");
        return 1;
    }
    circle_t a,b;
    a.center.x = atof(argv[1]);
    a.center.y = atof(argv[2]);
    a.radius = atof(argv[3]);
    b.center.x = atof(argv[4]);
    b.center.y = atof(argv[5]);
    b.radius = atof(argv[6]);
    if(Check(a,b) == 0){
        printf("2 hinh tron khong giao nhau");
    }
    else if(Check(a,b)==1){
        printf("2 hinh tron giao nhau");
    }
    else if(Check(a,b)==2){
        printf("2 hinh tron tiep xuc nhau");
    }
    return 0;
}