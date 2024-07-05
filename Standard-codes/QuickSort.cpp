#include<iostream>
using namespace std;

int MakePartition( int arr[], int s, int e){

    int pivot = arr[s];
    int count = 0;

    for(int i = s + 1 ; i <= e ; i++){
        if( arr[i] <= pivot)    count++;
    }

    int pivotIndex =  s + count;

    swap( arr[pivotIndex] , arr[s] );

    int i = s;
    int j = e;

    while( i < pivotIndex && j > pivotIndex ){

        while( arr[i] <= pivot )     i++;

        while( arr[j] > pivot )     j--;

        if( i < pivotIndex && j > pivotIndex )    swap( arr[i] , arr[j] );

    }

    return pivotIndex;

}


void QuickSort( int arr[], int s, int e){

    if( s >= e )     return;

    int PartitionIndex = MakePartition( arr, s, e);

    QuickSort( arr, s, PartitionIndex-1);

    QuickSort( arr,  PartitionIndex+1, e);

}


int main(){

    int array[10] = { 23, 2, 3, 45, 4, 5, 1, 60, 50, 30};


    cout<<endl<<"Original Array : ";
    for(int i : array)      cout<<i<<" ";

    QuickSort( array, 0, 9);

    cout<<endl<<endl<<"Sorted Array : ";
    for(int i : array)      cout<<i<<" ";

    cout<<endl<<endl;

    return 0;
}