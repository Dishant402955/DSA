class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>a;
        string r;
        int n = k;
        for(int i = 0 ; i < s.size() ;i++)
        {   
            r += s[i];
            if(r.size() == k){
                a.push_back(r);
                r.clear();
                // k = n;
            }
        }
        if(!r.empty())
        {
           r.append(k - r.size() ,fill);
           a.push_back(r);
        }   
        return a;
     }
};
