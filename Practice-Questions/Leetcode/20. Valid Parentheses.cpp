class Solution {
public:
    bool can(char c, char d){
        if( c == '(' && d == ')')
            return true;
        if( c == '[' && d == ']')
            return true;
        if( c == '{' && d == '}')
            return true;

        return false;
    }

    bool isValid(string s) {
        
        if( s.size() <= 1)
            return false;

        stack<char> stack;

        for( char ch: s){

            if( ch=='(' || ch=='{' || ch=='['){
                stack.push(ch);
            }
            else{
                if( stack.empty())
                    return false;
                    
                char top = stack.top();


                if( top == '(' && ch == ')'){
                  stack.pop();
                  continue;
                }
                else if( top == '[' && ch == ']'){
                  stack.pop();
                  continue;
                }
                else if( top == '{' && ch == '}'){
                  stack.pop();
                  continue;
                }
                else{
                  return false;
                }                 
            }

        }
    
        return stack.empty();
    }
};