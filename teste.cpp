#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numTask;
    cin >> numTask;

    if (numTask == 1) {
        int N, D, K, R;
        cin >> N >> D >> K >> R;

        for (int i = 0; i < N; i++) {
            vector<int> price(D);
            for (int j = 0; j < D; j++) {
                cin >> price[j];
            }

            vector<vector<long long>> tabela(D, vector<long long>(2, 0));

            tabela[0][0] = 0;
            tabela[0][1] = -K * (price[0] + R);

            long long maxProfitInWindow = tabela[0][0];
            for (int i = 1; i < D; i++) {
                // Profit selling the shares
                tabela[i][0] = max(tabela[i - 1][0], tabela[i - 1][1] + K * price[i]);

                // Profit buying or holding the shares
                tabela[i][1] = max(tabela[i - 1][1], tabela[i - 1][0] - K * (price[i] + R));
            }

            long long maxProfit = tabela[D - 1][0];

            cout << maxProfit << endl;
        }
    } else if (numTask == 2) {
        /* code */
    } else if (numTask == 3) {
        /* code */
    }

    return 0;
}