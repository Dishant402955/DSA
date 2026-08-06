class Solution {
public:
    int product_digit(int x){
        int ans=1;
        while(x>0){
            auto [q, r]=div(x, 10);
            ans*=r;
            x=q;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        for(int z=n; z<n+10; z++){
            if (product_digit(z)%t==0) return z;
        }
        return 0;
    }
};
