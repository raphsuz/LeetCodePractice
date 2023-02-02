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

int IsHappy(int target) {
    // input nums: 19
    // return true;
    int turtle = target;
    int rabbit = target;
    // rabbit runs 2x speed faster than turtle
    // if the path loops like a circle, rabbit will meet turtle after a few steps
    do {
        turtle = ComputeNextTarget(turtle);
        rabbit = ComputeNextTarget(rabbit);
        rabbit = ComputeNextTarget(rabbit);
    } while (turtle != rabbit);

    if (rabbit == 1) return true;
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