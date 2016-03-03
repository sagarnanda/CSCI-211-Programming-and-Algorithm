#include<iostream>
#include"vlist.h"
#include"video.h"

using namespace std;

Vlist::Vlist()
{
    m_head = NULL;
}   

Vlist::~Vlist()
{   
    Node *ptr = m_head;
    while(ptr != NULL)
    {
        Node *tmp = ptr;
        ptr = ptr -> m_next;
        delete tmp;

    }

}   

Vlist::Node::Node(Video *v, Node *next)
{
    this->v = v;
    this->m_next = next;
}

/*
   Vlist::Node::~Node()
   {
   delete this->v;
   }
 */
bool Vlist::titlecheck(string title)
{
    if (m_head != NULL)
    {
        Node *temp = m_head;
        do
        {
            string t = temp -> v->getm_title(); 
            if (t == title)
            {
                return true;
            }
        }
        while((temp = temp -> m_next) != NULL);

    }
    return false;
}

void Vlist::insert(Video *v)
{
    if (m_head == NULL || v-> getm_title() < m_head-> v-> getm_title())
    {
        m_head = new Node(v,m_head);
    }
    else
    {
        Node *ptr = m_head;
        while(ptr-> m_next != NULL && (ptr-> m_next-> v->getm_title() < v->getm_title()))
        { 
            ptr = ptr->m_next;
        }
        ptr -> m_next = new Node(v,ptr->m_next);
    }
}

void Vlist::print()

{ 
    if(m_head != NULL)
    { 
        Node *ptr = m_head; 
        while (ptr != NULL)
        {
            ptr->v->print();
            ptr = ptr ->m_next;    
        }
    }
}

int Vlist::length()
{
    Node *ptr = m_head;
    int count=0;
    while (ptr != NULL)
    {
        ptr = ptr ->m_next;
        count++;
    }
    return count;
}  

bool Vlist::lookup(string title)
{
    if (m_head != NULL)
    {
        Node *temp = m_head;
        do
        {
            string t = temp -> v->getm_title(); 
            if (t == title)
            {
                temp->v->print();
                return false;
            }
        }
        while((temp = temp -> m_next) != NULL);

    }
    return true;
}
bool Vlist::remove(string title)
{
    if (m_head != NULL)
    {   
        Node *prev;
        Node *ptr = m_head;
        Node *next = ptr -> m_next;

        while(ptr != NULL)
        {
            if (ptr -> v->getm_title() == title && ptr == m_head)
            {
                m_head = ptr -> m_next;
                delete ptr -> v;
                delete ptr;
                return false;
            }
            else if (ptr -> v -> getm_title() == title && ptr -> m_next == NULL)
            {       
                prev->m_next = NULL;
                delete ptr -> v;
                delete ptr;
                return false;
            }
            else if (ptr ->v ->getm_title() == title)
            {
                prev -> m_next = next;
                ptr -> m_next = NULL;
                delete ptr ->v;
                delete ptr;
                return false;
            }
            prev = ptr;
            ptr = ptr -> m_next;
            if(next-> m_next != NULL)
            {
                next = next -> m_next;
            }
        } 
    }
    return true;
}               

