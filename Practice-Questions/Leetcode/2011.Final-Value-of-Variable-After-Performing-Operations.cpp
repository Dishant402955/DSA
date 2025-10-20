class Solution {
public:
    int finalValueAfterOperations(vector<string> &operations) {
        int value = 0;

        for(auto &str: operations) {
            if((str[0] == '+' && str[1] == '+') || (str[1] == '+' && str[2] == '+')) value++;
            else value--;
        }

        return value;
    }
};
