#include <iostream>
using namespace std;

int main()
{
    int prices[5] = {1,5,4,2,5};
    int max_profit = 0;
    int transaction_cost = 1;

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
                    if (2 * prices[i] > 2 * prices[sell_day] + 2 * transaction_cost)
                    {
                        profit += 2 * prices[i] - (2 * prices[sell_day] + 2 * transaction_cost);
                    }
                    cout << "  COMECO AQUI : " << prices[i] << endl;
                    cout << "Operacao do prof: 2 * " << prices[i] << " - (2 * " << prices[sell_day] << " + 2 * " << transaction_cost << ")" << endl;
                    cout << "  COMECO AQUI : (profit)" << profit << endl;
                }
                if (profit > max_profit)
                {
                    max_profit = profit;
                }
                //num_actions = 0;
            }

            if (2 * prices[sell_day] > 2 * prices[buy_day] + 2 * transaction_cost )
            {
                cout <<"AAAAAAAAAA" << endl;
                cout << "Buy day: " << buy_day << " Sell day: " << sell_day << " | Buy money " << 2 * prices[buy_day] + 2 * transaction_cost << " Sell money " << 2 * prices[sell_day] << endl;
                profit = 2 * prices[sell_day] - (2 * prices[buy_day] + 2 * transaction_cost);
                cout << "Profit: " << profit << endl;
                num_actions = 3;
            }
            if (profit > max_profit)
            {
                max_profit = profit;
            }
        }
        cout << "_______________________________________________________________________________________" << endl;
    }

    cout << "Max profit: " << max_profit << endl;

    return 0;
}
