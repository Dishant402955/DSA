class Solution {
public:

    int find1(int n){
        int sum = 0;
        while(n > 0){
            sum += n%2;
            n /= 2;
        }
        return sum;
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<multiset<int>>  v(15);
        for(int i=0;i<arr.size();i++){
            v[find1(arr[i])].insert(arr[i]);
        }
        vector<int> ans;
        for(multiset<int> a : v){
            for(int i : a){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
