class Solution {
public:

long long maxAlternatingSum(vector<int>& A) {
    long long res = 0, n = A.size();
    for(int& x : A) x = x*x;
    nth_element(A.begin(), A.begin()+n/2, A.end()); 
    for(int i=0; i<n/2; ++i) res += A[n-i-1]-A[i]; 
    return res + (n%2 ? A[n/2] : 0); 
}
};
