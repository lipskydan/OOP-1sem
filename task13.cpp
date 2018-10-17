//
//  main.cpp
//  task13
//
//  Created by Danial on 16.10.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int** readFile(int& numRows, int& numColumns) {
    ifstream fin;
    fin.open("/Users/danial/Desktop/2 курс/OOP/task13/matrix.txt");
    fin >> numRows >> numColumns;
    
    int** matrix = new int*[numRows];
    for (int i = 0; i < numRows; i++)
        matrix[i] = new int[numColumns];
    
    for (int i(0); i < numRows; i++)
    {
        for (int j(0); j < numColumns; j++)
        {
            fin >> matrix[i][j];
        }
    }
    
    return matrix;
}

int main() {
    int numRows = 0;
    int numColumns = 0;
    int** matrix = readFile(numRows, numColumns);
    int currentSum = 0;
    int maxSum = 0;
    int x[2], y[2];
    
    for (int i(0); i < numRows; i++)
    {
        for (int j(0); j < numColumns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int y0 = 0; y0 < numRows; y0++) {
        for (int x0 = 0; x0 < numColumns; x0++) {
            for (int y1 = y0 + 1; y1 < numRows; y1++){
                for (int x1 = x0 + 1; x1 < numColumns; x1++) {
                    currentSum = matrix[y0][x0];
                    currentSum += matrix[y1][x1];
                    currentSum += matrix[y0][x1];
                    currentSum += matrix[y1][x0];
                   // cout << "currentSum = " << currentSum <<endl;
                    if (currentSum > maxSum)
                    {
                        x[0] = x0;
                        x[1] = x1;
                        y[0] = y0;
                        y[1] = y1;
                        maxSum = currentSum;
                    }
                    currentSum = 0;
                }
            }
        }
    }
    
    cout << "\
    nmaxSum: " << maxSum << endl;
    cout << "(" << x[0] << ";" << y[0] << ")" << "  " << "(" << x[1] << ";" << y[0] << ")" << endl;
    cout << "(" << x[0] << ";" << y[1] << ")" << "  " << "(" << x[1] << ";" << y[1] << ")" << endl;
    cout << matrix[y[0]][x[0]] << "  " << matrix[y[0]][x[1]] << endl;
    cout << matrix[y[1]][x[0]] << "  " << matrix[y[1]][x[1]] << endl;
   
}
