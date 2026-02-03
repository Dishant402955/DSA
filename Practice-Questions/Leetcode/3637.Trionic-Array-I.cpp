class Solution {
public:
    bool isTrionic(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        while(i+1<n && arr[i+1]>arr[i]){
            i++;
        }
        if(i==n-1 || i==0)  return false;

        int p=i;

        while(i+1<n && arr[i+1]<arr[i]){
            i++;
        }
        if(i==n-1 || i==p)  return false;

        while(i+1<n && arr[i+1]>arr[i]){
            i++;
        }

        if(i==n-1)  return true;
        return false;
    }
};
