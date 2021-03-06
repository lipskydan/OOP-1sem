//
//  graph.hpp
//  lab1
//
//  Created by Danial on 03.10.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <list>

using namespace std;

template<class T> class Graf
{
public:
    Graf(int size);
    ~Graf();
    void initializeGraf();
    void printAsMatrix();
    void printAsList();
    bool isLinked();
    bool informOfLinking();
    void lenght();
    
private:
    int mData;
    vector<set<int>> mList;
    vector<int> vecLink;
    vector<int> vecLenght;
    bool checked(int a, vector<int> vec);
    int checked2(int a, vector<set<int>> vec, int index);
    void showVec();
};

#endif /* graph_hpp */
