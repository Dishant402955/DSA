#include<bits/stdc++.h>
using namespace std;

int Binary_search(int arr[] , int size , int key){

    int s = 0;
    int e = size-1 ;
    int mid = s + (e-s)/2 ;

    while( s <= e ){

        if( arr[mid] == key )   return mid;

        else if( arr[mid] > key )   e = mid - 1 ;

        else    s = mid + 1 ;

        mid = s + (e-s)/2 ;

    }

    return -1;
}

int main(){

    int array[10] = { 12, 23, 34, 45, 56, 67, 78, 89, 910, 1000};

    cout<<"printing the index of the key '67' by Binary Search : "<<Binary_search(array,10,67)<<endl;

    cout<<"printing the index of the key '77' by Binary Search : "<<Binary_search(array,10,77)<<endl;

    cout<<"printing the index of the key '45' by Binary Search : "<<Binary_search(array,10,45)<<endl;

    cout<<"printing the index of the key '1000' by Binary Search : "<<Binary_search(array,10,1000)<<endl;

    return 0;
}