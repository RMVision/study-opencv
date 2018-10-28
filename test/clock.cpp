//
// Created by niracler on 18-10-27.
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    long loop = 10000000L;
    double duration;
    clock_t start, end;
    printf("Time to do %ld empty loops is ", loop);
    start = clock();
    while (loop--);
    end = clock();
    duration = (double) (end - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);
    return (0);
}
