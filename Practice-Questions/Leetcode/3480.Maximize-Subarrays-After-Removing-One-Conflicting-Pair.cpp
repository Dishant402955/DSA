class Solution {
public:
    static bool comp(pair<int,int> p , int val){
        return p.first <= val ;
    }
    long long maxSubarrays(int n, vector<vector<int>>& pair) {
        multiset<std::pair<int,int>> pairs ; 

        for(auto i : pair){
            auto p = make_pair(max(i[0] , i[1]) , min(i[0] , i[1])) ;
            pairs.insert(p) ;
        }

        map<std::pair<int,int> , int> indx ; 
        int k = 0 ;

        for(auto i : pairs){
            indx[i] = k++;
        }

        long long ans = 0 ;
        auto second_boundary = pairs.begin() ;
        second_boundary++;
        auto first_boundary = pairs.begin() ;
        unordered_map<int,long long> extra ;


        for(int i = 1 ; i <= n ; i++){
            auto it = first_boundary ;
            while(it != pairs.end() && i > it->second) it++;
            //moving to the conflicting pair where both a and b are on the right side of i
            first_boundary = it ;
            if(it == pairs.end()){
                ans += (n+1 - i) ;
                second_boundary = it ;
            }
            else{
                auto temp = it ;
                ans += it->first - i ;
                int ct = it->first - i ;
                if(second_boundary == pairs.end()){
                    extra[indx[*temp]] += n+1-i - ct ;
                }
                else if(second_boundary->second >= i && second_boundary != first_boundary){
                    extra[indx[*temp]] += (second_boundary->first - i) - ct ;
                }
                else{
                    it++ ; 
                    while(it != pairs.end() && i > it->second) it++;
                    if(it != pairs.end()){
                        extra[indx[*temp]] += (it->first - i) - ct ;
                    }else{
                        extra[indx[*temp]] += n+1-i - ct ;
                    }
                    second_boundary = it ;
                }
                
            }
        }
        long long max_extra = 0LL ; 
        for(auto i : extra) max_extra = max(max_extra , i.second) ;
        return ans + max_extra ;
    }
};

