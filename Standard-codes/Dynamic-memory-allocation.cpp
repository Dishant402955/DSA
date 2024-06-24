// referance variable and dynamic memory allocation


#include<iostream>
using namespace std;


void func(int& a){
    a = 4346;
}

int main(){

    cout<<endl<<"Referance variable : "<<endl;

    int i = 57 ;
    int& j = i ;

    cout << i << " --- " << j << endl;

    int p = 10 ;
     cout<<"Before : "<<p<<endl;
     func(p);
     cout<<"After : "<<p<<endl;
    


      cout<<endl<<endl<< "Dynamic memory allocation : "<<endl;
    int *ptr = new int ;
    *ptr = 346;

    cout<<endl<<"Memory allocated as single block : "<<endl;
    cout<<"Block address : "<<ptr<<endl<<"Stored value in block : "<<*ptr << endl;
    int *array = new int[10];

    array[0] = 45675;
    array[4] = 352425;

    cout<<endl<<"Memory allocated as Array : "<<endl<<"Index 0 : "<<array[0]<<endl;
    cout<<"Index 4 : "<<array[4]<<endl;

    delete ptr;
    delete [] array;
    
     int **matrix = new int*[5];


     for(int i = 0 ; i < 5 ; i++){
         matrix[i] = new int[5];
     }
     
    matrix[0][0] = 5415;
    matrix[2][4] = 87584;

    cout<<endl<<"Memory allocated as 2-D array : "<<endl;
    cout<<"Accessing 0,0 position : "<<matrix[0][0]<<endl;
    cout<<"Accessing 2,4 position : "<<matrix[2][4]<<endl;

      for(int i = 0 ; i < 5 ; i++){
        delete [] matrix[i];
      }

      delete [] matrix;
      
    cout<<endl<<" Tanks for watching 👌 :) "<<endl;
    
    return 0 ;
}