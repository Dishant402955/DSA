class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.length(), m = allowed.size();
        vector<string> mat(n);
        unordered_map<string, bool> memo;
        mat.back() = bottom;

        auto dfs = [&](this auto&& dfs, int i, int j){
            if(i == 0)return true;
            if(j == i){
                if(memo.find(mat[i-1]) != memo.end())return memo[mat[i-1]];
                return memo[mat[i-1]] = dfs(i-1, 0);
            }
            for(int k=0;k<m;k++){
                char l = allowed[k][0], r = allowed[k][1], t = allowed[k][2];
                if(mat[i][j]!=l || mat[i][j+1]!=r)continue;
                mat[i-1].push_back(t);
                if(dfs(i, j+1))return true;
                mat[i-1].pop_back();
            }
            return false;
        };

        return dfs(n-1, 0);
    }
};
