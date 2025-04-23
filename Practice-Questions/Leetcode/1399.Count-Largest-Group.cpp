class Solution {
public:
    int countLargestGroup(int n) {
        int maxi = 0;
        int count = 0;
        unordered_map<int,int> mp;

        // First get the Frequency of each digit Sum so, we cna know which group is of largest size
        for(int i = 1; i<=n; i++){
            int temp = i;
            int digSum = 0;
            while(temp){
                digSum += temp%10;
                temp /= 10;
            }

            mp[digSum]++;   
            maxi = max(maxi, mp[digSum]);
        }

        // Now count the groups who have maximum size 
        for(auto &i : mp){
            if(i.second == maxi){
                count++;
            }
        }
        return count;
    }
};