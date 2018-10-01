//
//  BTree.hpp
//  task34
//
//  Created by Danial on 30.09.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#ifndef BTree_hpp
#define BTree_hpp

#include "BNode.hpp"
#include <iostream>

class BTree
{
public:
    BTree();
    BTree(int key);
    void add_to_tree(int key);
    void show_tree();
    
private:
    BNode* root;
    void print(BNode* node);
    const int t = 2;
    void add_recursive (BNode* node, int key);
    
};

#endif /* BTree_hpp */

