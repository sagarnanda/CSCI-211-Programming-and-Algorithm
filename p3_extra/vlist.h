//vlist.h
//Nanda, Sagar
//snanda

#include<iostream>
#include "video.h"
#ifndef VLIST_H
#define VLIST_H

using namespace std;

class Vlist
{
    public:
        Vlist();
        ~Vlist();
        void insert(Video *v);
        void print();
        int length();
        bool lookup(string title);
        bool remove(string title);
        bool titlecheck(string title);	
        void print_by_length();
        void print_by_rating();	
        int lookup_expression(string expr);

    private:
        class Node
        {
            public:
                Node(Video *v,Node *next);
                Video *v;
                Node *m_next;
        };
        Node *m_head;

};

#endif
