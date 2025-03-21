class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_set<string> st;
        unordered_set<string> st1;
        for (int i = 0; i < supplies.size(); i++) {
            st.insert(supplies[i]);
        }
        vector<string> ans;
        for (int j = 0; j < ingredients.size(); j++) {
            if(st1.find(recipes[j])!=st1.end()) continue;
            bool isPresent = true;
            for (int k = 0; k < ingredients[j].size(); k++) {
                if (st.find(ingredients[j][k]) == st.end())
                    isPresent = false;
            }
            if (isPresent) {
                ans.push_back(recipes[j]);
                st.insert(recipes[j]);
                st1.insert(recipes[j]);
                j=-1;
            }
        }
        return ans;
    }
};