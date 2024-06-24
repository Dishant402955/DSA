#include<iostream>
using namespace std;


 class hero {

    public:

    string name;
    int health;
    string power;
    static int MaxHealth ;


    static int get_MaxHealth (){
        return MaxHealth;
    }

    static void set_MaxHealth(int MaxHealth){
        hero::MaxHealth = MaxHealth;
    }

   
};


 int hero::MaxHealth = 200;


int main(){

    cout<<endl<<" 'this' keyword is used as a pointer to the current object !!! "<<endl<<endl;
    cout<<endl<<"We can access static variable without creating a object !!!"<<endl<<endl;

    cout<<"Max health (Static variable) = "<<hero::MaxHealth<<endl;

    hero::MaxHealth = 300;

    cout<<endl<<"After updating it Max health = "<<hero::MaxHealth<<endl;


    return 0;
}