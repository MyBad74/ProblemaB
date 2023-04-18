#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

int main() {
    int task;

    cin >> task;

    if (task == 1)  //_______________________________________TASK 1_________________________________________________________
    {
        vector<long long> valores;
        for (int i = 0; i < 4; i++) {
            long long valor;
            cin >> valor;

            valores.push_back(valor);
        }
        // cout << valores[0] << " " << valores[1] << " " << valores[2] << " " << valores[3] << endl;

        // auto inicio = high_resolution_clock::now();

        for (int i = 0; i < valores[0]; i++) {
            vector<long long> val_share;

            for (int j = 0; j < valores[1]; j++) {
                int share;
                cin >> share;
                if (share > 5000 || share < 1) {
                    return 0;
                }
                val_share.push_back(share);
            }

            vector<vector<long long>> dp(valores[1], vector<long long>(2, 0));

            dp[0][0] = 0;
            dp[0][1] = -valores[2] * (val_share[0] + valores[3]);

            long long max_profit = 0;

            for (int current_day = 1; current_day < valores[1]; current_day++) {
                dp[current_day][0] = max(dp[current_day - 1][0], dp[current_day - 1][1] + valores[2] * val_share[current_day]);

                dp[current_day][1] = max(dp[current_day - 1][1], dp[current_day - 1][0] - valores[2] * (val_share[current_day] + valores[3]));

                if (current_day >= valores[2]) {
                    max_profit = max(max_profit, dp[current_day - valores[2]][1] + valores[2] * val_share[current_day] - valores[2] * valores[3]);
                }

                dp[current_day][0] = max(dp[current_day][0], max_profit);
            }

            cout << dp[valores[1] - 1][0] << endl;
        }
    }

    if (task == 2)  //_______________________________________TASK 2_________________________________________________________
    {
        vector<long long> valores;
        for (int i = 0; i < 4; i++) {
            long long valor;
            cin >> valor;
            valores.push_back(valor);
        }

        for (int i = 0; i < valores[0]; i++) {
            vector<long long> val_share;

            for (int j = 0; j < valores[1]; j++) {
                int share;
                cin >> share;
                if (share > 5000 || share < 1) {
                    return 0;
                }
                val_share.push_back(share);
            }

            vector<vector<long long>> dp(valores[1], vector<long long>(2, 0));

            dp[0][0] = 0;
            dp[0][1] = -valores[2] * (val_share[0] + valores[3]);

            long long max_profit = 0;

            for (int current_day = 1; current_day < valores[1]; current_day++) {
                dp[current_day][0] = max(dp[current_day - 1][0], dp[current_day - 1][1] + valores[2] * val_share[current_day]);

                dp[current_day][1] = max(dp[current_day - 1][1], dp[current_day - 1][0] - valores[2] * (val_share[current_day] + valores[3]));

                if (current_day >= valores[2]) {
                    max_profit = max(max_profit, dp[current_day - valores[2]][1] + valores[2] * val_share[current_day] - valores[2] * valores[3]);
                }

                dp[current_day][0] = max(dp[current_day][0], max_profit);
            }

            cout << dp[valores[1] - 1][0] << endl;

            // percorrer o vetor de tras para a frente dp das acoes e ver quando houve compra print k, quando houve venda print -k e quando nao houve action print 0

            // print dp

            int current_day = valores[1] - 1;

            int lado = 0;

            int valor = dp[current_day][0];

            vector <int> guardar;
            

            //cout << "Current day: " << current_day << endl;

            while (current_day > 0) {
                // Çcout << "Curretn day in the while : " << current_day << endl;

                if (lado == 0) {
                    if (current_day == 1 && dp[current_day][0] == dp[current_day - 1][0]) {
                        // cout << 0 << " ";
                        guardar.push_back(0);
                        // current_day--;
                    }

                    if (valor == dp[current_day - 1][0]) {
                        // cout << 0 << " ";
                        guardar.push_back(0);
                        // current_day--;

                    } else {
                        // cout << -valores[2] << " ";
                        guardar.push_back(-valores[2]);
                        valor = dp[current_day][1];
                        lado = 1;

                        if (current_day == 1 && dp[current_day][1] == dp[current_day - 1][1]) {
                            // cout << valores[2] << " ";
                            guardar.push_back(valores[2]);
                            // current_day--;
                        }
                    }
                } else {
                    if (current_day == 1 && dp[current_day][1] == dp[current_day - 1][1]) {
                        // cout << valores[2] << " ";
                        guardar.push_back(valores[2]);
                        // current_day--;
                    }
                    
                    if (valor == dp[current_day - 1][1]) {
                        // cout << 0 << " ";
                        guardar.push_back(0);
                        // current_day--;

                    } else {
                        // cout << valores[2] << " ";
                        guardar.push_back(valores[2]);
                        //cout << "current day: " << current_day << endl;
                        valor = dp[current_day][0];
                        lado = 0;

                        if (current_day == 1 && dp[current_day][0] == dp[current_day - 1][0]) {
                            // cout << 0 << " ";
                            guardar.push_back(0);
                            // current_day--;
                        }
                    }
                }
                current_day--;
                // cout << "Current day end of the while : " << current_day << endl;
            }

            //invert the vector guardar

            for (int i = guardar.size() - 1; i >= 0; i--) {
                
                //when it reaches the last element of the vector dont print ""
                if (i == 0) {
                    cout << guardar[i];
                } else {
                    cout << guardar[i] << " ";
                }
            }
            cout << endl;
        }
    }
    if (task == 3) {
        vector<long long> valores;
        for (int i = 0; i < 4; i++) {
            long long valor;
            cin >> valor;

            valores.push_back(valor);
        }
    }
}

// compile with g++ problemaB.cpp -o problemaB