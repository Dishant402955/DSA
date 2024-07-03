#include<iostream>
using namespace std;

void BubbleSort( int arr[] , int size ){

    int update = 0 ;
    for(int i = 0 ; i < size-1 ; i++){

        for( int j = 0 ; j <= size+1-i ; j++){
            if( arr[j] > arr[j+1] ) {
                swap(arr[j],arr[j+1]);
                update++;    
            }
        }
        if(!update)     break;

    }
    
}


int main(){

    int array[15] = { 5, 4, 45, 7, 98,44, 32, 40, 89, 50, 55, 54, 42, 39, 10};

    BubbleSort( array ,15 );

    cout<<endl;
    for( int i : array )        cout<<i<<" ";
    cout<<endl;

    return 0;
}