//
//  main.cpp
//  ex_1
//
//  Created by Danial on 08.09.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    int tmp = 1;
    
    for (int i = 0 ; i < 10 ; i++)
    {
        for ( int j = 0; j < 10; j++)
        {
            cout << tmp << " ";
            tmp ++;
        }
        cout << endl;
    }
    return 0;
}
