#include<iostream>
#include<string>
#include"video.h"

using namespace std;

int inputFromUser (Video *V[]);
void longerVideo(int num_videos,Video *V[]);
void ratedVideo(int num_videos, Video *V[]);
void titledVideo(int num_videos, Video *V[]);
int main()
{
	const int MAX = 100;
	Video *V[MAX];
	int total=0;
	int ret=0;
	string sort;
	getline(cin,sort);

	if (sort == "rating")
	{	
		total=inputFromUser(V);
		if(total > 0)
		{
			ratedVideo(total,V);
		}
	}
	else if (sort == "length")
	{
		total=inputFromUser(V);
		if(total > 0)
		{
			longerVideo(total,V);
		}
	}
	else if (sort == "title")
	{
		total=inputFromUser(V);
		if(total > 0)
		{
			titledVideo(total,V);
		}
	}
	else
	{
		cerr<<sort<<" is not a legal sorting method, giving up."<<endl;
		return 1;

	}
	if(total > 0)
	{	
		for (int i = 0; i < total; i++)
		{
			(*V[i]).print();		//Calling print funcion to print the output.
		}
	}
	else if (total == -1)
	{
		ret = 1;
	}
	return ret;
}

//Function to take input from user till the end of input.
//Input: Array
//Output:Total number of inputs.

int inputFromUser (Video *V[])
{	
	string title,url,comment;
	double length;
	int rating;
	int count =0;
	while(getline(cin,title))
	{
		getline(cin, url);
		getline(cin, comment);
		cin >> length;
		cin >> rating;
		if (rating < 1||rating > 5)
			return -1;
		cin.ignore();
		V[count] = new Video(title,url,comment,length,rating);			//Creating a new Video object for each description read.
		if (count<100)
		{
			count++;
		} 
		else
		{
			cerr<<"Too many videos, giving up."<<endl;
			return -1;
		}
	}
	return 0;
}
//Function to sort the output so the shortest videos come first.
//Input: Total number of videos and array
//Output: NA
void longerVideo(int num_videos,Video *V[])
{               
	for (int last = num_videos-1;last > 0; last--)

	{               
		for (int cur =0 ; cur < last; cur++)
		{
			if (V[cur]->longer(V[cur+1]))
				swap (V[cur],V[cur+1]);
		}
	}               
}
//Function to sort the output so the highest ratings come first.
//Input: Total number of videos and array
//Output: NA
void ratedVideo(int num_videos, Video *V[])
{
	for (int last = num_videos-1; last > 0;last--)
	{
		for(int cur = 0; cur < last; cur++)
		{
			if (V[cur]-> ratings(V[cur+1]))
				swap (V[cur],V[cur+1]);
		}
	}
}
//Function to sort the output so the videos titles are in alphabetical order.
//Input: Total number of videos and array
//Output: NA
void titledVideo(int num_videos, Video *V[])
{
	for (int last = num_videos-1; last > 0;last--)
	{
		for(int cur = 0; cur < last; cur++)
		{
			if (V[cur]-> titles(V[cur+1]))
				swap (V[cur],V[cur+1]);
		}
	}
}
