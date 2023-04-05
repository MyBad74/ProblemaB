#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int calculaT1(vector<int> &shares,int dias, int num_actions, int fee)
{
    
    int max_profit = 0;
    // cout << "shares: " << shares[0] << " " << shares[1] << " " << shares[2] << " " << shares[3] << " " << shares[4] << endl;
    // cout << "fee: " << fee << endl;
    // cout << "num_actions: " << num_actions << endl;

    for (int buy_day = 0; buy_day < dias; buy_day++)
    {
        int num_actions_aux = 0;
        int profit = 0;
        // cout << "BOAS" << endl;

        for (int sell_day = buy_day + 1; sell_day < dias; sell_day++)
        {

            if (num_actions_aux == num_actions)
            {
                for (int i = sell_day; i < dias; i++)
                {
                    if (num_actions * shares[i] > num_actions * shares[sell_day] + num_actions * fee)
                    {
                        profit += num_actions * shares[i] - (num_actions * shares[sell_day] + num_actions * fee);
                    }
                    // cout << "  COMECO AQUI : " << shares[i] << endl;
                    // cout << "  COMECO AQUI : (profit)" << profit << endl;
                }
                if (profit > max_profit)
                {
                    max_profit = profit;
                }
                //num_actions_aux = 0;
            }
            // cout << "num actions" << num_actions << endl;
            // cout << "shares buy day: " << shares[buy_day] << endl;
            // cout << "Buy day: " << buy_day << " Sell day: " << sell_day << " | Buy money " << num_actions * shares[buy_day] + num_actions * fee << " Sell money " << num_actions * shares[sell_day] << endl;

            if (num_actions * shares[sell_day] > num_actions * shares[buy_day] + num_actions * fee )
            {
                // cout << "Buy day: " << buy_day << " Sell day: " << sell_day << " | Buy money " << num_actions * shares[buy_day] + num_actions * fee << " Sell money " << num_actions * shares[sell_day] << endl;
                profit = num_actions * shares[sell_day] - (num_actions * shares[buy_day] + num_actions * fee);
                // cout << "Profit: " << profit << endl;
                num_actions_aux = num_actions;
            }
            if (profit > max_profit)
            {
                max_profit = profit;
            }
        }
        cout << "_______________________________________________________________________________________" << endl;
    }

    cout << "Max profit: " << max_profit << endl;

    return max_profit;
}

int main()
{

    int task;

    cin >> task;

    int max_profits[100];

    if (task == 1)
    {
        vector<int> valores;
        for (int i = 0; i < 4; i++)
        {

            int valor;
            cin >> valor;
            if (i == 0 && (valor > 100 || valor < 1))
            {
                return 0;
            }
            if (i == 1 && (valor > 20000 || valor < 1))
            {
                return 0;
            }
            if (i == 2 && (valor > 200 || valor < 1))
            {
                return 0;
            }
            if (i == 3 && (valor > 100 || valor < 1))
            {
                return 0;
            }
            valores.push_back(valor);
        }
        // cout << valores[0] << " " << valores[1] << " " << valores[2] << " " << valores[3] << endl;

        for (int i = 0; i < valores[0]; i++)
        {
            vector<int> val_share;

            for (int j = 0; j < valores[1]; j++)
            {
                int share;
                cin >> share;
                if (share > 5000 || share < 1)
                {
                    return 0;
                }
                val_share.push_back(share);
            }
            // cout << "company number " << i + 1 << ": " << val_share[0] << " " << val_share[1] << " " << val_share[2] << " " << val_share[3] << " " << val_share[4] << endl;
            // add the results from calculaT1 to the max_profits array
            max_profits[i] = calculaT1(val_share, valores[1] ,valores[2], valores[3]);
        }

        // print the max profits
        for (int i = 0; i < valores[0]; i++)
        {
            cout << "MAX PROFIT ["<< i <<"] : " << max_profits[i] << endl;
        }
    }

    if (task == 2)
    {
        vector<int> valores;
        for (int i = 0; i < 4; i++)
        {

            int valor;
            cin >> valor;
            if (i == 0 && (valor > 100 || valor < 1))
            {
                return 0;
            }
            if (i == 1 && (valor > 20000 || valor < 1))
            {
                return 0;
            }
            if (i == 2 && (valor > 200 || valor < 1))
            {
                return 0;
            }
            if (i == 3 && (valor > 100 || valor < 1))
            {
                return 0;
            }
            valores.push_back(valor);
        }
    }
    if (task == 3)
    {
        vector<int> valores;
        for (int i = 0; i < 4; i++)
        {

            int valor;
            cin >> valor;
            if (i == 0 && (valor > 100 || valor < 1))
            {
                return 0;
            }
            if (i == 1 && (valor > 25 || valor < 1))
            {
                return 0;
            }
            if (i == 2 && (valor > 5 || valor < 1))
            {
                return 0;
            }
            if (i == 3 && (valor > 5 || valor < 1))
            {
                return 0;
            }
            valores.push_back(valor);
        }
    }
}

// compile with g++ problemaB.cpp -o problemaB