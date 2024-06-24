#include<iostream>
using namespace std;


 class hero {

    public:
    
    string name;
    int health;
    string power;
    static int MaxHealth ;


    void print( hero object ){
        cout<<"Printing all details of the object using the function : "<<endl;
        cout<<"[ name : "<<object.name<<" , Health : "<<object.health<<" , Power : "<<object.power<<" ] "<<endl;
  
    }

};



int main(){

   
    hero man;

    cout<<"Size of the object 'man' (which contains one 'int' , two 'char' arrays of size 100)  is : "<<sizeof(man)<<endl;
    cout<<"Size of an empty object/class will be '1 Byte'."<<endl;

    man.health = 54;
    man.name = "Dishant";
    man.power = "Nothing";

    cout<<endl<<"Accessing the variables of object man : "<<endl;
    man.print(man);


    cout<<endl<<"Dynamic allocation of the object : "<<endl<<endl;
    hero *ptr = new hero;

    (*ptr).name = "meet";
    ptr->health = 90;
    ptr->power = "Something";

    ptr->print(*ptr);
    

    return 0;
}