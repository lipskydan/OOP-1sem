//
//  lotsVariable.hpp
//  lab_1_
//
//  Created by Danial on 07.10.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#ifndef lotsVariable_hpp
#define lotsVariable_hpp

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <string.h>
#include <cstdio>


using namespace std;

class lotsVariable
{
public:
    double myPow();
    double myLog();
    double readLine();
    
private:
    
    string function;
    double x;
    double y;
    double z;
    char a[100] = { 0 };
    char out[100] = { 0 };
    stack <char> S;
    int prior(char v);
    bool isOp(char c);
    bool isDigit(char c);
    void polRat(char *a, char *out);
    int Calc(char *out);
    
};

#endif /* lotsVariable_hpp */
