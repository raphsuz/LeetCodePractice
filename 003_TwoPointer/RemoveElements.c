#include <stdio.h>
#include <stdbool.h>

void RemoveElements(int* nums, int numsSize, int val){
    // input nums: nums = [3,2,2,3], numsSize = 4, val = 3
    // return 2, and nums = [2,2,_,_]

    // Set 2 indicator, 1 is faster, the other is slower.
    size_t slowIndicator = 0;
    for (size_t fastIndicator = 0; fastIndicator < numsSize; fastIndicator++) {
        if (nums[fastIndicator]==val) {
            continue;
        }
        else {
            nums[slowIndicator] = nums[fastIndicator];
            slowIndicator = slowIndicator + 1;
        }
    }
}

int main(void) {    
    int input[4] = {3, 2, 2, 3};
    int numsSize = 4;
    int val = 3;    
    RemoveElements(input, numsSize, val);
    for (int i = 0; i < numsSize; i++) {
        printf("Current elements in array: %d\n", input[i]);
    }    
}