class Solution {
public:
    //Approach : Reverse Sliding Window with a Monotonic Deque

    //Time Complexity = O(n) =>
    /* The left pointer visits every element once → O(n).
    * The right pointer only moves left, at most n times in total → O(n).
    * Each group is added to the deque once and removed at most once → O(n) total deque operations.
    * Although the code has nested loops, their work across the entire traversal is linear.
    * Total: O(n) + O(n) + O(n) = O(n).
    */

    //Space Complexity = O(n) =>
    /* 
    * The deque can hold up to n groups in the worst case.
    * Variables such as left, right, cost, and answer use O(1) space.
    * The input array is unchanged; no extra array is created.
    * Total auxiliary space: O(n).
    */


    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        
        //1.) Initialization
        int n = nums.size();

        int right = n - 1;
        long long cost = 0;
        long long ans = 0;

        //Each group stores {required_height, no_of_elements}
        //Front = rightmost element, Back = leftmost element
        deque<pair<int, int>> groups;

        //2.) Traverse from right to left(Sliding window)
        for(int left = n - 1; left >= 0; left--){

            int height = nums[left];
            int count = 1;

            //Raise smaller groups to the new leftmost height
            //Equal-height groups merge without increasing the cost
            while(!groups.empty() && groups.back().first <= height){
                
                auto [oldHeight, oldCount] = groups.back();
                groups.pop_back();

                cost += 1LL *(height - oldHeight) * oldCount;
                count += oldCount;
            }

            groups.push_back({height, count});

            //3.) Shrink from right until the cost fits k
            while(cost > k){

                //Remove the rightmost element's repair cost
                cost -= 1LL * groups.front().first - nums[right];
                
                groups.front().second--;

                if(groups.front().second == 0){
                    
                    groups.pop_front();
                }

                right--;//shrinking from right
           
            }

            //4.) Count all valid subarrays starting at left
            //their ending indices ranges from left through right

            ans += right - left + 1;

        }

        //5.) Finally return the answer
        return ans;
    }
};
