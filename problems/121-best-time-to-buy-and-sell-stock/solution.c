#include <stdlib.h>


int max_profit(int* prices, int size) 
{
    int min_price = prices[0];
    int profit = 0;
    
    for (size_t i = 0; i < size; i++)
    {
        if (prices[i] - min_price > profit)
            profit = prices[i] - min_price;
        if (prices[i] < min_price)
            min_price = prices[i];
    }
    return profit;
}