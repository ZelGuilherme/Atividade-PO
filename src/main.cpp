#include "../headers/dependencies.h"
#include "../headers/matrixManipulation.h"

using namespace std;

//Mat.csv:
// Valor        Valor           Valor           demanda
// Valor        Valor           Valor           demanda
// Valor        Valor           Valor           demanda
// oferta       oferta          oferta      total balanceado

//Onde tem -1 significa que está vazio

int main(){

    string fileMatrix = "mat.csv";
    string fileWeight = "pesos.csv";

    vector<vector<int>> matriz;
    vector<vector<int>> pesos;

    matriz = createMatrix(fileMatrix);
    pesos = createMatrix(fileWeight);

    printMatrix(matriz);
    printMatrix(pesos);

    vector<vector<int>> positionList = createSortedWeightPositionList(pesos);

    //Escrevi isso aqui morrendo de sono
    //Não tem um ponteiro nesse código, tá horrível
    if(isBalanced(matriz))
    {
        matriz[matriz.size()-1][matriz[0].size()-1] = getBalancedValue(matriz);
        printMatrix(matriz);

        for(int i = 0; i < matriz.size()-1; i++)
        {
            for(int j = 0; j < matriz[0].size()-1; j++)
            {
                if(matriz[i][j] == -1)
                {
                    int value = getInsertValue(matriz, i, j);
                    matriz[i][j] = value;

                    if(matriz[i][j] != -1)
                    {
                        matriz[i][matriz[0].size()-1] = matriz[i][matriz[0].size()-1] - value;
                        matriz[matriz.size()-1][j] = matriz[matriz.size()-1][j] - value;
                    }
                }
            }
        }

        printMatrix(matriz);
    }
    else
    {
        cout << "\n\nDEU RUIM PQ NAO TA BALANCEADO\n\n";
    }

    return 0;
}