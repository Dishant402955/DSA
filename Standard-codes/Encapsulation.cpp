#include<iostream>
using namespace std;

class D {

    private:

    int A;
    char B;
    double C;
    long long int E ;

    void func1(){
        cout<<endl<<"This is a private  function!!! "<<endl;
    }

    void func2(){
        cout<<endl<<"This is also a private function!!! "<<endl;
    }

};


int main(){

    cout<<endl<<"Implementing Encapsulation : "<<endl<<endl;

    cout<<"We have made all data members and functions private so that we can access them iutside the class."<<endl;

    cout<<endl<<"Which increses the safety of our data !!!!"<<endl;
    return 0;
}