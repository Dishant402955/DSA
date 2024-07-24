#include<iostream>
#include<vector>
using namespace std;

int main(){

    string s;
    cin >> s;

    vector<int> v(26,0);

    for( char ch:s ){
        v[ ch - 'a']++;
    }

    int ans = 0;
    for(int i = 0; i < 26; i++){
        if(v[i])
            ans++;
    }

    if(ans&1)
        cout << "IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";
    
    return 0;
}