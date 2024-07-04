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



int main(){

    cout<<endl<<endl<<"Implementing Recursion from basic : "<<endl<<endl;
    
    cout<<"Factorial of '12' is : "<<Factorial(12)<<endl<<endl;

    cout<<"Printing '25th' Fibonnaci term : "<<Fibonnaci(25)<<endl<<endl;

   
    return 0;
    
}
