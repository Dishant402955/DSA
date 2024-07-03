#include<iostream>
using namespace std;

void  InsertionSort( int arr[] , int size ){

    for(int i = 1 ; i < size ; i++){

        int temp = arr[i];

        int j = i-1 ;
        while( j>=0 && arr[j] > temp){

                arr[j+1] = arr[j];
                j--;
        }
            arr[j+1] = temp;

    }
    
}


int main(){

    int array[15] = { 5, 4, 45, 7, 98,44, 32, 40, 89, 50, 55, 54, 42, 39, 10};

    InsertionSort( array ,15 );

    cout<<endl;
    for( int i : array )        cout<<i<<" ";
    cout<<endl;

    return 0;
}