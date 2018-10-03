//
//  Graph.hpp
//  lab_1
//
//  Created by Danial on 03.10.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

template<class T> class Graf
{
public:
    Graf(int size);
    void initializeGraf();
    void printAsMatrix();
    void printAsList();
    bool isLinked();
private:
    int mData;
    vector<set<int>> mList;
    vector<int> vec1;
    vector<int> vec2;
    vector<int> vec_full;
};

#endif /* Graph_hpp */
