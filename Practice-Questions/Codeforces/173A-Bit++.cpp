#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int ans = 0;

    for( int i = 1; i <= n; i++ ){

        string temp;
        cin >> temp;

        if(temp[1] == '-'){
            ans -= 1;
        }
        else{
            ans += 1;
        }

    }

    cout<<ans;
    return 0;
}