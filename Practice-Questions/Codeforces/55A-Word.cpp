#include<iostream>
using namespace std;

int main(){

    string s;
    cin >> s;

    int Ucnt = 0;
    int Lcnt = 0;

    for(char ch: s){
        if( ch >= 'A' && ch <= 'Z')
            Ucnt++;
        else 
            Lcnt++;
    }

    if(Ucnt > Lcnt){
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if( ch <= 'z' && ch >= 'a')
                s[i] = (ch - 'a') + 'A';
        }
    }
    else{
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if( ch <= 'Z' && ch >= 'A')
                s[i] = (ch - 'A') + 'a';
        }
    }

    cout << s;

    return 0;
}