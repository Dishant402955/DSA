class Solution {
public:
    int passThePillow(int n, int time) {
        
        int forward = 1;
        int index = 1;
        int count = 0;
        
       
        
        
        for(int i = 1 ; i <= time ; i++){
            
            if(forward){
                
                if(index == n){
                    index = n-1;
                    forward = 0;
                    continue;
                }
                index++;
                
            }
            
            else{
                
                if(index == 1){
                    index = 2;
                    forward = 1;
                    continue;
                }
                index--;
            }
            
            
        }
        
        return index;
    }
};