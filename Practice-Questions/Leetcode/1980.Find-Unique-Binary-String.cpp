class Solution {
public:
    unordered_set<string> st;
    string backtrack(string s, int n){
        if(s.size()==n){
            if(st.find(s)==st.end()){
                return s;
            }
            return "";
        }

        string ans = backtrack(s+"0", n);
        if(ans!="") return ans;
        ans = backtrack(s+"1", n);

        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        st.insert(nums.begin(), nums.end());

        int n = nums[0].size();

        string ans = backtrack("0", n);
        if(ans!="") return ans;
        ans = backtrack("1", n);

        return ans;
    }
};