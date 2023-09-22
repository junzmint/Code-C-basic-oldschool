#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1000
bool check(char str[], int start, int end)
{
    int n = strlen(str);

    if (n == 0)
        return true;

    if (start == end)
    return true;
 
    if (str[start] != str[end])
    return false;
 
    if (start < end + 1)
    return check(str, start + 1, end - 1);
}

int main(int argc, char * argv[])
{
    char str[MAX];
    strcpy(str, argv[1]);
    int n = strlen(str);
    if (check(str, 0, n - 1))
        printf("Palindrome string!");
    else
        printf("Not a palindrome string!");
    return 0;
}