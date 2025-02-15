class Solution {
public:

    void backTracking(int i, vector<int>&numbers, int sum, int val, int find, bool &ans){

        if(!ans){
            if(i == numbers.size() && sum+val == find){
                ans = true;    
            }
            else if(i == numbers.size()){
                ans = false;
            }
            else{
                backTracking(i+1, numbers, sum, (val*10)+numbers[i], find, ans);
                backTracking(i+1, numbers, sum+val, numbers[i], find, ans);
            }
        }
    }

    int punishmentNumber(int n) {
        
        int i, ans = 0, aux, index;
        bool flag;

        for(i = 1; i<=n; i++){
            flag = false;
            index = 0;
            aux = i*i;
            vector<int>numbers;

            while(aux){
                numbers.push_back(aux%10);
                aux/=10;
                index++;
            }

            reverse(numbers.begin(), numbers.end());
            backTracking(0, numbers, 0, 0, i, flag);
            if(flag){
                ans+=(i*i);
            }
            
        }

        return ans;
    }
};