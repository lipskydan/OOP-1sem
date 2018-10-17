//
//  main.cpp
//  task4
//
//  Created by Danial on 10.10.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>
#include <time.h>

using namespace std;

double func(double x, double y){
    return x*x + y*y;
}

int main()
{
    double x;
    double y;
    double upX = 1;
    double upY = 2*upX-1;
    double lowX = 0.5;
    double lowY = 0;
    
    double checkLowY = 0, checkUpY = 0;
    double sum = 0;

    int N;
    cout << "Enter N = ";
    cin >> N;
    
    srand(time_t(NULL));
    for (int i = 0; i < N; i++)
    {
        x = lowX + (upX - lowX)*(double(rand())/RAND_MAX);
        y = lowY + (upY - lowY)*(double(rand()) / RAND_MAX);
        
        checkUpY = 2 * x - 1;
        if ((y > checkLowY) && (y < checkUpY))
            sum += func(x, y);
    }
    
    cout << "Integral: " << sum*(upX-lowX)*(upY-lowY)/N << endl;
    return 0;
}
