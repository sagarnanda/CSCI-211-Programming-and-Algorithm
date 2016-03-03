//cirlce.h
//Nanda, Sagar
//snanda

#include"shape.h"
#include"grid.h"

#ifndef CIRLCE_H
#define CIRCLE_H

using namespace std;

class Circle : public Shape 
{
    public:
        Circle(int x, int y);
        /*virtual*/ void draw(Grid &grid);
    protected:
        char m_ch;
};
#endif
