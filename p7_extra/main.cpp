//main.cpp
//Nanda, Sagar
//snanda

#include<iostream>
#include<string>
#include<vector>

#include"bst_tree.h"

using namespace std;
void print_vector(vector<string> &ft_vector)
{
    cout<<"{";
    for(unsigned int i = 0; i < ft_vector.size(); i++)
    {
        if(i != 0)
        {
            cout<<", ";
        }
        cout<<ft_vector[i];
    }
    cout<<"}"<<endl;
}
int main()
{
    string command;
    BST_tree tree;
    while(cin>>command)
    {
        if(command == "echo")
        {
            string line;
            cin.ignore();
            getline(cin,line);
            cout<<line<<endl;
        }
        else if(command == "insert")
        {
            string word;
            cin.ignore();
            getline(cin,word);
            if(tree.insert(word) == false)
            {
                cerr<<"insert <"<<word<<"> failed. String already in tree."<<endl;
            }

        }
        else if(command == "size")
        {
            cout<<tree.size()<<endl;
        }
        else if(command == "find")
        {
            string word;
            cin.ignore();
            getline(cin,word);
            if(tree.find(word) == true)
            {
                cout<<"<"<<word<<"> is in tree."<<endl;
            }
            else
            {
                cout<<"<"<<word<<"> is not in tree."<<endl;
            }
        }
        else if(command == "print")
        {
            vector<string> dft_vector;
            tree.print(dft_vector);
            print_vector(dft_vector);
        }
        else if(command == "breadth")
        {
            vector<string> bft_vector;
            tree.breadth(bft_vector);
            print_vector(bft_vector);
        }
        else if(command == "distance")
        {
            cout<<"Average distance of nodes to root = "<<tree.distance()<<endl;
        }
        else if(command == "balanced")
        {
            if (tree.balanced() == true)
            {
                cout <<"Tree is balanced."<<endl;
            }
            else
            {
                cout <<"Tree is not balanced."<<endl;

            }
        }
        else if(command == "rebalance")
        {
            vector<string> strings;
            tree.rebalance();
        }
        else if(command == "remove")
        {
            string word;
            cin.ignore();
            getline(cin,word);
            if(tree.find(word) == true)
            {
            }
            else
            {
                cout<<"<"<<word<<"> not in tree and cannot be removed."<<endl;
            }

        }
        else
        {
            string word;
            cerr<<"Illegal command <"<<command<<">."<<endl;
            getline(cin,word);
        }
    }
    return 0;
}
