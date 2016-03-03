//shape.h
//Nanda, Sagar
//snanda

#include<iostream>
#include"grid.h"

#ifndef SHAPE_H 
#define SHAPE_H
using namespace std;

class Shape
{
    public:
        Shape(int x, int y);
        virtual void draw (Grid & grid) = 0;
    protected:
        int m_x;
        int m_y;
        int m_size;

};

#endif
