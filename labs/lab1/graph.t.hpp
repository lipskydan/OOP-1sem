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

template<class T> Graf<T>::~Graf()
{
    
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

template<class T> void Graf<T>::showVec()
{
    for (int i = 0; i < vecLink.size(); i++)
    {
        cout << vecLink[i] << " ";
    }
}

template<class T> bool Graf<T>::checked(int a, vector<int> vec)
{
     for (int i = 0; i < vec.size(); i++)
     {
         if ( a == vec[i])
         {
             return true;
         }
     }
    return false;
}

template<class T> int Graf<T>::checked2(int a, vector<set<int>> vec, int index)
{
    int result = 0;
    //int i = 0;
     for (int i = 0; i < vec.size(); i++)
     {
         for (auto j = mList[i].begin(); j != mList[i].end(); j++)
         {
             auto tmp = mList[i].end();
             if (a != *j && *j == *tmp && *tmp != NULL)
             {
                 result++;
             }
         }
     }
    
    return result;
}

template<class T> bool Graf<T>::isLinked()
{
    bool isLinked = true;
    vecLink.push_back(1);
    
      for (int i = 0; i < mList.size(); i++)
      {
          for (auto j = mList[i].begin(); j != mList[i].end(); j++)
          {
                  if ( i == 0)
                  {
                      vecLink.push_back(*j);
                  }
                  else if ( checked(i+1, vecLink) == true  && checked(*j, vecLink) == false )
                  {
                      vecLink.push_back(*j);
                  }
          }
      }
    
    for (int i = 0; i < mList.size(); i++)
    {
        if (checked(i+1, vecLink) == true )
        {
            for (auto j = mList[i].begin(); j != mList[i].end(); j++)
            {
                if (checked(*j, vecLink) == false)  vecLink.push_back(*j);
            }
        }
    }
    
   // showVec();
   
    if (mList.size() == vecLink.size())
    {
        isLinked = true;
    }
    else
    {
        isLinked = false;
    }
    
    return isLinked;
}

template<class T> bool Graf<T>::informOfLinking()
{
    bool result = isLinked();
    
    if ( result == true ) cout << "Graph is linked :) \n" <<endl;
    else cout << "Graph is not linked :( \n" <<endl;
    
    return result;
}

template <class T> void Graf<T>::lenght()
{
    //cout << f << " <-> " << s << " length = " << lenght <<endl;
    /* int res = 0;
    
    for (int i = 0; i < mList.size(); i++)
    {
        for (int j = i+1; j < mList.size(); j++)
        {
            auto tmp = mList[j].begin();
            if ( i != j )
            {
                res = checked2(*tmp, mList, j);
                if (res == 0) res++;
                cout << i+1 << " <-> " << j+1 << " length = " << res << endl;
            }
        }
    }
     */
    list<int> myList;
    vector<int> used;
    int lenght = 1;
    
    if ( informOfLinking() == false)
    {
        cout << "Lenght can't be determine complitely " <<endl;
        return;
    }
    
        for (int i = 0, cur = 1, target = 2; i < mList.size() && cur <= mList.size(); )
        {
            
            bool isFind = false;
            
            for ( auto j = mList[i].begin(); j != mList[i].end(); j++)
            {
                //cout << i + 1 << " " << *j << endl;
                if ( checked(i, used) == true )
                {
                    continue;
                }
                
                if ( target == *j )
                {
                    if (cur < target)
                    {
                        cout << cur << " <-> " << target << " = " << lenght << endl;
                    }
                    //cout << cur << " <-> " << target << " = " << lenght << endl;
                    isFind = true;
                    break;
                }
                else
                {
                    if (checked(*j - 1, used) == false && checked(i, used) == false) {
                        myList.push_back(*j - 1);
                        //auto k = j;
                        //if (k++ == mList[i].end())
                        //    lenght--;
                    }
                }
            }
            
            used.push_back(i);
            
            if (isFind == false)
            {
                if (myList.size() != 0)
                {
                    i = myList.front();
                    myList.pop_front();
                }
                else
                {
                    cout << cur << " <-> " << target << " = " << 0 << endl;
                    target++;
                    lenght = 1;
                    used.clear();
                    if(target == mList.size() - 1)
                        cur++;
                }
                myList.unique();
                lenght++;
            }
            else
            {
                i = 0;
                lenght = 1;
                target++;
                used.clear();
                myList.clear();
                if(target == mList.size() + 1)
                {
                    cur++;
                    target = 1;
                }
                
            }
        }
    cout << endl;
}
    
    



