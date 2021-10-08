#include<stdio.h>
#include<time.h>

int main()
{
    clock_t start_time, end_time;
    double time_difference;

    start_time = clock();

    for(int i = 0; i < 5000; i++)
        for(int j = 0; j < 1000; j++)

    end_time = clock();

    time_difference = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Time taken %lf sec", time_difference);

    return 0;
}
