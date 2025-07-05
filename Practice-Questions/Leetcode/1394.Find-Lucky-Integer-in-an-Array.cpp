class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i = 0, j = 0, n = arr.size(), res = -1;
        while (j < n) {
            while (j < n && arr[i] == arr[j]) j++;
            if (arr[i] == j - i) res = max(res, arr[i]);
            i = j;
        }
        return res;
    }
};
