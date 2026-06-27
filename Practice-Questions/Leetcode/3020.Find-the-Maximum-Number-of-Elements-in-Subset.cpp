//translated using AI
class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        int ans = 1;

        if (mp.count(1)) {
            int f = mp[1];
            if (f % 2 == 0)
                ans = max(ans, f - 1);
            else
                ans = max(ans, f);
        }

        vector<long long> keys;
        for (auto &it : mp) {
            keys.push_back(it.first);
        }

        for (long long cur : keys) {

            if (cur == 1)
                continue;

            long long temp = cur;
            int len = 0;

            while (true) {

                if (!mp.count(temp) || mp[temp] < 2)
                    break;

                len += 2;
                temp = temp * temp;
            }

            if (mp.count(temp) && mp[temp] == 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};
