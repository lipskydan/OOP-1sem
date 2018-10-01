//
//  BTree.cpp
//  task34
//
//  Created by Danial on 30.09.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include "BTree.hpp"
#include <algorithm>

using namespace std;

BTree::BTree()
{
    root = new BNode;
    
}

BTree::BTree(int key)
{
    root = new BNode;
    root->key.push_back(key);
    root->count_keys++;
}

void BTree::add_to_tree(int key)
{
    if (root->count_keys < (2 * t) - 1)
    {
        /*for (int i = 0; i < root->count_keys; i++)
        {
            if (key < root->key[i])
            {
                add_recursive(root, key);
            }
        }*/
        root->key.push_back(key);
    }
    else
        add_recursive(root, key);
    
    root->count_keys++;
    
    sort(root->key.begin(), root->key.end());
}

void BTree::add_recursive (BNode* node, int key)
{
    for (int i = 0; i <= node->count_child; i++)
    {
        if (node->child[i] == NULL)
        {
            node->child[i] = new BNode(key);
            node->count_child++;
            break;
        }
    }
}

void BTree::show_tree()
{
    if (root == NULL)
    {
        cerr << " ERROR in show tree" <<endl;
        exit(0);
    }
    
    print(root);
    
}

void BTree::print(BNode* node)
{
    if(node == NULL)
        return;
    
    for (int i = 0; i < 2 * t; i++)
    {
        print(node->child[i]);
        
        if(i < node->key.size())
            cout << node->key[i] << " ";
    }
    print(node->child[2 * t]);
}
