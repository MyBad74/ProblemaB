#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int recursivade(vector<int> &shares, int transaction_cost, int max_days, int acao, int day, int max_profit, int dia_compra){

    int dia_venda = 0;

    for (day; day < max_days; day++){
        int nex_day = day + 1;

        for(nex_day; nex_day < max_days; nex_day++){

            if(shares[day] < shares[nex_day] && (acao * shares[nex_day] > acao*(transaction_cost + shares[day])) ){

                int profit = acao * shares[nex_day] - acao*(transaction_cost + shares[day]);

                if(profit >= max_profit)
                {
                    if (dia_compra != day && dia_venda != nex_day){
                        max_profit += profit;
                    } else {
                        max_profit = profit;
                    }
                    
                    dia_venda = nex_day;
                    dia_compra = day;

                    // cout << "dia de compra: " << day << " dia de venda: " << dia_venda << endl;
                    // cout << "Profit: " << max_profit << endl;

                    max_profit = recursivade(shares, transaction_cost, max_days, acao, dia_venda + 1, max_profit, dia_compra);

                }
            }
        }
    }

    return max_profit;

}

long long task1(const vector<int>& shares, int d, int k, int r) {

    vector<vector<long long>> dp(d, vector<long long>(2, 0));

    // Inicializa o vector DP
    dp[0][0] = 0;  // dar hold a 0 shares inicialmente
    dp[0][1] = -k * (shares[0] + r);  // comprar k shares

    // Preenchimento do vector DP
    long long maxProfitInWindow = dp[0][0];

    for (int i = 1; i < d; i++) {
        // Calcula o profit máximo se não tivermos a dar hold a nenhuma share
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + k * shares[i]);

        // Calcula o profit máximo se tivermos a dar hold a k shares
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - k * (shares[i] + r));

        // Verifica se é mais rentável esperar para vender as shares num dia futuro com maior profit
        if (i >= k) {
            maxProfitInWindow = max(maxProfitInWindow, dp[i-k][1] + k * shares[i] - k * r);
        }


        dp[i][0] = max(dp[i][0], maxProfitInWindow);
    }

    //print dp

    cout << "\nTABELA DP" << endl;

    for (int i = 0; i < d; i++){

        for (int j = 0; j < 2; j++){
            
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "---------------------" << endl;

    // no final todas as shares estão vendidas
    return dp[d-1][0];
}

int main()
{

    int task;

    cin >> task;

    long long int max_profits[100];

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

        auto inicio = high_resolution_clock::now();

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

            // print val_share, valores[3], valores[1], valores[2]
            //val_share são é o custo de cada ação
            //valores[3] => ultimo valor da linha
            //valores[1] => numero de dias
            //valores[2] => preço acrescido

            max_profits[i] = task1(val_share, valores[1], valores[2], valores[3]);
            

        }

        // print the max profits
        for (int i = 0; i < valores[0]; i++)
        {
            cout << max_profits[i] << endl;
        }

        auto fim = high_resolution_clock::now();

        auto duracao = duration_cast<microseconds>(fim - inicio); // Calcula a duracao em microsegundos

        //make duracao in seconds

        duracao = duracao;

        //cout << "A funcao levou " << duracao.count() << " microssegundos para executar." << endl;

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