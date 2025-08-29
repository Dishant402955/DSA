class Solution {
public:
    long long flowerGame(int n, int m) {
       int odda=(n+1)/2;
       int evena=n/2;
       int oddb=(m+1)/2;
       int evenb=m/2;
       return (long long)odda * evenb + (long long)evena * oddb;
    }
};
