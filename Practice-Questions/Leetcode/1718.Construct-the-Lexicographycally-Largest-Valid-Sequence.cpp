class Solution {
public:

    vector<int> res;

    int s;

    void backtrack(int index, vector<int>& arr, vector<int>& nums) {

        

        if (res[0]!=0) {
            return;
        }


        if (index>=arr.size()) {
            res = arr;
            return;
        }

        if (arr[index]!=0) {
            backtrack(index+1,arr,nums);
            return;
        }

        for (int i = s;i>=1;i--) {
            if (arr[index]==0&&i==1&&nums[i]!=0) {
                nums[i]=0;
                arr[index]=i;
                backtrack(index+1,arr,nums);
                arr[index]=0;
                nums[i]=1;
            }
            else if (arr[index]==0&&index+i<arr.size()&&arr[index+i]==0&&nums[i]!=0) {
                arr[index]=i;
                arr[index+i]=i;
                nums[i]=0;
                backtrack(index+1,arr,nums);
                arr[index]=0;
                arr[index+i]=0;
                nums[i]=1;
            }
        }
        
    }

    vector<int> constructDistancedSequence(int n) {
        res = vector<int>((n*2)-1);
        vector<int> vec((n*2)-1);

        s = n;

        vector<int> nums(n+1,1);

        backtrack(0,vec,nums);



        return res;
    }
};