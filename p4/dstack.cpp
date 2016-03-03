#include<iostream>
#include"dstack.h"

using namespace std;

Dstack::Dstack()
{
    m_head = NULL;
}

Dstack ::~Dstack()
{
}

void Dstack::push(double value)
{
    m_head = new Node(value, m_head);
    m_size++ ;
}

double Dstack::pop()
{
    if (m_head == NULL)
    {  
        return 0;
    }
    double value= 0.0;
    value = m_head -> m_value;
    Node *tmp = m_head;
    m_head = m_head -> m_next;
    delete tmp;
    m_size-- ;
    return value;
}

bool Dstack::empty()
{
    if (m_head == NULL)
        return true;
    else 
        return false;
}


