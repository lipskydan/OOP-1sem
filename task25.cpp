//
//  main.cpp
//  test
//
//  Created by Danial on 26.09.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void show_string (const string& str)
{
    cout << str;
}

/*##########################################################################################*/

void copy_str ( string& str, string& str_empty)
{
    str_empty = str;
}

/*##########################################################################################*/

bool check_for_palindrom (const string& str)
{
    for(unsigned long l = 0, r = str.size() - 1; l < r; l++, r--)
    {
        if (str[l] != str[r])
        {
            return false;
        }
    }
    return true;
}

/*##########################################################################################*/

void palindrom_l ( string& str)
{
    for(unsigned long l = 0, r = str.size() - 1; l < r; l++, r--)
    {
        if ( check_for_palindrom(str) == false )
        {
            if ( str[l] != str[r])
            {
                str.erase(r,1);
                l--;
            }
        }
    }
}

/*##########################################################################################*/

void palindrom_r ( string& str)
{
    for(unsigned long l = 0, r = str.size() - 1; l < r; l++, r--)
    {
        if ( check_for_palindrom(str) == false )
        {
            if ( str[l] != str[r])
            {
                str.erase(l,1);
                r++;
                l--;
            }
        }
    }
}

/*##########################################################################################*/

void palindrom (string& str)
{
    string str1;
    string str2;
    
    copy_str(str, str1);
    copy_str(str, str2);
    
    palindrom_l(str1);
    palindrom_r(str2);
    
    if (str1.size() < str2.size())
    {
        palindrom_r(str);
    }
    else
    {
        palindrom_l(str);
    }
}


int main()
{
    cout << " Input string : ";
    string str;
    cin >> str;
    
    palindrom(str);
    
    show_string(str);
    
    return 0;
}
