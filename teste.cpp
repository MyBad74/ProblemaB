#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*

N: o número de empresas (companhias) que John está considerando adicionar ao seu portfólio.
d: o número de dias de valores diários de ações que John tem para cada empresa.
k: o número máximo de ações que John pode ter de uma única empresa.
R: a taxa fixa cobrada pela bolsa de valores por cada ação comprada.

*/

bool validate_input(int task, int n, int d, int k, int r, const vector<vector<int>> &companies_prices)
{
    if (n < 1 || n > 100)
    {
        return false;
    }

    if (task == 1 || task == 2)
    {
        if (d < 1 || d > 20000)
        {
            return false;
        }
        if (k < 1 || k > 2000)
        {
            return false;
        }
        if (r < 1 || r > 100)
        {
            return false;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (companies_prices[i][j] < 1 || companies_prices[i][j] > 5000)
                {
                    return false;
                }
            }
        }
    }
    else if (task == 3)
    {
        if (d < 1 || d > 50)
        {
            return false;
        }
        if (k < 1 || k > 5)
        {
            return false;
        }
        if (r < 1 || r > 5)
        {
            return false;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (companies_prices[i][j] < 1 || companies_prices[i][j] > 10)
                {
                    return false;
                }
            }
        }
    }
    else
    {
        return false;
    }

    return true;
}

long long int calcula_lucro_maximo(vector<int> &shares, int dias, int num_actions, int fee)
{
    // Cria um vetor auxiliar para armazenar os lucros máximos para cada dia
    vector<int> max_profits(dias);

    // Inicializa o último elemento do vetor com zero
    max_profits[dias - 1] = 0;

    // Percorre os dias de trás para frente, calculando os lucros máximos para cada dia
    for (int i = dias - 2; i >= 0; i--)
    {
        int max_profit_dp = 0;
        for (int j = i + 1; j < dias; j++)
        {
            int profit = 0;

            // Calcula o lucro máximo para o intervalo de dias [i, j]
            for (int k = i; k < j; k++)
            {
                if (num_actions * shares[j] > num_actions * shares[k] + num_actions * fee)
                {
                    profit = max(profit, num_actions * shares[j] - (num_actions * shares[k] + num_actions * fee));
                }
            }

            // Atualiza o lucro máximo para o intervalo [i, dias-1] usando o lucro máximo para o intervalo [j, dias-1]
            max_profit_dp = max(max_profit_dp, profit + max_profits[j]);
        }

        // Armazena o lucro máximo para o dia i no vetor auxiliar
        max_profits[i] = max_profit_dp;
    }

    // Retorna o lucro máximo para o intervalo [0, dias-1]
    return max_profits[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("testes\\teste_enunciado1.in", "r", stdin);
    //  freopen("testes\\extra0.in", "r", stdin);
    //  freopen("testes\\extra1.in", "r", stdin);
    //  freopen("testes\\extra2.in", "r", stdin);

    int task,
        n, d, k, r;
    cin >> task >> n >> d >> k >> r;

    vector<vector<int>> companies_prices(n, vector<int>(d));
    vector<vector<int>> memo(d + 1, vector<int>(d + 1, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> companies_prices[i][j];
        }
    }

    if (!validate_input(task, n, d, k, r, companies_prices))
    {
        return 1;
    }

    if (task == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << calcula_lucro_maximo(companies_prices[i], d, k, r) << endl;
        }
    }

    return 0;
}

// Run: g++ main.cpp -o main; ./main