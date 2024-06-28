class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
      
      int max = INT_MIN ;
      vector<int> answer;
      
      for(int i = n-1 ; i >= 0 ; i--){
          
          if( arr[i] < max )   continue;
          
          max = arr[i] ;
          answer.push_back(max);
          
      }
      
      reverse(answer.begin(),answer.end());
      
      return answer;
      
    }
};