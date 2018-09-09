//
//  main.cpp
//  task7
//
//  Created by Danial on 09.09.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>
#include <time.h>
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

Node* push_back ( Node* root, const int data )
{
    while (root->next)
    {
        root = root->next;
    }
    
    Node* add = new Node;
    root->next = add;
    add->data = data;
    add->next = NULL;
    
    return add;
}

Node* pop_begin ( Node* root)
{
    delete root;
    return root->next;
}

int get_length ( Node* root )
{
    int Size = 0;
    while (root)
    {
        root = root->next;
        Size++;
    }
    return Size;
}

void copy_to_arr ( int Size, int arr[], Node* root)
{
    int i = 0;
    while ( root)
    {
        arr[i] = root->data;
        root = root->next;
        i++;
    }
}

void copy_to_list ( int Size, int arr[], Node* root)
{
    int i = 0;
    while ( root)
    {
        root->data = arr[i];
        root = root->next;
        i++;
    }
}

void copy_list ( Node* full, Node* empty )
{
    bool tmp = false;
    while(full)
    {
        if (!tmp)
        {
            empty->data = full->data;
            tmp = true;
        }
        else
        {
            push_back(empty, full->data);
        }
        full = full->next;
    }
}

void insertion_sort(int arr[], const unsigned size)
{
    int curr_elem;
    int last_index;
    for (int i = 1; i < size; i++)
    {
        curr_elem = arr[i];
        last_index = i - 1;
        
        while (last_index >= 0 && arr[last_index] > curr_elem)
        {
            arr[last_index + 1] = arr[last_index];
            arr[last_index] = curr_elem;
            last_index--;
        }
    }
}

void my_swap(int& first, int& second)
{
    int temp = first;
    first = second;
    second = temp;
}

void quick_sort(int arr[], const unsigned size)
{
    int left = 0;
    int right = size - 1;
    int p = arr[size >> 1];
    while (left < right)
    {
        while (arr[left] < p)
            left++;
        while (arr[right] > p)
            right--;
        if (left < right)
        {
            my_swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    if (left < size - 1)
    {
        quick_sort(arr, left + 1);
    }
    if (right > 0)
    {
        quick_sort(arr + right, size - right);
    }
    
}

int main() {
  
    Node* root1 = create_list(1);
    Node* root2 = create_list();
    
    push_back(root1, 20);
    push_back(root1, 13);
    push_back(root1, 48);
    push_back(root1, 5);
    push_back(root1, 50);
    push_back(root1, 15);
 
    int Size = get_length(root1);
    
    copy_list(root1, root2);
    
    cout << " Our list : ";
    show_list(root1);
   
    int arr1[Size];
    int arr2[Size];
    
    copy_to_arr(Size, arr1, root1);
    copy_to_arr(Size, arr2, root2);
    
    clock_t start = clock();
    quick_sort(arr1, Size);
    clock_t end = clock();
    
    clock_t result_of_quick_sort = (end - start);
    
    start = clock();
    insertion_sort(arr2, Size);
    end = clock();
    
    clock_t result_of_insertion_sort = (end - start);
    
    copy_to_list(Size, arr1, root1);
    copy_to_list(Size, arr2, root2);
    
    cout << "\n quick_sort : ";
    show_list(root1);
    cout << " result_of_quick_sort = " << result_of_quick_sort <<endl;
    
    cout << "\n insertion_sort : ";
    show_list(root2);
    cout << " result_of_insertion_sort = " << result_of_insertion_sort <<endl;
    
    return 0;
}
