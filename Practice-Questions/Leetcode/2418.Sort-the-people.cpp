class Solution {
public:
    vector<string> sortPeople(vector<string>& n, vector<int>& h) {
        
        vector<pair<int,string>> m;

        for( int i=0; i<h.size(); i++){
            m.push_back(make_pair(h[i],n[i]));
        }

        sort(m.begin(), m.end());

        reverse(m.begin(),m.end());

        for(int i=0; i<h.size(); i++){
            n[i] = m[i].second;
        }

        return n;
    }
};