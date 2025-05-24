class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> v;
        for(int i=0;i<words.size();i++){
            string t = words[i];
            if(t.find(x) != string::npos){
                v.push_back(i);
            }
        }
        return v;
    }
};