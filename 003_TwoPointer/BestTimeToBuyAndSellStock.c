#include <stdio.h>
#include <stdbool.h>

int MaxProfit(int* prices, int pricesSize){
    // input prices: [7, 1, 5, 3, 6, 4], numSize: 6
    // return 7 (because you can buy $1 at 2nd day and sell it at $5 at 3rd day to earn $4, and buy $3 at 4th day and sell it at $6 at 5th day to earn $3, totally earn $7)

    if (pricesSize <= 1) return 0;      // if pricesSize == 1, means that we can only buy and can not sell, so our profit is 0.

    int profit;
    int max = 0;

    // 1st condition: may we sell stocks at the last day?    
    // 1) if the answer is NO, the situation will become:  [7, 1, 5, 3, 6, 4] <-> [7, 1, 5, 3, 6]
    //                                                     [7, 1, 5, 3, 6, 4] -> MaxProfit(prices, 6)
    //                                                     [7, 1, 5, 3, 6]    -> MaxProfit(prices, 5)

    profit = MaxProfit(prices, pricesSize - 1);
    if (profit > max) {
        max = profit;
    }

    // 2) if the answer is YES, the situation will become:                            b  s
    //                                                   MAX([7, 1, 5, 3, 6]     +   [6, 4]) -> MaxProfit(prices, 5) + (4 - 6),  
    //                                                      ([7, 1, 5, 3]        +   [3, 4]) -> MaxProfit(prices, 4) + (4 - 3),
    //                                                      ([7, 1, 5]           +   [5, 4]) -> MaxProfit(prices, 3) + (4 - 5),
    //                                                      ([7, 1]              +   [1, 4]) -> MaxProfit(prices, 2) + (4 - 1),
    //                                                      ([7]                 +   [7, 4]) -> MaxProfit(prices, 1) + (4 - 7))

    for (size_t i = 1; i <= pricesSize - 1; i++) {
        profit = MaxProfit(prices, i) + prices[pricesSize - 1] - prices[i - 1];
        if (profit > max) {
            max = profit;
        }
    }   
    return max;
}

int main(void) {    
    int prices[6] = {7, 1, 5, 3, 6, 4};
    int pricesSize = 6;
    int profit = MaxProfit(prices, pricesSize);    
    printf("The most profit earned in the period is $%d!\n", profit);
    
}