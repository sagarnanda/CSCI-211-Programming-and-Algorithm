//video.h
//Nanda, Sagar
//snanda

#include<iostream>
#include<string>
#ifndef Video_H
#define Video_H

using namespace std;

class Video
{
    public:
        Video(string title,string url,string comment,float length,int rating);
        void print();
        bool titles(Video *other);
        string getm_title();
        float getm_length();
        int getm_rating();
    private:
        string m_title;
        string m_url;
        string m_comment;
        float m_length;	
        int m_rating;


};
#endif
