#include <stdio.h>
#include <stdbool.h>

int MaxSubarray(int* nums, int numsSize) {
    // input nums array: [-2, 1, -3, 4, -1, 2, 1, -5, 4], numsSize: 9
    // return [4, -1, 2, 1], Maximum: 6

    int max = nums[0];    // set current maximum
    // set the start index and end index
    size_t start_index, end_index = 0;

    for (size_t i = 1; i < numsSize; i++) {
        if (nums[i-1] > 0) nums[i] = nums[i-1] + nums[i];
        if (nums[i] > max) max = nums[i]; 
    }
    return max; 
}

int main(void) {
    int result = 0;
    int input_1st[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    result = MaxSubarray(input_1st, 9);
    printf("The max subarray summation is %d!\n", result);
    int input_2nd[2] = {-2, 1};
    result = MaxSubarray(input_2nd, 2);
    printf("The max subarray summation is %d!\n", result);
    }