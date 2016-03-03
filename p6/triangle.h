//triangle.h
//Nanda, Sagar
//snanda

#include"shape.h"
#include"grid.h"

#ifndef TRIANGLE_H
#define TRIANGLE_H

using namespace std;

class Triangle : public Shape 
{
    public:
        Triangle(int x, int y);
        /*virtual*/ void draw(Grid &grid);
    protected:
        char m_ch;
        int m_x;
        int m_y;
};
#endif
