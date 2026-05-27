class Solution {
public:
    int numberOfSpecialChars(string s) 
    {
        vector<int>t1(26,-1);
        vector<int>t2(26,-1);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                t1[s[i]-'a'] = i;
            }
            else
            {
                if(t2[s[i]-'A']==-1) t2[s[i]-'A'] = i;
            }
        }
        int cnt = 0;
        for(int i=0;i<26;i++)
        {
            if(t1[i]<t2[i] && t1[i]!=-1) cnt++;
        }
        return cnt;
    }
//please upvote...
};
