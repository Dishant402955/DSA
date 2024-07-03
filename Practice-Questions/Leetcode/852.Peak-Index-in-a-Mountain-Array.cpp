class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int s = 0;
        int e = arr.size();
        int mid = s + (e-s)/2 ;
        
        while(s <= e){
            
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
                return mid;
            }
            else if(arr[mid] > arr[mid+1]){
                e = mid-1;
            }
            else if(arr[mid] < arr[mid+1]){
                s = mid+1;
            }
            
            mid = s + (e-s)/2 ;
        }
        
    return  -1;
    }
};