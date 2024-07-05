#include<iostream>
using namespace std;

void MergeArrays(int arr[], int s, int e){

    int mid = s + (e-s)/2;

    int *arr1 = new int[mid-s+1];
    int *arr2 = new int[e-mid];

    int index1 = 0;
    int index2 = 0;

    int Index = s;
    for(int i = 0 ; i < mid-s+1  ; i++){
        arr1[i] = arr[Index++];
    }
    
    Index = mid+1;
    for(int i = 0 ; i < e-mid ; i++){
        arr2[i] = arr[Index++];
    }

    Index = s;


    while( index1 < mid-s+1 || index2 < e-mid){

        if( index1 >= mid-s+1 ){
            while( index2 < e-mid )     arr[Index++] = arr2[index2++];
            break;
        }
        if( index2 >= e-mid ){
            while( index1 < mid-s+1 )   arr[Index++] = arr1[index1++];
            break;
        }

        if( arr1[index1] > arr2[index2] )
            arr[Index++] = arr2[index2++];
        else    
            arr[Index++] = arr1[index1++];
    
    }

}

void MergeSort( int arr[], int s, int e){

    if( s >= e )   return;

    int mid = s + (e-s)/2;

    MergeSort( arr, s, mid);

    MergeSort( arr, mid+1, e);

    MergeArrays( arr, s, e);

}

int main(){

    int arr[10] = { 2, 10, 4, 56, 40, 35, 91, 20, 22, 30};

    MergeSort( arr, 0, 9);

    for( int i : arr)   cout<<i<<" ";

    return 0;
}