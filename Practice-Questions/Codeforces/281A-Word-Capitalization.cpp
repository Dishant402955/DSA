#include<iostream>
using namespace std;

int main(){

    string s;
    cin >> s;

    char ch = s[0];

    if(ch >= 'a' && ch <= 'z'){
        s[0] = (ch - 'a') + 'A'; 
    }
  
    cout << s;

    return 0;
}