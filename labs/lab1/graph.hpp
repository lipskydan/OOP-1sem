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

using namespace std;

template<class T> class Graf
{
public:
    Graf(int size);
    void initializeGraf();
    void printAsMatrix();
    void printAsList();
    bool isLinked();
    bool checked(int a, vector<int> vec);
    void informOfLinking();
    void showVec();
private:
    int mData;
    vector<set<int>> mList;
    vector<int> vec;
};

#endif /* graph_hpp */
