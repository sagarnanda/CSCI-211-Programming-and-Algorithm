//square.cpp
//Nanda, Sagar
//snanda

#include<iostream>

#include"square.h"

using namespace std;

Square::Square(int x, int y,int size): Shape(x,y)
{
    m_x = x;
    m_y = y;
    m_size = size;
}
void Square::draw(Grid & grid)
{
    for(int row = m_x; row < m_x + m_size; row++)
    {
        grid.set(row, m_y, '*');
        grid.set(row, m_y + (m_size-1), '*');
    }
    for (int col = m_y; col < m_y + m_size; col++)
    {
        grid.set(m_x, col, '*');
        grid.set(m_x + (m_size-1), col, '*');
    }

}
