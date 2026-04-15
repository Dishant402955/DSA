class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        
        int left = startIndex;
        int right = startIndex;
        int steps = 0;

        while (true) {
            if (words[left] == target || words[right] == target)
                return steps;

            left = (left - 1 + n) % n;
            right = (right + 1) % n;
            steps++;

            if (left == right) { 
                if (words[left] == target) return steps;
                break;
            }
        }

        return -1;
    }
};
