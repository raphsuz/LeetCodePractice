#include <stdio.h>

int singleNumber(int* nums, int numSize) {
    // input nums: [2, 2, 1]
    //         [2, 2, 1]
    // nums:    ^           (address)
    // numSize: 3
    // *(nums+0) == 2, *(nums+1) == 2, *(nums+2) == 1
    // return 1;

    // input nums: [4, 1, 2, 1, 2]
    // numSize: 5
    // return 4;
    int currentXOR = nums[0];
    for (int i = 1; i < numSize; i++) {
        currentXOR = currentXOR ^ nums[i];
    }
    return currentXOR;
}

int main(void) {
    int input_1st[3] = {2, 2, 1};
    printf("The 1st output : %d\n", singleNumber(&input_1st[0], 3));
    int input_2nd[5] = {4, 1, 2, 1, 2};
    printf("The 2nd output : %d\n", singleNumber(input_2nd, 5));
}