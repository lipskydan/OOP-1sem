//
//  BTree.cpp
//  task34
//
//  Created by Danial on 30.09.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include "BNode.hpp"
using namespace std;

BNode::BNode()
{
   child.resize(2 * t + 1, NULL);
    leaf = false;
    count_keys = 0;
    count_child = 0;
}

BNode::BNode(int key)
{
    child.resize(2 * t + 1, NULL);
    leaf = false;
    count_keys = 1;
    count_child = 0;
    this->key.push_back(key);
}
