#include <stdio.h>
#include <stdbool.h>

void MoveZeroes(int* nums, int numsSize){
    // input nums: [0, 1, 0, 3, 12], numSize: 5
    // no return but shall output [1, 3, 12, 0, 0]

    // 1st condition :the condition to end up
    //                it is easy to check whether correct or not
    // Variable checkIncorrect == -1 implies the checking process have not started; otherwise, checkIncorrect > 0 implies the checking process have started.
    int checkIncorrect = -1;
    while (checkIncorrect != 0) {
        checkIncorrect = 0;
        for (size_t i = 1; i < numsSize; i++) {
            if (nums[i-1] == 0 && nums[i] != 0) {
                // check uncomplete
                checkIncorrect++;
                // swap the element and zero-element
                int swap_t = nums[i-1];            
                nums[i-1] = nums[i];
                nums[i] = swap_t;
            }
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