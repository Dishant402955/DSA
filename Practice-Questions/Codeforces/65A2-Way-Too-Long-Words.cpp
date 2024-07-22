#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<string> v;

    for( int i=0; i<n; i++){
        string temp;
        cin >> temp;

        v.push_back(temp);
    }

    for( int i=0; i<n; i++){

        if(v[i].size() > 10){
            cout << v[i][0] <<  v[i].size()-2  << v[i][v[i].size()-1] << endl;
        }
        else{
            cout << v[i] << endl;
        }
    }

    return 0;
}