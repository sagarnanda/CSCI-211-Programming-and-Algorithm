//bst_tree.h
//Nanda, Sagar
//snanda

#include<iostream>
#include<iostream>
#include<string>
#include<vector>

#ifndef BST_TREE_H
#define BST_TREE_H

using namespace std;

class BST_tree
{
    public:
        BST_tree()
        {m_root = NULL;}
//        ~BST_tree();
        bool insert(string value);
        bool find(string value);
        int size();
        void print(vector<string> &dft_vector);
        void breadth(vector<string> &bft_vector);
        double distance();
        bool balanced();
        void rebalance();
    private:
        class Node
        {
            public:
                Node(string value)
                {   
                    m_value = value;
                    m_left = NULL;
                    m_right = NULL;
                }
                ~Node()
                {
                   delete m_left;
                   delete m_right;
                }
                string m_value;
                Node *m_left;
                Node *m_right;
        };
        Node *m_root;
        bool insert(string value, Node *cur_root);
        bool find(string value, Node *cur_root);
        void print(vector<string> &dft_vector,Node *cur_root); 
        int size(Node *cur_root);
        int balanced(Node *cur_root);
        int sum(int level, Node *cur_root);
        bool rebalance(Node *cur_root);
        void insert_from_vector(vector <string> &strings, int start_index, int end_index);
};

#endif
