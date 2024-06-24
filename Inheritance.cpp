#include<iostream>
using namespace std;

class human {

    public:

    int height;
    int weight;
    int age;

    void print(human& obj){
        cout<<endl<<"[ Height : "<<obj.height<<" , Weight : "<<obj.weight<<" , Age : "<<obj.age<<" ]"<<endl;
    }

};

// hierarchiral
class male: public human {

};

class female: public human {

};

// multiple + multilevel = hybrid
class trans: public male , public female{

};

// inheritance ambiguity 
class A {
    public:
    void abc(){
        cout<<endl<<"Inside class A !!"<<endl;
    }
};

class B {
    public:
    void abc(){
        cout<<endl<<"Inside class B !!"<<endl;
    }
};

class C: public A , public B{

};


int main(){

    cout<<endl<<"Implementing Inheritance "<<endl<<endl;
        
    male male1;
    male1.height = 130;
    male1.weight = 120;
    male1.age = 30;

    male1.print(male1);



    cout<<endl<<endl<<"Implementing a inheritance ambiguity :"<<endl<<endl;

    cout<<"Calling Functions of parent classes through inheritance ambiguity :"<<endl;
    
    C obj;
    obj.A::abc();
    obj.B::abc();

        return 0;
}