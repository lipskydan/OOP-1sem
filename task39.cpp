//
//  main.cpp
//  task39
//
//  Created by Danial on 10.09.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void create_arr (int Size, int** arr)
{
    for ( int i = 0; i < Size; i++)
    arr[i] = new int[Size];
}

void add_to_arr ( const int Size, int** arr)
{
    for ( int i = 0; i < Size; i++)
    {
        for ( int j = 0; j < Size; j++)
        {
            if ( i != j)
            {
                cout << " Friendship between " << i << " and " << j << " is ";
                cin >> arr[i][j];
            }
            else arr[i][j] = 2;
        }
    }
}

void show_arr (const int Size, int** arr)
{
    cout << " ------ show_arr ------ " <<endl;
    for ( int i = 0; i < Size; i++)
    {
        for ( int j = 0; j < Size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void function_for_first_step (const int Size, int** arr, vector<int> &vec1, vector<int> &vec2)
{
    bool tmp = false;
    for ( int i = 0; i < Size; i++)
    {
        tmp = false;
        for ( int j = 0; j < Size; j++)
        {
            if (arr[i][j] == 1)
            {
                if (tmp == false)
                {
                    vec1.push_back(i);
                    tmp = true;
                }
                vec2.push_back(j);
            }
        }
    }
    
}

void function_for_second_step (const int Size, int** arr, vector<int> &vec1, vector<int> &vec2)
{
    for ( int i = 0; i < vec2.size(); i++)
    {
        for ( int j = 0; j < Size; j++)
        {
            if ( arr[vec2[i]][j] == 1)
            {
                vec1.push_back(j);
            }
        }
    }
}

bool find_similar_in_vecs (vector<int> &vec1, vector<int> &vec2)
{
    for ( int i = 0; i < vec2.size(); i++)
    {
        for ( int j = 0; j < vec1.size(); j++)
        {
            if (vec2[i] == vec1[j])
            {
                return false;
            }
        }
    }
    return true;
}

void result_of_work (bool a)
{
    if (!a)
    {
        cout << " NO " <<endl;
    }
    else
    {
         cout << " YES ! " <<endl;
    }
}

void show_vec (vector<int> &vec, int number_of_vec)
{
    for ( int i = 0; i < vec.size(); i++)
    {
        if ( i == 0) cout << " vec #" << number_of_vec << " : ";
        cout << vec[i] << " ";
    }
    cout<<endl;
}

int main() {
    
    cout << " Quantity of people = ";
    int Size;
    cin >> Size;
    
    int** arr = new int*[Size];
    vector<int> vec1;
    vector<int> vec2;
    
    create_arr(Size, arr);
    
    add_to_arr(Size, arr);
    
    show_arr(Size, arr);
    
    function_for_first_step(Size, arr, vec1, vec2);
    
    function_for_second_step(Size, arr, vec1, vec2);
    
    show_vec(vec1,1);
    show_vec(vec2,2);
    
    bool result = find_similar_in_vecs(vec1, vec2);
    result_of_work(result);
    return 0;
}
