//sim.cpp
//Nanda, Sagar
//snanda

#include<iostream>
#include<string>
#include"cust.h"

#ifndef Pqueue_H
#define Pqueue_H
using namespace std;

class Pqueue
{
    public:
        Pqueue();
        Cust *dequeue();
        void enqueue(Cust *cust,int priority);
        void print(ostream &os);
        int total_customers();
        bool empty();
        int first_prio();
    private:
        class Node
        {
            public:
                Node(Cust *cdetail, int priority, Node *next);
                Cust *m_cdetail;
                int m_prio;
                Node *m_next;
        };
        Node *m_head;   
};


#endif
