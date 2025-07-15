class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3)
        return false;

        bool vowel = false;
        bool cons = false;

        for(char ch : word)
        {
            if(!((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')))
            return false;

            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            vowel = true;

            if(!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') && (!(ch >= '0' && ch <= '9')))
            cons = true;
        }

        return vowel & cons;
    }
};
