class Solution {
public:
    bool isvowel(char& x) {
        return x=='a' ||  x=='A' || x=='e' || x=='E' || x=='O' || x=='o' || x=='i' || x=='u' || x=='U' || x=='I';
    }
    string sortVowels(string s) {
        //find all the vowels
        vector<char> vowels;
        for(char& x:s) {
            if(isvowel(x)){
                vowels.push_back(x);
            }
        }
        sort(vowels.begin(),vowels.end());
        int idx = 0;
        for(int i = 0;i<s.size();i++){
            if(isvowel(s[i])){
                s[i] = vowels[idx];
                idx++;
            }
        }
        return s;
    }
};
