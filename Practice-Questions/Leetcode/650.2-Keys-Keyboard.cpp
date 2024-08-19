class Solution {
public:
    vector<int> prime;
    bitset<1001> isPrime;
    void sieve(int M){
        isPrime.set();
        isPrime[0]=isPrime[1]=0;
        int sqrtM=sqrt(M);
        for(int p=2; p<=sqrtM; p++){
            if (isPrime[p]==0) continue;
            prime.push_back(p);
            for(int j=p*p; j<=M; j+=p){
                isPrime[j]=0;
            }
        }
    //    cout<<isPrime.count();// 168 
        int q=(sqrtM&1)?sqrtM+2:sqrtM+1;
        for(int p=q; p<=M; p+=2){
            if (isPrime[p])
                prime.push_back(p);
        }
    }
    //for avoid of double computing special if n has prime factor p^k
    vector<int> dp;
    int f(int n){
        if (dp[n]!=-1) return dp[n];
        if (isPrime[n]) return dp[n]=n;
        int sqrtn=sqrt(n), factor;
        for(int i=0; prime[i]<=sqrtn; i++){
            if (n%prime[i]==0){
                factor=prime[i];
                break;
            }
        }
        return dp[n]=factor+f(n/factor);
    }

    int minSteps(int n) {
        if (n==1) return 0;// edge case
        sieve(max(7, n));// sieve method can work when n>=4
        dp.assign(n+1, -1);
        return f(n);
    }
};