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