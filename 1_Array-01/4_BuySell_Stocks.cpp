#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>&prices){
    int n = prices.size();
    int MaximumProfit = 0;
    int MinPrices = INT_MAX;

    for(int i=0;i<n;i++){
        MinPrices = min(MinPrices, prices[i]);
        MaximumProfit = max(MaximumProfit , prices[i]-MinPrices);
    }
    return MaximumProfit;
}

int main (){
    vector<int> prices = {7,1,5,3,6,4};
    int result = maxProfit(prices);
    cout << "Maximum profit: " << result << endl;
    return 0;
}

/*
Time Complexity - O(n) 
Space Complexity - O(1)
*/

/*
    Approach :
    1. Initialize two variables: MaximumProfit to 0 and MinPrices to INT_MAX.
    2. Iterate through the prices array:
        - Update MinPrices to the minimum of MinPrices and the current price.
        - Calculate the potential profit by subtracting MinPrices from the current price.
        - Update MaximumProfit to the maximum of MaximumProfit and the potential profit.
    3. Return MaximumProfit as the result.
    4. The algorithm runs in O(n) time complexity and uses O(1) space complexity.

    Dry Run :
    prices = [7,1,5,3,6,4]
    n = 6
    MaximumProfit = 0
    MinPrices = INT_MAX

    Iteration 1: i = 0
        MinPrices = min(INT_MAX, 7) = 7
        MaximumProfit = max(0, 7 - 7) = 0

    Iteration 2: i = 1
        MinPrices = min(7, 1) = 1
        MaximumProfit = max(0, 1 - 1) = 0

    Iteration 3: i = 2
        MinPrices = min(1, 5) = 1
        MaximumProfit = max(0, 5 - 1) = 4

    Iteration 4: i = 3
        MinPrices = min(1, 3) = 1
        MaximumProfit = max(4, 3 - 1) = 4

    Iteration 5: i = 4
        MinPrices = min(1, 6) = 1
        MaximumProfit = max(4, 6 - 1) = 5

    Iteration 6: i = 5
        MinPrices = min(1, 4) = 1
        MaximumProfit = max(5, 4 - 1) = 5

    Final Result: MaximumProfit = 5
*/