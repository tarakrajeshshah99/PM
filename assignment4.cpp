#ifndef ASSIGNMENT4_CPP_INCLUDED
#define ASSIGNMENT4_CPP_INCLUDED
#include<iostream>
#define INT_MAX 999
using namespace std;

class prims
{
	public:

	prims()
	{}
	int** build(int);
	void print(int[],int**,int);
	int minKey(int[],bool[], int);
	void Prims_Algo(int**,int);
};

int** prims::build(int V)
{
	int i,j,cost,e;
	int** graph=new int*[V];


	for(int i=0;i<V;i++)
	{
		graph[i]=new int [V];
		for(int j=0;j<V;j++)
		{
		graph[i][j]=0;
		}

	}

	cout<<"Enter edges"<<endl;
	cin>>e;

	for(int k=1;k<=e;k++)
	{
		cout<<"Enter start vertex"<<endl;
		cin>>i;
		cout<<"Enter end vertex"<<endl;
		cin>>j;
		cout<<"Enter cost of edge"<<endl;
		cin>>cost;
		graph[i-1][j-1]=cost;
		graph[j-1][i-1]=cost;
	}

	for(int k=0;k<V;k++)
	{
		for(int l=0;l<V;l++)
		{
		cout<<graph[k][l]<<"\t";
		}
		cout<<"\n";
	}

	return graph;
}

void prims::print(int parent[],int** g,int V)
{
	cout<<"Shortest path will be"<<endl;
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V;i++)
	cout<< parent[i]+1<<"-"<< i+1<<"\t"<< g[i][parent[i]]<<endl;

}

int prims::minKey(int key[], bool mstSet[], int V)
{

	int min = INT_MAX;
	int min_index;

	for (int v = 0; v < V; v++)
	if (mstSet[v] == false && key[v] < min)
		min = key[v], min_index = v;

	return min_index;

}

void prims::Prims_Algo(int** g,int V)
{

	int parent[V];

	int key[V];

	bool mstSet[V];


	for (int i = 0; i < V; i++)
	{
		key[i] = INT_MAX;
		 mstSet[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;


	for (int count = 0; count < V-1; count++)
	{

		int u = minKey(key, mstSet,V);


		mstSet[u] = true;


		for (int z = 0; z < V; z++)


		if (g[u][z] && mstSet[z] == false && g[u][z] < key[z])
		{
			parent[z] = u;
			 key[z] = g[u][z];
		}
	}


	print(parent,g,V);

}

int main()
{
	prims p;
	int V;
	cout<<"Enter number of vertices"<<endl;
	cin>>V;
	//p.build(V);
	int **g=p.build(V);
	p.Prims_Algo(g,V);
	return 0;
}



#endif // ASSIGNMENT4_CPP_INCLUDED
