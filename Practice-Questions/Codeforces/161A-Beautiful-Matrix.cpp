#include<iostream>
using namespace std;

int main(){

    int row , col;

    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            int temp;
            cin >> temp;
            if(temp){
                row = i;
                col = j;
                break;
            }
        }
    }

    int ans;

    if(row == 3 && col == 3){
        ans = 0;
    }
    else if(row == 3){
        if(col>3){
            ans = col-3;
        }
        else{
            ans = 3-col;
        }
    }
    else if(col == 3){
        if(row>3){
            ans = row-3;
        }
        else{
            ans = 3-row;
        }
    }
    else{
        if(row>3){
            ans = row-3;
        }
        else{
            ans = 3-row;
        }
        if(col>3){
            ans += col-3;
        }
        else{
            ans += 3-col;
        }

    }

    cout << ans;

    return 0;
}