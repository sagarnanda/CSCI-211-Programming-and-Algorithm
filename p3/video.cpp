#include<iostream>
#include<string>
#include <stdlib.h>
#include"video.h"

using namespace std;

Video::Video(string title,string url,string comment,float length,int rating)
{

    m_title = title;
    m_url = url;
    m_comment = comment;
    m_length = length;
    m_rating = rating;
}

void Video::print()
{


    cout<<m_title<<", "<<m_url<<", "<<m_comment<<", "<<m_length<<", ";
    for (int star = 1; star <= m_rating; star++)
    {
        cout<<"*";
    }
    cout<<endl;


}
string Video::getm_title()
{
    return m_title;
}
bool Video::titles(Video *other)
{
    return m_title > other ->m_title;
}
