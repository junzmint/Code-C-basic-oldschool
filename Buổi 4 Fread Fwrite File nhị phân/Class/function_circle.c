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

int InorOut(circle_t a){
    double OA = sqrt(a.center.x * a.center.x + a.center.y * a.center.y );
    if(OA < a.radius){
        return 1;
    }
    else if(OA = a.radius){
        return 2;
    }
    else{
        return 0;
    }
}


int main(int argc, char *argv[]){
    circle_t a;
    int m;
    if(argc != 4){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: ./function_circle <x> <y> <radius>");
        return 1;
    }
    a.center.x = atof(argv[1]);
    a.center.y = atof(argv[2]);
    a.radius = atof(argv[3]);
    m = InorOut(a);
    if(m == 0){
        printf("The point p is out of the circle.");
    }
    if (m == 1)
    {
        printf("The point p is covered by the circle.");
    }
    if (m == 2){
        printf("The point p is on the line of the circle.");
    }
    return 0;
}

