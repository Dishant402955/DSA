class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        int n  =A.size();
        vector<bool>abool(n,false);
        vector<bool>bbool(n,false);
        int num = 0;
        for(int i=0;i<A.size();i++){
            abool[A[i]] = true;
            bbool[B[i]]=true;
            if(bbool[A[i]]==true) num++;
            if(abool[B[i]]==true) num++;
            if(A[i]==B[i]) num--;
            ans.push_back(num);
        }
        return ans;
    }
};
