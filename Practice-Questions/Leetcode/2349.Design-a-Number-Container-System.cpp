class NumberContainers {
public:
    unordered_map<int,set<int>>umap;
    unordered_map<int,int>nums;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(nums.find(index)!=nums.end()){
            int prev=nums[index];
            if(umap[prev].size()==1) umap.erase(prev);
            else umap[prev].erase(index);
        }
        nums[index]=number;
        umap[number].insert(index);
    }
    
    int find(int number) {
        if(umap.find(number)!=umap.end()) return *umap[number].begin();
        else return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */