//
//  main.cpp
//  lab_1
//
//  Created by Danial on 22.09.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <ctime>

using namespace std;



template<class T> class Graph {
public:
    Graph* obj;
    T data;
};



template<class T> class Graf
{
public:
    Graf(int size);
    void initializeGraf();
    void printAsMatrix();
    void printAsList();
    bool isLinked();
private:
    int mData;
    vector<set<int>> mList;
};

/*##########################################################################################*/
template<class T> Graf<T>::Graf(int size)
{
    mData = -1;
    mList.resize(size);
}
/*##########################################################################################*/
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
/*##########################################################################################*/
template<class T> void Graf<T>::printAsMatrix()
{
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
/*##########################################################################################*/
template<class T> void Graf<T>::printAsList()
{
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
/*##########################################################################################*/
template<class T> bool Graf<T>::isLinked()
{
    
}
int main() {
    Graf<int> first(10);
    first.initializeGraf();
    first.printAsList();
    first.printAsMatrix();
    
    
    return 0;
}
