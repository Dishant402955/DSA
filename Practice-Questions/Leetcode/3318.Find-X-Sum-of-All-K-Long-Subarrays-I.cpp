class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;

            for (int j = i; j < i + k; j++)
                freq[nums[j]]++;

            vector<pair<int, int>> v(freq.begin(), freq.end());

            sort(v.begin(), v.end(), [](auto &a, auto &b) {
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });

            unordered_set<int> top;
            for (int j = 0; j < x && j < v.size(); j++)
                top.insert(v[j].first);

            int sum = 0;
            for (int j = i; j < i + k; j++)
                if (top.count(nums[j])) sum += nums[j];

            ans.push_back(sum);
        }

        return ans;
    }
};
