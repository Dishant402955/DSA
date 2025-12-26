class Solution {
public:
    int bestClosingTime(string customers) {
        int totalOnes = 0;
        for(char c: customers){
            if(c == 'Y')
                totalOnes++;
        }
        int ones = 0, zeroes = 0, mini = customers.size(), minInd = -1, n  = customers.size(), penalty;
        for(int i = 0;i<n;i++){
            penalty = totalOnes - ones + zeroes;
            if(penalty < mini){
                mini = penalty;
                minInd = i;
            }
            if(customers[i] == 'Y')
                ones++;
            else
                zeroes++;
        }
        if(zeroes < mini){
            return n;
        }
        return minInd;
    }
};
