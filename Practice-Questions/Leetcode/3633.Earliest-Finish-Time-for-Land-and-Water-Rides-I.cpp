class Solution {
public:
    int solve(vector<int>& firstStartTime, vector<int>& firstDuration, vector<int>& secondStartTime, vector<int>& secondDuration) {
        // core logic
        // basically we are must startng with the earlierst in one of them
        // and for other ride checking the optimal way
        int ans=1e5;

        for(int j=0;j<firstStartTime.size();j++){
            int first_start=firstStartTime[j];
            int first_end=first_start+firstDuration[j];

            for(int i=0;i<secondStartTime.size();i++){
                if(secondStartTime[i]>=first_start &&
                   secondStartTime[i]<first_end){
                    // then we have to start at first_end
                    ans=min(ans,first_end+secondDuration[i]);
                }
                else if(secondStartTime[i]>=first_end){
                    ans=min(ans,secondStartTime[i]+secondDuration[i]);
                }
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n=landStartTime.size();
        int m=waterStartTime.size();
        
        int ans=1e5;

        // first W then L
        ans=min(ans,solve(waterStartTime,waterDuration, landStartTime,landDuration));

        // first L then W
        ans=min(ans,solve(landStartTime,landDuration, waterStartTime,waterDuration));

        return ans;
    }
};
