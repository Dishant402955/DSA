/*
By   :: savetrees
Used :: In Place Modification using Erase and Insert
*/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums,int pivot) {
        int ptr=0;
        bool check=false;
        for (int i=0;i<nums.size();i++) {
            int n=nums[i];
            if (nums[i]<pivot) {  
                if (ptr!=i) {
                    int temp=nums[i];
                    nums.erase(nums.begin()+i);
                    nums.insert(nums.begin()+ptr,temp);
                }
                ptr++;
            }
        }
        for (int i=ptr;i<nums.size();i++) {  
            if (nums[i]==pivot) {
                if (ptr!=i) {
                    int temp=nums[i];
                    nums.erase(nums.begin()+i);
                    nums.insert(nums.begin()+ptr,temp);
                }
                ptr++;
            }
        }
        return nums;
    }
};