#include<iostream>
#include<string>
#include"video.h"
#include"vlist.h"
using namespace std;

int main()
{
    Video *vid;
    int total=0;
    string sort;
    string command;
    string title,url,comment;
    double length;
    int rating;
    //    int count =0;
    Vlist vlist;
    while(getline(cin,command))
    {
        if (command == "insert")
        {
            getline(cin,title);
            if  (vlist.titlecheck(title))
            {
                cerr<<"Could not insert video <"<<title<<">, already in list." <<endl; 
            }
            else
            {

                getline(cin, url);
                getline(cin, comment);
                cin >> length;
                cin >> rating;
                cin.ignore();
                vid = new Video(title,url,comment,length,rating);
                vlist.insert(vid);       	
            }
        }
        else if (command == "print")
        {	
            vlist.print();	
        }
        else if (command == "length")
        {
            total = vlist.length();	
            cout<<total<<endl;
        }
        else if (command == "lookup")
        {    
            getline(cin,title);
            if (vlist.lookup(title))
            {
                cerr<<"Title <"<<title<<"> not in list."<<endl;
            }
        }
        else if (command == "remove")
        {
            getline (cin,title);
            if( vlist.remove(title))
            {   
                cerr<<"Title <"<<title<<"> not in list, could not delete."<<endl;
            }
        }
        else 
        {
            cerr <<"<"<<command<<"> is not a legal command, giving up."<<endl;
            return 1;
        }
    }
    return 0;
}

