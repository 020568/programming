// C Program to find the minimum number of coins
// to construct a given amount using greedy approach

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) 
{
    return (*(int *)b - *(int *)a);
}

int minCoins(int coins[], int n, int amount) 
{
  
    // Sort the coins in descending order
    qsort(coins, n, sizeof(int), compare);
  
    int res = 0;
  
    // Start from the coin with highest denomination
    for(int i = 0; i < n; i++) 
	{
        if(amount >= coins[i]) 
		{
          
            // Find the maximum number of ith coin 
            // we can use
            int cnt = (amount / coins[i]);
          
            // Add the count to result
            res += cnt;
          
            // Subtract the corresponding amount from
            // the total amount
            amount -= (cnt * coins[i]);
        }
      
        // Break if there is no amount left
        if(amount == 0)
            break;
    }
    return res;
}

int main() 
{
    int coins[] = {5, 2, 10, 1};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 39;
  
    printf("%d", minCoins(coins, n, amount));
    return 0;
}