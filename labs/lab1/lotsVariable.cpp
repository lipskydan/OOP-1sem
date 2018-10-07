//
//  lotsVariable.cpp
//  lab_1_
//
//  Created by Danial on 07.10.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include "lotsVariable.hpp"

using namespace std;

int lotsVariable::prior(char v)
{
    switch (v)
    {
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
    }
    return 0;
}

bool lotsVariable::isOp(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool lotsVariable::isDigit(char c)
{
    return (c >= '0' && c <= '9') && c == 'x';
}

void lotsVariable::polRat(char *a, char *out)
{
    stack <char> S;
    int i = 0, j = 0;
    char t;
    for ( ; a[i] != '\0'; ++i)
    {
        if (isDigit(a[i]))
        {
            out[j] = a[i];
            ++j;
        }
        else
        {
            if (j != 0 && out[j - 1] >= '0' && out[j - 1] <= '9')
            {
                out[j] = '_';
                ++j;
            }
            
            if (isOp(a[i]))
            {
                if (S.empty() || prior(S.top()) < prior(a[i]))
                {
                    S.push(a[i]);
                }
                else
                {
                    while (!S.empty() && (prior(S.top()) >= prior(a[i])))
                    {
                        out[j++] = S.top();
                        S.pop();
                    }
                    S.push(a[i]);
                }
            }
            else
            {
                if (a[i] == '(')
                {
                    S.push(a[i]);
                }
                else
                {
                    if (a[i] == ')')
                    {
                        if (S.empty() || S.top() == '(')
                        {
                            cout << "Input error!";
                            //_getch();
                            exit(1);
                        }
                        else
                        {
                            while (S.top() != '(')
                            {
                                out[j] = S.top();
                                S.pop();
                                j++;
                            }
                        }
                        S.pop();
                    }
                }
            }
        }
    }
    while (!S.empty())
    {
        if (S.top() == '(')
        {
            cout << "Input error!";
            exit(1);
        }
        else
        {
            out[j] = S.top();
            S.pop();
            j++;
        }
    }
}
int lotsVariable::Calc(char *out)
{
    int j = 0, c = 0, r1 = 0, r2 = 0;
    stack <double> S;
    stack <double> S1;
    char num[17];
    char* pEnd = nullptr;
    while (out[j] != '\0')
    {
        if (out[j] == '_') {
            ++j;
            continue;
        }
        if (out[j] >= '0' && out[j] <= '9')
        {
            long iNum = strtol(&out[j], &pEnd, 10);
            S.push(iNum);
            j += pEnd - &out[j];
        }
        else
        {
            if (isOp(out[j]))
            {
                r1 = S.top();
                S.pop();
                r2 = S.top();
                S.pop();
                switch (out[j])
                {
                    case '+':
                    {
                        S.push(r2 + r1);
                        break;
                    }
                    case '-':
                    {
                        S.push(r2 - r1);
                        break;
                    }
                    case '*':
                    {
                        S.push(r2*r1);
                        break;
                    }
                    case '/':
                    {
                        S.push(r2 / r1);
                        break;
                    }
                }
            }
            ++j;
        }
    }
    return (S.top());
}


double lotsVariable::myPow()
{
    return 0;
}

double lotsVariable::myLog()
{
    return 0;
}

double lotsVariable::readLine()
{
    cout << "String : ";
    cin >> a;
    //sscanf("%s", a);
    polRat(a, out);
    cout << "pol_rat : " << out << std::endl;
    cout << "result : " << Calc(out) << "\n\n";
        
    return 0;
}
