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

Node* create_list(const int data = 0)
{
    Node* root = new Node;
    root->next = NULL;
    root->data = data;
    return root;
}

Node* find_by_position (Node* root,  const int position)
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
    
    return root;
}

Node* add_element (Node* root, const int data, const int position)
{
    if ((root = find_by_position(root,position)) == NULL)
    {
        cerr << " find by position failed " << endl;
        return NULL;
    }
    
    Node* add = new Node;
    add->data = data;
    add->next = root->next;
    root->next = add;
    
    
    return add;
}

void erase_element (Node* root, const int position)
{
    if ((root = find_by_position(root,position)) == NULL)
    {
        cerr << " root element is NULL " << endl;
    }
    
    root->next = root->next->next;
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

void push_element ( Node* root, const int data)
{
    root->data = data;
    Node* add = new Node;
    root->next = add;
    add = NULL;
}

void add ( Node* root, const int data)
{
    while ( root->next)
    {
        root = root->next;
    }
    
    Node* add = new Node;
    root->next = add;
    add->data = data;
    add->next = NULL;
}


void split ( Node* root, Node* first, Node* second, const int N )
{
    if ( root == NULL )
    {
        cerr << " root element is NULL " << endl;
        return;
    }

    bool tmp1 = false;
    bool tmp2 = false;
    
    while(root)
    {
        if (root->data > N)
        {
            if (!tmp1)
            {
                first->data = root->data;
                tmp1 = true;
            }
            else
            {
                add(first, root->data);
                first = first->next;
            }
            
        }
        else
        {
            if (!tmp2)
            {
                second->data = root->data;
                tmp2 = true;
            }
            else
            {
                add(second, root->data);
                second = second->next;
            }
            
        }
    
        root = root->next;
    }
}



int main()
{
    Node* root = create_list(1);
    Node* first = create_list();
    Node* second = create_list();
    
    add_element(root, 2, 2);
    add_element(root, 4, 3);
    add_element(root, 5, 4);
    add_element(root, 3, 3);
    show_list(root);
    //erase_element(root, 3);
    // show_list(root);
    
    cout << endl << endl;
    
    split(root, first, second, 5);
    
    cout << " First list : ";
    show_list(first);
    cout << " Second list : ";
    show_list(second);
    
    
    return 0;
}
