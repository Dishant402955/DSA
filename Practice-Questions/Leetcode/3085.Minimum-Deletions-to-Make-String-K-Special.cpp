class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<int,int>mpp;
       vector<int>freq;
       for(auto it:word){
        mpp[it-'a']++;
       }
       for(auto it:mpp)freq.push_back(it.second);
       sort(freq.begin(),freq.end());
       int mini=INT_MAX;
       for(int i=0;i<freq.size();i++){
        int base=freq[i],curr=0;
        for(int j=0;j<i;j++)curr+=freq[j];
        
        for(int j=i;j<freq.size();j++){
            if(freq[j]>(base+k))curr+=freq[j]-(base+k);
        }
        mini=min(mini,curr);
       }
     return mini;
    }
};
