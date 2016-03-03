//chart.cpp
//Nanda, Sagar
//snanda

#include<iostream>

using namespace std;

//Function to print asterics or blank space
int printAsterisks(int values[], int largest, int count)
{
    for (int row = 0; row<largest; row++)
    {
        for(int col =0; col <= count-1; col++)
        {
            if (row + values[col] >= largest)
                cout<<"*";
            else
                cout<<" ";
        }	
        cout<<endl;
    }
    return 0;
}

//Function to find out largest element in the array.
int retrieveLargestElement(int values[], int count)
{
    int largest =0;
    for (int i = 0; i < count; i++)
    {
        if (values[i]>= largest)
        {
            largest = values[i];
        }
    }
    return largest;
}

//Function to take input from user and store it into array.
int takeInputFromUser(int values[])
{
    const int MAX=100;	
    int k,count=0;
    //for (int i = 0; i < MAX-1 ; i++ ) Used this in submission.
    for (int i = 0; i < MAX ; i++ )
    {
        cin>>k;
        if (k==0)
            break;
        else
        {
            values[i]=k;
            count ++ ;
        }
    }
    return count;
}

int main()
{
    const int MAX=100;
    int values[MAX];
    int largest =0,count =0;
    count=takeInputFromUser(values);  
    largest = retrieveLargestElement(values,count);
    printAsterisks(values,largest,count);
} 

