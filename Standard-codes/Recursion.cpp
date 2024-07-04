#include<iostream>
#include<string>
using namespace std;


int Factorial(int n){

    if( n == 0 )    return 1;

    return n*Factorial(n-1);
}


int Fibonnaci(int n){

    if( n == 0 )    return 0;
    if( n == 1 )    return 1;

    return Fibonnaci(n-1) + Fibonnaci(n-2);

}

int BinarySearch( int arr[], int s, int e, int key){

    if( s>e )   return -1;

    int mid = s + (e-s)/2;

    if(arr[mid] == key)     return mid;

    else if( arr[mid] > key)
        return BinarySearch(arr, s, mid-1, key);

    else
        return BinarySearch(arr, mid+1, e, key);

}

void ReverseString(string& S, int i, int j){

    if( i > j )    return;

    swap( S[i] , S[j] );

    ReverseString( S, ++i , --j);

}

bool IsPalindrome(string& S, int i, int j){

    if( i > j )     return true;

    if( S[i] != S[j] )      return false;

    IsPalindrome( S, ++i, --j);

}


int main(){

    cout<<endl<<endl<<"Implementing Recursion from basic : "<<endl<<endl;
    
    cout<<"Factorial of '12' is : "<<Factorial(12)<<endl<<endl;

    cout<<"Printing '25th' Fibonnaci term : "<<Fibonnaci(25)<<endl<<endl;

   
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<"Index of '10' using recursive binary search : "<<BinarySearch(array,0,9,10)<<endl<<endl;


    string S = "Dishant";

    cout<<"Reversing the string '"<<S<<"' using Recursive approach : ";
    ReverseString(S, 0, S.length()-1);
    cout<<S<<endl<<endl;


    string A = "abcddcba";
    string B = "abcdedcba";
    string C = "abcdefdcba";

    cout<<"Is string 'abcddcba' Palindrome ? : ";
    IsPalindrome( A, 0, A.length()-1 ) ? cout<<"yes"<<endl : cout<<"No"<<endl ;
   

    cout<<"Is string 'abcdedcba' Palindrome ? : ";
    IsPalindrome( B, 0, B.length()-1 ) ? cout<<"yes"<<endl : cout<<"No"<<endl ;


    cout<<"Is string 'abcdefdcba' Palindrome ? : ";
    IsPalindrome( C, 0, C.length()-1 ) ? cout<<"yes"<<endl : cout<<"No"<<endl ;


    

    return 0;
    
}
