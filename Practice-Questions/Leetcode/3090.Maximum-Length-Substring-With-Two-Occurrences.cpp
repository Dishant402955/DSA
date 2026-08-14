class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size(),l=0,ans=0;
        int cnt[26]={0};
        for(int r=0;r<n;r++){
            cnt[s[r]-'a']++;
            while(cnt[s[r]-'a']>2) cnt[s[l++]-'a']--;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
