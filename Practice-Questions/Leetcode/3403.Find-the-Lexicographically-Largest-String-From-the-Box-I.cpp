class Solution {
public:
    string answerString(string word, int numFriends) {
        
    
        if(numFriends == 1)
            return word;

        int i=0; 

        int j = word.size()-(numFriends - 1); 
       
        
        string ans = ""; 

        int n = word.size(); 

        while(i<=n) 
        {
            string temp = "";

            for(int k=i ; k < min(n, j) ; k++)
            {
                temp+=word[k];
            }
            ans = max(ans, temp); 
            i++;
            j++;
        }
        return ans;
    }
};