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
