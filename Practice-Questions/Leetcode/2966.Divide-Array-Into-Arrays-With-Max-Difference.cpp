class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0; i<n; i+=3){
            vector<int>arr;
            int x=nums[i];
            int y=nums[i+1];
            int z=nums[i+2];
            if(abs(x-y)<=k && abs(y-z)<=k && abs(x-z)<=k){
   arr.push_back(x);
    arr.push_back(y);
     arr.push_back(z);
     ans.push_back(arr);
            }
        } 
        if(ans.size()==n/3){
            return ans;
        }
        else{
            return {};
        }
    }
};
