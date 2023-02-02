#include <stdio.h>
#include <stdbool.h>

// return the next TARGET Number
int ComputeNextTarget(int n) {
    int sum = 0;
    int exp = 10;
    while (n != 0) {        
        int digit = n % exp;        
        //printf("current nums: %d | creent digit: %d\n ", n, digit);
        n = n / exp;
        sum = digit * digit + sum;
        //printf("current sum: %d\n", sum);
    }
    return sum;
}

// check the target whether in the history records
bool Contains(int array[], size_t size, int target) {
    // input: array
    // purpose: to find target whether in array
    for (size_t i = 0; i < size; i++) {
        if (target == array[i]) return true;
        else continue;
    }
    return false;
}

int IsHappy(int target) {
    // input nums: 19
    // return true;
    int history[1000];      // record the path
    size_t size;            // the amount of the path

    // compute the 1st result number
    target = ComputeNextTarget(target);

    while (!Contains(history, size, target)) {
        history[size] = target;
        size++;

        target = ComputeNextTarget(target);
    }

    if (target == 1) return true;
    else return false;
}

int main(void) {
    bool result;
    int input = 19;
    result = IsHappy(input);
    if (result == true) printf("The number %d is a Happy Number!", input);
    else printf("The number %d is NOT a Happy Number.", input);
    //int input_2nd[5] = {4, 1, 2, 1, 2};
    //printf("The 2nd output : %d\n", singleNumber(input_2nd, 5));
}