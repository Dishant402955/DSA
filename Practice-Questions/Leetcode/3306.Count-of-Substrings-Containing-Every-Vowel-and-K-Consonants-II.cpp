class Solution {
public:
    long long atMostK(string word, int k) {
        int n = word.size(), l = 0, cons = 0;
        long long atleastk = 0;
        map<char, int> vowels;

        // Step 1: Store all the vowels
        set<char> allvows = {'a', 'e', 'i', 'o', 'u'};
         
        for (int i = 0; i < n; i++) {

            // Step 2: Check whether word[i] is a vowel or consonant
            if (allvows.find(word[i]) != allvows.end())
                vowels[word[i]]++;
            else
                cons++;

            /* Step 3: We keep reducing the string from the left when we find 
             a substr with aeiou and atleast k consonants to the point where we have
             atleast aeiou and barely k consonants*/
            while (vowels.size() == 5 && cons > k) {
                if (allvows.find(word[l]) != allvows.end()) {
                    vowels[word[l]]--;
                    if (vowels[word[l]] == 0)
                        vowels.erase(word[l]);
                } else
                    cons--;
                l++;
            }
            
            // Step 4: The number of atleast k substr's at this index is i - l + 1
            atleastk += (i - l + 1);
        }
        return atleastk;
    }
    long long countOfSubstrings(string word, int k) {
        return atMostK(word, k) - atMostK(word, k - 1);
    }
};