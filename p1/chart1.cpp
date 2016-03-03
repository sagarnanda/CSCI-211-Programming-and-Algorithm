//chart.cpp
//Nanda,Sagar
//snanda
#include<iostream>

using namespace std;
//Function to print UpChart.
int printUpChart(int values[], int largest, int count)
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

//Function to retrieve largest element from an array.
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

//Function to take input from user and store it in an array.
int takeInputFromUser(int values[])
{
	const int MAX=100;	
	int k,count=0;
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

//Function to print down chart.
int printDownChart(int values[], int largest, int count)
{
    for (int row = 0; row< largest; row++)
	{
		for(int col =0; col <= count-1; col++)
		{
			if (row < values[col])
				cout<<"*";
				
			else
				cout<<" ";
		}	
	cout<<endl;
	}
	return 0;
}

//Function to print left chart.
int printLeftChart(int values[], int largest, int count)
{
    for (int row = 0; row < count; row++)
	{
		for(int col =0; col < largest; col++)
		{
			if (values[row] > col)
				cout<<"*";
				
			else
				cout<<" ";
		}	
	cout<<endl;
	}
	return 0;
}

//Function to print right chart.
int printRightChart(int values[], int largest, int count)
{
    for (int row = 0; row < count; row++)
	{
		for(int col =0; col < largest; col++)
		{
			if (values[row] < largest - col )
				cout<<" ";
				
			else
				cout<<"*";
		}	
	cout<<endl;
	}
	return 0;
}

int main()
{
	const int MAX=100;
	int values[MAX];
	int largest =0,count =0;
	count=takeInputFromUser(values);  
	largest = retrieveLargestElement(values,count);
	printUpChart(values,largest,count);
    cout << endl;
	printDownChart(values,largest,count);
    cout << endl;
	printLeftChart(values,largest,count);
    cout << endl;
	printRightChart(values,largest,count);
} 

