class Solution {
public:
    const long long mod=1e9+7;
    long long powMod(long long x, long long exp){
        if (exp==0) return 1;
        bitset<64> E(exp);
        long long ans=1;
        for(int i=50; i>=0; i--){
            ans=(ans*ans%mod)*(E[i]?x:1LL)%mod;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        const long long n0=(n+1)/2 , n1=n-n0;
        return powMod(5, n0)*powMod(4, n1)%mod;
    }
};