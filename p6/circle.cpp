//circle.cpp
//Nanda, Sagar
//snanda

#include<iostream>

#include"circle.h"

using namespace std;

Circle::Circle(int x, int y):Shape(x,y)
{
    m_x = x;
    m_y = y;
}

void Circle::draw(Grid &grid)
{
        grid.set(m_x+1, m_y, 'o');
        grid.set(m_x+2, m_y, 'o');
        grid.set(m_x, m_y+1, 'o');
        grid.set(m_x+3, m_y+1, 'o');
        grid.set(m_x, m_y+2, 'o');
        grid.set(m_x+3, m_y+2, 'o');
        grid.set(m_x+1, m_y+3, 'o');
        grid.set(m_x+2, m_y+3, 'o');
    
} 
