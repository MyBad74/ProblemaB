#include <iostream>
using namespace std;

int main()
{
    int prices[5] = {100, 20, 40, 200, 170};
    int max_profit = 0;
    int transaction_cost = 10;

    for (int buy_day = 0; buy_day < 5; buy_day++)
    {
        int num_actions = 0;
        int profit = 0;

        for (int sell_day = buy_day + 1; sell_day < 5; sell_day++)
        {

            if (num_actions == 3)
            {
                for (int i = sell_day; i < 5; i++)
                {
                    if (3 * prices[i] > 3 * prices[sell_day] + 3 * transaction_cost)
                    {
                        profit += 3 * prices[i] - (3 * prices[sell_day] + 3 * transaction_cost);
                    }
                    cout << "  COMEÇO AQUI : " << prices[i] << endl;
                    cout << "  COMEÇO AQUI : (profit)" << profit << endl;
                }

                num_actions = 0;
            }

            if (3 * prices[sell_day] > 3 * prices[buy_day] + 3 * transaction_cost && num_actions == 0)
            {
                cout << "Buy day: " << buy_day << " Sell day: " << sell_day << endl;
                profit += 3 * prices[sell_day] - (3 * prices[buy_day] + 3 * transaction_cost);
                cout << "Profit: " << profit << endl;
                num_actions = 3;
            }
        }
        if (profit > max_profit)
        {
            max_profit = profit;
        }
    }

    cout << "Max profit: " << max_profit << endl;

    return 0;
}
