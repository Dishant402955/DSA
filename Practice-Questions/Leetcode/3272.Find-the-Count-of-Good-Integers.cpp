class Solution {
public:
    vector<int> fact = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
    set<string> sortedNum;
    
    //counts the number of ways a numeric string can be rearranged 
    //without leading zeroes
    long long countWays(string s){
        
        //storing frequency of each digit
        //max size of map: 10(0-9)
        map<char,int> m;
        for(char c:s) m[c]++;
        
        long long ans = 0, temp, n = s.size();
        
        map<char,int> cm = m; //copy of the map
        
        for(auto it:m){
            if(it.first=='0') continue;
            cm = m;
            
            //first digit must be non-zero
            // 0 0 2 2 2 :
            // first digit: 2, remaining 4 digits can be 0 0 2 2(n-1)
            cm[it.first]--;
            temp = fact[n-1];
            for(auto it:cm) temp /= fact[it.second];
            ans += temp;
        }
        return ans;
    }
    long long recursion(long long num,int idx,int &n,int &k){
        //base case
        if(idx>=((n+1)/2)){
            string s = to_string(num);
            string left = s.substr(0,n/2);
            reverse(left.begin(),left.end());//right
            
            //s is now plaindromic
            //now we need to check if s is divisible by k
            s.append(left);
            if(k==1 || stol(s)%k==0) {
                //for every k-palindromic string
                //we are checking how many ways can it be rearranged
                //all those rearrangements will be good integers.
                //2442 and 4224 will have same rearrangements
                //2442 - 2244,2442,4422,2424,4224,4242
                //4224 - 2244,2442,4422,2424,4224,4242 (same as 2442)
                //so sorting the numbers and storing in set to avoid duplicate calculations
                //if we have already calculated for 2442, no need to check for 4224 
                sort(s.begin(),s.end());
                
                //if not in set - calculate ways and add to answer.
                if(sortedNum.find(s)==sortedNum.end()){
                    sortedNum.insert(s);
                    return countWays(s);
                }
                return 0;
            }
            return 0;
        }
        
        //trying with all possible digits
        long long temp=0 , ans = 0;
        for(int i=0;i<=9;i++){
            temp  = num*10+i;
            ans += recursion(temp,idx+1,n,k);
        }
        return ans;
    }
    long long countGoodIntegers(int n, int k) {
        long long ans = 0;
        
        //generating all k-palindromes  
        // and finding the number of rearrangements
        //making the first half of the array
        //appending the reverse of first half to make it palindrome
        //4 digits- first half:10,11,12,13,....20,21,22....
        // palindromic strings: 1001,1111,1221,1331,....2002,2112,2222...
        
        //first digit will always be non-zero
        for(int i=1;i<=9;i++){
            ans += recursion(i,1,n,k);
        }
        return ans;
    }
};