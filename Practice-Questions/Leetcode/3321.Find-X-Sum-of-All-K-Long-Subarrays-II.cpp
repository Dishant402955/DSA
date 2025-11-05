using ll = long long;
class Solution {
private:
    unordered_map<int, int> freq;
    // top holds current TOP x, rest hold elements in current window but !(top x)
    // using a descending set so easier to think
    set<pair<int, int>, greater<pair<int, int>>> top, rest; 
    ll currSum = 0;

    void insert(int value, int x) {
        if (freq[value] > 0) {
            // means we have to add it
            const pair<int, int> fv = {freq[value], value};
            if (top.find(fv) != top.end()) {
                // exist, remove so we can add it
                auto it = top.find(fv);
                currSum -= 1LL * it->first * it->second;
                top.erase(it);
                freq[value]++; // increment freq for value
                top.insert({freq[value], value});
            } else {
                // has to be in rest
                rest.erase(fv);
                freq[value]++; // increment freq for value
                top.insert({freq[value], value});
            }
        } else {
            top.insert({++freq[value], value});
        }
        // then we need a take of currSum
        currSum += 1LL * freq[value] * value;

        if (top.size() > x) {
            // if more elements, we need to move the smallest to rest
            auto it = prev(top.end());
            currSum -= 1LL * it->first * it->second;
            rest.insert(*it);
            top.erase(it);
        }
    }

    void erase(int value, int x) {
        // first check top
        if (freq[value] > 0) {
            // means we have to decrease freq by one
            const pair<int, int> fv = {freq[value], value};
            if (top.find(fv) != top.end()) {
                // if we have it in top, remove and add --freq
                auto it = top.find(fv);
                currSum -= 1LL * it->first * it->second;
                top.erase(it);

                // now add
                if (--freq[value] == 0) {
                    freq.erase(value);
                } else {
                    // now really what we need is to check if --freq is still the largest one to keep in top
                    // we don't know unless we push it to rest and compare.
                    // so we should insert to rest and then pick head from top
                    rest.insert({freq[value], value});
                }
            } else {
                // could it be in rest? yes
                auto it = rest.find(fv);
                if (it != rest.end()) {
                    // if in rest we should remove it because it's out of the window
                    rest.erase(it);
                }

                // now add
                if (--freq[value] == 0) {
                    freq.erase(value);
                } else {
                    // now still insert to rest bc we still have valid frequency
                    rest.insert({freq[value], value});
                }
            }

            // then we need to move head of rest to head 
            // bc if top is smaller than x, we need to promote the biggest freq in rest up to top.
            if (top.size() < x && !rest.empty()) {
                auto it = rest.begin();
                currSum += 1LL * it->first * it->second;
                top.insert(*it);
                rest.erase(it);
            }
        } // and freq[value] will not be <= 0
    }

public:
    vector<ll> findXSum(vector<int>& nums, int k, int x) {
        if (k <= 0 || k > (int)nums.size()) return {};

        vector<ll> ans(nums.size() - k + 1, 0);

        for (int i = 0; i < k; ++i) insert(nums[i], x);

        ans[0] = currSum;

        for (int left = 1, right = k; right < nums.size(); ++left, ++right) {
            erase(nums[left - 1], x);
            insert(nums[right], x);
            ans[left] = currSum;
        }

        return ans;
    }
};
