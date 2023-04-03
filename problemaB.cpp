#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;



int main(){

    int task;

    cin >> task;


    if (task == 1)
    {
        vector<int> valores;
        for (int i = 0; i < 4; i++)
        {

            int valor;
            cin >> valor;
            if (i == 0 && (valor > 100 || valor < 1)) {
                return 0;
            }
            if (i == 1 && (valor > 20000 || valor < 1)){
                return 0;
            }
            if (i == 2 && (valor > 200 || valor < 1)){
                return 0;
            }
            if (i == 3 && (valor > 100 || valor < 1)){
                return 0;
            }
            valores.push_back(valor);

            
        }
        cout << valores[0] << " " << valores[1] << " " << valores[2] << " " << valores[3] << endl;

        for (int i = 0; i < valores[0]; i++)
        {
            vector<int> val_share;

            for (int j = 0; j < valores[1]; j++)
            {
                int share; 
                cin >> share;
                if (share > 5000 || share < 1){
                    return 0;
                }
                val_share.push_back(share);
            }
            cout << "company number " << i+1 << ": " << val_share[0] << " " << val_share[1] << " " << val_share[2] << " " << val_share[3] << " " << val_share[4] << endl;

        }

    }

    if (task == 2)
    {
        
    }
    if (task == 3)
    {
        
    }
    
}


//compile with g++ problemaB.cpp -o problemaB