#include "../headers/dependencies.h"
#include <fstream>

vector<vector<int>> createMatrix(string fileName);
void printMatrix(vector<vector<int>> matrix);
int countDigits(int value);
bool isBalanced(vector<vector<int>> matrix);
int getBalancedValue(vector<vector<int>> matrix);
int getLinEndAt(vector<vector<int>> matrix, int line);
int getColEndAt(vector<vector<int>> matrix, int col);
int getInsertValue(vector<vector<int>> matrix, int line, int col);
vector<vector<int>> createSortedWeightPositionList(vector<vector<int>> weightList);
vector<vector<int>> copyMatrix(vector<vector<int>> matrix);