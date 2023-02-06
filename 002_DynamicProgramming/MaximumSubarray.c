#include <stdio.h>
#include <stdbool.h>

int MaxSubarray(int* nums, int numsSize) {
    // input nums array: [-2, 1, -3, 4, -1, 2, 1, -5, 4], numsSize: 9
    // return [4, -1, 2, 1], Maximum: 6

    int max = nums[0];    // set current maximum

    // set the start index
    for (size_t i = 0; i < numsSize; i++) {
        // set the end index
        for (size_t j = i; j < numsSize; j++) {
            // compute the summation of the subarray
            int sum = 0;
            for (size_t k = i; k < j; k++) {
                sum = nums[k] + sum;
            }
            // if current summation > current maximum, set new maximum
            if (sum > max) {
                max = sum;
            }
        }
    }
    return max; 
}

int main(void) {
    int result = 0;
    int input[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    result = MaxSubarray(input, 9);
    printf("The max subarray summation is %d!", result);
    }