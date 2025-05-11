class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
     int c=0;
     int i=0;
     while(i<arr.size())
     {
        if(arr[i]%2!=0)
        {
            c++;
          if(c==3) return true;
        }
        else c=0;
        i++;
     } 
     return false;  
    }
};