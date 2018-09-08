//
//  main.cpp
//  ex_2
//
//  Created by Danial on 08.09.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>


using namespace std;

int main() {
    
    float *arr = new float;
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (rand() % 10 + 1) / float((rand() % 10 + 1));
        cout << arr[i] << " ";
    }
    
    
    return 0;
}
