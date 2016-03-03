//vlist.cpp
//Nanda, Sagar
//snanda

#include<iostream>
#include<string>
#include<regex.h>
#include<stdlib.h>
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
        delete tmp ->v ;
        delete tmp;
    }
}   

Vlist::Node::Node(Video *v, Node *next)
{
    this->v = v;
    this->m_next = next;
}

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

void Vlist::print_by_length()
{   
    if (m_head != NULL)
    {   int i =0;
        int count =0;
        Node *ptr = m_head;
        Node *cptr = m_head;
        while(cptr != NULL)
        {
            cptr = cptr ->m_next;
            count++;
        }
        const int counter = count;
        Video *temp;
        Video **video = new Video*[counter];
        while(ptr != NULL)
        {
            video[i] =ptr-> v;
            i++;
            ptr = ptr->m_next;
        }
        for (int last = count-1; last > 0; last--)
        {
            for (int cur = 0; cur < last; cur++)
            {
                if (video[cur]->getm_length() > (video[cur +1])->getm_length())
                {
                    temp = video[cur];
                    video[cur] = video[cur+1];
                    video[cur+1] = temp;
                }
            }
        }
        for(int j = 0; j < count; j++)
        {
            video[j]->print();
        }
        delete []video;
    }   
}
void Vlist::print_by_rating()
{
    if (m_head != NULL)
    {   
        int i =0;
        int count =0;
        Node *ptr = m_head;
        Node *cptr = m_head;
        while(cptr != NULL)
        {
            cptr = cptr ->m_next;
            count++;
        }
        Video *temp;
        Video **video = new Video*[count];
        while(ptr != NULL)
        {
            video[i] =ptr-> v;
            i++;
            ptr = ptr->m_next;
        }
        for (int last = count-1; last > 0; last--)
        {
            for (int cur = 0; cur < last; cur++)
            {
                if (video[cur]->getm_rating() < (video[cur +1])->getm_rating())
                {
                    temp = video[cur];
                    video[cur] = video[cur+1];
                    video[cur+1] = temp;
                }
            }
        }
        for(int j = 0; j < count; j++)
        {
            video[j]->print();
        }
        delete []video;
    }
}
int Vlist::lookup_expression(string expr)
{
    regex_t reg_expression;
    string str;
    int result = regcomp(&reg_expression, expr.c_str(),/*flags=*/ REG_EXTENDED);

    // many system functions return non-zero (true) on failure
    // if result is not 0, there was an error
    if (result)
    {
        return result;
    }

    int return_value = 1;

    Node *ptr = m_head;
    while(ptr !=  NULL)
    {
        int result = regexec(&reg_expression, ptr->v->getm_title().c_str(), 0, 0, 0);
        if (result == 0)
        {
            return_value = 0;
            ptr->v->print();
        }
        ptr = ptr ->m_next;
    }
    return return_value;
}	
