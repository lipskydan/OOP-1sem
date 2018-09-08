#include <iostream>
#include <time.h>
using namespace std;

struct Stack
{
    Stack * next;
    int data;
};

struct List
{
    Stack* begin;
    Stack* end;
    int Size;
};

List* create_list()
{
    List* result = new List;
    Stack * stk = new Stack;
    stk->next = NULL;
    result->begin = NULL;
    result->end = NULL;
    result->Size = 0;
    
    return result;
}

Stack* push_element (List* lst, Stack* stk, int element)
{
    
    stk = lst->begin;
    
    Stack * add = new Stack;
    add->data = element;
    
    if (lst->Size == 0)
    {
        lst->begin = lst->end = add;
    }
    else
    {
        lst->begin = add;
        lst->begin->next = stk;
        
    }
    lst->Size++;
    return add;
    
}

int pop_element (List* lst, Stack* stk)
{
    if (lst->Size != 0)
    {
        stk = lst->begin;
        int temp = stk->data;
        stk = stk->next;
        lst->begin = stk;
        lst->Size--;
        
        return temp;
    }
    
    
    return -1;
}

int peek_element (List* list, Stack* stk)
{
    stk = list->begin;
    if (list->Size != 0)
    {
        return stk->data;
    }
    return -1;
}


void show_list(List* list, Stack * stk)
{
    
    stk = list->begin;
    if (list->Size == 0)
    {
        cout << " List is empty" << endl;
        return;
    }
    while(stk)
    {
        cout<<stk->data << " " ;
        if (stk->next)
        {
            cout<<" -> ";
        }
        stk = stk->next;
    }
    cout<<endl;
}

bool Is_Empty (List* list)
{
    
    if (list->Size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Time_of_function (List* list, Stack* stack, int el)
{
    //int start = GetTickCount();
    clock_t start = clock();
    for (int i = 0; i <= 100 ; i++)
    {
        push_element(list,stack,el);
    }
    clock_t end = clock();
    //int end = GetTickCount();
    cout << " Time of 100 times using of push_element = " << end-start << " takts " << endl << endl;
    
    //start = GetTickCount();
    start = clock();
    for (int i = 0; i <= 100 ; i++)
    {
        peek_element(list,stack);
    }
    end = clock();
    //end = GetTickCount();
    cout << " Time of 100 times using of peek_element = " << end-start << " takts " << endl << endl;
    
    
    start = clock();
    for (int i = 0; i <= 100 ; i++)
    {
        Is_Empty(list);
    }
    end = clock();
    cout << " Time of 100 times using of Is_Empty = " << end-start << " takts " << endl << endl;
    
    start = clock();
    for (int i = 0; i <= 100 ; i++)
    {
        pop_element(list,stack);
    }
    end = clock();
    cout << " Time of 100 calling of pop_element = " << end-start << " takts " << endl << endl;
}

bool Continue()
{
    cout<<endl;
    cout << " Back to menu (y(YES)/n(NO))?";
    char tmp;
    cin >> tmp;
    if (tmp == 'n')
    {
        //system("pause");
        return false;
    }
    else
    {
        //system("pause");
        return true;
    }
}

void Function_With_List(List* list, Stack* stack, List* list_test, Stack* stack_test)
{
    bool cont = true;
    //int push = 0;
    int peek = 0;
    int pop = 0;
    
    do
    {
        cout << " Our list : ";
        show_list(list, stack);
        cout<<endl;
        cout<<endl;
        int i;
        cout << " 1 - push_element;\n 2 - pop_element;\n 3 - peek_element;\n 4 - Is_Empty ;\n 5 - Time_of_function " << endl;
        cout << " write number ";
        cin >> i;
        cout<<endl;
        
        switch(i)
        {
            case 1:
                int el;
                cout << " Put element : ";
                cin >> el;
                
                push_element(list, stack, el);
                
                cout << " Pushed element is " << el <<endl;
                cont = Continue();
                break;
            case 2:
                pop = pop_element(list,stack);
                
                
                
                
                
                if(pop != -1)
                {
                    cout << " Element which was poped  " << pop <<endl;
                }
                else
                {
                    cout << "There are not element in list ";
                }
                
                cont = Continue();
                break;
            case 3:
                
                peek = peek_element(list, stack);
                
                
                
                
                if (peek != -1)
                {
                    cout << " Peek_element is " << peek;
                }
                else
                {
                    cout << "There isn't peek_element because list is empty  ";
                }
                
                cont = Continue();
                break;
            case 4:
                
                Is_Empty(list);
                
                if (Is_Empty(list))
                {
                    cout << " List is empty" << endl;
                }
                else
                {
                    cout << " List isn't empty" << endl;
                }
                //show_list(list);
                cont = Continue();
                break;
            case 5 :
                cout << " Time_of_function: " << endl;
                Time_of_function(list_test,stack_test,5);
                cont = Continue();
                break;
                
        }
        //  system("cls");
        cout << endl;
        cout << " ---------------------------------------------------------------- " <<endl<<endl;
    }
    while(cont);
    cout << " ------------------------ RESULT OF WORK ------------------------ " <<endl;
    cout << " Our list : ";
    show_list(list, stack);
    
}
int main()
{
    time_t start, end;
    
    time(&start);
    
    List* list = create_list();
    Stack* stack = list->begin;
    
    List* list_test = create_list();
    Stack* stack_test = list->begin;
    
    Function_With_List(list, stack, list_test, stack_test);
    
    time(&end);
    
    double seconds = difftime(end, start);
    cout << " Programe take = " << seconds << " seconds " << endl;
    
    return 0;
}
