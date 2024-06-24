#include<iostream>
using namespace std;

class sample1{

    public:

    int a;

    void func(int a){
        cout<<endl<<"Inside the function with 1 integer as parameter !!!"<<endl;
    }

    void func(char a){
        cout<<endl<<"Inside the function with 1 character as parameter !!!"<<endl;
    }

    void func(int a , int b ){
        cout<<endl<<"Inside the function with 2 integers as parameter !!!"<<endl;
    }

    void operator+ (sample1& obj){
        cout<<endl<<"This is sum operator!!!"<<endl;
    }

    void operator() (){
        cout<<endl<<"These are braces!!!"<<endl;
    }

    void func(){
        cout<<endl<<"Inside the parent class !!!"<<endl;
    }
    
};

class sample_child1: public sample1{
    
};

class sample_child2: public sample1{
    public:
    void func(){
        cout<<endl<<"Inside the child class !!!"<<endl;
    }
};



int main(){

    cout<<endl<<"Implementing Compile time polymorphism : "<<endl<<endl;
    cout<<endl<<"Function overloading : "<<endl;

    sample1 obj , obj2;
    obj.func(100);
    obj.func('a');
    obj.func(12,23);

    cout<<endl<<endl<<"Operator overloading : "<<endl;

    obj + obj2 ;
    obj ();

    cout<<"\n\n\n\n\nImplementing Runtime polymorphism : "<<endl<<endl;
    sample_child1 o1;
    sample_child2 o2;

    o1.func();
    o2.func();
    return 0;
}