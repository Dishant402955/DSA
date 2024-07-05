class Solution {
public:
    
    void Merge( vector<int>& nums, int s, int e){
        
        int mid = (s+e)/2;
        
        int arr1[mid-s+1];
        int arr2[e-mid];
        
        int index = s;
        
        for(int i = s ; i <= mid; i++)
            arr1[i-s] = nums[index++] ;
        
        for(int i = mid+1 ; i <= e; i++)
            arr2[i-mid-1] = nums[index++] ;
        
        index = s;
        
        int index1 = 0;
        int index2 = 0;
        
        while( index1 < mid-s+1 && index2 < e-mid){
            
            if(arr1[index1] <= arr2[index2])
                nums[index++] = arr1[index1++];
            
            else
                nums[index++] = arr2[index2++];
            
        }
        
        while( index1 < mid-s+1 ){
            nums[index++] = arr1[index1++]; 
        }
        
        while( index2 < e-mid ){
            nums[index++] = arr2[index2++]; 
        }
            
    }
    
    
    void MergeSort( vector<int>& nums, int s, int e){
        
        if(s >= e)   return;
        
        int mid = (s+e)/2;
        
        MergeSort( nums, s, mid);
        
        MergeSort( nums, mid+1, e);
        
        Merge( nums, s, e);
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        
        MergeSort( nums, 0, nums.size()-1 );
        return nums;
        
    }
    
};