#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> stack(n + 1, 0);
        int top = 0;
        int ans = 0;

        for (int num : nums) {
            while (stack[top] > num) {
                top--;
                ans++;
            }
            if (stack[top] != num) {
                top++;
                stack[top] = num;
            }
        }

        return ans + top;
    }
};
