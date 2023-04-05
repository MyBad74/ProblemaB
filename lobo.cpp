#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print_dp_table(const vector<vector<int>>& dp) {
    for (const auto& row : dp) {
        for (const auto& val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int max_profit(int D, int K, vector<int>& shares, int fee) {
    vector<vector<int>> dp(D+1, vector<int>(K+1, 0));

    for (int i = 1; i <= D; i++) {
        int min_price = *min_element(shares.begin(), shares.begin()+i);
        for (int j = 1; j <= K; j++) {
            for (int k = 0; k <= min(j, i); k++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-k] + k*((shares[i-1]-min_price)-fee));
            }
        }
        print_dp_table(dp);
    }

    return dp[D][K];
}

int main() {
    int D = 5;
    int K = 3;
    // vector<int> shares = {100, 20, 40, 200, 170};
    vector<int> shares = {10, 10, 40, 10, 50};
    int fee = 10;

    cout << max_profit(D, K, shares, fee) << endl;

    return 0;
}

