#include "../headers/matrixManipulation.h"
#include <sstream>
#include <bits/stdc++.h> 

//Lê arquivo e cria matriz de tamanho especificado
vector<vector<int>> createMatrix(string fileName){

    fstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        cerr << "\n\nFALHA AO ABRIR O ARQUIVO\n\n" << endl;
    }

    vector<vector<int>> matrix;

    string lineRead;
    while(getline(inputFile, lineRead))
    {
        stringstream lineStream(lineRead);
        string cell;
        vector<int> parsedRow;
        while(getline(lineStream,cell,','))
        {
            parsedRow.push_back(stoi(cell));
        }

        matrix.push_back(parsedRow);
    }

    inputFile.close();

    return matrix;
}

//Retorna a quandidade de digitos em um numero inteiro
int countDigits(int number){
    int digits;
    number < 0 ? digits = 1 : digits = 0;
    do {
        number /= 10;
        digits++;
        }
        while(number != 0);
    
    return digits;
}

//Imprime matriz
void printMatrix(vector<vector<int>> matrix){
    cout << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            int space = 10;
            int spaceRemove = 0;

            if(i == matrix.size()-1 || j == matrix[0].size()-1)
            {
                spaceRemove = countDigits(matrix[i][j]) + 1;
                cout << "*" << matrix[i][j];
            }
            else
            {
                spaceRemove = countDigits(matrix[i][j]);
                cout << matrix[i][j];
            }
                
            for(space; space > spaceRemove; space--){
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Confere se demanda e oferta estão balanceados
bool isBalanced(vector<vector<int>> matrix){
    int somaLin = 0;
    int somaCol = 0;

    //matrix.size() = profundidade da matriz
    //matrix[0].size() = largura da matriz

    //Soma o valor final de cada linha
    for(int i = 0; i < matrix.size(); i++)
    {
        somaLin += matrix[i][matrix[0].size()-1];
    }

    //Soma o valor final de cada coluna
    for(int j = 0; j < matrix[0].size(); j++)
    {
        somaCol += matrix[matrix.size()-1][j];
    }

    if(somaLin == somaCol)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getBalancedValue(vector<vector<int>> matrix)
{
    int somaLin = 0;

    //Soma o valor final de cada linha
    for(int i = 0; i < matrix.size(); i++)
    {
        somaLin += matrix[i][matrix[0].size()-1];
    }

    return somaLin;
}


//Pega o valor no fim da linha (I.E: Demanda)
int getLinEndAt(vector<vector<int>> matrix, int line)
{
    return matrix[line][matrix[0].size()-1];
}

//Pega o valor no fim da coluna (I.E: Oferta)
int getColEndAt(vector<vector<int>> matrix, int col)
{
    return matrix[matrix.size()-1][col];
}


int getInsertValue(vector<vector<int>> matrix, int line, int col)
{
    if(matrix[line][matrix[0].size()-1] < matrix[matrix.size()-1][col]
        && matrix[line][matrix[0].size()-1] != 0
        && matrix[matrix.size()-1][col] != 0)
    {
        return matrix[line][matrix[0].size()-1];
    }
    else if(matrix[line][matrix[0].size()-1] != 0
        && matrix[matrix.size()-1][col] != 0)
    {
        return matrix[matrix.size()-1][col];
    }
    else
    {
        return -1;
    }
}

//Retorna 
vector<vector<int>> createSortedWeightPositionList(vector<vector<int>> weightList)
{
    //Cria um vetor 2 * tamanho matriz iniciando tudo com 9999
    vector<vector<int>> posList(2, vector<int>(weightList.size() * weightList[0].size(), 9999));

    vector<int> listaAux;
    for(int i = 0; i < weightList.size(); i++)
    {
        for(int j = 0; j < weightList[0].size(); j++)
        {
            listaAux.push_back(weightList[i][j]);
        }
    }

    sort(listaAux.begin(), listaAux.end());

    for(int x = 0; x < listaAux.size(); x++)
    {
        for(int y = 0; y < weightList.size(); y++)
        {
            for(int z = 0; z < weightList[0].size(); z++)
            {
                if(listaAux[x] == weightList[y][z]
                    && posList[0][x] == 9999
                    && posList[1][x] == 9999)
                {
                    posList[0][x] = y;
                    posList[1][x] = z;
                    weightList[y][z] = -1;
                }
            }
        }
    }

    // for(int HAHA = 0; HAHA < listaAux.size(); HAHA++)
    // {
    //     cout << listaAux[HAHA] << " ";
    // }

    return posList;
}
