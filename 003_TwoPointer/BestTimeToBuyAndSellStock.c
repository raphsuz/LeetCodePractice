#include <stdio.h>
#include <stdbool.h>

void MaxProfit(int* prices, int numsSize){
    // input prices: [7, 1, 5, 3, 6, 4], numSize: 6
    // return 7 (because you can buy $1 at 2nd day and sell it at $5 at 3rd day to earn $4, and buy $3 at 4th day and sell it at $6 at 5th day to earn $3, totally earn $7)

    // 1st condition :the condition to end up
    //                it is easy to check whether correct or not
    

}

int main(void) {    
    int input[5] = {0, 1, 0, 3, 12};
    int numsSize = 5;
    MaxProfit(input, numsSize);
    for (size_t k = 0; k < numsSize; k++){
        printf("The %d element of array is %d!\n", k, input[k]);
    }
    
}