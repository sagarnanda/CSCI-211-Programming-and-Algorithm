// video.h
// Nanda, Sagar
// snanda




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
	bool longer(Video *other);
	bool ratings(Video *other);
	bool titles(Video *other);
	private:
        string m_title;
	string m_url;
	string m_comment;
	float m_length;	
	int m_rating;
	
	
};
#endif
