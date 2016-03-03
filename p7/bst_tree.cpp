//bst_tree.cpp
//Nanda, Sagar
//snanda

#include<iostream>
#include<string>
#include<queue>
#include<cmath>

#include"bst_tree.h"

using namespace std;

bool BST_tree::insert(string value)
{
    if(m_root == NULL)
    {
        m_root = new Node(value);
        return true;
    }
    else
    {
        return insert(value,m_root);
    }
}
bool BST_tree::insert(string value, Node *cur_root)
{
    if (value == cur_root->m_value)
    {
        return false;
    }
    if (value < cur_root ->m_value)
    {
        if(cur_root->m_left == NULL)
        {
            cur_root->m_left = new Node(value);
            return true;
        }
        else
        {
            return insert(value,cur_root->m_left);
        }
    }
    else
    {
        if (cur_root -> m_right == NULL)
        {
            cur_root ->m_right = new Node(value);
            return true;
        }
        else
        {
            return insert(value,cur_root->m_right);
        }
    }
}
bool BST_tree::find(string value)
{
    return find(value,m_root);
}
bool BST_tree::find(string target, Node *cur_root)
{
    if(cur_root == NULL)
    {
        return false;
    }
    if(target == cur_root -> m_value)
    {
        return true;
    }
    if(target < cur_root ->m_value)
    {
        return find(target,cur_root->m_left);
    }
    else
    {
        return find(target,cur_root->m_right);
    }
}
void BST_tree::print(vector<string>&dft_vector)
{
    return print(dft_vector,m_root);
}
void BST_tree::print(vector<string>&dft_vector, Node *cur_root)
{
    if (cur_root != NULL)
    {
        print(dft_vector,cur_root->m_left);
        dft_vector.push_back(cur_root->m_value);     
        print(dft_vector,cur_root->m_right);
    }
}
int BST_tree::size()
{
    return size(m_root);
}
int BST_tree::size(Node *cur_root)
{
    if(cur_root == NULL)
    {
        return 0;
    }
    return 1 + size(cur_root->m_left) + size(cur_root->m_right);
}
void BST_tree::breadth(vector<string> &bft_vector)
{
    if(m_root == NULL)
    {
        return;
    }
    queue<Node *> breadth_queue;
    breadth_queue.push(m_root);
    while (!breadth_queue.empty())
    {
        Node *cur_root = breadth_queue.front();
        breadth_queue.pop();

        bft_vector.push_back(cur_root->m_value);

        if (cur_root->m_left != NULL)
            breadth_queue.push(cur_root->m_left);

        if (cur_root->m_right != NULL)
            breadth_queue.push(cur_root->m_right);

    }
}
double BST_tree::distance()
{
    if(size() == 0)
    {
        return 0;
    }
    return double(sum(0,m_root))/size();
}
int BST_tree::sum(int level, Node * cur_root)
{
    if (cur_root == NULL)
    {
        return 0;
    }
    return level + sum (level +1,cur_root->m_left) + sum(level + 1, cur_root->m_right );
}
bool BST_tree::balanced()
{
    if(balanced(m_root)== -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int BST_tree::balanced(Node *cur_root)
{
    if(cur_root == NULL)
    {
        return 0;        
    }
    int left = balanced(cur_root->m_left);
    int right = balanced(cur_root->m_right);
    if(left == -1 || right == -1)
    {
        return -1;
    }
    if(abs(left - right) > 1 )
    {
        return -1;
    }
    else
    {
        return max(left,right)+1;
    }
}
void BST_tree::rebalance()
{
    vector<string> strings;    
    print(strings,m_root);
    delete m_root;
    m_root = NULL;
    insert_from_vector(strings,0,strings.size()-1);
}
void BST_tree::insert_from_vector(vector <string> &strings, int start_index, int end_index)
{
    if(end_index < start_index)
    {
        return;
    }
    if(start_index == end_index)
    {
        insert(strings[start_index]);
        return;
    }
    int middle_index = (start_index + end_index) /2; 
    insert(strings[middle_index]);
    insert_from_vector(strings,start_index,middle_index-1);
    insert_from_vector(strings,middle_index+1,end_index);
}
