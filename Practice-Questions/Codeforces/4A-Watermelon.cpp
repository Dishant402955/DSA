#include<iostream>
using namespace std;

int main(){

    int w;
    cin >> w;

    int temp = w;

    if(w&1){
        cout << "NO";
    }
    else if(w == 2){
        cout << "NO"; 
    }
    else{
        cout << "YES";
    }


    return 0;
}