class Solution {
public:
void BackTrack(vector<int>&nums,vector<int>&store,int i,int &sum){
    if(i>=nums.size()){
        int val=0;
        for(auto it:store)val^=it;
        sum+=val;
        return;
    }
    BackTrack(nums,store,i+1,sum);
    store.push_back(nums[i]);
    BackTrack(nums,store,i+1,sum);
    store.pop_back();
}
    int subsetXORSum(vector<int>& nums) {
        vector<int>store;
        int sum=0;
        BackTrack(nums,store,0,sum);
        return sum;
    }
};