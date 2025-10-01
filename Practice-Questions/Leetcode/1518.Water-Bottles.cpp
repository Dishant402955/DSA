
class Solution {
    
private: 
    
    void solve( int& ans, int e, int Empty, int filled){
        
        if( filled == 0 && Empty < e)
            return;
        
        ans += filled;
        Empty += filled;
        filled = 0;
        
        while(Empty >= e){
            
            Empty -= e;
            filled++;
            
        }
            
        solve( ans, e, Empty, filled);
        
    }
    
    
public:
    
    int numWaterBottles(int numBottles, int numExchange) {
        
        int empty = numBottles;
        int filled = 0;
        int ans = numBottles;
        
        solve(ans, numExchange, empty, filled);
        
        return ans;
        
    }
    
};
