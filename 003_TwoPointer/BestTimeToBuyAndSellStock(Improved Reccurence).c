#include <stdio.h>
#include <stdbool.h>

int MaxProfit(int* prices, int pricesSize){
    // input prices: [7, 1, 5, 3, 6, 4], numSize: 6
    // return 7 (because you can buy $1 at 2nd day and sell it at $5 at 3rd day to earn $4, and buy $3 at 4th day and sell it at $6 at 5th day to earn $3, totally earn $7)

    int profitsRecord[pricesSize + 1];            // use array to record max profit in each short period (dynamic programming method), and let profits[i] = MaxPorfit(prices, i).
    memset(profitsRecord, 0, sizeof profitsRecord);

    // if pricesSize == 1, means that we can only buy and can not sell, so our profit is 0.
    if (pricesSize <= 1) return 0;

    int max = 0;

    for (size_t i = 2; i <= pricesSize; i++) {
        // 1st condition: may we sell stocks at the last day?    
        // 1) if the answer is NO, the situation will become: [7, 1, 5, 3, 6, 4] <-> [7, 1, 5, 3, 6]
        //                                                    [7, 1, 5, 3, 6, 4] -> MaxProfit(prices, 6)
        //                                                    [7, 1, 5, 3, 6]    -> MaxProfit(prices, 5)
        int profit;
        
        profit = profitsRecord[i - 1];
        if (profit > max) {
            max = profit;
        }

        // 2) if the answer is YES, the situation will become:   NOT SELL AT LAST DAY |  SELL AT LAST DAY        b  s
        //     MaxProfit(prices, 6)            ->            MAX(MaxProfit(prices, 5),  [7, 1, 5, 3, 6]     +   [6, 4]) -> MaxProfit(prices, 5) + (4 - 6),  
        //                                                                              [7, 1, 5, 3]        +   [3, 4]) -> MaxProfit(prices, 4) + (4 - 3),
        //                                                                              [7, 1, 5]           +   [5, 4]) -> MaxProfit(prices, 3) + (4 - 5),
        //                                                                              [7, 1]              +   [1, 4]) -> MaxProfit(prices, 2) + (4 - 1),
        //                                                                              [7]                 +   [7, 4]) -> MaxProfit(prices, 1) + (4 - 7)) -> MAX(7, 7 + (-2), 4 + 1, 4 + (-1), 0 + 3, 0 + (-3)) = 7

        //     MaxProfit(prices, 5)            ->            MAX(MaxProfit(prices, 4),  [7, 1, 5, 3]        +   [3, 6]) -> MaxProfit(prices, 4) + (6 - 3),
        //                                                                              [7, 1, 5]           +   [5, 6]) -> MaxProfit(prices, 3) + (6 - 5),
        //                                                                              [7, 1]              +   [1, 6]) -> MaxProfit(prices, 2) + (6 - 1),
        //                                                                              [7]                 +   [7, 6]) -> MaxProfit(prices, 1) + (6 - 7)) -> MAX(4, 4 + 3, 4 + 1, 0 + 5, 0 + (-1)) = 7
        
        //     MaxProfit(prices, 4)            ->            MAX(MaxProfit(prices, 3),  [7, 1, 5]           +   [5, 3]) -> MaxProfit(prices, 3) + (3 - 5),  
        //                                                                              [7, 1]              +   [1, 3]) -> MaxProfit(prices, 2) + (3 - 1), 
        //                                                                              [7]                 +   [7, 3]) -> MaxProfit(prices, 1) + (3 - 7)) -> MAX(4, 4 + (-2), 0 + 2, 0 + (-4)) = 4
        
        //     MaxProfit(prices, 3)            ->            MAX(MaxProfit(prices, 2),  [7, 1]              +   [1, 5]) -> MaxProfit(prices, 2) + (5 - 1), 
        //                                                                              [7]                 +   [7, 5]) -> MaxProfit(prices, 1) + (5 - 7)) -> MAX(0, 0 + 4, 0 + (-2)) = 4
        
        //     MaxProfit(prices, 2)            ->            MAX(MaxProfit(prices, 1),  [7]                 +   [7, 1]) -> MaxProfit(prices, 1) + (1 - 7)) -> MAX(0, 0 + (-6)) = 0

        for (size_t j = 1; j <= i; j++) {
            profit = profitsRecord[j - 1] + prices[i - 1] - prices[j - 1];
            //printf("Current (i, j): (%d, %d)\nprofit = %d + %d - %d\n", i, j, profitsRecord[j], prices[i], prices[j - 1]);
            if (profit > max) {
                max = profit;
            }
        }
        profitsRecord[i] = max;
        //printf("profitsRecord[%d]: %d\n", i, profitsRecord[i]);

    }
      
    return max;

}

int main(void) {    
    int prices_1st[6] = {7, 1, 5, 3, 6, 4};
    int pricesSize = 6;
    int profit = MaxProfit(prices_1st, pricesSize);    
    printf("The profit we can earn in the 1st period is: $%d\n", profit);
    int prices_2nd[2] = {1, 2};
    pricesSize = 2;
    profit = MaxProfit(prices_2nd, pricesSize);
    printf("The profit we can earn in the 2nd period is: $%d\n", profit);
}