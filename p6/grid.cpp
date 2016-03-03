//grid.cpp
//Nanda, Sagar
//snanda

#include<iostream>

#include"shape.h"

using namespace std;

Grid::Grid()
{
    for (int col = 0; col < 60; col++)
        for (int row =0; row < 24; row++)
            m_grid[col][row] = ' ';
}

void Grid::set(int x, int y, char ch)
{
    if (x >= 0 && x < 60 && y >= 0 && y < 24)
    {
        m_grid[x][y] = ch;
    }
}
void Grid::print()
{
    for (int row =0; row < 24; row++)
    {
        for (int col = 0; col < 60; col++)
        {
            cout<<m_grid[col][row];
        }
        cout<<endl;
    }
}

