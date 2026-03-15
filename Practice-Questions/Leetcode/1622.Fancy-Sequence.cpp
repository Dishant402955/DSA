constexpr int N=1e5+1, MOD=1e9+7;
int A[N];
long long Add[N], Inv[N];
static long long inverse(long long a) {
    long long b=MOD; 
    long long x0=1, x1=0; 
    while (b>0){
        auto [q, r]=div(a, b);
        x0=exchange(x1, x0-q*x1);
        a=exchange(b, r);
    }
    return (x0<0)?x0+MOD:x0;
}
long long inv0[101];
void compute_inv(){
    if (inv0[1]==1) return;
    inv0[1]=1;
    for(int m=2; m<=100; m++)
        inv0[m]=inverse(m);
}

class Fancy {
    int n;
    int *nums;
    long long *add, *inv;
    long long curMul=1, curAdd=0, curInv=1; 

public:
    Fancy() : n(0) {
        nums=A; add=Add; inv=Inv;
        compute_inv();
    }

    void append(int val) {
        nums[n]=val;
        add[n]=curAdd;
        inv[n]=curInv;
        n++;
    }

    void addAll(int inc) {
        curAdd=(curAdd+inc)%MOD;
    }

    void multAll(int m) {
        curMul=(curMul*m)%MOD;
        curAdd=(curAdd*m)%MOD;
        curInv=(curInv*inv0[m])%MOD;
    }
    int getIndex(int i) {
        if (i>=n) return -1; 
        // (nums[i]-add[i])*inv[i]*curMul+curAdd
        return ((nums[i]-add[i]+MOD)*inv[i]%MOD*curMul%MOD+curAdd)%MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
