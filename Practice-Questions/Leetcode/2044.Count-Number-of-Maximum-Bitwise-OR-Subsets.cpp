class Solution {
public:
    int solve(vector<int>& nums,int i,int currOR ,int maxOR,vector<vector<int>>&t){
           if(i==nums.size()){
             if(currOR==maxOR) return 1;
             return 0;
           }

           if(t[i][currOR]!=-1) return t[i][currOR];

           return t[i][currOR]=solve(nums,i+1,nums[i]|currOR,maxOR,t)+solve(nums,i+1,currOR,maxOR,t);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        
        int maxOR=0;
        int currOR=0;
        for(int num:nums){
            maxOR|=num;
        }
        int n=nums.size();
        vector<vector<int>>t(n+1,vector<int>(maxOR+1,-1));
        return solve(nums,0,currOR,maxOR,t);
    }
};
