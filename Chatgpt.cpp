#include <iostream>
using namespace std;

int main()
{
    int prices[5] = {100, 20, 40, 200, 170};
    int max_profit = 0;
    int transaction_cost = 10;
    int acao = 3;

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
                    if (acao * prices[i] > acao * prices[sell_day] + acao * transaction_cost)
                    {
                        profit += acao * prices[i] - (acao * prices[sell_day] + acao * transaction_cost);
                        num_actions = 0;
                    }
                    cout << "buy day: " << buy_day << " sell day: " << sell_day << " i: " << i << endl;
                    cout << "Operacao do profit: 3 * " << prices[i] << " - (3 * " << prices[sell_day] << " + 3 * " << transaction_cost << ")" << endl;
                    cout << "  COMECO AQUI : (profit)" << profit << endl;
                }
                if (profit > max_profit)
                {
                    max_profit = profit;
                }
                num_actions = 0;
            }
            cout << "Buy day: " << buy_day << " Sell day: " << sell_day << " | Buy money " << 2 * prices[buy_day] + 2 * transaction_cost << " Sell money " << 2 * prices[sell_day] << endl;

            cout << "num actions" << num_actions << endl;
            cout << "Operacao do prof: 2 * " << prices[sell_day] << " - (2 * " << prices[buy_day] << " + 2 * " << transaction_cost << ") : " << 2 * prices[sell_day] - (2 * prices[buy_day] + 2 * transaction_cost) << endl;
            if (acao * prices[sell_day] > acao * prices[buy_day] + acao * transaction_cost && num_actions == 0)
            {
                cout << "AAAAAAAAAA" << endl;
                cout << "Buy day: " << buy_day << " Sell day: " << sell_day << " | Buy money " << 2 * prices[buy_day] + 2 * transaction_cost << " Sell money " << 2 * prices[sell_day] << endl;
                profit = acao * prices[sell_day] - (acao * prices[buy_day] + acao * transaction_cost);
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
