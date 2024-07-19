class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& m) {
        
        int r = m.size();
        int c = m[0].size();

        vector<int> ans;
        vector<int> minis;

        for(int i = 0 ; i < r; i++){

            int mini = INT_MAX;
            for(int j = 0; j < c; j++){
                mini = min( mini , m[i][j] );
            }  
            minis.push_back(mini);

        }

        for(int j = 0; j < c; j++){

            int maxi = INT_MIN;
            for(int i = 0; i < r; i++){
                maxi = max( maxi, m[i][j]);
            }
        
            for(int i = 0; i < minis.size(); i++){
                if(maxi == minis[i])
                    ans.push_back(maxi);
            }

    
    }
    return ans;
    }
};