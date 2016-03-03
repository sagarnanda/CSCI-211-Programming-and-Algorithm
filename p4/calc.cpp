#include<iostream>
#include<ctype.h>
#include<cmath>
#include"dstack.h"

using namespace std;
void error();
int main()
{
    Dstack stack;
    double value = 0.0;
    char oprt;
    while (cin.peek() != EOF)
    { 

        if (isdigit(cin.peek()) || cin.peek() == '.')
        {
            cin>>value;
            if(cin.good())
            {
                stack.push(value);
            }
            else
            {
                error();
            }
        }   
        else if (isspace(cin.peek()))
        {
            cin.ignore();
        }
        else
        {
            cin>>oprt;
            if (stack.m_size < 2)
            {
                error();
            }
            //    chek that there are at least 2 on stack
            double right_side = stack.pop();
            double left_side = stack.pop();
            double result=0.0;
            switch (oprt)
            {
                case '+' :
                    result = right_side + left_side; 
                    break;
                case '-' :

                    result = left_side - right_side; 
                    break;
                case '*' :

                    result = right_side * left_side; 
                    break;
                case '/' :
                    if (right_side == 0)
                    {
                        error();
                    }
                    else
                    {
                        result = left_side / right_side; 
                        break;
                    }
                case '^' :
                    if(right_side == 0)
                    {
                        result = 1;
                        break;
                    }
                    if (left_side  == 0)
                    {
                        error();
                    }
                    result = pow(left_side,right_side); 
                    break;
                default:    
                    error();
            }  
            stack.push(result);
        }
    }   
    if (stack.m_size == 1)
    {
        double output = stack.pop();
        cout<<output<<endl;
    }
    else
    {
        error();
    }
}
void error()
{
    cerr<<"Error: Invalid expression."<<endl;
    exit(1);
}
