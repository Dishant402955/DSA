#include <vector>
using namespace std;

class Solution {
public:
   int minimumPairRemoval(vector<int>& nums) {
       vector<int> arr(nums.begin(), nums.end());
       int ops = 0;

       while (!isSorted(arr)) {
           int minSum = INT_MAX, idx = 0;
           for (int i = 0; i + 1 < arr.size(); i++) {
               if (arr[i] + arr[i+1] < minSum) {
                   minSum = arr[i] + arr[i+1];
                   idx = i;
               }
           }
           arr[idx] = minSum;
           arr.erase(arr.begin() + idx + 1);
           ops++;
       }
       return ops;
   }

   bool isSorted(vector<int>& arr) {
       for (int i = 1; i < arr.size(); i++)
           if (arr[i] < arr[i-1]) return false;
       return true;
   }
};
