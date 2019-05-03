#ifndef ASSIGN1_CPP_INCLUDED
#define ASSIGN1_CPP_INCLUDED
#include<iostream>
using namespace std;

int insert(int *arr,int size){
    cout<<"Enter the number to be inserted : ";
    size++;
    cin>>arr[size-1];
    return size;
}
int remove(int *arr,int size){
    cout<<"Enter the position of number to be removed : ";
    int pos;
    cin>>pos;
    for(int i = pos-1;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
    return size;
}

void contains(int * arr, int size){
        cout<<"Enter the number to be searched : "<<endl;
        int no,counter=0;
        cin>>no;
        for(int i=0;i<size;i++){
            if(arr[i]==no){
                cout<<"The number "<<no<<" is present at position "<<i+1<<endl;
                counter++;
            }
        }
        if(counter==0){cout<<"Number you entered is not present in the set."<<endl;}
}
void size(int size1,int size2){
    cout<<"The size of Set 1 = "<<size1<<endl;
    cout<<"The size of Set 2 = "<<size2<<endl;
}

void display(int * arr1,int *arr2,int size1,int size2){
    for(int i=0;i<size1;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
     for(int i=0;i<size2;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

}

void _union(int * arr1,int *arr2,int size1,int size2){

    cout<<"Union is ";
    for(int i=0;i<size1;i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<size2;i++){
        bool isSame=false;
        for(int j=0;j<size1;j++){
            if(arr2[i]==arr1[j]){
                isSame=true;
            }
        }
        if(isSame==false){
            cout<<arr2[i]<<"  ";
        }
    }

    cout<<endl;
}

void intersection(int * arr1,int *arr2,int size1,int size2){
    cout<<"intersection is : ";

    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
               if(arr1[i]==arr2[j]){
                    cout<<arr1[i]<<" ";
               }
        }
    }
    cout<<endl;

}

void diff(int * arr1,int *arr2,int size1,int size2){
    cout<<"Difference is : ";
    for(int i=0;i<size1;i++){
        bool isDiff=true;
        for(int j=0;j<size2;j++){
               if(arr1[i]==arr2[j]){
                    isDiff=false;
               }
        }
        if(isDiff==true){
            cout<<arr1[i]<<"  ";
        }

    }
    cout<<endl;
}

void isSubset(int * arr1,int *arr2,int size1,int size2){
    if(size2>size1){
        cout<<"set 2 is not a subset"<<endl;
    }
    else{
        int k=0;
        for(int i=0;i<size2;i++){
            bool isMatched = false;
            for(int j=0;j<size1;j++){
                if(arr2[i]==arr1[j]){
                    isMatched=true;
                    k++;
                }
            }
            if(isMatched==false){
                cout<<"set 2 is not a subset"<<endl;
            }
        }
        if(k==size2){
            cout<<"set 2 is a subset of set 1"<<endl;
        }

    }
}

int main(){
    cout<<"How many elements do you want to enter in first set :";
    int size1;
    cin>>size1;
    int arr1[100];
    cout<<"Enter the elements below :";
    for(int i=0;i<size1;i++){
        cin>>arr1[i];
    }
    cout<<"How many elements do you want to enter in second set :";
    int size2;
    cin>>size2;
    int arr2[100];
    cout<<"Enter the elements below :";
    for(int i=0;i<size2;i++){
        cin>>arr2[i];
    }
    char choice;
    do{
        cout<<"    M E N U    "<<endl;
        cout<<"1.insert"<<endl<<"2.remove"<<endl<<"3.contains element?"<<endl<<"4.size"<<endl<<"5.display"<<endl<<"6.intersection"<<endl<<"7.Union"<<endl<<"8.Difference"<<endl<<"9.is Subset "<<endl;
        int ch;
        cin>>ch;
        switch(ch){
            case 1 :
                cout<<"In which set do you want to insert the element ? "<<endl;
                cout<<"1.set 1"<<endl<<"2.set 2"<<endl;
                int no2;
                cin>>no2;
                if(no2==1){size1 = insert(arr1,size1);}
                else{size2 = insert(arr2,size2);}
            break;
            case 2 : cout<<"from which set do you want to remove the element ? "<<endl;
                cout<<"1.set 1"<<endl<<"2.set 2"<<endl;
                int no3;
                cin>>no3;
                if(no3==1){size1 = remove(arr1,size1);}
                else{size2 = remove(arr2,size2);}
            break;
            case 3 :
                cout<<"In which set do you want to search the element ? "<<endl;
                cout<<"1.set 1"<<endl<<"2.set 2"<<endl;
                int no4;
                cin>>no4;
                if(no4==1){contains(arr1,size1);}
                else{contains(arr2,size2);}
            break;
            case 4 : size(size1,size2);
            break;
            case 5 : display(arr1,arr2,size1,size2);
            break;
            case 6 : intersection(arr1,arr2,size1,size2);
            break;
            case 7 : _union(arr1,arr2,size1,size2);
            break;
            case 8 : diff(arr1,arr2,size1,size2);
            break;
            case 9 : isSubset(arr1,arr2,size1,size2);
            break;
            default : "Sorry!! Wrong choice.";
        }
        cout<<"Do you want to continue?[y/n]";
        cin>>choice;
    }while(choice=='Y' || choice=='y');
    return 0;
}
#endif // ASSIGN1_CPP_INCLUDED
