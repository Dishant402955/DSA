#include<iostream>
using namespace std;


 class hero {

    public:
    string name;
    int health;
    string power;
    static int MaxHealth ;


    hero(){
        cout<<"Calling User defined constructor."<<endl;
    }

    hero(string name , string power){
        cout<<endl<<"Calling parameterized constructor : "<<endl;
        this -> name = name ;
        this -> power = power ;
    }
    

    void print( hero object ){
        cout<<"Printing all details of the object using the function : "<<endl;
        cout<<"[ name : "<<object.name<<" , Health : "<<object.health<<" , Power : "<<object.power<<" ] "<<endl;
  
    }

};




int main(){

    
    hero man;
    cout<<"Size of the object 'man' (which contains one 'int' , two 'char' arrays of size 100)  is : "<<sizeof(man)<<endl;
    cout<<"Size of an empty object/class will be '1 Byte'."<<endl;

    hero men("Me","Nothing");
    men.print(men);

    return 0;
}