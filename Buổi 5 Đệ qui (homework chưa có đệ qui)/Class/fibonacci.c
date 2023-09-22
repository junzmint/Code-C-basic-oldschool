#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %i from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

int main()
{
    int n = 5;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}