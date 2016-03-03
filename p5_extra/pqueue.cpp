//sim.cpp
//Nanda, Sagar
//snanda

#include<iostream>
#include<string>
#include"pqueue.h"
#include"cust.h"

using namespace std;
Pqueue::Pqueue()
{
    m_head = NULL;
}

Pqueue::Node::Node(Cust *cdetail, int priority, Node *next)
{
    m_cdetail = cdetail;
    m_prio = priority;
    m_next = next;

}
Cust *Pqueue::dequeue()
{
    if (m_head == NULL)
    {
        return NULL;
    }
    Node *ptr = m_head;
    Cust *cur_cust = m_head->m_cdetail;
    m_head = m_head ->m_next;
    delete ptr;
    return cur_cust;
}

void Pqueue::enqueue(Cust *cust, int priority)
{
    if (m_head == NULL || priority < m_head ->m_prio)
    {
        m_head = new Node(cust,priority,m_head);
        return;
    }
    Node *ptr = m_head;
    while(ptr ->m_next != NULL && ptr->m_next->m_prio <= priority)
    {
        ptr = ptr ->m_next;
    }
    ptr ->m_next = new Node(cust,priority,ptr->m_next);
}

bool Pqueue::empty()
{
    if (m_head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Pqueue::total_customers()
{   
    int size=0;
    Node *ptr = m_head;
    while(ptr != NULL)
    {
        size++;
        ptr = ptr->m_next;
    }
    return size;
}
// only for debugging output
void Pqueue::print(ostream &os)
{
    Node *ptr = m_head;
    while(ptr != NULL)
    {
        ptr->m_cdetail->print(os);
        ptr = ptr->m_next;
    }

}

int Pqueue::first_prio()
{
    if(m_head == NULL)
    {
        return -1;
    }
    else
    {
        return m_head->m_prio;
    }
}
