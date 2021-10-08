#include<stdio.h>

void tower(int n, char from, char aux, char to)
{
    if(n == 0)
        return;
    if(n == 1)
    {
        printf("Move disc %d from %c to %c\n", n, from, to);
        return;
    }
    tower(n - 1, from, to, aux);
    printf("Move disc %d from %c to %c\n", n, from, to);
    tower(n - 1, aux, from, to);
}

int main()
{
    tower(3, 'A', 'B', 'C');

    return 0;
}
