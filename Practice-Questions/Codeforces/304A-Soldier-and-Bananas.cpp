#include<iostream>
#include<vector>
using namespace std;

int main(){

    int k, w, n;
    cin >> k  >> n >> w;

    int totalCost = 0;

    for( int i = 1; i <= w; i++)
        totalCost += i*k;
    
    int borrow;

    if(totalCost > n)
        borrow = totalCost - n;
    else 
        borrow = 0;
    
    cout << borrow;

    return 0;
}