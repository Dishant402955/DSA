#include<iostream>
using namespace std;

void SelectionSort( int arr[] , int size ){

    for (int i = 0 ; i < size ; i++){

        int minIndex = i;

        for(int j = i+1 ; j < size ; j++ ){

            if(arr[j] < arr[minIndex])  minIndex = j;

        }

        swap(arr[minIndex] , arr[i]);

    }
}


int main(){

    int array[15] = { 5, 4, 45, 7, 98,44, 32, 40, 89, 50, 55, 54, 42, 39, 10};

    SelectionSort(array,15);
    
    cout<<endl;
    for( int i : array)     cout<<i<<" ";
    cout<<endl;
    
    return 0;
}