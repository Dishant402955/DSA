#include<iostream>
using namespace std;


 class hero {


    public:
    
    string name;
    int health;
    string power;
    static int MaxHealth ;


    
    ~hero(){
        cout<<"User defined Destructor\n where the current object's hero name which will be deallocated = "<<this->name<<endl;
    }
    

    void print( hero object ){
        cout<<endl<<"Printing all details of the object using the function : "<<endl;
        cout<<"[ name : "<<object.name<<" , Health : "<<object.health<<" , Power : "<<object.power<<" ] "<<endl;
  
    }

};


int main(){

 
    hero man;
    man.name = "Dishant";
    cout<<endl<<endl<<"!!! For statically created object the destructor will be called automatically but for Dynamically created you will require to call it in function manually."<<endl<<endl;

 
    hero women;
    women.name = "she";

    hero *ptr = new hero;
    ptr -> name = "HE";
    ptr -> ~hero();
    

    return 0;
}