//point.h 
//Nanda, Sagar
//snanda

#include"shape.h"
#include"grid.h"

#ifndef POINT_H
#define POINT_H

using namespace std;

class Point : public Shape
{
    public:
        Point(int x, int y, char ch);
        /*virtual*/ void draw(Grid &grid);
    protected:
        char m_ch;
};
#endif
