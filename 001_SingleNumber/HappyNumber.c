#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int ComputeN(int n) {
    int sum = 0;
    int exp = 10;
    while (n != 0) {        
        int digit = n % exp;        
        printf("current nums: %d | creent digit: %d\n ", n, digit);
        n = n / exp;
        sum = digit * digit + sum;
        printf("current sum: %d\n", sum);
    }
    return sum;
}

bool contains(int array[], int size, int target) {
    // input: array
    // purpose: to find target whether in array
    for (int i = 0; i < size; i++) {
        if (target == array[i]) return true;
        else continue;
    }
    return false;
}

int isHappy(int n, int history[], size_t times) {
    // input nums: [19]
    // return true;
    int next_N;
    next_N = ComputeN(n);
    times += 1;
    int *next_history = (int *) malloc(times * sizeof(int));
    for (size_t i = 0; i < times; i++) {
        if (i != (times - 1)) continue;
        else next_history[i] = next_N;
    }
    printf("history : %d", history);
    if (next_N == 1) return true;
    else if (!contains(history, n, next_N)) return ComputeN(next_N);
    return false;
}

int main(void) {
    bool result;
    int input_1st = 19;
    size_t times = 1;
    int *history = (int *) malloc(times * sizeof(int));
    result = isHappy(input_1st, history, times);
    if (result == true) printf("True");
    else printf("False");
    //int input_2nd[5] = {4, 1, 2, 1, 2};
    //printf("The 2nd output : %d\n", singleNumber(input_2nd, 5));
}