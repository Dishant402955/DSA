class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        for(auto word : words)
        {
            int sum = 0;
            for(char ch : word)
            {
                sum += weights[ch - 'a'];
            }
            sum %= 26;
            result.push_back('z' - sum);
        }
        return result;
    }
};
