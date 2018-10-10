//
//  main.cpp
//  task29
//
//  Created by Danial on 09.10.2018.
//  Copyright © 2018 Danial. All rights reserved.
//
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string.h>
#include <cstdio>
#include <stack>
#include <fstream>

using namespace std;

int prior(char v)
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

bool is_operation(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool is_number(char c)
{
    return c >= '0' && c <= '9';
}

void post_form(char *a, char *out)
{
    stack <char> S;
    int i = 0, j = 0;
    for ( ; a[i] != '\0'; ++i)
    {
        if (is_number(a[i]))
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
            
            if (is_operation(a[i]))
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

int Calc(char *out)
{
    int j = 0, r1 = 0, r2 = 0;
    stack <double> S;
    
    char* pEnd = nullptr;
    while (out[j] != '\0')
    {
        if (out[j] == '_')
        {
            ++j;
            continue;
        }
        if (out[j] >= '0' && out[j] <= '9')
        {
            long iNum = strtol(&out[j], &pEnd, 10);
            S.push(iNum);
            j += 1;
        }
        else
        {
            if (is_operation(out[j]))
            {
                r1 = S.top(); S.pop();
                r2 = S.top(); S.pop();
                switch (out[j])
                {
                    case '+': S.push(r2 + r1); break;
                    case '-': S.push(r2 - r1); break;
                    case '*': S.push(r2*r1); break;
                    case '/': S.push(r2 / r1); break;
                }
            }
            ++j;
        }
    }
    return (S.top());
}


int main() {
    
    char a[100] = { 0 };
    char res[100] = { 0 };
    int i = 0;
    
    //ifstream fout("/Users/danial/Desktop/2 курс/OOP/task29/text.txt");
    
    cout << "String : ";
    cin >> a;
    //fout.close();
    
    //for ( int i = 0 ; i < 100 ; i++) cout << a[i] << " ";
    
    post_form(a, res);
    cout << "Post_form : " << res << endl;
    cout << "Result = " << Calc(res) << "\n\n";
    
    return 0;
}
