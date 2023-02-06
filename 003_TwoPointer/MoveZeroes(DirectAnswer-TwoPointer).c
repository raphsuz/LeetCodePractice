#include <stdio.h>
#include <stdbool.h>

void MoveZeroes(int* nums, int numsSize){
    // input nums: [0, 1, 0, 3, 12], numSize: 5
    // no return but shall output [1, 3, 12, 0, 0]

    // 2nd condition: find non-zero elements and move to top of the array
    //                locate the index where to swap value
    // two pointer: i & currentIndex
    // i > currentIndex
    // Because above condition, we can sort array in place
    size_t currentIndex = 0;
    for (size_t i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[currentIndex] = nums[i];
            currentIndex++;
        }        
    }
    for (currentIndex; currentIndex < numsSize; currentIndex++) {
        if (nums[currentIndex] != 0) {
            nums[currentIndex] = 0;
        }
    }
}

int main(void) {    
    int input[5] = {0, 1, 0, 3, 12};    
    int numsSize = 5;
    MoveZeroes(input, numsSize);
    for (size_t k = 0; k < numsSize; k++){
        printf("The %d element of array is %d!\n", k, input[k]);
    }    
}