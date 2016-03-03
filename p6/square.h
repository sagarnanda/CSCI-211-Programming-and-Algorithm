//square.h
//Nanda, Sagar
//snanda

#include"shape.h"
#include"grid.h"

#ifndef SQUARE_H
#define SQUARE_H

using namespace std;

class Square : public Shape
{
    public:
        Square(int x, int y, int size);
        /*virtual*/ void draw(Grid &grid);
    protected:
        char m_ch;
        int m_size;
};
#endif
