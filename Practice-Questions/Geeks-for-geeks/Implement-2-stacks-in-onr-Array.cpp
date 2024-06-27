// Approach will be written soon

class twoStacks
{
    public:

    int size = 100 ;
    int array[100] ;
    int top1 = -1;
    int top2 = 49;
    
    twoStacks() {}
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if( top1 < 49 )    array[++top1] = x;
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        if( top2 < 99 )    array[++top2] = x;
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if( top1 == -1 )   return -1;
           
        else      return array[top1--];
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(top2 == 49)      return -1;
           
       else       return array[top2--];
    }

};

