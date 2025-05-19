class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> numStrings;
        
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }

        // Sort strings based on concatenated values
        sort(numStrings.begin(), numStrings.end(),
             [](string &a, string &b) { return a + b > b + a; });

        
        if (numStrings[0] == "0") return "0";

        
        string ans;
        for (string &numStr : numStrings) {
            ans += numStr;
        }

        return ans;
    }
};