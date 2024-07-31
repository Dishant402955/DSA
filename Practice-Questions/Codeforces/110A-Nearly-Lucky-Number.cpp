#include<iostream>
using namespace std;

int main(){

    int ans = 0;

    long long int n;
    cin >> n;

    while(n!=0){

        if( n%10 != 4 && n%10 != 7)
            ans = 1;
            break;

        n = n/10;

    }

    if(ans)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}