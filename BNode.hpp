//
//  BTree.hpp
//  task34
//
//  Created by Danial on 30.09.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#ifndef BNode_hpp
#define BNode_hpp

//#include <set>
#include <vector>

using namespace std;

class BNode
{
public:
    BNode(); // constructor
    BNode(int key);
    friend class BTree;
    
private:
    vector<int> key;
    vector<BNode*> child;
    bool leaf;
    
    int count_keys;
    int count_child;
    
    const int t = 2;
};
#endif /* BTree_hpp */
