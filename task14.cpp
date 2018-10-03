//
//  task14.cpp
//  task14
//
//  Created by Danial on 01.10.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void siftDown(int *numbers, int root, int bottom)
{
    int maxChild;
    int done = 0;
    
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)
            maxChild = root * 2;
        
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else
            done = 1;
    }
}

void heapSort(int *numbers, int array_size)
{
    
    for (int i = (array_size / 2) - 1; i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}

int main()
{
    int a[5] = {3,7,5,8,2};
    
    //for (int i = 0; i<10; i++)
    //    a[i] = rand() % 20 - 10;
    
    for (int i = 0; i<5; i++)
        cout << a[i] << " ";
    
    cout<<endl;
    
    heapSort(a, 5);
    
    for (int i = 0; i<5; i++)
        cout << a[i] << " ";
    
    
    return 0;
}
