//grid.h
//Nanda, Sagar
//snanda

#include<iostream>

#ifndef GRID_H
#define GRID_H

using namespace std;

class Grid
{
    public:
        Grid();
        void set(int x, int y, char ch);
        void print();
    protected:
        char m_grid[60][24];    
};
#endif
