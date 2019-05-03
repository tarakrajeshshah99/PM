#ifndef ASSIGMENT3_CPP_INCLUDED
#define ASSIGMENT3_CPP_INCLUDED
#include<iostream>
using namespace std;
#define SIZE 10
int main ()
{
	string cities [SIZE]={"Pune","Mumbai","Chennai","Delhi"};
	int dis[SIZE][SIZE]={
							{0,200,0,1200},
							{200,0,1400,1000},
							{0,1400,0,0},
							{1200,1000,0,0}
						};
	string current,destination;
	cout<<"\nEnter current city :";
	cin>>current;
	cout<<"\nEnter destination city :";
	cin>>destination;
	if (current==destination)
		cout<<"Error! Current and Destination cities cannot be same.";
	else
	{
		int cr,cc;
		for (int i=0;i<4;i++)
		{
			if (cities[i]==current)
				cr=i;
			//else
				//cout<<"\nEnter valid city.";
			if (cities[i]==destination)
				cc=i;
			//else
				//cout<<"\nEnter valid city.";
		}


		if (dis[cr][cc]!=0)
			cout<<"\nThere is a path in between "<<current<<" and "<<destination<<" of distance "<<dis[cr][cc] <<"km.";
		else
			cout<<"\nThere is no path between these cities.";
	}

	return 0;
}



#endif // ASSIGMENT3_CPP_INCLUDED
