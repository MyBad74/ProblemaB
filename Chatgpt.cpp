#include <iostream>
using namespace std;


int recursivade(int prices[5], int transaction_cost, int max_days, int acao, int day, int max_profit, int dia_compra, int array[5]){

    int dia_venda = 0;

    for (day; day < max_days; day++){
        int nex_day = day + 1;

        for(nex_day; nex_day < max_days; nex_day++){
            
            if(prices[day] > prices[nex_day] && acao == 2){
                break;
            }
            
            if(prices[day] < prices[nex_day] && acao == 2 && (acao * prices[nex_day] > acao*(transaction_cost + prices[day])) ){

                int profit = acao * prices[nex_day] - acao*(transaction_cost + prices[day]);

                //print day and buys 

                cout << "dia de compra: " << day << " dia de venda: " << nex_day << endl;

                cout << "profit: " << profit << endl;
                

                if(profit >= max_profit)
                {
                    cout << "dia de compra: " << day << " dia de venda: " << nex_day << endl;

                    cout << "profit: " << profit << endl;

                    if (dia_compra != day && dia_venda != nex_day){
                        max_profit += profit;
                    } else {
                        max_profit = profit;
                    }
                    
                    dia_venda = nex_day;
                    dia_compra = day;

                    // cout << "dia de compra: " << day << " dia de venda: " << dia_venda << endl;
                    // cout << "Profit: " << max_profit << endl;

                    if(max_profit > array[day]){
                        array[day] = max_profit;
                    }
                    max_profit = recursivade(prices, transaction_cost, max_days, acao, dia_venda + 1, max_profit, dia_compra);

                }
            }
        }

    }

    return max_profit;


}


int main()
{
    int prices[5] = {1, 5, 4 ,2 ,5};

    int transaction_cost = 1;
    int acao = 2;
    int max_days = 5;
    int array[5] = {0,0,0,0,0};

    cout << recursivade(prices, transaction_cost, max_days, acao, 0, 0, 0, array) << endl;



    return 0;
}
