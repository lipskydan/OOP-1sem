//
//  main.cpp
//  task5
//
//  Created by Danial on 09.09.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>

using namespace std;



struct Node
{
    Node* next;
    int data;
};

Node* create_list(const int data)
{
    Node* root = new Node;
    root->next = NULL;
    root->data = data;
    return root;
}

Node* add_element (Node* root, const int data, const int position)
{
    if ( root == NULL )
    {
        cerr << " root element is NULL " << endl;
        return NULL;
    }
    
    int i = 1;
    
    while ( i < position - 1 && root != NULL )
    {
        root = root->next;
        i++;
    }
    
    if ( i != position - 1)
    {
        cerr << " wrong position " << endl;
        return NULL;
    }
    Node* add = new Node;
    add->data = data;
    add->next = root->next;
    root->next = add;
    
    
    return add;
}

void show_list(Node* root)
{
    if ( root == NULL )
    {
        cerr << " root element is NULL " << endl;
        return;
    }
    
    while(root)
    {
        cout<<root->data << " " ;
        if (root->next)
        {
            cout<<" -> ";
        }
        root = root->next;
    }
    cout<<endl;
}



int main()
{
    Node* root;
    
    root = create_list(1);
    
    add_element(root, 2, 2);
    add_element(root, 4, 3);
    add_element(root, 5, 4);
    add_element(root, 3, 3);
    show_list(root);
    
    return 0;
}
