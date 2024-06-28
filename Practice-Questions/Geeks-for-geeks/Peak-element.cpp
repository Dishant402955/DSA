class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       if( n==1 )   return 0;    
        
       if( arr[0] > arr[1] )   return 0;
       
       if( arr[n-1] > arr[n-2] ) return n-1;
       
       int start = 0 ;
       int end = n-2;
       int mid = (start+end)/2;
       
       while( start <= end ){
           
           if( arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1] ){
               return mid;
           } 
           else if ( arr[mid] < arr[mid+1] ){
               start = mid+1 ;
           }
           else{
               end = mid-1;
           }
           
           mid = (start+end)/2;
       }
       
       return -1;
       
    }
    
  
};