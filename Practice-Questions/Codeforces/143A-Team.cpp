#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int ans = 0;

    for(int i = 0; i < n; i++ ){

        int one, two, three;
        cin >> one >> two >> three;

        int cnt = 0;
        if(one)     cnt++;
        if(two)     cnt++;
        if(three)   cnt++;

        if( cnt >= 2)   ans++;
    }

    cout << ans;
    return 0;
}