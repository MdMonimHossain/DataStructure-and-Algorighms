#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, num, lower = 2, upper = 8;

    srand(time(0));

    for(i = 0; i < 10; i++)
    {
        num = (rand() % (upper - lower + 1)) + lower;
        printf("%d\n", num);
    }

    return 0;
}
