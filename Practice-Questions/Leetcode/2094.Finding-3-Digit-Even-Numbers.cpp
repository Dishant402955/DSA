class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        set<int>st;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(digits[i]!=0){
  if( ( i!=j && j!=k &&  i!=k && digits[k]==0) ||(i!=j && j!=k&& i!=k && digits[k]%2==0)){
                    int z=100*digits[i]+10*digits[j]+digits[k];
                    st.insert(z);
                }
                    }
                }
            }
        }
      vector<int>ans;
    for(auto it:st){
        ans.push_back(it);
    }
    return ans;
    }
};