//dstack.h
//Nanda, Sagar
//snanda



#include<iostream>

using namespace std;

#ifndef Dstack_H
#define Dstack_H

class Dstack
{
    public:
        Dstack();
        ~Dstack();
        void push(double value);
        double pop();
        bool empty();
        int m_size = 0;
    private:
        class Node
        {
            public:
                Node (double value, Node *next)
                {m_value = value;m_next = next;}
                Node *m_next;
                double m_value;
        };
        Node *m_head;
};

#endif
