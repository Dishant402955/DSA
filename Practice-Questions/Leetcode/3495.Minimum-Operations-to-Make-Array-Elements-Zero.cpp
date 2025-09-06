class Solution {
public:
    int cal(int x){
        return (log10(x)/log10(4)) + 1;
    }
    long long pow(long long a , int n){
        long long res = 1;
        while(n){
            if(n&1){
                res *= a;
            }
            a *= a;
            n >>= 1;
        }
        return res;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long op = 0;
        for(auto& q : queries){
            long long cnt = 0, a = q[0], b = q[1], lo = cal(a), hi = cal(b), x = lo, num = a;

            while(x <= hi){
                if(x == hi){
                    cnt += (b-num+1)*x;                  
                }else{
                    cnt += (pow(4,x)-num)*x;
                }
                num = pow(4,x++);
            }
            op += (cnt+1)/2;
        }
        return op;
    }
};
