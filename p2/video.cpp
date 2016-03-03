// video.cpp
// Nanda, Sagar
// snanda


#include<iostream>
#include<string>
#include"video.h"

using namespace std;

Video :: Video(string title,string url,string comment,float length,int rating)
{
	m_title = title;
        m_url = url;    
        m_comment = comment;
        m_length = length;
        m_rating = rating;
}
//Function to print the description.
void Video::print()
{
	cout<<m_title<<", "<<m_url<<", "<<m_comment<<", "<<m_length<<", ";
	for (int star = 1; star <= m_rating; star++)
	{
		cout<<"*";
	}
	cout<<endl;

	
}
//Function to compare longer.
bool Video::longer(Video *other)
{
	return this->m_length > other->m_length;
}
//Function to compare rating.
bool Video::ratings(Video *other)
{
	return m_rating < other->m_rating;
}
//Function to compare strings alphabetically.
bool Video::titles(Video *other)
{
	return m_title > other->m_title;
}
