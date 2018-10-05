//
//  graph.cpp
//  lab1
//
//  Created by Danial on 03.10.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include "graph.hpp"

using namespace std;

template<class T> Graf<T>::Graf(int size)
{
    mData = -1;
    mList.resize(size);
}

template<class T> void Graf<T>::initializeGraf()
{
    srand(time(NULL));
    for (int i = 0; i < mList.size(); i++)
    {
        int quantityElements = (rand() % (mList.size() - 1));
        for (int j = 0; j < quantityElements; j++)
        {
            int link = i;
            while(link == i || link == i + 1)
            {
                link = (rand() % (mList.size())) + 1;
            }
            mList[i].insert(link);
            mList[link - 1].insert(i + 1);
        }
    }
}

template<class T> void Graf<T>::printAsMatrix()
{
     cout << "printAsMatrix : \n" <<endl;
    for (int i = 0; i < mList.size(); i++)
    {
        auto j = mList[i].begin();
        
        for (int k = 1; k < mList.size() + 1; k++)
        {
            if (j != mList[i].end())
            {
                if (*j == k){
                    cout << 1 << " ";
                    j++;
                    continue;
                }
            }
            cout << 0 << " ";
            
        }
        cout << endl;
    }
    
    cout << endl;
}

template<class T> void Graf<T>::printAsList()
{
    cout << "printAsList : \n" <<endl;
    for (int i = 0; i < mList.size(); i++)
    {
        cout << i + 1 << ": ";
        for (auto j = mList[i].begin(); j != mList[i].end(); j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }
    
    cout << endl;
}

template<class T> bool Graf<T>::checked(int a, vector<int> vec)
{
    bool result = false;
     for (int i = 0; i < vec.size(); i++)
     {
         if ( a == vec[i])
         {
             result = true;
         }
     }
    return result;
}

template<class T> bool Graf<T>::isLinked()
{
    bool isLinked = true;
    vec1.push_back(1);
    
      for (int i = 0; i < mList.size(); i++)
      {
          for (auto j = mList[i].begin(); j != mList[i].end(); j++)
          {
                  if ( i == 0)
                  {
                      vec1.push_back(*j);
                  }
                  else if ( checked(i+1, vec1) == true  && checked(*j, vec1) == false )
                  {
                      vec1.push_back(*j);
                  }
          }
      }
    
    
    
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i] << " ";
    }
    
    if (mList.size() == vec1.size())
    {
        isLinked = true;
    }
    else
    {
        isLinked = false;
    }
    
    return isLinked;
}

template<class T> void Graf<T>::informOfLinking()
{
    bool result = isLinked();
    
    if ( result == true ) cout << " Linked :) " <<endl;
    else cout << " Not linked :( " <<endl;
}