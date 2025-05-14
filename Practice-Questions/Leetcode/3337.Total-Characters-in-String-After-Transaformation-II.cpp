class Solution {
public:
    using Matrix =vector<vector<int>> ;
    const int Alpha = 26 ;
    const int MOD = 1e9 + 7 ; 
    Matrix multiply(Matrix &A, Matrix &B){
        Matrix C (Alpha, vector<int>(Alpha,0));

        for(int i=0;i<Alpha;i++){
            for(int j=0;j<Alpha;j++){
                for(int k = 0;k<Alpha;k++){
                    C[i][j]=(C[i][j] + 1LL * A[i][k] * B[k][j]) % MOD ; 
                }
            }
        } 

        return C ;

    }

    Matrix power(Matrix A, int pow){
        Matrix res(Alpha, vector<int>(Alpha,0));
        //making Identitiy Matrix

        for(int i=0;i<Alpha;i++){
            res[i][i]=1 ;
        }

        while(pow>0){
            if(pow&1){
                res= multiply(res, A);
            }
            A = multiply(A,A) ; 
            pow = pow/2 ; 
        }
        return res ;
    }


    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int n = s.length() ; 
        //let's build the transformation matrix 
         
        Matrix T(Alpha, vector<int> (Alpha,0)) ;

        // for(int i=0;i<n;i++){
        //     int cnt = nums[s[i]-'a'] ;
        //     for(int j=1;j<=cnt;j++){
        //         T[(j+s[i]-'a')%26][s[i]-'a'] = 1 ;
        //     }
        // } 
        for(int i = 0; i < 26; i++) {
            for(int j = 1; j <= nums[i]; j++) {
                T[(i + j) % 26][i] = (T[(i + j) % 26][i] + 1) % MOD;
            }
        }


        // for(int i=0;i<nums.size();i++){
        //     int cnt = nums[i] ; 
        //     for(int j=1;j<=cnt;j++){
        //         T[(j+i)%26][i] = 1 ;
        //     }
        // }

        // for(int i = 0;i<Alpha;i++){
        //     for(int j=0;j<Alpha;j++){
        //         cout<<T[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // Matrix Tt = power(T,)
        Matrix Tt = power(T,t) ; 
        vector<int> freq(Alpha,0);

        for(auto it : s){
            freq[it-'a']++;
        }

        vector<int> res(Alpha,0) ;

        for(int i=0;i<Alpha;i++){
            for(int j=0;j<Alpha;j++){
                res[i] = (res[i]+ 1LL* Tt[i][j] * freq[j] )%MOD;
            }
        }

        int cnt = 0 ; 

        for(auto it : res){
            cnt = (cnt+it)%MOD;
        }

        return cnt ;



    }
};