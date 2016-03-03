//point.cpp 
//Nanda, Sagar
//snanda

#include<iostream>
 
#include"point.h"

using namespace std;

Point::Point(int x, int y,char ch): Shape(x,y)
{
    m_ch = ch;
}
void Point::draw(Grid & grid)
{
    grid.set(m_x,m_y,m_ch);
    grid.set(m_x,m_y,m_ch);
}
