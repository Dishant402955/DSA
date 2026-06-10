class Solution {
public:
    int n;
    vector<int>tree_max;
    vector<int>tree_min;
    void build_ST(int node,int start,int end,vector<int>&nums){
        if(start==end){
            tree_max[node] = nums[start];
            tree_min[node] = nums[start];
            return;
        }

        int mid = start + (end-start)/2;
        int left_child = 2*node + 1;
        int right_child = 2*node + 2;

        build_ST(left_child,start,mid,nums);
        build_ST(right_child,mid+1,end,nums);

        tree_max[node] = max(tree_max[left_child],tree_max[right_child]);
        tree_min[node] = min(tree_min[left_child],tree_min[right_child]);
    }

    int query_max(int i,int start,int end, int l, int r){
        if(end<l || r<start) return -1e9;
        if(l<=start && end<=r) return tree_max[i];

        int mid  = start + (end-start)/2;
        
        int m1 = query_max(2*i+1,start,mid,l,r);
        int m2 = query_max(2*i+2,mid+1,end,l,r);

        return max(m1,m2);
    }
    int query_min(int i,int start,int end, int l, int r){
        if(end<l || r<start) return 1e9;
        if(l<=start && end<=r) return tree_min[i];

        int mid  = start + (end-start)/2;
        
        int m1 = query_min(2*i+1,start,mid,l,r);
        int m2 = query_min(2*i+2,mid+1,end,l,r);

        return min(m1,m2);
    }

    int get_value(int l,int r){
        return query_max(0,0,n-1,l,r)-query_min(0,0,n-1,l,r);
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        n = nums.size();
        tree_max.assign(4*n,0);
        tree_min.assign(4*n,0);
        
        build_ST(0,0,n-1,nums);

        //storing value for each starting point and also subarray range,
        // so that its next element can be inserted once its other element popped

        // pushing all longest subarray range firstly for each starting point

        // max heap
        priority_queue<pair<long long,pair<long long,long long>>>pq;

        for(int i=0;i<n;i++) pq.push({get_value(i,n-1),{i,n-1}});
        long long ans=0;
        while(k>0 && !pq.empty()){
            auto it = pq.top(); pq.pop();
            long long value = it.first;
            long long l = it.second.first;
            long long r = it.second.second;

            ans +=value;

            if(r>l) pq.push({get_value(l,r-1),{l,r-1}});
            k--;
        }

        return ans;
    }
};
