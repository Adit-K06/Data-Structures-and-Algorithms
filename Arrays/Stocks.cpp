#include <iostream>
#include <vectors>
#include <unordered_map>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = 0;
    int profit = 0;

    for(int i = 0; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);
        profit = max(profit, prices[i] - minPrice);
    }

    return profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(prices);

    return 0;
}