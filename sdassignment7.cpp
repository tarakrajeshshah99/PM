#ifndef SDASSIGNMENT7_CPP_INCLUDED
#define SDASSIGNMENT7_CPP_INCLUDED
#include<iostream>
#define MAX 100
using namespace std;
class doublehashing
{
private:
   struct node
   {
       int key;
       string value;
    }a[MAX];
public:
    doublehashing()
    {
        for(int i=0;i<MAX;i++)
        {
        a[i].key=0;
        }
    }
    void create(int table)
    {
        int i,key,index;
        string value;
        index=0;
       unsigned int index1=0;
            cout<<"enter a key value";
            cin>>key;
            cout<<"enter value";
            cin>>value;
            cout<<endl;
            index=key%table;
                if(a[index].key==0)
                {
                a[index].key=key;
                a[index].value=value;
                }
                else if(a[index].key!=0)
                {
                for(int j=1;j<table;j++)
                    {
                    index1=7-(key)%7;
                    index=(index+ j*index1)%10;
                    a[index].key=key;
                    a[index].value=value;
                    break;
                    }
                }
            }
    void display(int table)
    {
        for(int i=0;i<table;i++)
        cout<<a[i].key<<a[i].value<<endl;
    }
    void searching(int table)
    {
        int count=0;
        int key;
        int i;
        cout<<"enter key-value to be searched"<<endl;
        cin>>key;
        for(i=0;i<table;i++)
        {
            if(a[i].key==key)
            {
                cout<<"search found"<<endl;
                cout<<"key"<<a[i].key<<endl;
                cout<<"value"<<a[i].value<<endl;
                break;
            }
            count++;
        }
        cout<<count;
    }
};
int main()
{
    doublehashing l;
    char ch;
    int choice;
    int table;
    cout<<"enter table size"<<endl;
    cin>>table;
do{
  cout<<"MENU"<<endl;
  cout<<"1.INSERT"<<endl;
  cout<<"2.DISPLAY"<<endl;
  cout<<"3.SEARCH"<<endl;
  cout<<"enter your choice"<<endl;
  cin>>choice;
  switch(choice)
  {
  case 1:
      l.create(table);
      break;
  case 2:
    l.display(table);
    break;
  case 3:
    l.searching(table);
    break;
  }
  cout<<"do you want to continue"<<endl;
  cin>>ch;
}while(ch=='y');
}



#endif // SDASSIGNMENT7_CPP_INCLUDED
