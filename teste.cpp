#include <iostream>
using namespace std;

int main()
{
    int prices[25] = {10 ,4, 9 ,6 ,8 ,1, 9 ,4 ,10 ,4 ,5 ,8 ,4 ,6 ,8 ,2 ,5 ,4 ,3 ,2 ,8, 9 ,6 ,4 ,8};

    int max_profit = 0;
    int transaction_cost = 5;
    int acao = 5;
    int day = 25;

    for (int buy_day = 0; buy_day < day; buy_day++)
    {
        int num_actions = 0;
        int profit = 0;

        for (int sell_day = buy_day + 1; sell_day < day; sell_day++)
        {

            if (num_actions == 3)
            {
                for (int i = sell_day; i < day; i++)
                {
                    for( int j = i + 1; j < day; j++)
                    {
                        if (acao * prices[j] > acao * prices[i] + acao * transaction_cost)
                        {
                            profit += acao * prices[j] - (acao * prices[i] + acao * transaction_cost);
                        }
                        cout << "buy day: " << buy_day << " sell day: " << sell_day << " i: " << i << " j: " << j << endl;
                        cout << "Operacao do profit: acao * " << prices[j] << " - (acao * " << prices[i] << " + acao * " << transaction_cost << ")" << endl;
                        cout << "  COMECO AQUI : (profit)" << profit << endl;
                    }
                }
                if (profit > max_profit)
                {
                    max_profit = profit;
                    
                }
                num_actions = 0;
                cout << " profit: " << profit << endl;
            }

            cout << "Buy day: " << buy_day << " Sell day: " << sell_day << " | Buy money " << acao * prices[buy_day] + acao * transaction_cost << " Sell money " << acao * prices[sell_day] << endl;

            cout << "num actions" << num_actions << endl;
            cout << "Operacao do prof: acao * " << prices[sell_day] << " - (acao * " << prices[buy_day] << " + 2 * " << transaction_cost << ") : " << acao * prices[sell_day] - (acao * prices[buy_day] + acao * transaction_cost) << endl;
            if (acao * prices[sell_day] > acao * prices[buy_day] + acao * transaction_cost && num_actions == 0)
            {
                cout << "AAAAAAAAAA" << endl;
                cout << "Buy day: " << buy_day << " Sell day: " << sell_day << " | Buy money " << acao * prices[buy_day] + acao * transaction_cost << " Sell money " << acao * prices[sell_day] << endl;
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
