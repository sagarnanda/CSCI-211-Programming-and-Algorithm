//calc.cpp
//Nanda, Sagar
//snanda



#include<iostream>
#include<ctype.h>
#include<cmath>
#include<math.h>
#include"dstack.h"
#include<assert.h>

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
        else if (isalpha(cin.peek())) 
        {
            cin>>oprt;
            //assert(stack.m_size > 0);
            if (stack.m_size < 1)
            {
                error();
            } 
            int total = stack.m_size;
            double right_side = stack.pop();
            double result=0.0;
            if(oprt == 'c')
            {
                if(cin.peek()== 'o')
                {
                    cin>>oprt;
                    if(cin.peek()=='s')
                    {
                        cin>>oprt;
                        right_side = right_side * M_PI / 180;
                        result =cos(right_side);
                    }
                }
            }


            if(oprt == 's')
            {
                if(cin.peek()== 'i')
                {
                    cin>>oprt;
                    if(cin.peek()=='n')
                    {
                        cin>>oprt;
                        right_side = right_side * M_PI / 180;
                        result = sin(right_side);
                    }
                }
                if(cin.peek()== 'q')
                {
                    cin>>oprt;
                    if(cin.peek()=='r')
                    {
                        cin>>oprt;
                        if (cin.peek()== 't')
                        {   
                            cin>>oprt;
                            result = sqrt(right_side);
                        }
                        else
                        {
                            error();
                        }
                    }
                }
            }
            if(oprt == 'a')
            {
                if(cin.peek()== 'v')
                {
                    cin>>oprt;
                    if(cin.peek()=='e')
                    {
                        cin>>oprt;
                        double add =0.0;
                        double addn = right_side;
                        int plusone = stack.m_size + 1;
                        while(plusone != 0)
                        {
                            add = stack.pop();
                            addn = addn + add;
                            plusone--;
                        }
                        result = addn / total;
                    }
                }
            }

            stack.push(result);
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
                    if (left_side < 0 && right_side != floor(right_side))
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
    return 0;
}
void error()
{
    cerr<<"Error: Invalid expression."<<endl;
    exit(1);
}

