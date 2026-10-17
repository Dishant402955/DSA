class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<tuple<int, int, int>> arr;

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            int digitSum = 0;

            while (curr > 0) {
                digitSum += curr % 10;
                curr /= 10;
            }

            arr.push_back({digitSum, nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> perm(n);

        for (int i = 0; i < n; i++) {
            perm[i] = get<2>(arr[i]);
        }

        vector<bool> visited(n, false);
        int cycles = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }

            cycles++;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = perm[j];
            }
        }

        return n - cycles;
    }
};
