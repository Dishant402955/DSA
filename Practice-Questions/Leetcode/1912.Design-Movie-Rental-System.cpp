class MovieRentingSystem {
public:
    struct Comp {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            if (a[0] != b[0]) return a[0] < b[0];  // price
            if (a[1] != b[1]) return a[1] < b[1];  // shop
            return a[2] < b[2];                    // movie
        }
    };

    // available movies grouped by movie
    map<int, set<vector<int>, Comp>> available;
    // rented movies grouped by movie
    map<int, set<vector<int>, Comp>> rented;
    // all rented movies globally
    set<vector<int>, Comp> allRented;
    // lookup (shop, movie) -> price
    map<pair<int,int>, int> priceMap;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            available[movie].insert({price, shop, movie});
            priceMap[{shop, movie}] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        int cnt = 0;
        for (auto &x : available[movie]) {
            res.push_back(x[1]); // shop id
            if (++cnt == 5) break;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        vector<int> curr = {price, shop, movie};
        available[movie].erase(curr);
        rented[movie].insert(curr);
        allRented.insert(curr);
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        vector<int> curr = {price, shop, movie};
        rented[movie].erase(curr);
        available[movie].insert(curr);
        allRented.erase(curr);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto &x : allRented) {
            res.push_back({x[1], x[2]}); // {shop, movie}
            if (++cnt == 5) break;
        }
        return res;
    }
};
