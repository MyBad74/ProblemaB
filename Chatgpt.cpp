#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices, int N, int X) {
    int n = prices.size();
    vector<int> dp(n, 0);

    int max_profit = 0;
    int min_price = prices[0];

    for (int i = 1; i < n; i++) {
        min_price = min(min_price, prices[i]);

        if (i >= N) {
            min_price = min(min_price, prices[i - N] + X);
        }

        dp[i] = max(dp[i - 1], prices[i] - min_price);

        if (i >= N && (i - N) % N == 0) {
            max_profit = max(max_profit, dp[i - N] + prices[i] - min_price - X);
        }
    }

    return max_profit;
}

int main() {
    vector<int> prices = {100, 20, 40, 200, 170};
    int N = 3;
    int X = 10;

    cout << "Maximum profit: " << maxProfit(prices, N, X) << endl;

    return 0;
}
