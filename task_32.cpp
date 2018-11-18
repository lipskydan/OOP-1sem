//
//  main.cpp
//  task_32
//
//  Created by Danial on 30.10.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

const int lettersCount = 52;

void InputString(string &str)
{
    cout << "Input string: ";
    getline(cin, str);
}

int* CountLetters(string str)
{
    int* result = new int[lettersCount];
    for (int i = 0; i < lettersCount; i++)
    {
        result[i] = 0;
    }
    for (int i = 0; i < str.size(); i++)
    {
        int index = str.at(i) - 'a';
        //cout << " index = " << index << endl;
        if (0 <= index && index < 26)
        {
            result[index]++;
            //cout  << " result[ " << index << " ] = " << result[index] << endl;
        }
        else
        {
            index = str.at(i) - 'A';
            if (0 <= index && index < 26)
            {
                result[index + 26]++;
                //cout  << " result [ " << index << " ] = " << result[index] << endl;
            }
        }
        
    }
    return result;
}

int main()
{
    string firstString;
    string secondString;
    InputString(firstString);
    InputString(secondString);
    int* countOfLettersInFirstString = CountLetters(firstString);
    //cout << " countOfLettersInFirstString = " << *countOfLettersInFirstString << endl;
    int* countOfLettersInSecondString = CountLetters(secondString);
    //cout << " countOfLettersInSecondString = " << *countOfLettersInFirstString << endl;
    int* countOfLettersInMaxSubstring = new int[lettersCount];
    
  

    cout << "Maximal Substring is: ";
    cout << endl << endl;
    for (int i = 0; i < lettersCount; i++)
    {
        countOfLettersInMaxSubstring[i] = min(countOfLettersInFirstString[i], countOfLettersInSecondString[i]);
       //cout << " countOfLettersInFirstString[ " << i << " ] = " << countOfLettersInFirstString[i] << endl;
       //cout << " countOfLettersInSecondString[ " << i << " ] = " << countOfLettersInSecondString[i] << endl;
       //cout << " countOfLettersInMaxSubstring[ " << i << " ] = " << countOfLettersInMaxSubstring[i] << endl << endl;
        for (int j = 0; j < countOfLettersInMaxSubstring[i]; j++)
        {
            if (i < 26)
            {
                cout << char('a' + i);
            }
            else
            {
                cout << char('A' + i - 26);
            }
        }
    }
    cout<<endl;
}
