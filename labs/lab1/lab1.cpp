//
//  main.cpp
//  lab1
//
//  Created by Danial on 03.10.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>
#include "graph.hpp"
#include "graph.t.hpp"

using namespace std;

int main()
{
    int Size = 5;
    Graf<int> first(Size);
    first.initializeGraf();
    first.printAsList();
    first.printAsMatrix();
    first.informOfLinking();
    first.lenght();
    
    return 0;
}
