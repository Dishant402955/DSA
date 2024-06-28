//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        
        stack<int> helper;
        
        while (!q.empty()){
    
            helper.push(q.front());
            q.pop();
            
        }
        
        while (!helper.empty()){
           
            q.push(helper.top());
            helper.pop();
           
        }
        
        return q;
    }
};