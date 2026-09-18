class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int>first(26,n);
        vector<int>last(26,-1);

        for(int i=0;i<n;i++)
        {
            int ch = s[i]-'a';
            first[ch] = min(first[ch],i);
            last[ch] = i;
        }

        vector<pair<int,int>>intervals;
        for(int i=0;i<n;i++)
        {
            int ch = s[i]-'a';
            if(i!=first[ch]) continue;

            int left = i;
            int right = last[ch];
            bool valid = true;
            for(int j=left;j<=right;j++)
            {
                int curr = s[j] - 'a';
                if(first[curr]<left) 
                {
                    valid = false;
                    break;
                }

                right = max(right,last[curr]);
            }
            
            if(!valid) continue;
            intervals.push_back({left,right});
        }

        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>>validIntervals;

        for(auto &pr:intervals)
        {
            if(validIntervals.empty()  ||  validIntervals.back().second<pr.first) validIntervals.push_back(pr);
            else
            {
                if(pr.second<validIntervals.back().second) validIntervals.back() = pr;
            }
        }

        vector<string>ans;
        for(auto &pr:validIntervals)
        {
            ans.push_back(s.substr(pr.first,pr.second-pr.first+1));
        }

        return ans;
    }
};
