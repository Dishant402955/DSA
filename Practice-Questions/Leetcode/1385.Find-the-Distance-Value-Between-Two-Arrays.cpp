class Solution {
public:
    int quadratic(vector<int> &arr1, vector<int> &arr2, int d) {
        int ans = 0;
        for(auto num1 : arr1) {
            bool isValid = true;
            for(auto num2 : arr2) {
                if(abs(num1 - num2) <= d) {
                    isValid = false;
                    break;
                }
            }

            if(isValid) ans += 1;
        }

        return ans;
    }

    int logarithmic(vector<int> &arr1, vector<int> &arr2, int d) {
        int n = arr2.size(), ans = 0;
        sort(arr2.begin(), arr2.end());

        for(auto num1 : arr1) {
            int l = 0, r = n - 1;
            bool isValid = true;

            // 1, 8, 9, 10
            while(l <= r) {
                int m = l + (r - l) / 2;

                if(abs(num1 - arr2[m]) <= d) {
                    isValid = false;
                    break;
                } else {
                    if(num1 - arr2[m] < 0) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
            }

            ans += isValid;
        }

        return ans;
    }

    // int linear(vector<int> &arr1, vector<int> &arr2, int d) {
    //     auto [minEle, maxEle] = minmax_element(arr2.begin(), arr2.end()); // Pair of Iterators

    //     cout << *minEle << " " << *maxEle << endl;

    //     int ans = 0;
    //     for(auto num1 : arr1) {
    //         if(abs(num1 - *minEle) > d && abs(num1 - *maxEle) > d) 
    //             ans += 1;
    //     } 
    
    //     return ans;
    // }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // return linear(arr1, arr2, d);
        return logarithmic(arr1, arr2, d);
        return quadratic(arr1, arr2, d);
    }
};
